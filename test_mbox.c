#include "config.h"
#include <signal.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "mutt/lib.h"
#include "email/email.h"
#include "core/lib.h"
#include "mbox/lib.h"
#include "mx.h"

struct Progress;

bool C_Autocrypt;
short C_Sort;
short C_WriteInc;
bool C_CheckMboxSize;
bool C_MailCheckRecent;
char *HomeDir;
char *ShortHostname;
char *Username;
short C_ReadInc;
volatile sig_atomic_t SigInt;
struct Context *Context = NULL;

typedef uint16_t CopyMessageFlags;
typedef uint32_t CopyHeaderFlags;
typedef uint16_t CompletionFlags;

struct Mailbox *ctx_mailbox(struct Context *ctx)
{
  return ctx ? ctx->mailbox : NULL;
}

void nm_edata_free(void **ptr)
{
}

void buf_mktemp_full(struct Buffer *buf, const char *prefix,
                             const char *suffix, const char *src, int line)
{
}

void buf_pretty_mailbox(struct Buffer *buf)
{
}

int mutt_autocrypt_process_autocrypt_header(struct Email *e, struct Envelope *env)
{
  return -1;
}

int buf_get_field(const char *field, struct Buffer *buf, CompletionFlags complete,
                          bool multiple, char ***files, int *numfiles)
{
  return -1;
}

int mutt_copy_message(FILE *fp_out, struct Mailbox *m, struct Email *e, CopyMessageFlags cmflags, CopyHeaderFlags chflags)
{
  return -1;
}

struct Context *mx_mbox_open(struct Mailbox *m, OpenMailboxFlags flags)
{
  return NULL;
}

int mx_mbox_close(struct Context **pctx)
{
  return -1;
}

int url_parse_mailto(struct Envelope *e, char **body, const char *src)
{
  return -1;
}

void mutt_clear_threads(struct Context *ctx)
{
  mutt_message("mutt_clear_threads NOTIMPL");
}

int mutt_copy_message_ctx(FILE *fpout, struct Context *src, struct Email *hdr, int flags, int chflags)
{
  mutt_message("mutt_copy_message_ctx NOTIMPL");
  return 0;
}

struct Mailbox *mutt_mailbox_find(const char *path)
{
  mutt_message("mutt_mailbox_find NOTIMPL");
  return NULL;
}

void mutt_make_label_hash(struct Context *ctx)
{
  mutt_message("mutt_make_label_hash NOTIMPL");
}

void mutt_mktemp_full(char *s, size_t slen, const char *prefix, const char *suffix, const char *src, int line)
{
  mutt_message("mutt_mktemp_full NOTIMPL");
}

void mutt_pretty_mailbox(char *s, size_t buflen)
{
  mutt_message("mutt_pretty_mailbox NOTIMPL");
}

void mutt_progress_init(struct Progress *progress, const char *msg, unsigned short flags, unsigned short inc, size_t size)
{
  mutt_message("mutt_progress_init NOTIMPL");
}

void mutt_progress_update(struct Progress *progress, long pos, int percent)
{
  mutt_message("mutt_progress_update NOTIMPL");
}

void mutt_set_flag_update(struct Context *ctx, struct Email *h, int flag, bool bf, bool upd_ctx)
{
  mutt_message("mutt_set_flag_update NOTIMPL");
}

void mutt_sort_headers(struct Context *ctx, int init)
{
  mutt_message("mutt_sort_headers NOTIMPL");
}

void mutt_mailbox_update(struct Mailbox *m)
{
  mutt_message("mutt_mailbox_update NOTIMPL");
}

void mx_alloc_memory(struct Mailbox *m)
{
  size_t s = MAX(sizeof(struct Email *), sizeof(int));

  if ((m->email_max + 25) * s < m->email_max * s)
  {
    mutt_error(_("Out of memory"));
    mutt_exit(1);
  }

  if (m->emails)
  {
    mutt_mem_realloc(&m->emails, sizeof(struct Email *) * (m->email_max += 25));
    mutt_mem_realloc(&m->v2r, sizeof(int) * m->email_max);
  }
  else
  {
    m->emails = mutt_mem_calloc((m->email_max += 25), sizeof(struct Email *));
    m->v2r = mutt_mem_calloc(m->email_max, sizeof(int));
  }
  for (int i = m->msg_count; i < m->email_max; i++)
  {
    m->emails[i] = NULL;
    m->v2r[i] = -1;
  }
}

void mx_fastclose_mailbox(struct Mailbox *m)
{
  mutt_message("mx_fastclose_mailbox NOTIMPL");
}

void mx_update_context(struct Context *ctx, int new_messages)
{
  mutt_message("mx_update_context NOTIMPL");
}

void mutt_get_stat_timespec(struct timespec *dest, struct stat *sb, enum MuttStatType type)
{
  dest->tv_sec = 0;
  dest->tv_nsec = 0;

  switch (type)
  {
    case MUTT_STAT_ATIME:
      dest->tv_sec = sb->st_atime;
#ifdef HAVE_STRUCT_STAT_ST_ATIM_TV_NSEC
      dest->tv_nsec = sb->st_atim.tv_nsec;
#endif
      break;
    case MUTT_STAT_MTIME:
      dest->tv_sec = sb->st_mtime;
#ifdef HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC
      dest->tv_nsec = sb->st_mtim.tv_nsec;
#endif
      break;
    case MUTT_STAT_CTIME:
      dest->tv_sec = sb->st_ctime;
#ifdef HAVE_STRUCT_STAT_ST_CTIM_TV_NSEC
      dest->tv_nsec = sb->st_ctim.tv_nsec;
#endif
      break;
  }
}

int mutt_timespec_compare(struct timespec *a, struct timespec *b)
{
  if (a->tv_sec < b->tv_sec)
    return -1;
  if (a->tv_sec > b->tv_sec)
    return 1;

  if (a->tv_nsec < b->tv_nsec)
    return -1;
  if (a->tv_nsec > b->tv_nsec)
    return 1;
  return 0;
}

int mutt_stat_timespec_compare(struct stat *sba, enum MuttStatType type, struct timespec *b)
{
  struct timespec a = { 0 };

  mutt_get_stat_timespec(&a, sba, type);
  return mutt_timespec_compare(&a, b);
}

enum MailboxType mx_path_probe(const char *path)
{
  mutt_message("mx_path_probe NOTIMPL");
  return -1;
}

int main(int argc, char *argv[])
{
  char *file = "test.mbox";
  struct Context ctx = { 0 };
  struct Account a = { 0 };
  struct Mailbox m = { 0 };
  ctx.mailbox = &m;
  m.type = MUTT_MBOX;
  m.account = &a;
  a.type = MUTT_MBOX;
  m.pathbuf = buf_make(128);
  buf_strcpy(&m.pathbuf, file);

  int rc = MxMboxOps.mbox_open(ctx.mailbox);
  printf("%d\n", rc);
  if (rc != 0)
    return 1;

  rc = MxMboxOps.mbox_close(ctx.mailbox);
  printf("%d\n", rc);
  if (rc != 0)
    return 1;

  buf_dealloc(&m.pathbuf);
  return 0;
}
