#include <locale.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "mutt/mutt.h"
#include "address.h"

void test_address(void)
{
  // struct Address *mutt_addr_append          (struct Address **a, struct Address *b, bool prune);
  // void            mutt_addr_cat             (char *buf, size_t buflen, const char *value, const char *specials);
  // bool            mutt_addr_cmp_strict      (const struct Address *a, const struct Address *b);
  // bool            mutt_addr_cmp             (struct Address *a, struct Address *b);
  // struct Address *mutt_addr_copy_list       (struct Address *addr, bool prune);
  // struct Address *mutt_addr_copy            (struct Address *addr);
  // const char *    mutt_addr_for_display     (struct Address *a);
  // void            mutt_addr_free            (struct Address **p);
  // int             mutt_addr_has_recips      (struct Address *a);
  // bool            mutt_addr_is_intl         (struct Address *a);
  // bool            mutt_addr_is_local        (struct Address *a);
  // int             mutt_addr_mbox_to_udomain (const char *mbox, char **user, char **domain);
  // struct Address *mutt_addr_new             (void);
  // struct Address *mutt_addr_parse_list2     (struct Address *p, const char *s);
  // struct Address *mutt_addr_parse_list      (struct Address *top, const char *s);
  // void            mutt_addr_qualify         (struct Address *addr, const char *host);
  // int             mutt_addr_remove_from_list(struct Address **a, const char *mailbox);
  // bool            mutt_addr_search          (struct Address *a, struct Address *lst);
  // void            mutt_addr_set_intl        (struct Address *a, char *intl_mailbox);
  // void            mutt_addr_set_local       (struct Address *a, char *local_mailbox);
  // bool            mutt_addr_valid_msgid     (const char *msgid);
  // size_t          mutt_addr_write           (char *buf, size_t buflen, struct Address *addr, bool display);
  // void            mutt_addr_write_single    (char *buf, size_t buflen, struct Address *addr, bool display);

  struct Address *a = mutt_addr_new();
  mutt_addr_free(&a);
}

int main()
{
  test_address();
  return 0;
}

