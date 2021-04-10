#include "config.h"
#include <errno.h>
#include <ftw.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "mutt/lib.h"
#include "email/email.h"
#include "core/lib.h"
#include "debug/lib.h"
#include "maildir/lib.h"
#include "context.h"
#include "mx.h"

struct Progress;

typedef uint16_t CopyMessageFlags;
typedef uint32_t CopyHeaderFlags;

bool C_Autocrypt;
bool C_FlagSafe;
char *HomeDir;
bool C_MailCheckRecent;
short C_ReadInc;
char *ShortHostname;
volatile sig_atomic_t SigInt;
short C_Sort;
short C_WriteInc;
int MonitorContextChanged = 0;
struct Context *Context = NULL;

bool mx_ac_add(struct Account *a, struct Mailbox *m)
{
  if (!a || !m || !m->mx_ops || !m->mx_ops->ac_add)
    return false;

  return m->mx_ops->ac_add(a, m) && account_mailbox_add(a, m);
}

void ctx_free(struct Context **ptr)
{
  if (!ptr || !*ptr)
    return;

  // struct Context *ctx = *ptr;

  FREE(ptr);
}

struct Context *ctx_new(struct Mailbox *m)
{
  struct Context *ctx = mutt_mem_calloc(1, sizeof(struct Context));

  ctx->mailbox = m;

  return ctx;
}

struct Mailbox *ctx_mailbox(struct Context *ctx)
{
  return ctx ? ctx->mailbox : NULL;
}

void nm_edata_free(void **ptr)
{
}

void mutt_buffer_encode_path(struct Buffer *buf, const char *src)
{
}

int mutt_autocrypt_process_autocrypt_header(struct Email *e, struct Envelope *env)
{
  return -1;
}

void mutt_pretty_mailbox(char *buf, size_t buflen)
{
}

void mutt_encode_path(char *dest, size_t dlen, const char *src)
{
  mutt_str_copy(dest, src, dlen);
  printf("mutt_encode_path: %s\n", src);
}

int mutt_copy_message(FILE *fp_out, struct Mailbox *m, struct Email *e, CopyMessageFlags cmflags, CopyHeaderFlags chflags)
{
  return -1;
}

int url_parse_mailto(struct Envelope *e, char **body, const char *src)
{
  return -1;
}

void ctx_update_tables(struct Context *ctx, bool committing)
{
}

void mutt_clear_threads(struct Context *ctx)
{
  mutt_message("mutt_clear_threads NOTIMPL");
}

int mutt_copy_message_ctx(FILE *fpout, struct Context *src, struct Email *hdr, int flags, int chflags)
{
  mutt_message("mutt_copy_message_ctx NOTIMPL");
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

int mx_msg_close(struct Mailbox *m, struct Message **msg)
{
  mutt_message("mx_msg_close NOTIMPL");
  return -1;
}

struct Message *mx_msg_open_new(struct Mailbox *m, const struct Email *e, MsgOpenFlags flags)
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

void build_test_maildir(struct Account *a, struct Mailbox *m)
{
  char *file = "test.maildir";

  a->type = MUTT_MAILDIR;
  neomutt_account_add(NeoMutt, a);

  m->type = MUTT_MAILDIR;
  m->mx_ops = &MxMaildirOps;
  mutt_buffer_strcpy(&m->pathbuf, file);

  mx_ac_add(a, m);
}

int test_open_and_close(struct Mailbox *m)
{
  struct Context *ctx = ctx_new(m);

  int rc = m->mx_ops->mbox_open(ctx->mailbox);
  printf("%d\n", rc);
  if (rc != 0)
    return 1;

#ifdef USE_DEBUG_GRAPHVIZ
  dump_graphviz("index", ctx);
#endif

  rc = m->mx_ops->mbox_close(ctx->mailbox);
  printf("%d\n", rc);
  if (rc != 0)
    return 1;

  ctx_free(&ctx);
  return 0;
}

int test_mbox_create(struct Account *test_account, struct Mailbox *test_mailbox)
{
  struct Mailbox *new_mailbox = NULL;
  int rc = MxMaildirOps.mbox_create(test_account, test_mailbox, "", &new_mailbox);
  if (rc != MX_CREATE_BAD_NAME) {
      fprintf(stderr, "Failed invalid name test\n");
      return 1;
  }

  rc = MxMaildirOps.mbox_create(test_account, test_mailbox, "child_maildir", &new_mailbox);
  if (rc != MX_CREATE_EXISTS) {
      fprintf(stderr, "Failed existing maildir test\n");
      return 1;
  }

  rc = MxMaildirOps.mbox_create(test_account, test_mailbox, "this_is_a_file", &new_mailbox);
  if (rc != MX_CREATE_SYS_ERROR) {
      if (errno != ENOTDIR)
          fprintf(stderr, "Failed setting errno correctly\n");
      fprintf(stderr, "Failed creation with system error\n");
      return 1;
  }

  rc = MxMaildirOps.mbox_create(test_account, test_mailbox, "new_maildir", &new_mailbox);
  if (rc != MX_CREATE_OK) {
      fprintf(stderr, "Failed creation test\n");
      return 1;
  }

  const char *expected_subdirs[] = {"test.maildir/new_maildir/cur", "test.maildir/new_maildir/new", "test.maildir/new_maildir/tmp"};
  int create_error = 0;
  for (int i = 0; i < 3; i++) {
      struct stat statbuf;
      const char *subdir = expected_subdirs[i];
      if (stat(subdir, &statbuf) || !S_ISDIR(statbuf.st_mode)) {
          fprintf(stderr, "Failed to create %s\n", subdir);
          create_error = -1;
      }
  }
  mutt_file_rmtree("test.maildir/new_maildir");

  return create_error;
}

int main(int argc, char *argv[])
{
  struct ConfigSet *cs = cs_new(32);
  if (!cs)
    return 1;

  NeoMutt = neomutt_new(cs);
  if (!NeoMutt)
    return 1;

  struct Account *test_account = account_new(NULL, NeoMutt->sub);
  struct Mailbox *test_mailbox = mailbox_new();
  build_test_maildir(test_account, test_mailbox);

  int rc = 0;
  //rc = test_open_and_close(test_mailbox);
  if (rc != 0)
    return 1;

  if (test_mbox_create(test_account, test_mailbox) != 0)
      return 1;

  neomutt_free(&NeoMutt);
  cs_free(&cs);

  return 0;
}
