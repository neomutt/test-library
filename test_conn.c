#include "config.h"
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mutt/lib.h"
#include "config/lib.h"
#include "conn/lib.h"
#include "conn/private.h"
#include "mutt.h"
#include "history/lib.h"
#include "key/lib.h"
#include "menu/lib.h"
#include "imap/account.h"

struct AddressList;
struct Envelope;
struct CompleteOps;

ARRAY_HEAD(CertArray, const char *);

int SigInt;
bool OptNoCurses;
char *Username;
char **EnvList = NULL;
char *HomeDir = "/";

#define CONFIG_INIT_TYPE(CS, NAME)                                             \
  extern const struct ConfigSetType Cst##NAME;                                 \
  cs_register_type(CS, &Cst##NAME)

void mutt_query_exit(void)
{
}

int mutt_system(const char *cmd)
{
  return 0;
}

void mutt_sleep(short s)
{
}

void mutt_need_hard_redraw(void)
{
}

int mw_get_field(const char *prompt, struct Buffer *buf, CompletionFlags complete,
                 enum HistoryClass hclass, const struct CompleteOps *comp_api, void *cdata)
{
  return 0;
}

void nm_edata_free(void **ptr)
{
}

void cert_array_clear(struct CertArray *carr)
{
}

int dlg_certificate(const char *title, struct CertArray *carr, bool allow_always, bool allow_skip)
{
  printf("\033[1;33mValidate certificate:\033[0m\n");
  const char **np = NULL;
  ARRAY_FOREACH(np, carr)
  {
    printf("\t%s\n", NONULL(*np));
  }

  return 2;
}

void mutt_addrlist_clear(struct AddressList *al)
{
}

bool mutt_addrlist_equal(const struct AddressList *ala, const struct AddressList *alb)
{
  return false;
}

int mutt_addrlist_to_local(struct AddressList *al)
{
  return 0;
}

int mutt_addrlist_to_intl(struct AddressList *al, char **err)
{
  return 0;
}

void test_connaccount(void)
{
  // int                mutt_account_getuser       (struct ConnAccount *cac);
  // int                mutt_account_getlogin      (struct ConnAccount *cac);
  // int                mutt_account_getpass       (struct ConnAccount *cac);
  // void               mutt_account_unsetpass     (struct ConnAccount *cac);
  // char *             mutt_account_getoauthbearer(struct ConnAccount *cac, bool xoauth2);

  struct ConnAccount cac = { 0 };
  cac.flags = MUTT_ACCT_USER;
  mutt_account_getuser(&cac);
}

void test_conn_raw(void)
{
  // int                raw_socket_open            (struct Connection *conn);
  // int                raw_socket_read            (struct Connection *conn, char *buf, size_t count);
  // int                raw_socket_write           (struct Connection *conn, const char *buf, size_t count);
  // int                raw_socket_poll            (struct Connection *conn, time_t wait_secs);
  // int                raw_socket_close           (struct Connection *conn);

  struct Connection conn;
  memset(&conn, 0, sizeof(conn));

  strcpy(conn.account.host, "flatcap.org");
  conn.account.port = 25;
  conn.account.type = MUTT_ACCT_TYPE_SMTP;
  conn.account.flags = MUTT_ACCT_PORT;

  raw_socket_open(&conn);
}

void test_getdomain(void)
{
  // int                getdnsdomainname           (struct Buffer *result);

  struct Buffer b = buf_make(256);
  getdnsdomainname(&b);
  buf_dealloc(&b);
}

void test_sasl(void)
{
  // int                mutt_sasl_client_new       (struct Connection *conn, sasl_conn_t **saslconn);
  // int                mutt_sasl_interact         (sasl_interact_t *interaction);
  // void               mutt_sasl_setup_conn       (struct Connection *conn, sasl_conn_t *saslconn);
  // void               mutt_sasl_cleanup          (void);
  mutt_sasl_cleanup();
}

void test_sasl_plain(void)
{
  // size_t             mutt_sasl_plain_msg        (char *buf, size_t buflen, const char *cmd, const char *authz, const char *user, const char *pass);

  char buf[256] = { 0 };
  mutt_sasl_plain_msg(buf, sizeof(buf), "cmd", "auth", NULL, NULL);
}

void test_socket(void)
{
  // int                mutt_socket_open           (struct Connection *conn);
  // int                mutt_socket_close          (struct Connection *conn);
  // int                mutt_socket_read           (struct Connection *conn, char *buf, size_t len);
  // int                mutt_socket_write          (struct Connection *conn, const char *buf, size_t len);
  // int                mutt_socket_write_d        (struct Connection *conn, const char *buf, int len, int dbg);
  // int                mutt_socket_poll           (struct Connection *conn, time_t wait_secs);
  // int                mutt_socket_readchar       (struct Connection *conn, char *c);
  // int                mutt_socket_readln_d       (char *buf, size_t buflen, struct Connection *conn, int dbg);
  // struct Connection *mutt_socket_new            (enum ConnectionType type);
  // void               mutt_socket_empty          (struct Connection *conn);
  // int                mutt_socket_buffer_readln_d(struct Buffer *buf, struct Connection *conn, int dbg);

  struct Connection *conn = mutt_socket_new(MUTT_CONNECTION_SIMPLE);
  FREE(&conn);
}

void test_ssl(void)
{
  // int                mutt_ssl_socket_setup      (struct Connection *conn);
  // int                mutt_ssl_starttls          (struct Connection *conn);

  struct Connection conn = { 0 };
  mutt_ssl_starttls(&conn);
}

void test_tunnel(void)
{
  // void               mutt_tunnel_socket_setup   (struct Connection *conn);

  struct Connection conn = { 0 };
  mutt_tunnel_socket_setup(&conn);
}

int main()
{
  static struct ConfigDef Vars[] = {
    // clang-format off
    { "certificate_file", DT_PATH|DT_PATH_FILE, IP "~/.mutt_certificates", 0, NULL, NULL },
    { "socket_timeout", DT_NUMBER, 30, 0, NULL, NULL },
    { "ssl_ca_certificates_file", DT_PATH|DT_PATH_FILE, 0, 0, NULL, NULL },
    { "ssl_ciphers", DT_STRING, 0, 0, NULL, NULL },
    { "ssl_client_cert", DT_PATH|DT_PATH_FILE, 0, 0, NULL, NULL },
    { "ssl_min_dh_prime_bits", DT_NUMBER|DT_NOT_NEGATIVE, 0, 0, NULL, NULL },
    { "ssl_use_sslv3", DT_BOOL, false, 0, NULL, NULL },
    { "ssl_use_tlsv1", DT_BOOL, false, 0, NULL, NULL },
    { "ssl_use_tlsv1_1", DT_BOOL, false, 0, NULL, NULL },
    { "ssl_use_tlsv1_2", DT_BOOL, true, 0, NULL, NULL },
    { "ssl_use_tlsv1_3", DT_BOOL, true, 0, NULL, NULL },
    { "use_ipv6", DT_BOOL, true, 0, NULL, NULL },
    { NULL },
    // clang-format on
  };

  struct ConfigSet *cs = cs_new(50);
  CONFIG_INIT_TYPE(cs, Bool);
  CONFIG_INIT_TYPE(cs, Number);
  CONFIG_INIT_TYPE(cs, Path);
  CONFIG_INIT_TYPE(cs, String);

  NeoMutt = neomutt_new(cs);

  cs_register_variables(cs, Vars, DT_NO_FLAGS);

  test_connaccount();
  test_conn_raw();
  test_getdomain();
  test_sasl();
  test_sasl_plain();
  test_socket();
  test_ssl();
  test_tunnel();

  // config_cache_cleanup();
  neomutt_free(&NeoMutt);
  cs_free(&cs);
  return 0;
}
