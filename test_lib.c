#include <locale.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "mutt/mutt.h"

void test_base64(void)
{
  // int                 mutt_b64_decode             (char *out, const char *in);
  // size_t              mutt_b64_encode             (char *out, const char *cin, size_t len, size_t olen);

  char buffer[16];
  char *msg = "hello";
  mutt_b64_encode(buffer, msg, strlen(msg), sizeof(buffer));
}

void test_buffer(void)
{
  // size_t              mutt_buffer_addch           (struct Buffer *buf, char c);
  // size_t              mutt_buffer_addstr          (struct Buffer *buf, const char *s);
  // struct Buffer *     mutt_buffer_alloc           (size_t size);
  // void                mutt_buffer_free            (struct Buffer **p);
  // struct Buffer *     mutt_buffer_from            (char *seed);
  // struct Buffer *     mutt_buffer_init            (struct Buffer *b);
  // bool                mutt_buffer_is_empty        (const struct Buffer *buf);
  // struct Buffer *     mutt_buffer_new             (void);
  // int                 mutt_buffer_printf          (struct Buffer *buf, const char *fmt, ...);
  // void                mutt_buffer_reset           (struct Buffer *b);

  struct Buffer *b = NULL;
  mutt_buffer_free(&b);
}

void test_charset(void)
{
  // void                mutt_cs_canonical_charset   (char *buf, size_t buflen, const char *name);
  // const char *        mutt_cs_charset_lookup      (const char *chs);
  // bool                mutt_cs_check_charset       (const char *cs, bool strict);
  // int                 mutt_cs_chscmp              (const char *cs1, const char *cs2);
  // int                 mutt_cs_convert_string      (char **ps, const char *from, const char *to, int flags);
  // void                mutt_cs_fgetconv_close      (struct FgetConv **fc);
  // struct FgetConv *   mutt_cs_fgetconv_open       (FILE *file, const char *from, const char *to, int flags);
  // char *              mutt_cs_fgetconvs           (char *buf, size_t buflen, struct FgetConv *fc);
  // int                 mutt_cs_fgetconv            (struct FgetConv *fc);
  // char *              mutt_cs_get_default_charset (void);
  // size_t              mutt_cs_iconv               (iconv_t cd, const char **inbuf, size_t *inbytesleft, char **outbuf, size_t *outbytesleft, const char **inrepls, const char *outrepl);
  // const char *        mutt_cs_iconv_lookup        (const char *chs);
  // iconv_t             mutt_cs_iconv_open          (const char *tocode, const char *fromcode, int flags);
  // bool                mutt_cs_lookup_add          (enum LookupType type, const char *pat, const char *replace, struct Buffer *err);
  // void                mutt_cs_lookup_remove       (void);
  // void                mutt_cs_set_langinfo_charset(void);

  mutt_cs_chscmp("us-ascii", "utf-8");
}

void test_date(void)
{
  // int                 mutt_date_check_month       (const char *s);
  // bool                mutt_date_is_day_name       (const char *s);
  // time_t              mutt_date_local_tz          (time_t t);
  // char *              mutt_date_make_date         (char *buf, size_t buflen);
  // int                 mutt_date_make_imap         (char *buf, size_t buflen, time_t timestamp);
  // time_t              mutt_date_make_time         (struct tm *t, int local);
  // void                mutt_date_normalize_time    (struct tm *tm);
  // time_t              mutt_date_parse_date        (const char *s, struct Tz *tz_out);
  // time_t              mutt_date_parse_imap        (char *s);

  mutt_date_local_tz(1501596063);
}

void test_debug(void)
{
  // int                 mutt_debug                  (int level, ...);

  const char *user = "Will Robinson";
  mutt_debug(1, "Danger, %s!\n", user);
}

void test_file(void)
{
  // const char *        mutt_file_basename          (const char *f);
  // int                 mutt_file_check_empty       (const char *path);
  // int                 mutt_file_chmod_add         (const char *path, mode_t mode);
  // int                 mutt_file_chmod_add_stat    (const char *path, mode_t mode, struct stat *st);
  // int                 mutt_file_chmod             (const char *path, mode_t mode);
  // int                 mutt_file_chmod_rm          (const char *path, mode_t mode);
  // int                 mutt_file_chmod_rm_stat     (const char *path, mode_t mode, struct stat *st);
  // char *              mutt_file_concatn_path      (char *dst, size_t dstlen, const char *dir, size_t dirlen, const char *fname, size_t fnamelen);
  // char *              mutt_file_concat_path       (char *d, const char *dir, const char *fname, size_t l);
  // int                 mutt_file_copy_bytes        (FILE *in, FILE *out, size_t size);
  // int                 mutt_file_copy_stream       (FILE *fin, FILE *fout);
  // time_t              mutt_file_decrease_mtime    (const char *f, struct stat *st);
  // const char *        mutt_file_dirname           (const char *p);
  // int                 mutt_file_fclose            (FILE **f);
  // FILE *              mutt_file_fopen             (const char *path, const char *mode);
  // int                 mutt_file_fsync_close       (FILE **f);
  // int                 mutt_file_lock              (int fd, int excl, int timeout);
  // int                 mutt_file_mkdir             (const char *path, mode_t mode);
  // int                 mutt_file_open              (const char *path, int flags);
  // size_t              mutt_file_quote_filename    (char *d, size_t l, const char *f);
  // char *              mutt_file_read_keyword      (const char *file, char *buffer, size_t buflen);
  // char *              mutt_file_read_line         (char *s, size_t *size, FILE *fp, int *line, int flags);
  // int                 mutt_file_rename            (char *oldfile, char *newfile);
  // int                 mutt_file_rmtree            (const char *path);
  // int                 mutt_file_safe_rename       (const char *src, const char *target);
  // void                mutt_file_sanitize_filename (char *f, short slash);
  // int                 mutt_file_sanitize_regex    (char *dest, size_t destlen, const char *src);
  // void                mutt_file_set_mtime         (const char *from, const char *to);
  // int                 mutt_file_symlink           (const char *oldpath, const char *newpath);
  // int                 mutt_file_to_absolute_path  (char *path, const char *reference);
  // void                mutt_file_touch_atime       (int f);
  // void                mutt_file_unlink            (const char *s);
  // void                mutt_file_unlink_empty      (const char *path);
  // int                 mutt_file_unlock            (int fd);

  mutt_file_mkdir("tmp", 0660);
}

void test_hash(void)
{
  // struct Hash *       mutt_hash_create            (int nelem, int flags);
  // void                mutt_hash_delete            (struct Hash *table, const char *strkey, const void *data);
  // void                mutt_hash_destroy           (struct Hash **ptr);
  // struct HashElem *   mutt_hash_find_bucket       (const struct Hash *table, const char *strkey);
  // void *              mutt_hash_find              (const struct Hash *table, const char *strkey);
  // struct HashElem *   mutt_hash_find_elem         (const struct Hash *table, const char *strkey);
  // struct HashElem *   mutt_hash_insert            (struct Hash *table, const char *strkey, void *data);
  // struct Hash *       mutt_hash_int_create        (int nelem, int flags);
  // void                mutt_hash_int_delete        (struct Hash *table, unsigned int intkey, const void *data);
  // void *              mutt_hash_int_find          (const struct Hash *table, unsigned int intkey);
  // struct HashElem *   mutt_hash_int_insert        (struct Hash *table, unsigned int intkey, void *data);
  // void                mutt_hash_set_destructor    (struct Hash *hash, hash_destructor fn, intptr_t fn_data);
  // struct HashElem *   mutt_hash_typed_insert      (struct Hash *table, const char *strkey, int type, void *data);
  // struct HashElem *   mutt_hash_walk              (const struct Hash *table, struct HashWalkState *state);

  struct Hash *h = NULL;
  mutt_hash_destroy(&h);
}

void test_idna(void)
{
  // char *              mutt_idna_intl_to_local     (const char *user, const char *domain, int flags);
  // char *              mutt_idna_local_to_intl     (const char *user, const char *domain);
  // int                 mutt_idna_to_ascii_lz       (const char *input, char **output, int flags);

  setlocale(LC_ALL, "");

  char *mailbox = NULL;

  IdnEncode = true;
  IdnDecode = true;

  mutt_str_replace(&Charset, "utf-8");

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

  FREE(&Charset);

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

void test_list(void)
{
  // void                mutt_list_clear             (struct ListHead *h);
  // int                 mutt_list_compare           (const struct ListHead *ah, const struct ListHead *bh);
  // struct ListNode *   mutt_list_find              (struct ListHead *h, const char *data);
  // void                mutt_list_free              (struct ListHead *h);
  // struct ListNode *   mutt_list_insert_after      (struct ListHead *h, struct ListNode *n, char *s);
  // struct ListNode *   mutt_list_insert_head       (struct ListHead *h, char *s);
  // struct ListNode *   mutt_list_insert_tail       (struct ListHead *h, char *s);
  // bool                mutt_list_match             (const char *s, struct ListHead *h);

  struct ListHead head = STAILQ_HEAD_INITIALIZER(head);

  struct ListNode *node = mutt_list_find(&head, "hello");
  if (node)
    printf("found\n");
}

void test_mapping(void)
{
  // const char *        mutt_map_get_name           (int val, const struct Mapping *map);
  // int                 mutt_map_get_value          (const char *name, const struct Mapping *map);

  struct Mapping m[] = { { "apple", 1 }, { NULL, 0 } };

  mutt_map_get_name(1, m);
}

void test_mbyte(void)
{
  // int                 mutt_mb_charlen             (const char *s, int *width);
  // bool                mutt_mb_get_initials        (const char *name, char *buf, int buflen);
  // bool                mutt_mb_is_lower            (const char *s);
  // bool                mutt_mb_is_shell_char       (wchar_t ch);
  // size_t              mutt_mb_mbstowcs            (wchar_t **pwbuf, size_t *pwbuflen, size_t i, char *buf);
  // void                mutt_mb_wcstombs            (char *dest, size_t dlen, const wchar_t *src, size_t slen);
  // int                 mutt_mb_wcswidth            (const wchar_t *s, size_t n);
  // int                 mutt_mb_wcwidth             (wchar_t wc);
  // size_t              mutt_mb_width_ceiling       (const wchar_t *s, size_t n, int w1);
  // int                 mutt_mb_width               (const char *str, int col, bool display);

  mutt_mb_charlen("hello", NULL);
}

void test_md5(void)
{
  // void *              mutt_md5_buf                (const char *buffer, size_t len, void *resblock);
  // void *              mutt_md5_finish_ctx         (struct Md5Ctx *ctx, void *resbuf);
  // void                mutt_md5_init_ctx           (struct Md5Ctx *ctx);
  // void                mutt_md5_process_block      (const void *buffer, size_t len, struct Md5Ctx *ctx);
  // void                mutt_md5_process_bytes      (const void *buffer, size_t len, struct Md5Ctx *ctx);
  // void *              mutt_md5_read_ctx           (const struct Md5Ctx *ctx, void *resbuf);
  // int                 mutt_md5_stream             (FILE *stream, void *resblock);

  struct Md5Ctx m;
  mutt_md5_init_ctx(&m);
}

void test_memory(void)
{
  // void *              mutt_mem_calloc             (size_t nmemb, size_t size);
  // void                mutt_mem_free               (void *ptr);
  // void *              mutt_mem_malloc             (size_t size);
  // void                mutt_mem_realloc            (void *ptr, size_t size);

  void *ptr = NULL;
  FREE(&ptr);
}

void test_message(void)
{
  // void                mutt_error                  (const char *format, ...);
  // void                mutt_message                (const char *format, ...);
  // void                mutt_perror                 (const char *message);

  mutt_message("mutt_message");
  mutt_error("mutt_error");
  errno = EHOSTUNREACH;
  mutt_perror("mutt_perror");
}

void test_regex(void)
{
  // struct Regex *      mutt_regex_compile          (const char *str, int flags);
  // struct Regex *      mutt_regex_create           (const char *str, int flags, struct Buffer *err);
  // void                mutt_regex_free             (struct Regex **r);
  // int                 mutt_regexlist_add          (struct RegexList **rl, const char *str, int flags, struct Buffer *err);
  // void                mutt_regexlist_free         (struct RegexList **rl);
  // bool                mutt_regexlist_match        (struct RegexList *rl, const char *str);
  // struct RegexList *  mutt_regexlist_new          (void);
  // int                 mutt_regexlist_remove       (struct RegexList **rl, const char *str);
  // int                 mutt_replacelist_add        (struct ReplaceList **rl, const char *pat, const char *templ, struct Buffer *err);
  // char *              mutt_replacelist_apply      (struct ReplaceList *rl, char *buf, size_t buflen, const char *str);
  // void                mutt_replacelist_free       (struct ReplaceList **rl);
  // bool                mutt_replacelist_match      (struct ReplaceList *rl, char *buf, size_t buflen, const char *str);
  // struct ReplaceList *mutt_replacelist_new        (void);
  // int                 mutt_replacelist_remove     (struct ReplaceList **rl, const char *pat);

  struct Regex *rx = mutt_regex_compile("hel*o", 0);
  mutt_regex_free(&rx);
}

void test_sha1(void)
{
  // void                mutt_sha1_final             (unsigned char digest[20], struct Sha1Ctx *context);
  // void                mutt_sha1_init              (struct Sha1Ctx *context);
  // void                mutt_sha1_transform         (uint32_t state[5], const unsigned char buffer[64]);
  // void                mutt_sha1_update            (struct Sha1Ctx *context, const unsigned char *data, uint32_t len);

  struct Sha1Ctx s;
  mutt_sha1_init(&s);
}

void test_signal(void)
{
  // void                mutt_sig_allow_interrupt    (int disposition);
  // void                mutt_sig_block_system       (void);
  // void                mutt_sig_block              (void);
  // void                mutt_sig_empty_handler      (int sig);
  // void                mutt_sig_exit_handler       (int sig);
  // void                mutt_sig_init               (sig_handler_t sig_fn, sig_handler_t exit_fn);
  // void                mutt_sig_unblock_system     (int catch);
  // void                mutt_sig_unblock            (void);

  mutt_sig_unblock();
}

void test_string(void)
{
  // void                mutt_str_adjust             (char **p);
  // void                mutt_str_append_item        (char **p, const char *item, int sep);
  // int                 mutt_str_atoi               (const char *str, int *dst);
  // int                 mutt_str_atol               (const char *str, long *dst);
  // int                 mutt_str_atos               (const char *str, short *dst);
  // void                mutt_str_dequote_comment    (char *s);
  // const char *        mutt_str_find_word          (const char *src);
  // bool                mutt_str_is_ascii           (const char *p, size_t len);
  // int                 mutt_str_is_email_wsp       (char c);
  // size_t              mutt_str_lws_len            (const char *s, size_t n);
  // size_t              mutt_str_lws_rlen           (const char *s, size_t n);
  // const char *        mutt_str_next_word          (const char *s);
  // void                mutt_str_remove_trailing_ws (char *s);
  // void                mutt_str_replace            (char **p, const char *s);
  // const char *        mutt_str_rstrnstr           (const char *haystack, size_t haystack_length, const char *needle);
  // char *              mutt_str_skip_email_wsp     (const char *s);
  // char *              mutt_str_skip_whitespace    (char *p);
  // int                 mutt_str_strcasecmp         (const char *a, const char *b);
  // char *              mutt_str_strcat             (char *d, size_t l, const char *s);
  // const char *        mutt_str_strchrnul          (const char *s, char c);
  // int                 mutt_str_strcmp             (const char *a, const char *b);
  // int                 mutt_str_strcoll            (const char *a, const char *b);
  // char *              mutt_str_strdup             (const char *s);
  // char *              mutt_str_strfcpy            (char *dest, const char *src, size_t dlen);
  // const char *        mutt_str_stristr            (const char *haystack, const char *needle);
  // size_t              mutt_str_strlen             (const char *a);
  // char *              mutt_str_strlower           (char *s);
  // int                 mutt_str_strncasecmp        (const char *a, const char *b, size_t l);
  // char *              mutt_str_strncat            (char *d, size_t l, const char *s, size_t sl);
  // int                 mutt_str_strncmp            (const char *a, const char *b, size_t l);
  // char *              mutt_str_strnfcpy           (char *dest, char *src, size_t size, size_t dlen);
  // char *              mutt_str_substr_cpy         (char *dest, const char *begin, const char *end, size_t destlen);
  // char *              mutt_str_substr_dup         (const char *begin, const char *end);
  // const char *        mutt_str_sysexit            (int e);
  // int                 mutt_str_word_casecmp       (const char *a, const char *b);

  mutt_str_strlen("hello");
}

void test_exit(void)
{
  // void                mutt_exit                   (int code);

  mutt_exit(42);
}

int main()
{
  test_base64();
  test_buffer();
  test_charset();
  test_date();
  test_debug();
  test_file();
  test_hash();
  test_idna();
  test_list();
  test_mapping();
  test_mbyte();
  test_md5();
  test_memory();
  test_message();
  test_regex();
  test_sha1();
  test_signal();
  test_string();
  test_exit();

  return 0;
}

