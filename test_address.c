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

  // void                    mutt_addr_cat                     (char *buf, size_t buflen, const char *value, const char *specials);
  // bool                    mutt_addr_cmp                     (const struct Address *a, const struct Address *b);
  // struct Address *        mutt_addr_copy                    (const struct Address *addr);
  // struct Address *        mutt_addr_create                  (const char *personal, const char *mailbox);
  // const char *            mutt_addr_for_display             (const struct Address *a);
  // void                    mutt_addr_free                    (struct Address **ptr);
  // struct Address *        mutt_addr_new                     (void);
  // bool                    mutt_addr_to_intl                 (struct Address *a);
  // bool                    mutt_addr_to_local                (struct Address *a);
  // bool                    mutt_addr_valid_msgid             (const char *msgid);
  // size_t                  mutt_addr_write                   (char *buf, size_t buflen, struct Address *addr, bool display);
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
  // bool                    mutt_addrlist_search              (const struct Address *needle, const struct AddressList *haystack);
  // int                     mutt_addrlist_to_intl             (struct AddressList *al, char **err);
  // int                     mutt_addrlist_to_local            (struct AddressList *al);
  // size_t                  mutt_addrlist_write               (char *buf, size_t buflen, const struct AddressList *al, bool display);

  struct Address *a = mutt_addr_new();
  mutt_addr_free(&a);
}

void test_group(void)
{
  // bool                    mutt_group_match                  (struct Group *g, const char *s);
  // void                    mutt_grouplist_add                (struct GroupList *gl, struct Group *group);
  // void                    mutt_grouplist_add_addrlist       (struct GroupList *gl, struct AddressList *al);
  // int                     mutt_grouplist_add_regex          (struct GroupList *gl, const char *s, int flags, struct Buffer *err);
  // void                    mutt_grouplist_clear              (struct GroupList *gl);
  // void                    mutt_grouplist_destroy            (struct GroupList *gl);
  // void                    mutt_grouplist_free               (void);
  // void                    mutt_grouplist_init               (void);
  // int                     mutt_grouplist_remove_addrlist    (struct GroupList *gl, struct AddressList *al);
  // int                     mutt_grouplist_remove_regex       (struct GroupList *gl, const char *s);
  // struct Group *          mutt_pattern_group                (const char *pat);

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

void print_addresses(const struct AddressList *al)
{
  struct Address *addr = NULL;
  TAILQ_FOREACH(addr, al, entries)
  {
    printf("Address %p\n", addr);
    printf("    personal     = %s\n", addr->personal);
    printf("    mailbox      = %s\n", addr->mailbox);
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
