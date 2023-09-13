#include <errno.h>
#include <locale.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mutt/lib.h"
#include "address/lib.h"
#include "config/lib.h"
#include "email/lib.h"
#include "core/lib.h"

#define CONFIG_INIT_TYPE(CS, NAME)                                             \
  extern const struct ConfigSetType Cst##NAME;                                 \
  cs_register_type(CS, &Cst##NAME)

void nm_edata_free(void **ptr)
{
}

void test_address(void)
{
  // const char AddressSpecials[];

  // void                    mutt_addr_cat                     (char *buf, size_t buflen, const char *value, const char *specials);
  // bool                    mutt_addr_cmp                     (const struct Address *a, const struct Address *b);
  // struct Address *        mutt_addr_copy                    (const struct Address *addr);
  // struct Address *        mutt_addr_create                  (const char *personal, const char *mailbox);
  // const char *            mutt_addr_for_display             (const struct Address *a);
  // void                    mutt_addr_free                    (struct Address **ptr);
  // struct Address *        mutt_addr_new                     (void);
  // bool                    mutt_addr_to_intl                 (struct Address *a);
  // bool                    mutt_addr_to_local                (struct Address *a);
  // bool                    mutt_addr_uses_unicode            (const char *str);
  // bool                    mutt_addr_valid_msgid             (const char *msgid);
  // size_t                  mutt_addr_write                   (struct Buffer *buf, struct Address *addr, bool display);
  // void                    mutt_addrlist_append              (struct AddressList *al, struct Address *a);
  // void                    mutt_addrlist_clear               (struct AddressList *al);
  // void                    mutt_addrlist_copy                (struct AddressList *dst, const struct AddressList *src, bool prune);
  // int                     mutt_addrlist_count_recips        (const struct AddressList *al);
  // void                    mutt_addrlist_dedupe              (struct AddressList *al);
  // bool                    mutt_addrlist_equal               (const struct AddressList *ala, const struct AddressList *alb);
  // int                     mutt_addrlist_parse               (struct AddressList *al, const char *s);
  // int                     mutt_addrlist_parse2              (struct AddressList *al, const char *s);
  // void                    mutt_addrlist_prepend             (struct AddressList *al, struct Address *a);
  // void                    mutt_addrlist_qualify             (struct AddressList *al, const char *host);
  // int                     mutt_addrlist_remove              (struct AddressList *al, const char *mailbox);
  // void                    mutt_addrlist_remove_xrefs        (const struct AddressList *a, struct AddressList *b);
  // bool                    mutt_addrlist_search              (const struct AddressList *haystack, const struct Address *needle);
  // int                     mutt_addrlist_to_intl             (struct AddressList *al, char **err);
  // int                     mutt_addrlist_to_local            (struct AddressList *al);
  // bool                    mutt_addrlist_uses_unicode        (const struct AddressList *al);
  // size_t                  mutt_addrlist_write               (const struct AddressList *al, struct Buffer *buf, bool display);
  // void                    mutt_addrlist_write_file          (const struct AddressList *al, FILE *fp, const char *header);
  // size_t                  mutt_addrlist_write_list          (const struct AddressList *al, struct ListHead *list);
  // size_t                  mutt_addrlist_write_wrap          (const struct AddressList *al, struct Buffer *buf, const char *header);

  struct Address *a = mutt_addr_new();
  mutt_addr_free(&a);
}

void test_config_type(void)
{
  // struct Address *        address_new                       (const char *addr);
  // const struct Address *  cs_subset_address                 (const struct ConfigSubset *sub, const char *name);

  struct Address *addr = address_new(NULL);

  mutt_addr_free(&addr);
}

void test_group(void)
{
  // bool                    mutt_group_match                  (struct Group *g, const char *s);
  // void                    mutt_grouplist_add                (struct GroupList *gl, struct Group *group);
  // void                    mutt_grouplist_add_addrlist       (struct GroupList *gl, struct AddressList *al);
  // int                     mutt_grouplist_add_regex          (struct GroupList *gl, const char *s, uint16_t flags, struct Buffer *err);
  // void                    mutt_grouplist_cleanup            (void);
  // void                    mutt_grouplist_clear              (struct GroupList *gl);
  // void                    mutt_grouplist_destroy            (struct GroupList *gl);
  // void                    mutt_grouplist_init               (void);
  // int                     mutt_grouplist_remove_addrlist    (struct GroupList *gl, struct AddressList *al);
  // int                     mutt_grouplist_remove_regex       (struct GroupList *gl, const char *s);
  // struct Group *          mutt_pattern_group                (const char *pat);

  mutt_grouplist_cleanup();
}

void test_idna(void)
{
  // char *                  mutt_idna_intl_to_local           (const char *user, const char *domain, uint8_t flags);
  // char *                  mutt_idna_local_to_intl           (const char *user, const char *domain);
  // const char *            mutt_idna_print_version           (void);
  // int                     mutt_idna_to_ascii_lz             (const char *input, char **output, uint8_t flags);

  setlocale(LC_ALL, "");

  static struct ConfigDef Vars[] = {
    // clang-format off
    { "assumed_charset", DT_SLIST|SLIST_SEP_COLON|SLIST_ALLOW_EMPTY, 0, 0, NULL, 0, 0 },
    { "charset", DT_STRING|DT_NOT_EMPTY|DT_CHARSET_SINGLE, IP "utf-8", 0, NULL, 0, 0},
    { "idn_decode", DT_BOOL, true, 0, NULL, 0, 0 },
    { "idn_encode", DT_BOOL, true, 0, NULL, 0, 0 },
    { "maildir_field_delimiter", DT_STRING, IP ":", 0, NULL, 0, 0 },
    { NULL },
    // clang-format on
  };

  struct ConfigSet *cs = cs_new(50);
  CONFIG_INIT_TYPE(cs, Bool);
  CONFIG_INIT_TYPE(cs, Slist);
  CONFIG_INIT_TYPE(cs, String);

  NeoMutt = neomutt_new(cs);

  cs_register_variables(cs, Vars, DT_NO_FLAGS);

  char *mailbox = NULL;

  char *user = "joe";
  char *domain1 = "\360\237\222\251.la";
  char *domain2 = "xn--pxaix.la";

  mailbox = mutt_idna_local_to_intl(user, domain1);
  if (mailbox)
  {
    printf("%s@%s -> %s\n", user, domain1, mailbox);
    FREE(&mailbox);
  }

  mailbox = mutt_idna_intl_to_local(user, domain2, 0);
  if (mailbox)
  {
    printf("%s@%s -> %s\n", user, domain2, mailbox);
    FREE(&mailbox);
  }

  char *input = "\316\264\317\200\316\270.com";
  char *output = NULL;

  int rc = mutt_idna_to_ascii_lz(input, &output, 0);
  if (rc == 0)
  {
    printf("%s -> %s\n", input, output);
    FREE(&output);
  }
  else
  {
    printf("failed: %d\n", rc);
  }

  config_cache_cleanup();
  neomutt_free(&NeoMutt);
  cs_free(&cs);
}

void print_addresses(const struct AddressList *al)
{
  struct Address *addr = NULL;
  TAILQ_FOREACH(addr, al, entries)
  {
    printf("Address %p\n", (void *) addr);
    printf("    personal     = %s\n", buf_string(addr->personal));
    printf("    mailbox      = %s\n", buf_string(addr->mailbox));
    printf("    group        = %d\n", addr->group);
    printf("    is_intl      = %d\n", addr->is_intl);
    printf("    intl_checked = %d\n", addr->intl_checked);
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("args\n");
    return 1;
  }

  test_address();
  test_config_type();
  test_group();
  test_idna();

  struct AddressList al = TAILQ_HEAD_INITIALIZER(al);

  mutt_addrlist_parse(&al, argv[1]);
  if (TAILQ_EMPTY(&al))
  {
    printf("failed\n");
    return 1;
  }

  print_addresses(&al);
  mutt_addrlist_clear(&al);

  return 0;
}
