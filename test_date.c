#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mutt/lib.h"

typedef int (*test_fn)(const char *arg);

static int test_imap_make_date(const char *arg)
{
  printf("%s: %s\n", __func__, arg);
  return 1;
}

static int test_imap_parse_date(const char *arg)
{
  printf("%s: %s\n", __func__, arg);
  return 1;
}

static int test_is_day_name(const char *arg)
{
  printf("%s: %s\n", __func__, arg);
  return 1;
}

static int test_mutt_check_month(const char *arg)
{
  printf("%s: %s\n", __func__, arg);
  return 1;
}

static int test_mutt_local_tz(const char *arg)
{
  printf("%s: %s\n", __func__, arg);
  return 1;
  // mutt_date_local_tz(1501596063);
}

static int test_mutt_make_date(const char *arg)
{
  struct Buffer buf = mutt_buffer_make(64);
  mutt_date_make_date(&buf);
  printf("%s", mutt_buffer_string(&buf));
  mutt_buffer_dealloc(&buf);

  return 0;
}

static int test_mutt_mktime(const char *arg)
{
  printf("%s: %s\n", __func__, arg);
  return 1;
}

static int test_mutt_normalize_time(const char *arg)
{
  printf("%s: %s\n", __func__, arg);
  return 1;
}

static int test_mutt_parse_date(const char *arg)
{
  printf("%s: %s\n", __func__, arg);
  return 1;
}

int main(int argc, char *argv[])
{
  struct Test
  {
    const char *name;
    test_fn test;
  };

  struct Test tests[] = {
    { "mutt_date_make_imap", test_imap_make_date },
    { "mutt_date_parse_imap", test_imap_parse_date },
    { "mutt_date_is_day_name", test_is_day_name },
    { "mutt_date_check_month", test_mutt_check_month },
    { "mutt_date_local_tz", test_mutt_local_tz },
    { "mutt_date_make_date", test_mutt_make_date },
    { "mutt_date_make_time", test_mutt_mktime },
    { "mutt_date_normalize_time", test_mutt_normalize_time },
    { "mutt_date_parse_date", test_mutt_parse_date },
  };

  if (argc == 3)
  {
    for (int i = 0; i < mutt_array_size(tests); i++)
      if (strcmp(argv[1], tests[i].name) == 0)
        return tests[i].test(argv[2]);
  }

  printf("Usage: %s TEST arg\n", argv[0]);
  for (int i = 0; i < mutt_array_size(tests); i++)
    printf("\t%s\n", tests[i].name);
  return 1;
}
