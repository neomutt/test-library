# Test Code for NeoMutt Libraries

## Notes

- They work for me, YMMV
- They may get deleted without warning
- They expect NeoMutt to be built in `../neo`

## Samples

- `test_conn` looks up a hostname
- `test_hcache` creates an entry in the header cache and retrieves it
- `test_lib` calls a function from each of the library source files

## Library (250 functions)

### address

```c
int AddressError;
const char *const AddressErrors[];
const char AddressSpecials[];

struct Address *    mutt_addr_append                  (struct Address **a, struct Address *b, bool prune);
void                mutt_addr_cat                     (char *buf, size_t buflen, const char *value, const char *specials);
bool                mutt_addr_cmp_strict              (const struct Address *a, const struct Address *b);
bool                mutt_addr_cmp                     (struct Address *a, struct Address *b);
struct Address *    mutt_addr_copy_list               (struct Address *addr, bool prune);
struct Address *    mutt_addr_copy                    (struct Address *addr);
const char *        mutt_addr_for_display             (struct Address *a);
void                mutt_addr_free                    (struct Address **p);
int                 mutt_addr_has_recips              (struct Address *a);
bool                mutt_addr_is_intl                 (struct Address *a);
bool                mutt_addr_is_local                (struct Address *a);
int                 mutt_addrlist_to_intl             (struct Address *a, char **err);
int                 mutt_addrlist_to_local            (struct Address *a);
int                 mutt_addr_mbox_to_udomain         (const char *mbox, char **user, char **domain);
struct Address *    mutt_addr_new                     (void);
struct Address *    mutt_addr_parse_list2             (struct Address *p, const char *s);
struct Address *    mutt_addr_parse_list              (struct Address *top, const char *s);
void                mutt_addr_qualify                 (struct Address *addr, const char *host);
int                 mutt_addr_remove_from_list        (struct Address **a, const char *mailbox);
bool                mutt_addr_search                  (struct Address *a, struct Address *lst);
void                mutt_addr_set_intl                (struct Address *a, char *intl_mailbox);
void                mutt_addr_set_local               (struct Address *a, char *local_mailbox);
bool                mutt_addr_valid_msgid             (const char *msgid);
size_t              mutt_addr_write                   (char *buf, size_t buflen, struct Address *addr, bool display);
void                mutt_addr_write_single            (char *buf, size_t buflen, struct Address *addr, bool display);
```

### base64

```c
const int Index64[];

int                 mutt_b64_decode                   (char *out, const char *in);
size_t              mutt_b64_encode                   (char *out, const char *cin, size_t len, size_t olen);
```

### buffer

```c
size_t              mutt_buffer_addch                 (struct Buffer *buf, char c);
size_t              mutt_buffer_addstr                (struct Buffer *buf, const char *s);
size_t              mutt_buffer_add                   (struct Buffer *buf, const char *s, size_t len);
struct Buffer *     mutt_buffer_alloc                 (size_t size);
void                mutt_buffer_free                  (struct Buffer **p);
struct Buffer *     mutt_buffer_from                  (char *seed);
struct Buffer *     mutt_buffer_init                  (struct Buffer *b);
bool                mutt_buffer_is_empty              (const struct Buffer *buf);
struct Buffer *     mutt_buffer_new                   (void);
int                 mutt_buffer_printf                (struct Buffer *buf, const char *fmt, ...);
void                mutt_buffer_reset                 (struct Buffer *b);
```

### charset

```c
char *AssumedCharset;
char *Charset;
bool CharsetIsUtf8;
wchar_t ReplacementChar;
const struct MimeNames PreferredMimeNames[];

void                mutt_ch_canonical_charset         (char *buf, size_t buflen, const char *name);
const char *        mutt_ch_charset_lookup            (const char *chs);
bool                mutt_ch_check_charset             (const char *cs, bool strict);
int                 mutt_ch_check                     (const char *s, size_t slen, const char *from, const char *to);
char *              mutt_ch_choose                    (const char *fromcode, const char *charsets, char *u, size_t ulen, char **d, size_t *dlen);
int                 mutt_ch_chscmp                    (const char *cs1, const char *cs2);
int                 mutt_ch_convert_nonmime_string    (char **ps);
int                 mutt_ch_convert_string            (char **ps, const char *from, const char *to, int flags);
void                mutt_ch_fgetconv_close            (struct FgetConv **fc);
struct FgetConv *   mutt_ch_fgetconv_open             (FILE *file, const char *from, const char *to, int flags);
char *              mutt_ch_fgetconvs                 (char *buf, size_t buflen, struct FgetConv *fc);
int                 mutt_ch_fgetconv                  (struct FgetConv *fc);
char *              mutt_ch_get_default_charset       (void);
char *              mutt_ch_get_langinfo_charset      (void);
size_t              mutt_ch_iconv                     (iconv_t cd, const char **inbuf, size_t *inbytesleft, char **outbuf, size_t *outbytesleft, const char **inrepls, const char *outrepl, int *iconverrno);
const char *        mutt_ch_iconv_lookup              (const char *chs);
iconv_t             mutt_ch_iconv_open                (const char *tocode, const char *fromcode, int flags);
bool                mutt_ch_lookup_add                (enum LookupType type, const char *pat, const char *replace, struct Buffer *err);
void                mutt_ch_lookup_remove             (void);
void                mutt_ch_set_charset               (const char *charset);
```

### date

```c
time_t              mutt_date_add_timeout             (time_t now, long timeout);
int                 mutt_date_check_month             (const char *s);
bool                mutt_date_is_day_name             (const char *s);
time_t              mutt_date_local_tz                (time_t t);
char *              mutt_date_make_date               (char *buf, size_t buflen);
int                 mutt_date_make_imap               (char *buf, size_t buflen, time_t timestamp);
time_t              mutt_date_make_time               (struct tm *t, int local);
int                 mutt_date_make_tls                (char *buf, size_t buflen, time_t timestamp);
void                mutt_date_normalize_time          (struct tm *tm);
time_t              mutt_date_parse_date              (const char *s, struct Tz *tz_out);
time_t              mutt_date_parse_imap              (char *s);
```

### envlist

```c
void                mutt_envlist_free                 (void);
char **             mutt_envlist_getlist              (void);
void                mutt_envlist_init                 (char *envp[]);
bool                mutt_envlist_set                  (const char *name, const char *value, bool overwrite);
bool                mutt_envlist_unset                (const char *name);
```

### exit

```c
void                mutt_exit                         (int code);
```

### file

```c
char *Tmpdir;

const char *        mutt_file_basename                (const char *f);
int                 mutt_file_check_empty             (const char *path);
int                 mutt_file_chmod_add               (const char *path, mode_t mode);
int                 mutt_file_chmod_add_stat          (const char *path, mode_t mode, struct stat *st);
int                 mutt_file_chmod                   (const char *path, mode_t mode);
int                 mutt_file_chmod_rm                (const char *path, mode_t mode);
int                 mutt_file_chmod_rm_stat           (const char *path, mode_t mode, struct stat *st);
char *              mutt_file_concatn_path            (char *dst, size_t dstlen, const char *dir, size_t dirlen, const char *fname, size_t fnamelen);
char *              mutt_file_concat_path             (char *d, const char *dir, const char *fname, size_t l);
int                 mutt_file_copy_bytes              (FILE *in, FILE *out, size_t size);
int                 mutt_file_copy_stream             (FILE *fin, FILE *fout);
time_t              mutt_file_decrease_mtime          (const char *f, struct stat *st);
char *              mutt_file_dirname                 (const char *path);
int                 mutt_file_fclose                  (FILE **f);
FILE *              mutt_file_fopen                   (const char *path, const char *mode);
int                 mutt_file_fsync_close             (FILE **f);
int                 mutt_file_lock                    (int fd, int excl, int timeout);
int                 mutt_file_mkdir                   (const char *path, mode_t mode);
FILE *              mutt_file_mkstemp_full            (const char *file, int line, const char *func);
int                 mutt_file_open                    (const char *path, int flags);
size_t              mutt_file_quote_filename          (char *d, size_t l, const char *f);
char *              mutt_file_read_keyword            (const char *file, char *buffer, size_t buflen);
char *              mutt_file_read_line               (char *s, size_t *size, FILE *fp, int *line, int flags);
int                 mutt_file_rename                  (char *oldfile, char *newfile);
int                 mutt_file_rmtree                  (const char *path);
int                 mutt_file_safe_rename             (const char *src, const char *target);
void                mutt_file_sanitize_filename       (char *f, bool slash);
int                 mutt_file_sanitize_regex          (char *dest, size_t destlen, const char *src);
void                mutt_file_set_mtime               (const char *from, const char *to);
int                 mutt_file_symlink                 (const char *oldpath, const char *newpath);
int                 mutt_file_to_absolute_path        (char *path, const char *reference);
void                mutt_file_touch_atime             (int fd);
void                mutt_file_unlink                  (const char *s);
void                mutt_file_unlink_empty            (const char *path);
int                 mutt_file_unlock                  (int fd);
```

### hash

```c
struct Hash *       mutt_hash_create                  (size_t nelem, int flags);
void                mutt_hash_delete                  (struct Hash *table, const char *strkey, const void *data);
void                mutt_hash_destroy                 (struct Hash **ptr);
struct HashElem *   mutt_hash_find_bucket             (const struct Hash *table, const char *strkey);
void *              mutt_hash_find                    (const struct Hash *table, const char *strkey);
struct HashElem *   mutt_hash_find_elem               (const struct Hash *table, const char *strkey);
struct HashElem *   mutt_hash_insert                  (struct Hash *table, const char *strkey, void *data);
struct Hash *       mutt_hash_int_create              (size_t nelem, int flags);
void                mutt_hash_int_delete              (struct Hash *table, unsigned int intkey, const void *data);
void *              mutt_hash_int_find                (const struct Hash *table, unsigned int intkey);
struct HashElem *   mutt_hash_int_insert              (struct Hash *table, unsigned int intkey, void *data);
void                mutt_hash_set_destructor          (struct Hash *table, hash_destructor fn, intptr_t fn_data);
struct HashElem *   mutt_hash_typed_insert            (struct Hash *table, const char *strkey, int type, void *data);
struct HashElem *   mutt_hash_walk                    (const struct Hash *table, struct HashWalkState *state);
```

### idna

```c
bool IdnDecode;
bool IdnEncode;

char *              mutt_idna_intl_to_local           (const char *user, const char *domain, int flags);
char *              mutt_idna_local_to_intl           (const char *user, const char *domain);
const char *        mutt_idna_print_version           (void);
int                 mutt_idna_to_ascii_lz             (const char *input, char **output, int flags);
```

### list

```c
void                mutt_list_clear                   (struct ListHead *h);
int                 mutt_list_compare                 (const struct ListHead *ah, const struct ListHead *bh);
struct ListNode *   mutt_list_find                    (struct ListHead *h, const char *data);
void                mutt_list_free                    (struct ListHead *h);
void                mutt_list_free_type               (struct ListHead *h, list_free_t fn);
struct ListNode *   mutt_list_insert_after            (struct ListHead *h, struct ListNode *n, char *s);
struct ListNode *   mutt_list_insert_head             (struct ListHead *h, char *s);
struct ListNode *   mutt_list_insert_tail             (struct ListHead *h, char *s);
bool                mutt_list_match                   (const char *s, struct ListHead *h);
```

### logging

```c
log_dispatcher_t MuttLogger;

int                 log_disp_file                     (time_t stamp, const char *file, int line, const char *function, int level, ...);
int                 log_disp_queue                    (time_t stamp, const char *file, int line, const char *function, int level, ...);
int                 log_disp_terminal                 (time_t stamp, const char *file, int line, const char *function, int level, ...);
void                log_file_close                    (bool verbose);
int                 log_file_open                     (bool verbose);
bool                log_file_running                  (void);
int                 log_file_set_filename             (const char *file, bool verbose);
int                 log_file_set_level                (int level, bool verbose);
void                log_file_set_version              (const char *version);
int                 log_queue_add                     (struct LogLine *ll);
void                log_queue_empty                   (void);
void                log_queue_flush                   (log_dispatcher_t disp);
int                 log_queue_save                    (FILE *fp);
void                log_queue_set_max_size            (int size);
```

### mapping

```c
const char *        mutt_map_get_name                 (int val, const struct Mapping *map);
int                 mutt_map_get_value                (const char *name, const struct Mapping *map);
```

### mbyte

```c
bool OptLocales;

int                 mutt_mb_charlen                   (const char *s, int *width);
int                 mutt_mb_filter_unprintable        (char **s);
bool                mutt_mb_get_initials              (const char *name, char *buf, size_t buflen);
bool                mutt_mb_is_display_corrupting_utf8(wchar_t wc);
bool                mutt_mb_is_lower                  (const char *s);
bool                mutt_mb_is_shell_char             (wchar_t ch);
size_t              mutt_mb_mbstowcs                  (wchar_t **pwbuf, size_t *pwbuflen, size_t i, char *buf);
void                mutt_mb_wcstombs                  (char *dest, size_t dlen, const wchar_t *src, size_t slen);
int                 mutt_mb_wcswidth                  (const wchar_t *s, size_t n);
int                 mutt_mb_wcwidth                   (wchar_t wc);
size_t              mutt_mb_width_ceiling             (const wchar_t *s, size_t n, int w1);
int                 mutt_mb_width                     (const char *str, int col, bool display);
```

### md5

```c
void *              mutt_md5_bytes                    (const void *buffer, size_t len, void *resbuf);
void *              mutt_md5                          (const char *string, void *resbuf);
void *              mutt_md5_finish_ctx               (struct Md5Ctx *ctx, void *resbuf);
void                mutt_md5_init_ctx                 (struct Md5Ctx *ctx);
void                mutt_md5_process_bytes            (const void *buffer, size_t len, struct Md5Ctx *ctx);
void                mutt_md5_process                  (const char *string, struct Md5Ctx *ctx);
void                mutt_md5_toascii                  (const void *digest, char *resbuf);
```

### memory

```c
void *              mutt_mem_calloc                   (size_t nmemb, size_t size);
void                mutt_mem_free                     (void *ptr);
void *              mutt_mem_malloc                   (size_t size);
void                mutt_mem_realloc                  (void *ptr, size_t size);
```

### mime

```c
const int IndexHex[128];
const char *const BodyTypes[];
const char *const BodyEncodings[];
const char MimeSpecials[];
```

### parameter

```c
bool                mutt_param_cmp_strict             (const struct ParameterList *p1, const struct ParameterList *p2);
void                mutt_param_delete                 (struct ParameterList *p, const char *attribute);
void                mutt_param_free_one               (struct Parameter **p);
void                mutt_param_free                   (struct ParameterList *p);
char *              mutt_param_get                    (const struct ParameterList *p, const char *s);
struct Parameter *  mutt_param_new                    (void);
void                mutt_param_set                    (struct ParameterList *p, const char *attribute, const char *value);
```

### regex

```c
struct Regex *      mutt_regex_compile                (const char *str, int flags);
struct Regex *      mutt_regex_create                 (const char *str, int flags, struct Buffer *err);
void                mutt_regex_free                   (struct Regex **r);
int                 mutt_regexlist_add                (struct RegexList **rl, const char *str, int flags, struct Buffer *err);
void                mutt_regexlist_free               (struct RegexList **rl);
bool                mutt_regexlist_match              (struct RegexList *rl, const char *str);
struct RegexList *  mutt_regexlist_new                (void);
int                 mutt_regexlist_remove             (struct RegexList **rl, const char *str);
int                 mutt_replacelist_add              (struct ReplaceList **rl, const char *pat, const char *templ, struct Buffer *err);
char *              mutt_replacelist_apply            (struct ReplaceList *rl, char *buf, size_t buflen, const char *str);
void                mutt_replacelist_free             (struct ReplaceList **rl);
bool                mutt_replacelist_match            (struct ReplaceList *rl, char *buf, size_t buflen, const char *str);
struct ReplaceList *mutt_replacelist_new              (void);
int                 mutt_replacelist_remove           (struct ReplaceList **rl, const char *pat);
```

### rfc2047

```c
void                mutt_rfc2047_decode               (char **pd);
void                mutt_rfc2047_encode               (char **pd, const char *specials, int col, const char *charsets);
```

### sha1

```c
void                mutt_sha1_final                   (unsigned char digest[20], struct Sha1Ctx *context);
void                mutt_sha1_init                    (struct Sha1Ctx *context);
void                mutt_sha1_transform               (uint32_t state[5], const unsigned char buffer[64]);
void                mutt_sha1_update                  (struct Sha1Ctx *context, const unsigned char *data, uint32_t len);
```

### signal

```c
void                mutt_sig_allow_interrupt          (int disposition);
void                mutt_sig_block_system             (void);
void                mutt_sig_block                    (void);
void                mutt_sig_empty_handler            (int sig);
void                mutt_sig_exit_handler             (int sig);
void                mutt_sig_init                     (sig_handler_t sig_fn, sig_handler_t exit_fn);
void                mutt_sig_unblock_system           (int catch);
void                mutt_sig_unblock                  (void);
```

### string

```c
void                mutt_str_adjust                   (char **p);
void                mutt_str_append_item              (char **str, const char *item, int sep);
int                 mutt_str_atoi                     (const char *str, int *dst);
int                 mutt_str_atol                     (const char *str, long *dst);
int                 mutt_str_atos                     (const char *str, short *dst);
int                 mutt_str_atoui                    (const char *str, unsigned int *dst);
int                 mutt_str_atoul                    (const char *str, unsigned long *dst);
void                mutt_str_dequote_comment          (char *s);
const char *        mutt_str_find_word                (const char *src);
const char *        mutt_str_getenv                   (const char *name);
bool                mutt_str_is_ascii                 (const char *p, size_t len);
bool                mutt_str_is_email_wsp             (char c);
size_t              mutt_str_lws_len                  (const char *s, size_t n);
size_t              mutt_str_lws_rlen                 (const char *s, size_t n);
const char *        mutt_str_next_word                (const char *s);
void                mutt_str_pretty_size              (char *buf, size_t buflen, size_t num);
void                mutt_str_remove_trailing_ws       (char *s);
void                mutt_str_replace                  (char **p, const char *s);
const char *        mutt_str_rstrnstr                 (const char *haystack, size_t haystack_length, const char *needle);
char *              mutt_str_skip_email_wsp           (const char *s);
char *              mutt_str_skip_whitespace          (char *p);
int                 mutt_str_strcasecmp               (const char *a, const char *b);
char *              mutt_str_strcat                   (char *d, size_t l, const char *s);
const char *        mutt_str_strchrnul                (const char *s, char c);
int                 mutt_str_strcmp                   (const char *a, const char *b);
int                 mutt_str_strcoll                  (const char *a, const char *b);
char *              mutt_str_strdup                   (const char *str);
size_t              mutt_str_strfcpy                  (char *dest, const char *src, size_t dsize);
const char *        mutt_str_stristr                  (const char *haystack, const char *needle);
size_t              mutt_str_strlen                   (const char *a);
char *              mutt_str_strlower                 (char *s);
int                 mutt_str_strncasecmp              (const char *a, const char *b, size_t l);
char *              mutt_str_strncat                  (char *d, size_t l, const char *s, size_t sl);
int                 mutt_str_strncmp                  (const char *a, const char *b, size_t l);
size_t              mutt_str_strnfcpy                 (char *dest, const char *src, size_t n, size_t dsize);
char *              mutt_str_substr_cpy               (char *dest, const char *begin, const char *end, size_t destlen);
char *              mutt_str_substr_dup               (const char *begin, const char *end);
const char *        mutt_str_sysexit                  (int e);
int                 mutt_str_word_casecmp             (const char *a, const char *b);
```

