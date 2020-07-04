// gcc -I. -o sample-smtp sample-smtp.c libsend.a libconn.a libconfig.a libcore.a libemail.a libaddress.a libmutt.a -lpcre2-8 -lidn2 -lsasl2 -lgnutls

#include "config.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "mutt/lib.h"
#include "config/lib.h"
#include "core/lib.h"
#include "conn/lib.h"
#include "context.h"
#include "send/lib.h"

static const char *lorem_text =
  "Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Vivamus vitae\n"
  "risus vitae lorem iaculis placerat. Aliquam sit amet felis. Etiam\n"
  "congue. Donec risus risus, pretium ac, tincidunt eu, tempor eu,\n"
  "quam. Morbi blandit mollis magna. Suspendisse eu tortor. Donec vitae felis\n"
  "nec ligula blandit rhoncus. Ut a pede ac neque mattis facilisis. Nulla\n"
  "nunc ipsum, sodales vitae, hendrerit non, imperdiet ac, ante. Morbi sit\n"
  "amet mi. Ut magna. Curabitur id est. Nulla velit. Sed consectetuer sodales\n"
  "justo. Aliquam dictum gravida libero. Sed eu turpis. Nunc id lorem. Aenean\n"
  "consequat tempor mi. Phasellus in neque. Nunc fermentum convallis ligula.\n";

// clang-format off
struct Address *C_EnvelopeFromAddress; ///< Config: Manually set the sender for outgoing messages
bool            C_SslForceTls;         ///< Config: (ssl) Require TLS encryption for all connections
unsigned char   C_SslStarttls;         ///< Config: (ssl) Use STARTTLS on servers advertising the capability

static struct ConfigDef Vars[] = {
  { "dsn_notify",                 DT_STRING,                &C_DsnNotify,               0,        0, NULL },
  { "dsn_return",                 DT_STRING,                &C_DsnReturn,               0,        0, NULL },
  { "envelope_from_address",      DT_ADDRESS,               &C_EnvelopeFromAddress,     0,        0, NULL },
  { "smtp_authenticators",        DT_SLIST|SLIST_SEP_COLON, &C_SmtpAuthenticators,      0,        0, NULL },
  { "smtp_oauth_refresh_command", DT_STRING|DT_COMMAND,     &C_SmtpOauthRefreshCommand, 0,        0, NULL },
  { "smtp_pass",                  DT_STRING,                &C_SmtpPass,                0,        0, NULL },
  { "smtp_user",                  DT_STRING,                &C_SmtpUser,                0,        0, NULL },
  { "smtp_url",                   DT_STRING,                &C_SmtpUrl,                 0,        0, NULL },
  { "ssl_force_tls",              DT_BOOL,                  &C_SslForceTls,             false,    0, NULL },
  { "ssl_starttls",               DT_QUAD,                  &C_SslStarttls,             MUTT_YES, 0, NULL },
  { NULL },
};
// clang-format on

struct ConfigSet *config_setup(void)
{
  struct ConfigSet *cs = cs_new(32);

  address_init(cs);
  bool_init(cs);
  quad_init(cs);
  slist_init(cs);
  string_init(cs);

  if (!cs_register_variables(cs, Vars, 0))
    cs_free(&cs);

  return cs;
}

typedef uint16_t CompletionFlags;

enum ProgressType
{
  dummy
};

struct Progress;

bool OptNoCurses;
char *ShortHostname;
int SigInt;
char *Username;

#define MUTT_ACCT_TYPE_SMTP 3

// gui

int mutt_get_field_full(const char *field, char *buf, size_t buflen, CompletionFlags complete, bool multiple, char ***files, int *numfiles)
{
  if (field || buf || buflen || complete || multiple || files || numfiles)
  {
  }

  return -1;
}

int mutt_get_field_unbuffered(const char *msg, char *buf, size_t buflen, CompletionFlags flags)
{
  if (msg || buf || buflen || flags)
  {
  }

  return -1;
}

void mutt_query_exit(void)
{
}

enum QuadOption query_quadoption(enum QuadOption opt, const char *prompt)
{
  if (opt || prompt)
  {
  }

  return 0;
}


// main

int mutt_account_fromurl(struct ConnAccount *cac, const struct Url *url)
{
  /* must be present */
  if (url->host)
    mutt_str_copy(cac->host, url->host, sizeof(cac->host));
  else
    return -1;

  if (url->user)
  {
    mutt_str_copy(cac->user, url->user, sizeof(cac->user));
    cac->flags |= MUTT_ACCT_USER;
  }
  if (url->pass)
  {
    mutt_str_copy(cac->pass, url->pass, sizeof(cac->pass));
    cac->flags |= MUTT_ACCT_PASS;
  }
  if (url->port)
  {
    cac->port = url->port;
    cac->flags |= MUTT_ACCT_PORT;
  }

  return 0;
}

void mutt_account_tourl(struct ConnAccount *cac, struct Url *url)
{
  url->scheme = U_UNKNOWN;
  url->user = NULL;
  url->pass = NULL;
  url->port = 0;
  url->path = NULL;

#ifdef USE_SMTP
  if (cac->type == MUTT_ACCT_TYPE_SMTP)
  {
    if (cac->flags & MUTT_ACCT_SSL)
      url->scheme = U_SMTPS;
    else
      url->scheme = U_SMTP;
  }
#endif

  url->host = cac->host;
  if (cac->flags & MUTT_ACCT_PORT)
    url->port = cac->port;
  if (cac->flags & MUTT_ACCT_USER)
    url->user = cac->user;
  if (cac->flags & MUTT_ACCT_PASS)
    url->pass = cac->pass;
}

struct Connection *mutt_conn_new(const struct ConnAccount *cac)
{
  enum ConnectionType conn_type;

  if (C_Tunnel)
    conn_type = MUTT_CONNECTION_TUNNEL;
  else if (cac->flags & MUTT_ACCT_SSL)
    conn_type = MUTT_CONNECTION_SSL;
  else
    conn_type = MUTT_CONNECTION_SIMPLE;

  struct Connection *conn = mutt_socket_new(conn_type);
  if (conn)
  {
    memcpy(&conn->account, cac, sizeof(struct ConnAccount));
  }
  else
  {
    if (conn_type == MUTT_CONNECTION_SSL)
    {
#ifndef USE_SSL
      /* that's probably why it failed */
      mutt_error(_("SSL is unavailable, can't connect to %s"), cac->host);
#endif
    }
  }
  return conn;
}

struct Connection *mutt_conn_find(const struct ConnAccount *cac)
{
  struct Url url = { 0 };

  /* cac isn't actually modified, since url isn't either */
  mutt_account_tourl((struct ConnAccount *) cac, &url);
  return mutt_conn_new(cac);
}

void mutt_progress_init(struct Progress *progress, const char *msg, enum ProgressType type, size_t size)
{
  if (progress || msg || type || size)
  {
  }
}

void mutt_progress_update(struct Progress *progress, size_t pos, int percent)
{
  if (progress || pos || percent)
  {
  }
}

void mutt_sleep(short s)
{
  if (s)
  {
  }
}

int mutt_system(const char *cmd)
{
  if (cmd)
  {
  }

  return -1;
}


// conn

int dlg_verify_cert(const char *title, struct ListHead *list, bool allow_always, bool allow_skip)
{
  if (title || list || allow_always || allow_skip)
  {
  }

  return 0;
}


// sendlib

const char *mutt_fqdn(bool may_hide_host, const struct ConfigSubset *sub)
{
  if (may_hide_host || sub)
  {
  }
  return NULL;
}


bool create_message(const char *file, struct AddressList *from, struct AddressList *to, struct AddressList *cc, const char *subject)
{
  FILE *fp = fopen(file, "w+");
  if (!fp)
    return false;

  char buf[1024];

  fputs(mutt_date_make_date(buf, sizeof(buf)), fp);

  if (!TAILQ_EMPTY(from))
  {
    buf[0] = '\0';
    mutt_addrlist_write(from, buf, sizeof(buf), false);
    fprintf(fp, "From: %s\n", buf);
  }

  if (!TAILQ_EMPTY(to))
  {
    buf[0] = '\0';
    mutt_addrlist_write(to, buf, sizeof(buf), false);
    fprintf(fp, "To: %s\n", buf);
  }

  if (!TAILQ_EMPTY(cc))
  {
    buf[0] = '\0';
    mutt_addrlist_write(cc, buf, sizeof(buf), false);
    fprintf(fp, "Cc: %s\n", buf);
  }

  fprintf(fp, "Subject: %s\n", subject);

  fprintf(fp, "\n");
  fprintf(fp, lorem_text);

  fclose(fp);
  return true;
}

void test_smtp(void)
{
  struct AddressList from = TAILQ_HEAD_INITIALIZER(from);
  struct AddressList to = TAILQ_HEAD_INITIALIZER(to);
  struct AddressList cc = TAILQ_HEAD_INITIALIZER(cc);
  struct AddressList bcc = TAILQ_HEAD_INITIALIZER(bcc);
  const char *msgfile = "message.txt";
  const char *subject = "something something";
  bool eightbit = false;

  struct Address *a1 = mutt_addr_create("Richard Russon", "rich@flatcap.org");
  mutt_addrlist_append(&from, a1);

  struct Address *a2 = mutt_addr_create("Richard Russon", "rich+to@flatcap.org");
  mutt_addrlist_append(&to, a2);

  // struct Address *a3 = mutt_addr_create("Richard Russon", "rich+cc@flatcap.org");
  // mutt_addrlist_append(&cc, a3);

  // struct Address *a4 = mutt_addr_create("Richard Russon", "rich+bcc@flatcap.org");
  // mutt_addrlist_append(&bcc, a4);

  if (!create_message(msgfile, &from, &to, &cc, subject))
    return;

  C_SmtpUrl = mutt_str_dup("smtp://flatcap.org");
  ShortHostname = "laptop";

  int rc = mutt_smtp_send(&from, &to, &cc, &bcc, msgfile, eightbit, NeoMutt->sub);
  printf("mutt_smtp_send = %d\n", rc);

  mutt_addrlist_clear(&from);
  mutt_addrlist_clear(&to);
  mutt_addrlist_clear(&cc);
  mutt_addrlist_clear(&bcc);
}

int main()
{
  struct ConfigSet *cs = config_setup();
  if (!cs)
    return 1;

  NeoMutt = neomutt_new(cs);
  if (!NeoMutt)
    return 1;

  test_smtp();

  neomutt_free(&NeoMutt);
  cs_free(&cs);
  return 0;
}
