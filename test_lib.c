#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "lib/lib.h"

int main()
{
  // memory
  void *ptr = NULL;
  FREE(&ptr);

  // buffer
  struct Buffer *b = NULL;
  mutt_buffer_free(&b);

  // file
  mutt_mkdir("tmp", 0660);

  // md5
  struct Md5Ctx m;
  md5_init_ctx(&m);

  // date
  mutt_local_tz(1501596063);

  // string
  mutt_strlen("hello");

  // hash
  struct Hash *h = NULL;
  hash_destroy(&h, NULL);

  // ascii
  ascii_strcasecmp("apple", "orange");

  // sha1
  struct Sha1Ctx s;
  sha1_init(&s);

  // base64
  char buffer[16];
  char *msg = "hello";
  mutt_to_base64(buffer, msg, strlen(msg), sizeof(buffer));

  mutt_message("mutt_message");
  mutt_error("mutt_error");
  errno = EHOSTUNREACH;
  mutt_perror("mutt_perror");

  // printf("done\n");
  return 0;
}
