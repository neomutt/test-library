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
#include <sasl/sasl.h>
#include <sasl/saslutil.h>

typedef uint16_t CompletionFlags;
int SigInt;
bool OptNoCurses;
char *Username;

#define MUTT_SOCK_LOG_CMD  2
#define MUTT_SOCK_LOG_FULL 5

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

int mutt_get_field_full(const char *field, char *buf, size_t buflen, CompletionFlags complete, bool multiple, char ***files, int *numfiles)
{
  printf("mutt_get_field_full\n");
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

int auth_sasl(struct Connection *conn)
{
  sasl_conn_t *saslconn = NULL;
  sasl_interact_t *interaction = NULL;
  int rc;
  char inbuf[1024];
  const char *mech = NULL;
  const char *pc = NULL;
  unsigned int len = 0, olen = 0;

  if (mutt_sasl_client_new(conn, &saslconn) < 0)
    return -1;

  while (true)
  {
    rc = sasl_client_start(saslconn, "PLAIN LOGIN", &interaction, &pc, &olen, &mech);
    if (rc != SASL_INTERACT)
      break;
    mutt_sasl_interact(interaction);
  }

  if ((rc != SASL_OK) && (rc != SASL_CONTINUE))
  {
    /* SASL doesn't support suggested mechanisms, so fall back */
    sasl_dispose(&saslconn);
    return -1;
  }

  /* About client_start:  If sasl_client_start() returns data via pc/olen,
   * the client is expected to send this first (after the AUTH string is sent).
   * sasl_client_start() may in fact return SASL_OK in this case.  */
  unsigned int client_start = olen;

  mutt_message(_("Authenticating (SASL)..."));

  size_t bufsize = MAX((olen * 2), 1024);
  char *buf = mutt_mem_malloc(bufsize);

  snprintf(buf, bufsize, "AUTH %s", mech);
  olen = strlen(buf);

  /* looping protocol */
  while (true)
  {
    mutt_str_copy(buf + olen, "\r\n", bufsize - olen);
    mutt_socket_write_d(conn, buf, mutt_str_len(buf), MUTT_SOCK_LOG_CMD);
    if (mutt_socket_readln_d(inbuf, sizeof(inbuf), conn, MUTT_SOCK_LOG_FULL) < 0)
    {
      sasl_dispose(&saslconn);
      FREE(&buf);
      return -1;
    }

    /* Note we don't exit if rc==SASL_OK when client_start is true.
     * This is because the first loop has only sent the AUTH string, we
     * need to loop at least once more to send the pc/olen returned
     * by sasl_client_start().  */
    if (!client_start && (rc != SASL_CONTINUE))
      break;

    if (mutt_str_startswith(inbuf, "+ ") &&
        (sasl_decode64(inbuf + 2, strlen(inbuf + 2), buf, bufsize - 1, &len) != SASL_OK))
    {
      mutt_debug(LL_DEBUG1, "error base64-decoding server response\n");
      goto bail;
    }

    if (!client_start)
    {
      while (true)
      {
        rc = sasl_client_step(saslconn, buf, len, &interaction, &pc, &olen);
        if (rc != SASL_INTERACT)
          break;
        mutt_sasl_interact(interaction);
      }
    }
    else
    {
      olen = client_start;
      client_start = 0;
    }

    /* Even if sasl_client_step() returns SASL_OK, we should send at
     * least one more line to the server.  */
    if ((rc != SASL_CONTINUE) && (rc != SASL_OK))
      break;

    /* send out response, or line break if none needed */
    if (pc)
    {
      if ((olen * 2) > bufsize)
      {
        bufsize = olen * 2;
        mutt_mem_realloc(&buf, bufsize);
      }
      if (sasl_encode64(pc, olen, buf, bufsize, &olen) != SASL_OK)
      {
        mutt_debug(LL_DEBUG1, "error base64-encoding client response\n");
        goto bail;
      }
    }
  }

  if (rc != SASL_OK)
    goto bail;

  if (mutt_str_startswith(inbuf, "+OK"))
  {
    mutt_sasl_setup_conn(conn, saslconn);
    FREE(&buf);
    return 0;
  }

bail:
  sasl_dispose(&saslconn);

  /* terminate SASL session if the last response is not +OK nor -ERR */
  // if (mutt_str_startswith(inbuf, "+ "))
  // {
  //   snprintf(buf, bufsize, "*\r\n");
  //   if (pop_query(adata, buf, bufsize) == -1)
  //   {
  //     FREE(&buf);
  //     return -1;
  //   }
  // }

  FREE(&buf);
  mutt_error(_("SASL authentication failed"));

  return -1;
}

const char *get_field(enum ConnAccountField field, void *gf_data)
{
  printf("get_field: %d\n", field);
  return NULL;
}

void send_text(const char *text)
{
  printf("\033[1;32msend:\033[0m\t%s\n", text);
}

void recv_text(const char *title, char *text, bool send)
{
  char *save = NULL;
  int colour = 31 + send;
  printf("\033[1;%dm%s\033[0m\n", colour, title);

  if (send)
  {
    printf("%s\t%s", title, text);
    return;
  }

  char *p = strtok_r(text, "\r\n", &save);
  printf("\t%s\n", p);

  while (p && (p = strtok_r(NULL, "\r\n", &save)))
  {
    printf("\t%s\n", p);
  }
}

void pop_command(struct Connection *conn, const char *cmd)
{
  char buf[256];
  int rc;

  snprintf(buf, sizeof(buf), "%s\n", cmd);
  send_text(buf);
  rc = mutt_socket_write(conn, buf, strlen(buf));
  printf("write = %d\n", rc);

  memset(buf, 0, sizeof(buf));
  rc = mutt_socket_read(conn, buf, sizeof(buf));
  printf("read = %d\n", rc);
  if (rc > 0)
    recv_text("response:", buf, false);
}

bool get_env_var(const char *name, char *buf, size_t buflen)
{
  const char *value = mutt_str_getenv(name);
  if (!value)
  {
    printf("env var '%s' not set\n", name);
    return false;
  }
  mutt_str_copy(buf, value, buflen);
  return true;
}

int main()
{
  C_CertificateFile = "";
  C_SslUseTlsv12 = true;
  C_SslUseTlsv13 = true;

  struct Connection *conn = mutt_socket_new(MUTT_CONNECTION_SSL);
  struct ConnAccount *cac = &conn->account;

  if (!get_env_var("NEOMUTT_SASL_HOST", cac->host, sizeof(cac->host)))
    return 1;
  if (!get_env_var("NEOMUTT_SASL_USER", cac->user, sizeof(cac->user)))
    return 1;
  mutt_str_copy(cac->login, cac->user, sizeof(cac->login));
  if (!get_env_var("NEOMUTT_SASL_PASS", cac->pass, sizeof(cac->pass)))
    return 1;

  cac->port = 995;
  cac->type = MUTT_ACCT_TYPE_POP;
  cac->service = "pop";
  cac->flags = MUTT_ACCT_PORT | MUTT_ACCT_USER | MUTT_ACCT_LOGIN | MUTT_ACCT_PASS | MUTT_ACCT_SSL;
  cac->get_field = get_field;

  int rc = mutt_socket_open(conn);
  if (rc != 0)
  {
    FREE(&conn);
    return 1;
  }

  printf("fd = %d\n", conn->fd);

  char buf[256] = { 0 };

  rc = mutt_socket_read(conn, buf, sizeof(buf));
  printf("read = %d\n", rc);
  if (rc > 0)
    recv_text("initial read", buf, false);

  pop_command(conn, "CAPA");

  rc = auth_sasl(conn);
  printf("auth = %d\n", rc);

  pop_command(conn, "CAPA");
  pop_command(conn, "STAT");
  pop_command(conn, "QUIT");

  mutt_socket_close(conn);
  FREE(&conn);
  return 0;
}
