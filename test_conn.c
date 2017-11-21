#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mutt/mutt.h"
#include "conn/conn.h"

unsigned char Options[50];
int SigInt;
char *Preconnect;
short ConnectTimeout;
bool OPT_NO_CURSES;
bool UseIpv6;

/**
 * enum AccountType - account types
 */
enum AccountType
{
  MUTT_ACCT_TYPE_NONE = 0,
  MUTT_ACCT_TYPE_IMAP,
  MUTT_ACCT_TYPE_POP,
  MUTT_ACCT_TYPE_SMTP,
  MUTT_ACCT_TYPE_NNTP
};

/* account flags */
#define MUTT_ACCT_PORT  (1 << 0)
#define MUTT_ACCT_USER  (1 << 1)
#define MUTT_ACCT_LOGIN (1 << 2)
#define MUTT_ACCT_PASS  (1 << 3)
#define MUTT_ACCT_SSL   (1 << 4)

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

int main()
{
  struct Connection conn;
  memset(&conn, 0, sizeof(conn));

  strcpy(conn.account.host, "flatcap.org");
  conn.account.port = 25;
  conn.account.type = MUTT_ACCT_TYPE_SMTP;
  conn.account.flags = MUTT_ACCT_PORT;

  // mutt_socket_open(&conn);
  raw_socket_open(&conn);
  return 0;
}
