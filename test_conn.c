#include "config.h"
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "conn/private.h"
#include "mutt/lib.h"
#include "conn/lib.h"
#include "imap/account.h"

typedef uint16_t CompletionFlags;
int SigInt;
bool OptNoCurses;
char *Username;

int dlg_verify_certificate(const char *title, struct ListHead *list, bool allow_always, bool allow_skip)
{
  printf("\033[1;33mValidate certificate:\033[0m\n");
  struct ListNode *np = NULL;
  STAILQ_FOREACH(np, list, entries)
  {
    printf("\t%s\n", NONULL(np->data));
  }

  return 2;
}

int mutt_system(const char *cmd)
{
  printf("mutt_system\n");
  return 0;
}

int mutt_get_field(const char *field, char *buf, size_t buflen, CompletionFlags complete, bool multiple, char ***files, int *numfiles)
{
  printf("mutt_get_field\n");
  return 0;
}

void mutt_query_exit(void)
{
  printf("mutt_query_exit\n");
}

int mutt_get_field_unbuffered(const char *msg, char *buf, size_t buflen, CompletionFlags flags)
{
  printf("mutt_get_field_unbuffered\n");
  return 0;
}

void mutt_sleep(short s)
{
}

void test_connaccount(void)
{
  // int                mutt_account_getuser       (struct ConnAccount *cac);
  // int                mutt_account_getlogin      (struct ConnAccount *cac);
  // int                mutt_account_getpass       (struct ConnAccount *cac);
  // void               mutt_account_unsetpass     (struct ConnAccount *cac);
  // char *             mutt_account_getoauthbearer(struct ConnAccount *cac);
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

  // mutt_socket_open(&conn);
  raw_socket_open(&conn);
}

void test_getdomain(void)
{
  // int                getdnsdomainname           (struct Buffer *domain);

  struct Buffer b = buf_make(256);
  getdnsdomainname(&b);
  buf_dealloc(&b);
}

void test_sasl(void)
{
  // int                mutt_sasl_client_new       (struct Connection *conn, sasl_conn_t * *saslconn);
  // void               mutt_sasl_done             (void);
  // int                mutt_sasl_interact         (sasl_interact_t *interaction);
  // void               mutt_sasl_setup_conn       (struct Connection *conn, sasl_conn_t *saslconn);
  mutt_sasl_done();
}

void test_sasl_plain(void)
{
  // size_t             mutt_sasl_plain_msg        (char *buf, size_t buflen, const char *cmd, const char *authz, const char *user, const char *pass);
  char buf[256] = { 0 };
  mutt_sasl_plain_msg(buf, sizeof(buf), "cmd", "auth", NULL, NULL);
}

void test_socket(void)
{
  // int                mutt_socket_close          (struct Connection *conn);
  // struct Connection *mutt_socket_new            (enum ConnectionType type);
  // int                mutt_socket_open           (struct Connection *conn);
  // int                mutt_socket_poll           (struct Connection *conn, time_t wait_secs);
  // int                mutt_socket_read           (struct Connection *conn, char *buf, size_t len);
  // int                mutt_socket_readchar       (struct Connection *conn, char *c);
  // int                mutt_socket_readln_d       (char *buf, size_t buflen, struct Connection *conn, int dbg);
  // int                mutt_socket_write          (struct Connection *conn, const char *buf, size_t len);
  // int                mutt_socket_write_d        (struct Connection *conn, const char *buf, int len, int dbg);
  mutt_socket_new(MUTT_CONNECTION_SIMPLE);
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
  test_connaccount();
  test_conn_raw();
  test_getdomain();
  test_sasl();
  test_sasl_plain();
  test_socket();
  test_ssl();
  test_tunnel();
  return 0;
}
