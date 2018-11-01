#include "config.h"
#include <signal.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "mutt/mutt.h"
#include "email/email.h"
#include "context.h"
#include "mailbox.h"
#include "mbox/mbox.h"
#include "mx.h"

struct Progress;

short Sort;
short WriteInc;
bool CheckMboxSize;
bool MailCheckRecent;
char *HomeDir;
char *ShortHostname;
char *Username;
short ReadInc;
volatile sig_atomic_t SigInt;

void mutt_clear_threads(struct Context *ctx)
{
  mutt_message("mutt_clear_threads NOTIMPL");
}

int mutt_copy_message_ctx(FILE *fpout, struct Context *src, struct Email *hdr, int flags, int chflags)
{
  mutt_message("mutt_copy_message_ctx NOTIMPL");
  return 0;
}

struct Mailbox *mutt_find_mailbox(const char *path)
{
  mutt_message("mutt_find_mailbox NOTIMPL");
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

void mutt_update_mailbox(struct Mailbox *m)
{
  mutt_message("mutt_update_mailbox NOTIMPL");
}

void mx_alloc_memory(struct Mailbox *m)
{
  size_t s = MAX(sizeof(struct Email *), sizeof(int));

  if ((m->hdrmax + 25) * s < m->hdrmax * s)
  {
    mutt_error(_("Out of memory"));
    mutt_exit(1);
  }

  if (m->hdrs)
  {
    mutt_mem_realloc(&m->hdrs, sizeof(struct Email *) * (m->hdrmax += 25));
    mutt_mem_realloc(&m->v2r, sizeof(int) * m->hdrmax);
  }
  else
  {
    m->hdrs = mutt_mem_calloc((m->hdrmax += 25), sizeof(struct Email *));
    m->v2r = mutt_mem_calloc(m->hdrmax, sizeof(int));
  }
  for (int i = m->msg_count; i < m->hdrmax; i++)
  {
    m->hdrs[i] = NULL;
    m->v2r[i] = -1;
  }
}

void mx_fastclose_mailbox(struct Context *ctx)
{
  mutt_message("mx_fastclose_mailbox NOTIMPL");
}

void mx_update_context(struct Context *ctx, int new_messages)
{
  mutt_message("mx_update_context NOTIMPL");
}

enum MuttStatType
{
  MUTT_STAT_ATIME,
  MUTT_STAT_MTIME,
  MUTT_STAT_CTIME
};

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

int mx_path_probe(const char *path, struct stat *st)
{
  mutt_message("mx_path_probe NOTIMPL");
  return -1;
}

int main(int argc, char *argv[])
{
  char *file = "test.mbox";
  struct Context ctx = { 0 };
  struct Mailbox m = { 0 };
  ctx.mailbox = &m;
  m.magic = MUTT_MBOX;
  mutt_str_strfcpy(m.path, file, sizeof(m.path));

  int rc = mx_mbox_ops.mbox_open(&ctx);
  printf("%d\n", rc);
  if (rc != 0)
    return 1;

  rc = mx_mbox_ops.mbox_close(&ctx);
  printf("%d\n", rc);
  if (rc != 0)
    return 1;

  return 0;
}
