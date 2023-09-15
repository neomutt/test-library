#include "config.h"
#include <signal.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "mutt/lib.h"
#include "email/email.h"
#include "core/lib.h"
#include "mutt.h"
#include "mbox/lib.h"
#include "progress/lib.h"
#include "mx.h"

char *HomeDir;
char *ShortHostname;
char *Username;
volatile sig_atomic_t SigInt;

typedef uint16_t CopyMessageFlags;
typedef uint32_t CopyHeaderFlags;

#define CONFIG_INIT_TYPE(CS, NAME)                                             \
  extern const struct ConfigSetType Cst##NAME;                                 \
  cs_register_type(CS, &Cst##NAME)

void buf_pretty_mailbox(struct Buffer *buf)
{
}

void mutt_set_flag(struct Mailbox *m, struct Email *e, enum MessageType flag,
                   bool bf, bool upd_mbox)
{
}

int mx_msg_close(struct Mailbox *m, struct Message **ptr)
{
  return -1;
}

struct Message *mx_msg_open(struct Mailbox *m, struct Email *e)
{
  return NULL;
}

void progress_free(struct Progress **ptr)
{
}

struct Progress *progress_new(const char *msg, enum ProgressType type, size_t size)
{
  return NULL;
}

bool progress_update(struct Progress *progress, size_t pos, int percent)
{
  return false;
}

void nm_edata_free(void **ptr)
{
}

int mutt_autocrypt_process_autocrypt_header(struct Email *e, struct Envelope *env)
{
  return -1;
}

int mutt_copy_message(FILE *fp_out, struct Mailbox *m, struct Email *e, CopyMessageFlags cmflags, CopyHeaderFlags chflags)
{
  return -1;
}

bool mx_mbox_open(struct Mailbox *m, OpenMailboxFlags flags)
{
  return true;
}

enum MxStatus mx_mbox_close(struct Mailbox *m)
{
  return MX_STATUS_OK;
}

void mutt_make_label_hash(struct Mailbox *m)
{
  mutt_message("mutt_make_label_hash NOTIMPL");
}

void mx_alloc_memory(struct Mailbox *m, int req_size)
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

void mx_fastclose_mailbox(struct Mailbox *m, bool keep_account)
{
  mutt_message("mx_fastclose_mailbox NOTIMPL");
}

int main(int argc, char *argv[])
{
  static struct ConfigDef Vars[] = {
    // clang-format off
    { "assumed_charset", DT_SLIST|SLIST_SEP_COLON|SLIST_ALLOW_EMPTY, 0, 0, NULL, 0, 0 },
    { "autocrypt", DT_BOOL, false, 0, NULL, 0, 0 },
    { "charset", DT_STRING|DT_NOT_EMPTY|DT_CHARSET_SINGLE, IP "utf-8", 0, NULL, 0, 0},
    { "maildir_field_delimiter", DT_STRING, IP ":", 0, NULL, 0, 0 },
    { "reply_regex", DT_REGEX|R_INDEX|R_RESORT, IP "^((re|aw|sv)(\\[[0-9]+\\])*:[ \t]*)*", 0, NULL, 0, 0 },
    { "send_charset", DT_SLIST|SLIST_SEP_COLON|SLIST_ALLOW_EMPTY|DT_CHARSET_STRICT, IP "us-ascii:iso-8859-1:utf-8", 0, NULL, },
    { NULL },
    // clang-format on
  };

  struct ConfigSet *cs = cs_new(50);
  struct ConfigSubset *sub = cs_subset_new (NULL, NULL, NULL);
  CONFIG_INIT_TYPE(cs, Bool);
  CONFIG_INIT_TYPE(cs, Path);
  CONFIG_INIT_TYPE(cs, Regex);
  CONFIG_INIT_TYPE(cs, Slist);
  CONFIG_INIT_TYPE(cs, String);

  NeoMutt = neomutt_new(cs);

  cs_register_variables(cs, Vars, DT_NO_FLAGS);

  char *file = "test.mbox";
  struct Account *a = account_new(NULL, sub);
  struct Mailbox *m = mailbox_new();
  m->type = MUTT_MBOX;
  m->account = a;
  a->type = MUTT_MBOX;
  m->pathbuf = buf_make(128);
  buf_strcpy(&m->pathbuf, file);

  int rc = MxMboxOps.mbox_open(m);
  printf("%d\n", rc);
  if (rc != 0)
    return 1;

  rc = MxMboxOps.mbox_close(m);
  printf("%d\n", rc);
  if (rc != 0)
    return 1;

  config_cache_cleanup();
  neomutt_free(&NeoMutt);
  cs_subset_free(&sub);
  cs_free(&cs);
  buf_dealloc(&m->pathbuf);

  mailbox_free(&m);
  account_free(&a);
  return 0;
}
