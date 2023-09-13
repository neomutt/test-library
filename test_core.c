#include "config.h"
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mutt/lib.h"
#include "config/lib.h"
#include "core/lib.h"

#define CONFIG_INIT_TYPE(CS, NAME)                                             \
  extern const struct ConfigSetType Cst##NAME;                                 \
  cs_register_type(CS, &Cst##NAME)

char *ShortHostname = "hostname";
char *HomeDir = "/";

void nm_edata_free(void **ptr)
{
}

void test_neomutt()
{
  // struct NeoMutt *NeoMutt;

  // bool                    neomutt_account_add               (struct NeoMutt *n, struct Account *a);
  // bool                    neomutt_account_remove            (struct NeoMutt *n, const struct Account *a);
  // void                    neomutt_free                      (struct NeoMutt **ptr);
  // void                    neomutt_mailboxlist_clear         (struct MailboxList *ml);
  // size_t                  neomutt_mailboxlist_get_all       (struct MailboxList *head, struct NeoMutt *n, enum MailboxType type);
  // struct NeoMutt *        neomutt_new                       (struct ConfigSet *cs);

  neomutt_free(NULL);
}

void test_account()
{
  // void                    account_free                      (struct Account **ptr);
  // bool                    account_mailbox_add               (struct Account *a, struct Mailbox *m);
  // bool                    account_mailbox_remove            (struct Account *a, struct Mailbox *m);
  // struct Account *        account_new                       (const char *name, struct ConfigSubset *sub);

  account_free(NULL);
}

void test_mailbox()
{
  // void                    mailbox_changed                   (struct Mailbox *m, enum NotifyMailbox action);
  // struct Mailbox *        mailbox_find                      (const char *path);
  // struct Mailbox *        mailbox_find_name                 (const char *name);
  // void                    mailbox_free                      (struct Mailbox **ptr);
  // void                    mailbox_gc_add                    (struct Email *e);
  // void                    mailbox_gc_run                    (void);
  // int                     mailbox_gen                       (void);
  // const char *            mailbox_get_type_name             (enum MailboxType type);
  // struct Mailbox *        mailbox_new                       (void);
  // bool                    mailbox_set_subset                (struct Mailbox *m, struct ConfigSubset *sub);
  // void                    mailbox_size_add                  (struct Mailbox *m, const struct Email *e);
  // void                    mailbox_size_sub                  (struct Mailbox *m, const struct Email *e);
  // void                    mailbox_update                    (struct Mailbox *m);

  mailbox_free(NULL);
}

void test_command(void)
{
  // struct Command *        command_get                       (const char *s);
  // size_t                  commands_array                    (struct Command **first);
  // void                    commands_cleanup                  (void);
  // void                    commands_register                 (const struct Command *cmds, const size_t num_cmds);

  command_get(NULL);
}

void test_config_cache(void)
{
  // const struct Slist *    cc_assumed_charset                (void);
  // const char *            cc_charset                        (void);
  // const char *            cc_maildir_field_delimiter        (void);
  // void                    config_cache_cleanup              (void);

  config_cache_cleanup();
}

void test_dispatcher(void)
{
  // const char *            dispatcher_get_retval_name        (int rv);

  dispatcher_get_retval_name(0);
}

void test_message(void)
{
  // void                    message_free                      (struct Message **ptr);
  // struct Message *        message_new                       (void);

  message_free(NULL);
}

void test_tmp(void)
{
  // void                    buf_mktemp_full                   (struct Buffer *buf, const char *prefix, const char *suffix, const char *src, int line);
  // FILE *                  mutt_file_mkstemp_full            (const char *file, int line, const char *func);

  static struct ConfigDef Vars[] = {
    // clang-format off
    { "tmp_dir", DT_PATH|DT_PATH_DIR|DT_NOT_EMPTY, IP TMPDIR, 0, NULL, },
    { NULL },
    // clang-format on
  };

  struct ConfigSet *cs = cs_new(50);
  CONFIG_INIT_TYPE(cs, Path);

  NeoMutt = neomutt_new(cs);

  cs_register_variables(cs, Vars, DT_NO_FLAGS);

  FILE *fp = mutt_file_mkstemp_full(__FILE__, __LINE__, __func__);

  if (fp)
    fclose(fp);

  config_cache_cleanup();
  neomutt_free(&NeoMutt);
  cs_free(&cs);
}

int main()
{
  test_neomutt();
  test_account();
  test_mailbox();
  test_command();
  test_config_cache();
  test_dispatcher();
  test_message();
  test_tmp();

  return 0;
}
