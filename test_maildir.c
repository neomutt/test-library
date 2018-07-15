#include "config.h"
#include <signal.h>
#include <stdbool.h>
#include "mutt/mutt.h"
#include "context.h"
#include "email/email.h"
#include "maildir/maildir.h"
#include "mx.h"

struct Progress;

bool FlagSafe;
char *HeaderCache;
bool MailCheckRecent;
bool MaildirTrash;
bool MarkOld;
short ReadInc;
char *ShortHostname;
volatile sig_atomic_t SigInt;
short Sort;
short WriteInc;

void mutt_clear_threads(struct Context *ctx)
{
  mutt_message("mutt_clear_threads NOTIMPL");
}

int mutt_copy_message_ctx(FILE *fpout, struct Context *src, struct Header *hdr, int flags, int chflags)
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

struct Header *mutt_hcache_restore(const unsigned char *d)
{
  mutt_message("mutt_hcache_restore NOTIMPL");
  return NULL;
}

int mutt_hcache_store(header_cache_t *h, const char *key, size_t keylen, struct Header *header, unsigned int uidvalidity)
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

struct Envelope *mutt_rfc822_read_header(FILE *f, struct Header *hdr, bool user_hdrs, bool weed)
{
  mutt_message("mutt_rfc822_read_header NOTIMPL");
  return NULL;
}

void mutt_set_flag_update(struct Context *ctx, struct Header *h, int flag, bool bf, bool upd_ctx)
{
  mutt_message("mutt_set_flag_update NOTIMPL");
}

void mutt_sort_headers(struct Context *ctx, int init)
{
  mutt_message("mutt_sort_headers NOTIMPL");
}

void mx_alloc_memory(struct Context *ctx)
{
  size_t s = MAX(sizeof(struct Header *), sizeof(int));

  if ((ctx->hdrmax + 25) * s < ctx->hdrmax * s)
  {
    mutt_error(_("Integer overflow -- can't allocate memory."));
    mutt_exit(1);
  }

  if (ctx->hdrs)
  {
    mutt_mem_realloc(&ctx->hdrs, sizeof(struct Header *) * (ctx->hdrmax += 25));
    mutt_mem_realloc(&ctx->v2r, sizeof(int) * ctx->hdrmax);
  }
  else
  {
    ctx->hdrs = mutt_mem_calloc((ctx->hdrmax += 25), sizeof(struct Header *));
    ctx->v2r = mutt_mem_calloc(ctx->hdrmax, sizeof(int));
  }
  for (int i = ctx->msgcount; i < ctx->hdrmax; i++)
  {
    ctx->hdrs[i] = NULL;
    ctx->v2r[i] = -1;
  }
}

int mx_msg_close(struct Context *ctx, struct Message **msg)
{
  mutt_message("mx_msg_close NOTIMPL");
  return -1;
}

struct Message *mx_msg_open_new(struct Context *ctx, struct Header *hdr, int flags)
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

int nm_update_filename(struct Context *ctx, const char *old, const char *new, struct Header *h)
{
  mutt_message("nm_update_filename NOTIMPL");
  return -1;
}

int main(int argc, char *argv[])
{
  char *file = "test.maildir";
  struct Context ctx = { 0 };
  ctx.magic = MUTT_MAILDIR;
  ctx.path = file;

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
