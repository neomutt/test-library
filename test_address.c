#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "mutt/mutt.h"
#include "email/lib.h"

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
