#include "config.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mutt/lib.h"
#include "email/lib.h"
#include "hcache/lib.h"

bool C_Autocrypt;
struct ConfigDef;

struct Context *Context = NULL;

struct Mailbox *ctx_mailbox(struct Context *ctx)
{
  return ctx ? ctx->mailbox : NULL;
}

void nm_edata_free(void **ptr)
{
}

void hcache_per_folder(struct Buffer *hcpath, const char *path,
                       const char *folder, hcache_namer_t namer)
{
}

void buf_encode_path(struct Buffer *buf, const char *src)
{
}

int mutt_autocrypt_process_autocrypt_header(struct Email *e, struct Envelope *env)
{
  return -1;
}

int url_parse_mailto(struct Envelope *e, char **body, const char *src)
{
  return -1;
}

int mutt_convert_string(char **ps, const char *from, const char *to, int flags)
{
  printf("mutt_convert_string\n");
  return -1;
}

void mutt_encode_path(struct Buffer *buf, const char *src)
{
  char *copy = strdup(src);
  buf_strcpy(buf, copy);
  printf("mutt_encode_path: %s\n", buf_string(buf));
  FREE(&copy);
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

int main()
{
#if 0
  const char *name = "lmdb";
  printf("%s is %svalid\n", name, mutt_hcache_is_valid_backend(name) ? "" : "not ");
#endif

  struct HeaderCache *hc = NULL;
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
  mutt_hcache_free(hc, (void **) &data);
#endif

  mutt_hcache_close(hc);

  return 0;
}
