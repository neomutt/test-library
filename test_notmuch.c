#include "config.h"
#include <stdio.h>
#include "mutt/lib.h"
#include "address/lib.h"
#include "email/lib.h"
#include "core/lib.h"
#include "notmuch/lib.h"
#include "mutt_commands.h"
#include "mx.h"

struct Progress;

typedef uint16_t CompletionFlags;
typedef uint16_t CopyMessageFlags;
typedef uint32_t CopyHeaderFlags;

bool C_Autocrypt;
bool C_FlagSafe;
bool C_MailCheckRecent;
char *C_Folder;
short C_Sort;

char *HomeDir;
char *ShortHostname;
int MonitorContextChanged = 0;
int SigInt = 0;
struct Context *Context = NULL;

struct Mailbox *mx_path_resolve(const char *path)
{
  return NULL;
}

bool mx_mbox_ac_link(struct Mailbox *m)
{
  return false;
}

struct Mailbox *ctx_mailbox(struct Context *ctx)
{
  return ctx ? ctx->mailbox : NULL;
}

void commands_register(const struct Command *cmds, const size_t num_cmds)
{
}

enum CommandResult parse_mailboxes(struct Buffer *buf, struct Buffer *s,
                                   intptr_t data, struct Buffer *err)
{
  return MUTT_CMD_SUCCESS;
}

enum CommandResult parse_unmailboxes(struct Buffer *buf, struct Buffer *s,
                                     intptr_t data, struct Buffer *err)
{
  return MUTT_CMD_SUCCESS;
}

void mutt_encode_path(char *dest, size_t dlen, const char *src)
{
  mutt_str_copy(dest, src, dlen);
  printf("mutt_encode_path: %s\n", src);
}

void mutt_set_header_color(struct Mailbox *m, struct Email *e)
{
}

struct Hash *mutt_make_id_hash(struct Mailbox *m)
{
  return NULL;
}

int mutt_autocrypt_process_autocrypt_header(struct Email *e, struct Envelope *env)
{
  return -1;
}

void buf_encode_path(struct Buffer *buf, const char *src)
{
}

void mutt_clear_error(void)
{
}

int mutt_copy_message(FILE *fp_out, struct Mailbox *m, struct Email *e, CopyMessageFlags cmflags, CopyHeaderFlags chflags)
{
  return -1;
}

int buf_get_field(const char *field, struct Buffer *buf, CompletionFlags complete,
                          bool multiple, char ***files, int *numfiles)
{
  return -1;
}

int mutt_get_field(const char *field, char *buf, size_t buflen, int complete,
                   bool multiple, char ***files, int *numfiles)
{
  return -1;
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

uint64_t mutt_rand64(void)
{
  mutt_message("mutt_rand64 NOTIMPL");
  return 0;
}

void mutt_set_flag_update(struct Context *ctx, struct Email *h, int flag, bool bf, bool upd_ctx)
{
  mutt_message("mutt_set_flag_update NOTIMPL");
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

int main(int argc, char *argv[])
{
  const char *path = "notmuch:///home/mutt/mail";
  enum MailboxType type = nm_path_probe(path, NULL);
  printf("%d\n", type);

  return 0;
}
