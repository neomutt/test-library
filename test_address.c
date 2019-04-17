#include <errno.h>
#include <locale.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mutt/mutt.h"
#include "address/lib.h"
#include "email/lib.h"

void test_address(void)
{
  // int AddressError;
  // const char *const AddressErrors[];
  // const char AddressSpecials[];

  // struct Address *        mutt_addr_append                  (struct Address **a, struct Address *b, bool prune);
  // void                    mutt_addr_cat                     (char *buf, size_t buflen, const char *value, const char *specials);
  // bool                    mutt_addr_cmp                     (struct Address *a, struct Address *b);
  // bool                    mutt_addr_cmp_strict              (const struct Address *a, const struct Address *b);
  // struct Address *        mutt_addr_copy                    (struct Address *addr);
  // struct Address *        mutt_addr_copy_list               (struct Address *addr, bool prune);
  // const char *            mutt_addr_for_display             (struct Address *a);
  // void                    mutt_addr_free                    (struct Address **p);
  // int                     mutt_addr_has_recips              (struct Address *a);
  // bool                    mutt_addr_is_intl                 (struct Address *a);
  // bool                    mutt_addr_is_local                (struct Address *a);
  // int                     mutt_addr_mbox_to_udomain         (const char *mbox, char **user, char **domain);
  // struct Address *        mutt_addr_new                     (void);
  // struct Address *        mutt_addr_parse_list              (struct Address *top, const char *s);
  // struct Address *        mutt_addr_parse_list2             (struct Address *p, const char *s);
  // void                    mutt_addr_qualify                 (struct Address *addr, const char *host);
  // int                     mutt_addr_remove_from_list        (struct Address **a, const char *mailbox);
  // struct Address *        mutt_addr_remove_xrefs            (struct Address *a, struct Address *b);
  // bool                    mutt_addr_search                  (struct Address *a, struct Address *lst);
  // void                    mutt_addr_set_intl                (struct Address *a, char *intl_mailbox);
  // void                    mutt_addr_set_local               (struct Address *a, char *local_mailbox);
  // bool                    mutt_addr_valid_msgid             (const char *msgid);
  // size_t                  mutt_addr_write                   (char *buf, size_t buflen, struct Address *addr, bool display);
  // void                    mutt_addr_write_single            (char *buf, size_t buflen, struct Address *addr, bool display);
  // struct Address *        mutt_addrlist_dedupe              (struct Address *addr);
  // int                     mutt_addrlist_to_intl             (struct Address *a, char **err);
  // int                     mutt_addrlist_to_local            (struct Address *a);

  struct Address *a = mutt_addr_new();
  mutt_addr_free(&a);
}

void test_group(void)
{
  // bool                    mutt_group_match                  (struct Group *g, const char *s);
  // void                    mutt_grouplist_add                (struct GroupList *head, struct Group *group);
  // void                    mutt_grouplist_add_addrlist       (struct GroupList *head, struct Address *a);
  // int                     mutt_grouplist_add_regex          (struct GroupList *head, const char *s, int flags, struct Buffer *err);
  // void                    mutt_grouplist_clear              (struct GroupList *head);
  // void                    mutt_grouplist_destroy            (struct GroupList *head);
  // void                    mutt_grouplist_free               (void);
  // void                    mutt_grouplist_init               (void);
  // int                     mutt_grouplist_remove_addrlist    (struct GroupList *head, struct Address *a);
  // int                     mutt_grouplist_remove_regex       (struct GroupList *head, const char *s);
  // struct Group *          mutt_pattern_group                (const char *k);

  mutt_grouplist_free();
}

void test_idna(void)
{
  // bool C_IdnDecode;
  // bool C_IdnEncode;

  // char *                  mutt_idna_intl_to_local           (const char *user, const char *domain, int flags);
  // char *                  mutt_idna_local_to_intl           (const char *user, const char *domain);
  // const char *            mutt_idna_print_version           (void);
  // int                     mutt_idna_to_ascii_lz             (const char *input, char **output, int flags);

  setlocale(LC_ALL, "");

  char *mailbox = NULL;

  C_IdnEncode = true;
  C_IdnDecode = true;

  mutt_str_replace(&C_Charset, "utf-8");

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

  FREE(&C_Charset);

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
}

void print_addresses(const struct Address *addr)
{
  for (; addr; addr = addr->next)
  {
    printf("Address %p\n", addr);
    printf("    personal     = %s\n", addr->personal);
    printf("    mailbox      = %s\n", addr->mailbox);
    printf("    group        = %d\n", addr->group);
    printf("    next         = %p\n", addr->next);
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
  test_group();
  test_idna();

  struct Address *a = NULL;

  a = mutt_addr_parse_list(a, argv[1]);
  if (!a)
  {
    printf("failed\n");
    return 1;
  }

  print_addresses(a);
  mutt_addr_free(&a);

  return 0;
}
