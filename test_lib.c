#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "lib/lib.h"

int main()
{
  // ascii
  ascii_strcasecmp("apple", "orange");

  // base64
  char buffer[16];
  char *msg = "hello";
  mutt_to_base64(buffer, msg, strlen(msg), sizeof(buffer));

  // buffer
  struct Buffer *b = NULL;
  mutt_buffer_free(&b);

  // date
  mutt_local_tz(1501596063);

  // debug
  const char *user = "Will Robinson";
  mutt_debug(1, "Danger, %s!\n", user);

  // file
  mutt_mkdir("tmp", 0660);

  // hash
  struct Hash *h = NULL;
  hash_destroy(&h, NULL);

  // md5
  struct Md5Ctx m;
  md5_init_ctx(&m);

  // memory
  void *ptr = NULL;
  FREE(&ptr);

  // message
  mutt_message("mutt_message");
  mutt_error("mutt_error");
  errno = EHOSTUNREACH;
  mutt_perror("mutt_perror");

  // sha1
  struct Sha1Ctx s;
  sha1_init(&s);

  // string
  mutt_strlen("hello");

  // exit
  mutt_exit(42);

  return 0;
}
