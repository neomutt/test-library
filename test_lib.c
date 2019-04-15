#include "config.h"
#include <errno.h>
#include <locale.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mutt/mutt.h"

void test_base64(void)
{
  // const int Index64[];

  // int                     mutt_b64_buffer_decode            (struct Buffer *buf, const char *in);
  // size_t                  mutt_b64_buffer_encode            (struct Buffer *buf, const char *in, size_t len);
  // int                     mutt_b64_decode                   (const char *in, char *out, size_t olen);
  // size_t                  mutt_b64_encode                   (const char *in, size_t inlen, char *out, size_t outlen);

  char buffer[16];
  char *msg = "hello";
  mutt_b64_encode(msg, strlen(msg), buffer, sizeof(buffer));
}

void test_buffer(void)
{
  // int                     mutt_buffer_add_printf            (struct Buffer *buf, const char *fmt, ...);
  // size_t                  mutt_buffer_addch                 (struct Buffer *buf, char c);
  // size_t                  mutt_buffer_addstr                (struct Buffer *buf, const char *s);
  // size_t                  mutt_buffer_addstr_n              (struct Buffer *buf, const char *s, size_t len);
  // struct Buffer *         mutt_buffer_alloc                 (size_t size);
  // void                    mutt_buffer_fix_dptr              (struct Buffer *buf);
  // void                    mutt_buffer_free                  (struct Buffer **p);
  // struct Buffer *         mutt_buffer_from                  (const char *seed);
  // void                    mutt_buffer_increase_size         (struct Buffer *buf, size_t new_size);
  // struct Buffer *         mutt_buffer_init                  (struct Buffer *buf);
  // bool                    mutt_buffer_is_empty              (const struct Buffer *buf);
  // size_t                  mutt_buffer_len                   (const struct Buffer *buf);
  // struct Buffer *         mutt_buffer_new                   (void);
  // void                    mutt_buffer_pool_free             (void);
  // struct Buffer *         mutt_buffer_pool_get              (void);
  // void                    mutt_buffer_pool_init             (void);
  // void                    mutt_buffer_pool_release          (struct Buffer **pbuf);
  // int                     mutt_buffer_printf                (struct Buffer *buf, const char *fmt, ...);
  // void                    mutt_buffer_reset                 (struct Buffer *buf);
  // void                    mutt_buffer_strcpy                (struct Buffer *buf, const char *s);
  // void                    mutt_buffer_strcpy_n              (struct Buffer *buf, const char *s, size_t len);

  struct Buffer *b = NULL;
  mutt_buffer_free(&b);
}

void test_charset(void)
{
  // char *C_AssumedCharset;
  // char *C_Charset;
  // bool CharsetIsUtf8;
  // wchar_t ReplacementChar;
  // const struct MimeNames PreferredMimeNames[];

  // void                    mutt_ch_canonical_charset         (char *buf, size_t buflen, const char *name);
  // const char *            mutt_ch_charset_lookup            (const char *chs);
  // int                     mutt_ch_check                     (const char *s, size_t slen, const char *from, const char *to);
  // bool                    mutt_ch_check_charset             (const char *cs, bool strict);
  // char *                  mutt_ch_choose                    (const char *fromcode, const char *charsets, const char *u, size_t ulen, char **d, size_t *dlen);
  // bool                    mutt_ch_chscmp                    (const char *cs1, const char *cs2);
  // int                     mutt_ch_convert_nonmime_string    (char **ps);
  // int                     mutt_ch_convert_string            (char **ps, const char *from, const char *to, int flags);
  // int                     mutt_ch_fgetconv                  (struct FgetConv *fc);
  // void                    mutt_ch_fgetconv_close            (struct FgetConv **fc);
  // struct FgetConv *       mutt_ch_fgetconv_open             (FILE *fp, const char *from, const char *to, int flags);
  // char *                  mutt_ch_fgetconvs                 (char *buf, size_t buflen, struct FgetConv *fc);
  // char *                  mutt_ch_get_default_charset       (void);
  // char *                  mutt_ch_get_langinfo_charset      (void);
  // size_t                  mutt_ch_iconv                     (iconv_t cd, const char **inbuf, size_t *inbytesleft, char **outbuf, size_t *outbytesleft, const char **inrepls, const char *outrepl, int *iconverrno);
  // const char *            mutt_ch_iconv_lookup              (const char *chs);
  // iconv_t                 mutt_ch_iconv_open                (const char *tocode, const char *fromcode, int flags);
  // bool                    mutt_ch_lookup_add                (enum LookupType type, const char *pat, const char *replace, struct Buffer *err);
  // void                    mutt_ch_lookup_remove             (void);
  // void                    mutt_ch_set_charset               (const char *charset);

  mutt_ch_chscmp("us-ascii", "utf-8");
}

void test_date(void)
{
  // time_t                  mutt_date_add_timeout             (time_t now, long timeout);
  // int                     mutt_date_check_month             (const char *s);
  // struct tm               mutt_date_gmtime                  (time_t t);
  // bool                    mutt_date_is_day_name             (const char *s);
  // time_t                  mutt_date_local_tz                (time_t t);
  // struct tm               mutt_date_localtime               (time_t t);
  // size_t                  mutt_date_localtime_format        (char *buf, size_t buflen, char *format, time_t t);
  // char *                  mutt_date_make_date               (char *buf, size_t buflen);
  // int                     mutt_date_make_imap               (char *buf, size_t buflen, time_t timestamp);
  // time_t                  mutt_date_make_time               (struct tm *t, int local);
  // int                     mutt_date_make_tls                (char *buf, size_t buflen, time_t timestamp);
  // void                    mutt_date_normalize_time          (struct tm *tm);
  // time_t                  mutt_date_parse_date              (const char *s, struct Tz *tz_out);
  // time_t                  mutt_date_parse_imap              (const char *s);

  mutt_date_local_tz(1501596063);
}

void test_envlist(void)
{
  // void                    mutt_envlist_free                 (void);
  // char **                 mutt_envlist_getlist              (void);
  // void                    mutt_envlist_init                 (char *envp[]);
  // bool                    mutt_envlist_set                  (const char *name, const char *value, bool overwrite);
  // bool                    mutt_envlist_unset                (const char *name);

  char *dummy[] = { "apple", "banana", "cherry", NULL };

  mutt_envlist_init(dummy);
  mutt_envlist_free();
}

void test_file(void)
{
  // char *C_Tmpdir;

  // int                     mutt_file_check_empty             (const char *path);
  // int                     mutt_file_chmod                   (const char *path, mode_t mode);
  // int                     mutt_file_chmod_add               (const char *path, mode_t mode);
  // int                     mutt_file_chmod_add_stat          (const char *path, mode_t mode, struct stat *st);
  // int                     mutt_file_chmod_rm                (const char *path, mode_t mode);
  // int                     mutt_file_chmod_rm_stat           (const char *path, mode_t mode, struct stat *st);
  // int                     mutt_file_copy_bytes              (FILE *fp_in, FILE *fp_out, size_t size);
  // int                     mutt_file_copy_stream             (FILE *fp_in, FILE *fp_out);
  // time_t                  mutt_file_decrease_mtime          (const char *fp, struct stat *st);
  // void                    mutt_file_expand_fmt              (char *dest, size_t destlen, const char *fmt, const char *src);
  // void                    mutt_file_expand_fmt_quote        (char *dest, size_t destlen, const char *fmt, const char *src);
  // int                     mutt_file_fclose                  (FILE **fp);
  // FILE *                  mutt_file_fopen                   (const char *path, const char *mode);
  // int                     mutt_file_fsync_close             (FILE **fp);
  // long                    mutt_file_get_size                (const char *path);
  // void                    mutt_file_get_stat_timespec       (struct timespec *dest, struct stat *sb, enum MuttStatType type);
  // bool                    mutt_file_iter_line               (struct MuttFileIter *iter, FILE *fp, int flags);
  // int                     mutt_file_lock                    (int fd, bool excl, bool timeout);
  // bool                    mutt_file_map_lines               (mutt_file_map_t func, void *user_data, FILE *fp, int flags);
  // int                     mutt_file_mkdir                   (const char *path, mode_t mode);
  // FILE *                  mutt_file_mkstemp_full            (const char *file, int line, const char *func);
  // int                     mutt_file_open                    (const char *path, int flags);
  // size_t                  mutt_file_quote_filename          (const char *filename, char *buf, size_t buflen);
  // char *                  mutt_file_read_keyword            (const char *file, char *buf, size_t buflen);
  // char *                  mutt_file_read_line               (char *line, size_t *size, FILE *fp, int *line_num, int flags);
  // int                     mutt_file_rename                  (const char *oldfile, const char *newfile);
  // int                     mutt_file_rmtree                  (const char *path);
  // int                     mutt_file_safe_rename             (const char *src, const char *target);
  // void                    mutt_file_sanitize_filename       (char *fp, bool slash);
  // int                     mutt_file_sanitize_regex          (struct Buffer *dest, const char *src);
  // void                    mutt_file_set_mtime               (const char *from, const char *to);
  // int                     mutt_file_stat_compare            (struct stat *sba, enum MuttStatType sba_type, struct stat *sbb, enum MuttStatType sbb_type);
  // int                     mutt_file_stat_timespec_compare   (struct stat *sba, enum MuttStatType type, struct timespec *b);
  // int                     mutt_file_symlink                 (const char *oldpath, const char *newpath);
  // int                     mutt_file_timespec_compare        (struct timespec *a, struct timespec *b);
  // void                    mutt_file_touch_atime             (int fd);
  // void                    mutt_file_unlink                  (const char *s);
  // void                    mutt_file_unlink_empty            (const char *path);
  // int                     mutt_file_unlock                  (int fd);

  mutt_file_mkdir("tmp", 0660);
}

void test_hash(void)
{
  // void                    mutt_hash_delete                  (struct Hash *table, const char *strkey, const void *data);
  // void *                  mutt_hash_find                    (const struct Hash *table, const char *strkey);
  // struct HashElem *       mutt_hash_find_bucket             (const struct Hash *table, const char *strkey);
  // struct HashElem *       mutt_hash_find_elem               (const struct Hash *table, const char *strkey);
  // void                    mutt_hash_free                    (struct Hash **ptr);
  // struct HashElem *       mutt_hash_insert                  (struct Hash *table, const char *strkey, void *data);
  // void                    mutt_hash_int_delete              (struct Hash *table, unsigned int intkey, const void *data);
  // void *                  mutt_hash_int_find                (const struct Hash *table, unsigned int intkey);
  // struct HashElem *       mutt_hash_int_insert              (struct Hash *table, unsigned int intkey, void *data);
  // struct Hash *           mutt_hash_int_new                 (size_t nelem, HashFlags flags);
  // struct Hash *           mutt_hash_new                     (size_t nelem, HashFlags flags);
  // void                    mutt_hash_set_destructor          (struct Hash *table, hashelem_free_t fn, intptr_t fn_data);
  // struct HashElem *       mutt_hash_typed_insert            (struct Hash *table, const char *strkey, int type, void *data);
  // struct HashElem *       mutt_hash_walk                    (const struct Hash *table, struct HashWalkState *state);

  struct Hash *h = NULL;
  mutt_hash_free(&h);
}

void test_history(void)
{
  // short C_History;
  // char *C_HistoryFile;
  // bool C_HistoryRemoveDups;
  // short C_SaveHistory;

  // void                    mutt_hist_add                     (enum HistoryClass hclass, const char *str, bool save);
  // bool                    mutt_hist_at_scratch              (enum HistoryClass hclass);
  // void                    mutt_hist_free                    (void);
  // void                    mutt_hist_init                    (void);
  // char *                  mutt_hist_next                    (enum HistoryClass hclass);
  // char *                  mutt_hist_prev                    (enum HistoryClass hclass);
  // void                    mutt_hist_read_file               (void);
  // void                    mutt_hist_reset_state             (enum HistoryClass hclass);
  // void                    mutt_hist_save_scratch            (enum HistoryClass hclass, const char *str);
  // int                     mutt_hist_search                  (const char *search_buf, enum HistoryClass hclass, char **matches);

  mutt_hist_free();
}

void test_list(void)
{
  // void                    mutt_list_clear                   (struct ListHead *h);
  // bool                    mutt_list_compare                 (const struct ListHead *ah, const struct ListHead *bh);
  // struct ListNode *       mutt_list_find                    (const struct ListHead *h, const char *data);
  // void                    mutt_list_free                    (struct ListHead *h);
  // void                    mutt_list_free_type               (struct ListHead *h, list_free_t fn);
  // struct ListNode *       mutt_list_insert_after            (struct ListHead *h, struct ListNode *n, char *s);
  // struct ListNode *       mutt_list_insert_head             (struct ListHead *h, char *s);
  // struct ListNode *       mutt_list_insert_tail             (struct ListHead *h, char *s);
  // bool                    mutt_list_match                   (const char *s, struct ListHead *h);

  struct ListHead head = STAILQ_HEAD_INITIALIZER(head);

  struct ListNode *node = mutt_list_find(&head, "hello");
  if (node)
    printf("found\n");
}

void test_logging(void)
{
  // log_dispatcher_t MuttLogger;

  // int                     log_disp_file                     (time_t stamp, const char *file, int line, const char *function, int level, ...);
  // int                     log_disp_queue                    (time_t stamp, const char *file, int line, const char *function, int level, ...);
  // int                     log_disp_terminal                 (time_t stamp, const char *file, int line, const char *function, int level, ...);
  // void                    log_file_close                    (bool verbose);
  // int                     log_file_open                     (bool verbose);
  // bool                    log_file_running                  (void);
  // int                     log_file_set_filename             (const char *file, bool verbose);
  // int                     log_file_set_level                (int level, bool verbose);
  // void                    log_file_set_version              (const char *version);
  // int                     log_queue_add                     (struct LogLine *ll);
  // void                    log_queue_empty                   (void);
  // void                    log_queue_flush                   (log_dispatcher_t disp);
  // int                     log_queue_save                    (FILE *fp);
  // void                    log_queue_set_max_size            (int size);

  log_file_set_level(3, false);
}

void test_mapping(void)
{
  // const char *            mutt_map_get_name                 (int val, const struct Mapping *map);
  // int                     mutt_map_get_value                (const char *name, const struct Mapping *map);

  struct Mapping m[] = { { "apple", 1 }, { NULL, 0 } };

  mutt_map_get_name(1, m);
}

void test_mbyte(void)
{
  // bool OptLocales;

  // int                     mutt_mb_charlen                   (const char *s, int *width);
  // int                     mutt_mb_filter_unprintable        (char **s);
  // bool                    mutt_mb_get_initials              (const char *name, char *buf, size_t buflen);
  // bool                    mutt_mb_is_display_corrupting_utf8(wchar_t wc);
  // bool                    mutt_mb_is_lower                  (const char *s);
  // bool                    mutt_mb_is_shell_char             (wchar_t ch);
  // size_t                  mutt_mb_mbstowcs                  (wchar_t **pwbuf, size_t *pwbuflen, size_t i, char *buf);
  // void                    mutt_mb_wcstombs                  (char *dest, size_t dlen, const wchar_t *src, size_t slen);
  // int                     mutt_mb_wcswidth                  (const wchar_t *s, size_t n);
  // int                     mutt_mb_wcwidth                   (wchar_t wc);
  // int                     mutt_mb_width                     (const char *str, int col, bool display);
  // size_t                  mutt_mb_width_ceiling             (const wchar_t *s, size_t n, int w1);

  mutt_mb_charlen("hello", NULL);
}

void test_md5(void)
{
  // void *                  mutt_md5                          (const char *str, void *buf);
  // void *                  mutt_md5_bytes                    (const void *buffer, size_t len, void *resbuf);
  // void *                  mutt_md5_finish_ctx               (struct Md5Ctx *md5ctx, void *resbuf);
  // void                    mutt_md5_init_ctx                 (struct Md5Ctx *md5ctx);
  // void                    mutt_md5_process                  (const char *str, struct Md5Ctx *md5ctx);
  // void                    mutt_md5_process_bytes            (const void *buffer, size_t len, struct Md5Ctx *md5ctx);
  // void                    mutt_md5_toascii                  (const void *digest, char *resbuf);

  struct Md5Ctx m;
  mutt_md5_init_ctx(&m);
}

void test_memory(void)
{
  // void *                  mutt_mem_calloc                   (size_t nmemb, size_t size);
  // void                    mutt_mem_free                     (void *ptr);
  // void *                  mutt_mem_malloc                   (size_t size);
  // void                    mutt_mem_realloc                  (void *ptr, size_t size);

  void *ptr = NULL;
  FREE(&ptr);
}

void test_path(void)
{
  // bool                    mutt_path_abbr_folder             (char *buf, size_t buflen, const char *folder);
  // const char *            mutt_path_basename                (const char *f);
  // bool                    mutt_path_canon                   (char *buf, size_t buflen, const char *homedir);
  // char *                  mutt_path_concat                  (char *d, const char *dir, const char *fname, size_t l);
  // char *                  mutt_path_concatn                 (char *dst, size_t dstlen, const char *dir, size_t dirlen, const char *fname, size_t fnamelen);
  // char *                  mutt_path_dirname                 (const char *path);
  // char *                  mutt_path_escape                  (const char *src);
  // bool                    mutt_path_parent                  (char *buf, size_t buflen);
  // bool                    mutt_path_pretty                  (char *buf, size_t buflen, const char *homedir);
  // size_t                  mutt_path_realpath                (char *buf);
  // bool                    mutt_path_tidy                    (char *buf);
  // bool                    mutt_path_tidy_dotdot             (char *buf);
  // bool                    mutt_path_tidy_slash              (char *buf);
  // int                     mutt_path_to_absolute             (char *path, const char *reference);

  mutt_path_basename("/home/mutt/file");
}

void test_regex(void)
{
  // struct Regex *          mutt_regex_compile                (const char *str, int flags);
  // void                    mutt_regex_free                   (struct Regex **r);
  // struct Regex *          mutt_regex_new                    (const char *str, int flags, struct Buffer *err);
  // int                     mutt_regexlist_add                (struct RegexList *rl, const char *str, int flags, struct Buffer *err);
  // void                    mutt_regexlist_free               (struct RegexList *rl);
  // bool                    mutt_regexlist_match              (struct RegexList *rl, const char *str);
  // struct RegexListNode *  mutt_regexlist_new                (void);
  // int                     mutt_regexlist_remove             (struct RegexList *rl, const char *str);
  // int                     mutt_replacelist_add              (struct ReplaceList *rl, const char *pat, const char *templ, struct Buffer *err);
  // char *                  mutt_replacelist_apply            (struct ReplaceList *rl, char *buf, size_t buflen, const char *str);
  // void                    mutt_replacelist_free             (struct ReplaceList *rl);
  // bool                    mutt_replacelist_match            (struct ReplaceList *rl, char *buf, size_t buflen, const char *str);
  // struct ReplaceListNode *mutt_replacelist_new              (void);
  // int                     mutt_replacelist_remove           (struct ReplaceList *rl, const char *pat);

  struct Regex *rx = mutt_regex_compile("hel*o", 0);
  mutt_regex_free(&rx);
}

void test_sha1(void)
{
  // void                    mutt_sha1_final                   (unsigned char digest[20], struct Sha1Ctx *sha1ctx);
  // void                    mutt_sha1_init                    (struct Sha1Ctx *sha1ctx);
  // void                    mutt_sha1_transform               (uint32_t state[5], const unsigned char buffer[64]);
  // void                    mutt_sha1_update                  (struct Sha1Ctx *sha1ctx, const unsigned char *data, uint32_t len);

  struct Sha1Ctx s;
  mutt_sha1_init(&s);
}

void test_signal(void)
{
  // void                    mutt_sig_allow_interrupt          (bool allow);
  // void                    mutt_sig_block                    (void);
  // void                    mutt_sig_block_system             (void);
  // void                    mutt_sig_empty_handler            (int sig);
  // void                    mutt_sig_exit_handler             (int sig);
  // void                    mutt_sig_init                     (sig_handler_t sig_fn, sig_handler_t exit_fn);
  // void                    mutt_sig_unblock                  (void);
  // void                    mutt_sig_unblock_system           (bool catch);

  mutt_sig_unblock();
}

void test_string(void)
{
  // void                    mutt_str_adjust                   (char **p);
  // void                    mutt_str_append_item              (char **str, const char *item, int sep);
  // int                     mutt_str_asprintf                 (char **strp, const char *fmt, ...);
  // int                     mutt_str_atoi                     (const char *str, int *dst);
  // int                     mutt_str_atol                     (const char *str, long *dst);
  // int                     mutt_str_atos                     (const char *str, short *dst);
  // int                     mutt_str_atoui                    (const char *str, unsigned int *dst);
  // int                     mutt_str_atoul                    (const char *str, unsigned long *dst);
  // int                     mutt_str_atoull                   (const char *str, unsigned long long *dst);
  // void                    mutt_str_dequote_comment          (char *s);
  // const char *            mutt_str_find_word                (const char *src);
  // const char *            mutt_str_getenv                   (const char *name);
  // bool                    mutt_str_inline_replace           (char *buf, size_t buflen, size_t xlen, const char *rstr);
  // bool                    mutt_str_is_ascii                 (const char *p, size_t len);
  // bool                    mutt_str_is_email_wsp             (char c);
  // size_t                  mutt_str_lws_len                  (const char *s, size_t n);
  // size_t                  mutt_str_lws_rlen                 (const char *s, size_t n);
  // const char *            mutt_str_next_word                (const char *s);
  // void                    mutt_str_pretty_size              (char *buf, size_t buflen, size_t num);
  // int                     mutt_str_remall_strcasestr        (char *str, const char *target);
  // void                    mutt_str_remove_trailing_ws       (char *s);
  // void                    mutt_str_replace                  (char **p, const char *s);
  // const char *            mutt_str_rstrnstr                 (const char *haystack, size_t haystack_length, const char *needle);
  // char *                  mutt_str_skip_email_wsp           (const char *s);
  // char *                  mutt_str_skip_whitespace          (char *p);
  // struct ListHead         mutt_str_split                    (const char *src, char sep);
  // size_t                  mutt_str_startswith               (const char *str, const char *prefix, enum CaseSensitivity cs);
  // int                     mutt_str_strcasecmp               (const char *a, const char *b);
  // const char *            mutt_str_strcasestr               (const char *haystack, const char *needle);
  // char *                  mutt_str_strcat                   (char *buf, size_t buflen, const char *s);
  // const char *            mutt_str_strchrnul                (const char *s, char c);
  // int                     mutt_str_strcmp                   (const char *a, const char *b);
  // int                     mutt_str_strcoll                  (const char *a, const char *b);
  // char *                  mutt_str_strdup                   (const char *str);
  // size_t                  mutt_str_strfcpy                  (char *dest, const char *src, size_t dsize);
  // const char *            mutt_str_stristr                  (const char *haystack, const char *needle);
  // size_t                  mutt_str_strlen                   (const char *a);
  // char *                  mutt_str_strlower                 (char *s);
  // int                     mutt_str_strncasecmp              (const char *a, const char *b, size_t l);
  // char *                  mutt_str_strncat                  (char *d, size_t l, const char *s, size_t sl);
  // int                     mutt_str_strncmp                  (const char *a, const char *b, size_t l);
  // size_t                  mutt_str_strnfcpy                 (char *dest, const char *src, size_t n, size_t dsize);
  // char *                  mutt_str_substr_cpy               (char *dest, const char *begin, const char *end, size_t destlen);
  // char *                  mutt_str_substr_dup               (const char *begin, const char *end);
  // const char *            mutt_str_sysexit                  (int e);
  // int                     mutt_str_word_casecmp             (const char *a, const char *b);

  mutt_str_strlen("hello");
}

void test_exit(void)
{
  // void                    mutt_exit                         (int code);

  mutt_exit(42);
}

int main()
{
  test_base64();
  test_buffer();
  test_charset();
  test_date();
  test_envlist();
  test_file();
  test_hash();
  test_history();
  test_list();
  test_logging();
  test_mapping();
  test_mbyte();
  test_md5();
  test_memory();
  test_path();
  test_regex();
  test_sha1();
  test_signal();
  test_string();
  test_exit();

  return 0;
}
