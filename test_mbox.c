#include "config.h"
#include <signal.h>
#include <stdbool.h>
#include "mutt/mutt.h"
#include "context.h"
#include "email/email.h"
#include "mbox/mbox.h"
#include "mx.h"

struct Progress;

short Sort;
short WriteInc;
bool CheckMboxSize;
bool MailCheckRecent;
char *ShortHostname;
char *Username;
short ReadInc;
volatile sig_atomic_t SigInt;

void mutt_clear_threads(struct Context *ctx)
{
  mutt_message("mutt_clear_threads NOTIMPL");
}

int mutt_copy_message_ctx(FILE *fpout, struct Context *src, struct Header *hdr, int flags, int chflags)
{
  mutt_message("mutt_copy_message_ctx NOTIMPL");
  return 0;
}

struct Buffy *mutt_find_mailbox(const char *path)
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

struct Envelope *mutt_rfc822_read_header(FILE *f, struct Header *hdr, short user_hdrs, short weed)
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

void mutt_update_mailbox(struct Buffy *b)
{
  mutt_message("mutt_update_mailbox NOTIMPL");
}

void mx_alloc_memory(struct Context *ctx)
{
  mutt_message("mx_alloc_memory NOTIMPL");
}

void mx_fastclose_mailbox(struct Context *ctx)
{
  mutt_message("mx_fastclose_mailbox NOTIMPL");
}

void mx_update_context(struct Context *ctx, int new_messages)
{
  mutt_message("mx_update_context NOTIMPL");
}

int main(int argc, char *argv[])
{
  char *file = "test.mbox";
  struct Context ctx = { 0 };
  ctx.magic = MUTT_MBOX;
  ctx.path = file;

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
