#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "lib/lib.h"

void test_base64(void)
{
  // int               mutt_from_base64        (char *out, const char *in);
  // size_t            mutt_to_base64          (char *out, const char *cin, size_t len, size_t olen);

  char buffer[16];
  char *msg = "hello";
  mutt_to_base64(buffer, msg, strlen(msg), sizeof(buffer));
}

void test_buffer(void)
{
  // void              mutt_buffer_addch       (struct Buffer *buf, char c);
  // void              mutt_buffer_addstr      (struct Buffer *buf, const char *s);
  // void              mutt_buffer_free        (struct Buffer **p);
  // struct Buffer *   mutt_buffer_from        (char *seed);
  // struct Buffer *   mutt_buffer_init        (struct Buffer *b);
  // struct Buffer *   mutt_buffer_new         (void);
  // int               mutt_buffer_printf      (struct Buffer *buf, const char *fmt, ...);
  // void              mutt_buffer_reset       (struct Buffer *b);

  struct Buffer *b = NULL;
  mutt_buffer_free(&b);
}

void test_date(void)
{
  // int               imap_make_date          (char *buf, size_t buflen, time_t timestamp);
  // time_t            imap_parse_date         (char *s);
  // bool              is_day_name             (const char *s);
  // int               mutt_check_month        (const char *s);
  // time_t            mutt_local_tz           (time_t t);
  // char *            mutt_make_date          (char *buf, size_t buflen);
  // time_t            mutt_mktime             (struct tm *t, int local);
  // void              mutt_normalize_time     (struct tm *tm);
  // time_t            mutt_parse_date         (const char *s, struct Tz *tz_out);

  mutt_local_tz(1501596063);
}

void test_debug(void)
{
  // void              mutt_debug              (int level, const char *fmt, ...);

  const char *user = "Will Robinson";
  mutt_debug(1, "Danger, %s!\n", user);
}

void test_file(void)
{
  // const char *      mutt_basename           (const char *f);
  // char *            mutt_concatn_path       (char *dst, size_t dstlen, const char *dir, size_t dirlen, const char *fname, size_t fnamelen);
  // char *            mutt_concat_path        (char *d, const char *dir, const char *fname, size_t l);
  // int               mutt_copy_bytes         (FILE *in, FILE *out, size_t size);
  // int               mutt_copy_stream        (FILE *fin, FILE *fout);
  // time_t            mutt_decrease_mtime     (const char *f, struct stat *st);
  // int               mutt_lock_file          (const char *path, int fd, int excl, int timeout);
  // int               mutt_mkdir              (const char *path, mode_t mode);
  // size_t            mutt_quote_filename     (char *d, size_t l, const char *f);
  // char *            mutt_read_line          (char *s, size_t *size, FILE *fp, int *line, int flags);
  // int               mutt_regex_sanitize_string(char *dest, size_t destlen, const char *src);
  // int               mutt_rmtree             (const char *path);
  // void              mutt_sanitize_filename  (char *f, short slash);
  // void              mutt_set_mtime          (const char *from, const char *to);
  // void              mutt_touch_atime        (int f);
  // void              mutt_unlink             (const char *s);
  // void              mutt_unlink_empty       (const char *path);
  // int               mutt_unlock_file        (const char *path, int fd);
  // int               safe_fclose             (FILE **f);
  // FILE *            safe_fopen              (const char *path, const char *mode);
  // int               safe_fsync_close        (FILE **f);
  // int               safe_open               (const char *path, int flags);
  // int               safe_rename             (const char *src, const char *target);
  // int               safe_symlink            (const char *oldpath, const char *newpath);

  mutt_mkdir("tmp", 0660);
}

void test_hash(void)
{
  // struct Hash *     hash_create             (int nelem, int flags);
  // void              hash_delete             (struct Hash *table, const char *strkey, const void *data, void (*destroy)(void *));
  // void              hash_destroy            (struct Hash **ptr, void (*destroy)(void *));
  // struct HashElem * hash_find_bucket        (const struct Hash *table, const char *strkey);
  // void *            hash_find               (const struct Hash *table, const char *strkey);
  // struct HashElem * hash_find_elem          (const struct Hash *table, const char *strkey);
  // int               hash_insert             (struct Hash *table, const char *strkey, void *data);
  // struct HashElem * hash_walk               (const struct Hash *table, struct HashWalkState *state);
  // struct Hash *     int_hash_create         (int nelem, int flags);
  // void              int_hash_delete         (struct Hash *table, unsigned int intkey, const void *data, void (*destroy)(void *));
  // void *            int_hash_find           (const struct Hash *table, unsigned int intkey);
  // int               int_hash_insert         (struct Hash *table, unsigned int intkey, void *data);

  struct Hash *h = NULL;
  hash_destroy(&h, NULL);
}

void test_mapping(void)
{
  // const char *      mutt_getnamebyvalue     (int val, const struct Mapping *map);
  // int               mutt_getvaluebyname     (const char *name, const struct Mapping *map);

  struct Mapping m[] = { { "apple", 1 }, { NULL, 0 } };

  mutt_getnamebyvalue(1, m);
}

void test_md5 (void)
{
  // void *            md5_buffer              (const char *buffer, size_t len, void *resblock);
  // void *            md5_finish_ctx          (struct Md5Ctx *ctx, void *resbuf);
  // void              md5_init_ctx            (struct Md5Ctx *ctx);
  // void              md5_process_block       (const void *buffer, size_t len, struct Md5Ctx *ctx);
  // void              md5_process_bytes       (const void *buffer, size_t len, struct Md5Ctx *ctx);
  // void *            md5_read_ctx            (const struct Md5Ctx *ctx, void *resbuf);
  // int               md5_stream              (FILE *stream, void *resblock);

  struct Md5Ctx m;
  md5_init_ctx(&m);
}

void test_memory(void)
{
  // void *            safe_calloc             (size_t nmemb, size_t size);
  // void              safe_free               (void *ptr);
  // void *            safe_malloc             (size_t size);
  // void              safe_realloc            (void *ptr, size_t size);

  void *ptr = NULL;
  FREE(&ptr);
}

void test_message(void)
{
  // void              mutt_error              (const char *format, ...);
  // void              mutt_message            (const char *format, ...);
  // void              mutt_perror             (const char *message);

  mutt_message("mutt_message");
  mutt_error("mutt_error");
  errno = EHOSTUNREACH;
  mutt_perror("mutt_perror");
}

void test_sha1(void)
{
  // void              sha1_final              (unsigned char digest[20], struct Sha1Ctx *context);
  // void              sha1_init               (struct Sha1Ctx *context);
  // void              sha1_transform          (uint32_t state[5], const unsigned char buffer[64]);
  // void              sha1_update             (struct Sha1Ctx *context, const unsigned char *data, uint32_t len);

  struct Sha1Ctx s;
  sha1_init(&s);
}

void test_string(void)
{
  // int               imap_wordcasecmp        (const char *a, const char *b);
  // int               is_email_wsp            (char c);
  // size_t            lwslen                  (const char *s, size_t n);
  // size_t            lwsrlen                 (const char *s, size_t n);
  // int               mutt_atoi               (const char *str, int *dst);
  // int               mutt_atos               (const char *str, short *dst);
  // void              mutt_remove_trailing_ws (char *s);
  // char *            mutt_skip_whitespace    (char *p);
  // void              mutt_str_adjust         (char **p);
  // void              mutt_str_append_item    (char **p, const char *item, int sep);
  // int               mutt_strcasecmp         (const char *a, const char *b);
  // const char *      mutt_strchrnul          (const char *s, char c);
  // int               mutt_strcmp             (const char *a, const char *b);
  // int               mutt_strcoll            (const char *a, const char *b);
  // const char *      mutt_stristr            (const char *haystack, const char *needle);
  // size_t            mutt_strlen             (const char *a);
  // char *            mutt_strlower           (char *s);
  // int               mutt_strncasecmp        (const char *a, const char *b, size_t l);
  // int               mutt_strncmp            (const char *a, const char *b, size_t l);
  // void              mutt_str_replace        (char **p, const char *s);
  // char *            mutt_substrcpy          (char *dest, const char *begin, const char *end, size_t destlen);
  // char *            mutt_substrdup          (const char *begin, const char *end);
  // const char *      next_word               (const char *s);
  // void              rfc822_dequote_comment  (char *s);
  // const char *      rstrnstr                (const char *haystack, size_t haystack_length, const char *needle);
  // char *            safe_strcat             (char *d, size_t l, const char *s);
  // char *            safe_strdup             (const char *s);
  // char *            safe_strncat            (char *d, size_t l, const char *s, size_t sl);
  // char *            skip_email_wsp          (const char *s);
  // char *            strfcpy                 (char *dest, const char *src, size_t dlen);
  // char *            strnfcpy                (char *dest, char *src, size_t size, size_t dlen);

  mutt_strlen("hello");
}

void test_exit(void)
{
  // void              mutt_exit               (int code);

  mutt_exit(42);
}

int main()
{
  test_base64();
  test_buffer();
  test_date();
  test_debug();
  test_file();
  test_hash();
  test_mapping();
  test_md5();
  test_memory();
  test_message();
  test_sha1();
  test_string();
  test_exit();

  return 0;
}

