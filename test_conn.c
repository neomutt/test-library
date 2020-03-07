#include "config.h"
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mutt/lib.h"
#include "conn/lib.h"
#include "imap/account.h"

unsigned char Options[50];
int SigInt;
const char *C_Preconnect;
short C_ConnectTimeout;
bool OptNoCurses;
bool UseIpv6;
struct Menu;
struct MuttWindow;
bool C_StatusOnTop;
bool OptIgnoreMacroEvents;
char *Username;

/* account flags */
#define MUTT_ACCT_PORT (1 << 0)
#define MUTT_ACCT_USER (1 << 1)
#define MUTT_ACCT_LOGIN (1 << 2)
#define MUTT_ACCT_PASS (1 << 3)
#define MUTT_ACCT_SSL (1 << 4)

enum MuttWindowOrientation
{
  MUTT_WIN_ORIENT_VERTICAL = 1, ///< Window uses all available vertical space
  MUTT_WIN_ORIENT_HORIZONTAL,   ///< Window uses all available horizontal space
};

enum MuttWindowSize
{
  MUTT_WIN_SIZE_FIXED = 1, ///< Window has a fixed size
  MUTT_WIN_SIZE_MAXIMISE,  ///< Window wants as much space as possible
  MUTT_WIN_SIZE_MINIMISE,  ///< Window size depends on its children
};

enum MenuType
{
  MENU_ALIAS,            ///< Select an email address by its alias
  MENU_ATTACH,           ///< Select an attachment
  MENU_COMPOSE,          ///< Compose an email
  MENU_EDITOR,           ///< Text entry area
  MENU_FOLDER,           ///< General file/mailbox browser
  MENU_GENERIC,          ///< Generic selection list
  MENU_MAIN,             ///< Index panel (list of emails)
  MENU_PAGER,            ///< Pager pager (email viewer)
  MENU_POSTPONE,         ///< Select a postponed email
  MENU_QUERY,            ///< Select from results of external query
  MENU_PGP,              ///< PGP encryption menu
  MENU_SMIME,            ///< SMIME encryption menu
  MENU_KEY_SELECT_PGP,   ///< Select a PGP key
  MENU_KEY_SELECT_SMIME, ///< Select a SMIME key
  MENU_MIX,              ///< Create/edit a Mixmaster chain
  MENU_AUTOCRYPT_ACCT,
  MENU_MAX,
};

typedef uint16_t CompletionFlags;    ///< Flags for mutt_enter_string_full(), e.g. #MUTT_ALIAS
#define MUTT_COMP_NO_FLAGS       0   ///< No flags are set

int mutt_get_field_full(const char *field, char *buf, size_t buflen, int complete, bool multiple, char ***files, int *numfiles)
{
  return -1;
}

int mutt_get_field_unbuffered(const char *msg, char *buf, size_t buflen, CompletionFlags flags)
{
  return -1;
}

void dialog_pop(void)
{
}

void dialog_push(struct MuttWindow *dlg)
{
}

void mutt_make_help(char *buf, size_t buflen, const char *txt, enum MenuType menu, int op)
{
}

void mutt_menu_free(struct Menu **ptr)
{
}

int mutt_menu_loop(struct Menu *menu)
{
  return -1;
}

struct Menu *mutt_menu_new(enum MenuType type)
{
  return NULL;
}

void mutt_menu_pop_current(struct Menu *menu)
{
}

void mutt_menu_push_current(struct Menu *menu)
{
}

void mutt_window_free(struct MuttWindow **ptr)
{
}

struct MuttWindow *mutt_window_new(enum MuttWindowOrientation orient, enum MuttWindowSize size, int rows, int cols)
{
  return NULL;
}

void mutt_menu_add_dialog_row(struct Menu *menu, const char *row)
{
}

void mutt_window_add_child(struct MuttWindow *parent, struct MuttWindow *child)
{
}

void mutt_query_exit(void)
{
}

int mutt_system(const char *cmd)
{
  return 0;
}

void mutt_allow_interrupt(int disposition)
{
}

void mutt_sleep(short s)
{
  printf("mutt_sleep\n");
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
  // int                getdnsdomainname           (char *buf, size_t buflen);
  char buf[256] = { 0 };
  getdnsdomainname(buf, sizeof(buf));
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
  void test_connaccount(void);
  void test_conn_raw(void);
  void test_getdomain(void);
  void test_sasl(void);
  void test_sasl_plain(void);
  void test_socket(void);
  void test_ssl(void);
  void test_tunnel(void);
  return 0;
}
