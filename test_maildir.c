#include "config.h"
#include <signal.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "mutt/mutt.h"
#include "email/email.h"
#include "context.h"
#include "mailbox.h"
#include "maildir/maildir.h"
#include "mx.h"

struct Progress;

bool FlagSafe;
char *HeaderCache;
char *HomeDir;
bool MailCheckRecent;
bool MaildirTrash;
bool MarkOld;
short ReadInc;
char *ShortHostname;
volatile sig_atomic_t SigInt;
short Sort;
short WriteInc;
int MonitorContextChanged = 0;

void mutt_clear_threads(struct Context *ctx)
{
  mutt_message("mutt_clear_threads NOTIMPL");
}

int mutt_copy_message_ctx(FILE *fpout, struct Context *src, struct Email *hdr, int flags, int chflags)
{
  mutt_message("mutt_copy_message_ctx NOTIMPL");
  return -1;
}

void mutt_hcache_close(header_cache_t *h)
{
  mutt_message("mutt_hcache_close NOTIMPL");
}

int mutt_hcache_delete(header_cache_t *h, const char *key, size_t keylen)
{
  mutt_message("mutt_hcache_delete NOTIMPL");
  return -1;
}

void *mutt_hcache_fetch(header_cache_t *h, const char *key, size_t keylen)
{
  mutt_message("mutt_hcache_fetch NOTIMPL");
  return NULL;
}

void mutt_hcache_free(header_cache_t *h, void **data)
{
  mutt_message("mutt_hcache_free NOTIMPL");
}

header_cache_t *mutt_hcache_open(const char *path, const char *folder, hcache_namer_t namer)
{
  mutt_message("mutt_hcache_open NOTIMPL");
  return NULL;
}

struct Email *mutt_hcache_restore(const unsigned char *d)
{
  mutt_message("mutt_hcache_restore NOTIMPL");
  return NULL;
}

int mutt_hcache_store(header_cache_t *h, const char *key, size_t keylen, struct Email *header, unsigned int uidvalidity)
{
  mutt_message("mutt_hcache_store NOTIMPL");
  return -1;
}

void mutt_progress_init(struct Progress *progress, const char *msg, unsigned short flags, unsigned short inc, size_t size)
{
  mutt_message("mutt_progress_init NOTIMPL");
}

void mutt_progress_update(struct Progress *progress, long pos, int percent)
{
  mutt_message("mutt_progress_update NOTIMPL");
}

uint64_t mutt_rand64(void)
{
  mutt_message("mutt_rand64 NOTIMPL");
  return 0;
}

void mutt_set_flag_update(struct Context *ctx, struct Email *h, int flag, bool bf, bool upd_ctx)
{
  mutt_message("mutt_set_flag_update NOTIMPL");
}

void mutt_sort_headers(struct Context *ctx, int init)
{
  mutt_message("mutt_sort_headers NOTIMPL");
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

int mx_msg_close(struct Context *ctx, struct Message **msg)
{
  mutt_message("mx_msg_close NOTIMPL");
  return -1;
}

struct Message *mx_msg_open_new(struct Context *ctx, struct Email *hdr, int flags)
{
  mutt_message("mx_msg_open_new NOTIMPL");
  return NULL;
}

void mx_update_context(struct Context *ctx, int new_messages)
{
  mutt_message("mx_update_context NOTIMPL");
}

void mx_update_tables(struct Context *ctx, bool committing)
{
  mutt_message("mx_update_tables NOTIMPL");
}

int nm_update_filename(struct Context *ctx, const char *old, const char *new, struct Email *h)
{
  mutt_message("nm_update_filename NOTIMPL");
  return -1;
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

int main(int argc, char *argv[])
{
  char *file = "test.maildir";
  struct Context ctx = { 0 };
  struct Mailbox m = { 0 };
  ctx.mailbox = &m;
  m.magic = MUTT_MAILDIR;
  mutt_str_strfcpy(m.path, file, sizeof(m.path));

  int rc = mx_maildir_ops.mbox_open(&ctx);
  printf("%d\n", rc);
  if (rc != 0)
    return 1;

  rc = mx_maildir_ops.mbox_close(&ctx);
  printf("%d\n", rc);
  if (rc != 0)
    return 1;

  return 0;
}
