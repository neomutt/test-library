#include "config.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "mutt/mutt.h"
#include "config/lib.h"
#include "email/lib.h"
#include "mutt.h"

struct PatternHead *mutt_pattern_comp(char *s, int flags, struct Buffer *err);
void mutt_pattern_free(struct PatternHead **pat);

struct Body;
struct Group;
struct Message;
struct Pattern;
struct Progress;
struct State;
struct TagHead;

struct Context *Context = NULL;
struct ConfigSet *Config = NULL;
bool g_addr_is_user = false;
int g_body_parts = 1;
bool g_is_mail_list = false;
bool g_is_subscribed_list = false;
const char *g_myvar = "hello";
int SigInt = 0;
bool OptSearchInvalid = false;
const char *C_SimpleSearch = "~f %s | ~s %s";
bool OptSearchReverse = false;
bool C_WrapSearch = false;
int C_ReadInc = 0;
const char *C_ExternalSearchCommand = NULL;

char *driver_tags_get(struct TagHead *head)
{
  return NULL;
}

bool mutt_group_match(struct Group *g, const char *s)
{
  return false;
}

struct Group *mutt_pattern_group(const char *pat)
{
  return NULL;
}

char *mutt_rfc822_read_line(FILE *fp, char *line, size_t *linelen)
{
  return NULL;
}

bool crypt_valid_passphrase(SecurityFlags flags)
{
  return 0;
}

int imap_search(struct Mailbox *m, const struct Pattern *pat)
{
  return -1;
}

bool mutt_addr_is_user(struct Address *addr)
{
  return g_addr_is_user;
}

struct Address *mutt_alias_reverse_lookup(struct Address *a)
{
  return NULL;
}

int mutt_body_handler(struct Body *b, struct State *s)
{
  return -1;
}

void mutt_clear_error(void)
{
}

int mutt_copy_header(FILE *in, struct Email *e, FILE *out, int flags, const char *prefix)
{
  return -1;
}

int mutt_count_body_parts(struct Mailbox *m, struct Email *e)
{
  return g_body_parts;
}

pid_t mutt_create_filter(const char *s, FILE **fp_in, FILE **fp_out, FILE **fp_err)
{
  return -1;
}

int mutt_get_field_full(const char *field, char *buf, size_t buflen,
                        int complete, bool multiple, char ***files, int *numfiles)
{
  return -1;
}

bool mutt_is_mail_list(struct Address *addr)
{
  return g_is_mail_list;
}

bool mutt_is_subscribed_list(struct Address *addr)
{
  return g_is_subscribed_list;
}

void mutt_parse_mime_message(struct Mailbox *m, struct Email *e)
{
}

void mutt_progress_init(struct Progress *progress, const char *msg,
                        unsigned short flags, unsigned short inc, size_t size)
{
}
void mutt_progress_update(struct Progress *progress, long pos, int percent)
{
}

void mutt_set_flag_update(struct Mailbox *m, struct Email *e, int flag, bool bf, bool upd_mbox)
{
}

int mutt_wait_filter(pid_t pid)
{
  return -1;
}

int mx_msg_close(struct Mailbox *m, struct Message **msg)
{
  return 0;
}

struct Message *mx_msg_open(struct Mailbox *m, int msgno)
{
  return NULL;
}

int mx_msg_padding_size(struct Mailbox *m)
{
  return 0;
}

const char *myvar_get(const char *var)
{
  return g_myvar;
}

int mutt_extract_token(struct Buffer *dest, struct Buffer *tok, TokenFlags flags)
{
  if (!dest || !tok)
    return -1;

  char ch;
  char qc = 0; /* quote char */
  char *pc = NULL;

  /* reset the destination pointer to the beginning of the buffer */
  dest->dptr = dest->data;

  SKIPWS(tok->dptr);
  while ((ch = *tok->dptr))
  {
    if (!qc)
    {
      if ((IS_SPACE(ch) && !(flags & MUTT_TOKEN_SPACE)) ||
          ((ch == '#') && !(flags & MUTT_TOKEN_COMMENT)) ||
          ((ch == '=') && (flags & MUTT_TOKEN_EQUAL)) ||
          ((ch == '?') && (flags & MUTT_TOKEN_QUESTION)) ||
          ((ch == ';') && !(flags & MUTT_TOKEN_SEMICOLON)) ||
          ((flags & MUTT_TOKEN_PATTERN) && strchr("~%=!|", ch)))
      {
        break;
      }
    }

    tok->dptr++;

    if (ch == qc)
      qc = 0; /* end of quote */
    else if (!qc && ((ch == '\'') || (ch == '"')) && !(flags & MUTT_TOKEN_QUOTE))
      qc = ch;
    else if ((ch == '\\') && (qc != '\''))
    {
      if (!*tok->dptr)
        return -1; /* premature end of token */
      switch (ch = *tok->dptr++)
      {
        case 'c':
        case 'C':
          if (!*tok->dptr)
            return -1; /* premature end of token */
          mutt_buffer_addch(dest, (toupper((unsigned char) *tok->dptr) - '@') & 0x7f);
          tok->dptr++;
          break;
        case 'e':
          mutt_buffer_addch(dest, '\033');
          break;
        case 'f':
          mutt_buffer_addch(dest, '\f');
          break;
        case 'n':
          mutt_buffer_addch(dest, '\n');
          break;
        case 'r':
          mutt_buffer_addch(dest, '\r');
          break;
        case 't':
          mutt_buffer_addch(dest, '\t');
          break;
        default:
          if (isdigit((unsigned char) ch) && isdigit((unsigned char) *tok->dptr) &&
              isdigit((unsigned char) *(tok->dptr + 1)))
          {
            mutt_buffer_addch(dest, (ch << 6) + (*tok->dptr << 3) + *(tok->dptr + 1) - 3504);
            tok->dptr += 2;
          }
          else
            mutt_buffer_addch(dest, ch);
      }
    }
    else if ((ch == '^') && (flags & MUTT_TOKEN_CONDENSE))
    {
      if (!*tok->dptr)
        return -1; /* premature end of token */
      ch = *tok->dptr++;
      if (ch == '^')
        mutt_buffer_addch(dest, ch);
      else if (ch == '[')
        mutt_buffer_addch(dest, '\033');
      else if (isalpha((unsigned char) ch))
        mutt_buffer_addch(dest, toupper((unsigned char) ch) - '@');
      else
      {
        mutt_buffer_addch(dest, '^');
        mutt_buffer_addch(dest, ch);
      }
    }
    else if ((ch == '`') && (!qc || (qc == '"')))
    {
      FILE *fp = NULL;
      pid_t pid;
      char *ptr = NULL;
      size_t expnlen;
      struct Buffer expn;
      int line = 0;

      pc = tok->dptr;
      do
      {
        pc = strpbrk(pc, "\\`");
        if (pc)
        {
          /* skip any quoted chars */
          if (*pc == '\\')
            pc += 2;
        }
      } while (pc && *pc != '`');
      if (!pc)
      {
        mutt_debug(LL_DEBUG1, "mismatched backticks\n");
        return -1;
      }
      struct Buffer cmd;
      mutt_buffer_init(&cmd);
      *pc = '\0';
      if (flags & MUTT_TOKEN_BACKTICK_VARS)
      {
        /* recursively extract tokens to interpolate variables */
        mutt_extract_token(&cmd, tok,
                           MUTT_TOKEN_QUOTE | MUTT_TOKEN_SPACE | MUTT_TOKEN_COMMENT |
                               MUTT_TOKEN_SEMICOLON | MUTT_TOKEN_NOSHELL);
      }
      else
      {
        cmd.data = mutt_str_strdup(tok->dptr);
      }
      *pc = '`';
      pid = mutt_create_filter(cmd.data, NULL, &fp, NULL);
      if (pid < 0)
      {
        mutt_debug(LL_DEBUG1, "unable to fork command: %s\n", cmd);
        FREE(&cmd.data);
        return -1;
      }
      FREE(&cmd.data);

      tok->dptr = pc + 1;

      /* read line */
      mutt_buffer_init(&expn);
      expn.data = mutt_file_read_line(NULL, &expn.dsize, fp, &line, 0);
      mutt_file_fclose(&fp);
      mutt_wait_filter(pid);

      /* if we got output, make a new string consisting of the shell output
       * plus whatever else was left on the original line */
      /* BUT: If this is inside a quoted string, directly add output to
       * the token */
      if (expn.data && qc)
      {
        mutt_buffer_addstr(dest, expn.data);
        FREE(&expn.data);
      }
      else if (expn.data)
      {
        expnlen = mutt_str_strlen(expn.data);
        tok->dsize = expnlen + mutt_str_strlen(tok->dptr) + 1;
        ptr = mutt_mem_malloc(tok->dsize);
        memcpy(ptr, expn.data, expnlen);
        strcpy(ptr + expnlen, tok->dptr);
        if (tok->destroy)
          FREE(&tok->data);
        tok->data = ptr;
        tok->dptr = ptr;
        tok->destroy = 1; /* mark that the caller should destroy this data */
        ptr = NULL;
        FREE(&expn.data);
      }
    }
    else if ((ch == '$') && (!qc || (qc == '"')) &&
             ((*tok->dptr == '{') || isalpha((unsigned char) *tok->dptr)))
    {
      const char *env = NULL;
      char *var = NULL;

      if (*tok->dptr == '{')
      {
        pc = strchr(tok->dptr, '}');
        if (pc)
        {
          var = mutt_str_substr_dup(tok->dptr + 1, pc);
          tok->dptr = pc + 1;

          if ((flags & MUTT_TOKEN_NOSHELL))
          {
            mutt_buffer_addch(dest, ch);
            mutt_buffer_addch(dest, '{');
            mutt_buffer_addstr(dest, var);
            mutt_buffer_addch(dest, '}');
            FREE(&var);
          }
        }
      }
      else
      {
        for (pc = tok->dptr; isalnum((unsigned char) *pc) || *pc == '_'; pc++)
          ;
        var = mutt_str_substr_dup(tok->dptr, pc);
        tok->dptr = pc;
      }
      if (var)
      {
        struct Buffer result;
        mutt_buffer_init(&result);
        int rc = cs_str_string_get(Config, var, &result);

        if (CSR_RESULT(rc) == CSR_SUCCESS)
        {
          mutt_buffer_addstr(dest, result.data);
          FREE(&result.data);
        }
        else if ((env = myvar_get(var)))
        {
          mutt_buffer_addstr(dest, env);
        }
        else if (!(flags & MUTT_TOKEN_NOSHELL) && (env = mutt_str_getenv(var)))
        {
          mutt_buffer_addstr(dest, env);
        }
        else
        {
          mutt_buffer_addch(dest, ch);
          mutt_buffer_addstr(dest, var);
        }
        FREE(&var);
      }
    }
    else
      mutt_buffer_addch(dest, ch);
  }
  mutt_buffer_addch(dest, 0); /* terminate the string */
  SKIPWS(tok->dptr);
  return 0;
}

bool test_pattern(char *pat)
{
  struct Buffer *err = mutt_buffer_alloc(1024);
  bool result = true;

  struct PatternHead *ph = mutt_pattern_comp(pat, 0, err);
  if (!ph)
  {
    printf("Error: %s\n", err->data);
    result = false;
  }

  mutt_pattern_free(&ph);
  mutt_buffer_free(&err);
  return result;
}

int main(int argc, char *argv[])
{
  for (argc--; argc > 0; argc--, argv++)
  {
    printf("Testing: %s\n", argv[1]);
    if (!test_pattern(argv[1]))
      return 1;

    if (argc > 1)
      printf("------------------------------------------------------------\n");
  }

  return 0;
}