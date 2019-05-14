#include "config.h"
#include <errno.h>
#include <locale.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "mutt/mutt.h"
#include "email/lib.h"

bool test_file(const char *name)
{
  FILE *fp = fopen(name, "r");
  if (!fp)
    return false;

  struct stat st = { 0 };
  if (fstat(fileno(fp), &st) != 0)
    return false;

  struct Email *e = mutt_email_new();
  struct Envelope *env = NULL;

  env = mutt_rfc822_read_header(fp, e, false, false);
  if (!env)
    return false;

  mutt_parse_part(fp, e->content);

  mutt_env_free(&env);
  mutt_email_free(&e);
  fclose(fp);
  return true;
}

int main(int argc, char *argv[])
{
  for (argc--; argc > 0; argc--, argv++)
  {
    printf("Testing: %s\n", argv[1]);
    if (!test_file(argv[1]))
      return 1;

    if (argc > 1)
      printf("----------------------------------------------------------------------------\n");
  }

  return 0;
}
