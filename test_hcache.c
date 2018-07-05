#include "config.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "mutt/mutt.h"
#include "hcache/hcache.h"

bool HeaderCacheCompress;
char *HeaderCachePagesize;

struct Address *mutt_addr_new(void)
{
  return NULL;
}

struct Body *mutt_body_new(void)
{
  return NULL;
}

struct Header *mutt_header_new(void)
{
  return NULL;
}

struct Envelope *mutt_env_new(void)
{
  return NULL;
}

int mutt_convert_string(char **ps, const char *from, const char *to, int flags)
{
  printf("mutt_convert_string\n");
  return -1;
}

void mutt_encode_path(char *dest, size_t dlen, const char *src)
{
  mutt_str_strfcpy(dest, src, dlen);
  printf("mutt_encode_path: %s\n", src);
}

struct Body *mutt_new_body(void)
{
  printf("mutt_new_body\n");
  return NULL;
}

void mutt_sleep(short s)
{
  printf("mutt_sleep\n");
}

int mx_lock_file(const char *path, int fd, int excl, int timeout)
{
  printf("mx_lock_file\n");
  return -1;
}

int mx_unlock_file(const char *path, int fd)
{
  printf("mx_unlock_file\n");
  return -1;
}


char *Charset;
char *HeaderCacheBackend;
char *HeaderCachePageSize;
unsigned char Options[50];
struct ReplaceList *SpamList;
struct RxList *NoSpamList;

int main()
{
#if 0
  const char *name = "lmdb";
  printf("%s is %svalid\n", name, mutt_hcache_is_valid_backend(name) ? "" : "not ");
#endif

  header_cache_t *hc = NULL;
  const char *path = "cache/";
  const char *folder = "test";
  
  hc = mutt_hcache_open(path, folder, NULL);
  // printf("%p\n", hc);

  char *key = "name";
  char *data = NULL;
#if 1
  int rc = -1;
  data = "The quick brown fox jumps over a lazy dog.";
  rc = mutt_hcache_store_raw(hc, key, strlen(key), data, strlen(data) + 1);
  printf("rc = %d\n", rc);
#else
  data = mutt_hcache_fetch_raw(hc, key, strlen(key));
  printf("data = '%s'\n", data);
  mutt_hcache_free(hc, (void**) &data);
#endif

  mutt_hcache_close(hc);

  return 0;
}

