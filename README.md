# Test Code for NeoMutt Libraries

## Notes

- They work for me, YMMV
- They may get deleted without warning
- They expect NeoMutt to be built in `../neo`

## Samples

- `test_conn` looks up a hostname
- `test_hcache` creates an entry in the header cache and retrieves it
- `test_lib` calls a function from each of the library source files

## Library (326 functions)

There are now two libararies, libmutt and libemail.

### address (email)

```c
int AddressError;
const char *const AddressErrors[];
const char AddressSpecials[];

struct Address *    mutt_addr_append                  (struct Address **a, struct Address *b, bool prune);
void                mutt_addr_cat                     (char *buf, size_t buflen, const char *value, const char *specials);
bool                mutt_addr_cmp                     (struct Address *a, struct Address *b);
bool                mutt_addr_cmp_strict              (const struct Address *a, const struct Address *b);
struct Address *    mutt_addr_copy                    (struct Address *addr);
struct Address *    mutt_addr_copy_list               (struct Address *addr, bool prune);
const char *        mutt_addr_for_display             (struct Address *a);
void                mutt_addr_free                    (struct Address **p);
int                 mutt_addr_has_recips              (struct Address *a);
bool                mutt_addr_is_intl                 (struct Address *a);
bool                mutt_addr_is_local                (struct Address *a);
int                 mutt_addr_mbox_to_udomain         (const char *mbox, char **user, char **domain);
struct Address *    mutt_addr_new                     (void);
struct Address *    mutt_addr_parse_list              (struct Address *top, const char *s);
struct Address *    mutt_addr_parse_list2             (struct Address *p, const char *s);
void                mutt_addr_qualify                 (struct Address *addr, const char *host);
int                 mutt_addr_remove_from_list        (struct Address **a, const char *mailbox);
bool                mutt_addr_search                  (struct Address *a, struct Address *lst);
void                mutt_addr_set_intl                (struct Address *a, char *intl_mailbox);
void                mutt_addr_set_local               (struct Address *a, char *local_mailbox);
bool                mutt_addr_valid_msgid             (const char *msgid);
size_t              mutt_addr_write                   (char *buf, size_t buflen, struct Address *addr, bool display);
void                mutt_addr_write_single            (char *buf, size_t buflen, struct Address *addr, bool display);
struct Address *    mutt_addrlist_dedupe              (struct Address *addr);
int                 mutt_addrlist_to_intl             (struct Address *a, char **err);
int                 mutt_addrlist_to_local            (struct Address *a);
```

### attach (email)

```c
void                mutt_actx_add_attach              (struct AttachCtx *actx, struct AttachPtr *attach);
void                mutt_actx_add_body                (struct AttachCtx *actx, struct Body *new_body);
void                mutt_actx_add_fp                  (struct AttachCtx *actx, FILE *new_fp);
void                mutt_actx_free                    (struct AttachCtx **pactx);
void                mutt_actx_free_entries            (struct AttachCtx *actx);
```

### base64 (mutt)

```c
const int Index64[];

int                 mutt_b64_decode                   (char *out, const char *in, size_t olen);
size_t              mutt_b64_encode                   (char *out, const char *cin, size_t len, size_t olen);
```

### body (email)

```c
bool                mutt_body_cmp_strict              (const struct Body *b1, const struct Body *b2);
void                mutt_body_free                    (struct Body **p);
struct Body *       mutt_body_new                     (void);
```

### buffer (mutt)

```c
size_t              mutt_buffer_add                   (struct Buffer *buf, const char *s, size_t len);
size_t              mutt_buffer_addch                 (struct Buffer *buf, char c);
size_t              mutt_buffer_addstr                (struct Buffer *buf, const char *s);
struct Buffer *     mutt_buffer_alloc                 (size_t size);
void                mutt_buffer_free                  (struct Buffer **p);
struct Buffer *     mutt_buffer_from                  (char *seed);
struct Buffer *     mutt_buffer_init                  (struct Buffer *b);
bool                mutt_buffer_is_empty              (const struct Buffer *buf);
struct Buffer *     mutt_buffer_new                   (void);
int                 mutt_buffer_printf                (struct Buffer *buf, const char *fmt, ...);
void                mutt_buffer_reset                 (struct Buffer *b);
```

### charset (mutt)

```c
char *AssumedCharset;
char *Charset;
bool CharsetIsUtf8;
wchar_t ReplacementChar;
const struct MimeNames PreferredMimeNames[];

void                mutt_ch_canonical_charset         (char *buf, size_t buflen, const char *name);
const char *        mutt_ch_charset_lookup            (const char *chs);
int                 mutt_ch_check                     (const char *s, size_t slen, const char *from, const char *to);
bool                mutt_ch_check_charset             (const char *cs, bool strict);
char *              mutt_ch_choose                    (const char *fromcode, const char *charsets, char *u, size_t ulen, char **d, size_t *dlen);
bool                mutt_ch_chscmp                    (const char *cs1, const char *cs2);
int                 mutt_ch_convert_nonmime_string    (char **ps);
int                 mutt_ch_convert_string            (char **ps, const char *from, const char *to, int flags);
int                 mutt_ch_fgetconv                  (struct FgetConv *fc);
void                mutt_ch_fgetconv_close            (struct FgetConv **fc);
struct FgetConv *   mutt_ch_fgetconv_open             (FILE *file, const char *from, const char *to, int flags);
char *              mutt_ch_fgetconvs                 (char *buf, size_t buflen, struct FgetConv *fc);
char *              mutt_ch_get_default_charset       (void);
char *              mutt_ch_get_langinfo_charset      (void);
size_t              mutt_ch_iconv                     (iconv_t cd, const char **inbuf, size_t *inbytesleft, char **outbuf, size_t *outbytesleft, const char **inrepls, const char *outrepl, int *iconverrno);
const char *        mutt_ch_iconv_lookup              (const char *chs);
iconv_t             mutt_ch_iconv_open                (const char *tocode, const char *fromcode, int flags);
bool                mutt_ch_lookup_add                (enum LookupType type, const char *pat, const char *replace, struct Buffer *err);
void                mutt_ch_lookup_remove             (void);
void                mutt_ch_set_charset               (const char *charset);
```

### date (mutt)

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

### email_globals (email)

```c
bool MarkOld;
struct Regex *ReplyRegex;
char *SendCharset;
char *SpamSeparator;
bool Weed;

struct ListHead Ignore;
struct RegexList *NoSpamList;
struct ReplaceList *SpamList;
struct ListHead UnIgnore;
```

### envelope (email)

```c
bool                mutt_env_cmp_strict               (const struct Envelope *e1, const struct Envelope *e2);
void                mutt_env_free                     (struct Envelope **p);
void                mutt_env_merge                    (struct Envelope *base, struct Envelope **extra);
struct Envelope *   mutt_env_new                      (void);
int                 mutt_env_to_intl                  (struct Envelope *env, char **tag, char **err);
void                mutt_env_to_local                 (struct Envelope *e);
```

### envlist (mutt)

```c
void                mutt_envlist_free                 (void);
char **             mutt_envlist_getlist              (void);
void                mutt_envlist_init                 (char *envp[]);
bool                mutt_envlist_set                  (const char *name, const char *value, bool overwrite);
bool                mutt_envlist_unset                (const char *name);
```

### exit (mutt)

```c
void                mutt_exit                         (int code);
```

### file (mutt)

```c
char *Tmpdir;

int                 mutt_file_check_empty             (const char *path);
int                 mutt_file_chmod                   (const char *path, mode_t mode);
int                 mutt_file_chmod_add               (const char *path, mode_t mode);
int                 mutt_file_chmod_add_stat          (const char *path, mode_t mode, struct stat *st);
int                 mutt_file_chmod_rm                (const char *path, mode_t mode);
int                 mutt_file_chmod_rm_stat           (const char *path, mode_t mode, struct stat *st);
int                 mutt_file_copy_bytes              (FILE *in, FILE *out, size_t size);
int                 mutt_file_copy_stream             (FILE *fin, FILE *fout);
time_t              mutt_file_decrease_mtime          (const char *f, struct stat *st);
void                mutt_file_expand_fmt              (char *dest, size_t destlen, const char *fmt, const char *src);
void                mutt_file_expand_fmt_quote        (char *dest, size_t destlen, const char *fmt, const char *src);
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
void                mutt_file_touch_atime             (int fd);
void                mutt_file_unlink                  (const char *s);
void                mutt_file_unlink_empty            (const char *path);
int                 mutt_file_unlock                  (int fd);
```

### from (email)

```c
bool                is_from                           (const char *s, char *path, size_t pathlen, time_t *tp);
```

### hash (mutt)

```c
struct Hash *       mutt_hash_create                  (size_t nelem, int flags);
void                mutt_hash_delete                  (struct Hash *table, const char *strkey, const void *data);
void                mutt_hash_destroy                 (struct Hash **ptr);
void *              mutt_hash_find                    (const struct Hash *table, const char *strkey);
struct HashElem *   mutt_hash_find_bucket             (const struct Hash *table, const char *strkey);
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

### header (email)

```c
bool                mutt_header_cmp_strict            (const struct Header *h1, const struct Header *h2);
void                mutt_header_free                  (struct Header **h);
struct Header *     mutt_header_new                   (void);
```

### history (mutt)

```c
short History;
char *HistoryFile;
bool HistoryRemoveDups;
short SaveHistory;

void                mutt_hist_add                     (enum HistoryClass hclass, const char *str, bool save);
bool                mutt_hist_at_scratch              (enum HistoryClass hclass);
void                mutt_hist_free                    (void);
void                mutt_hist_init                    (void);
char *              mutt_hist_next                    (enum HistoryClass hclass);
char *              mutt_hist_prev                    (enum HistoryClass hclass);
void                mutt_hist_read_file               (void);
void                mutt_hist_reset_state             (enum HistoryClass hclass);
void                mutt_hist_save_scratch            (enum HistoryClass hclass, const char *str);
int                 mutt_hist_search                  (char *search_buf, enum HistoryClass hclass, char **matches);
```

### idna (email)

```c
bool IdnDecode;
bool IdnEncode;

char *              mutt_idna_intl_to_local           (const char *user, const char *domain, int flags);
char *              mutt_idna_local_to_intl           (const char *user, const char *domain);
const char *        mutt_idna_print_version           (void);
int                 mutt_idna_to_ascii_lz             (const char *input, char **output, int flags);
```

### list (mutt)

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

### logging (mutt)

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

### mapping (mutt)

```c
const char *        mutt_map_get_name                 (int val, const struct Mapping *map);
int                 mutt_map_get_value                (const char *name, const struct Mapping *map);
```

### mbyte (mutt)

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
int                 mutt_mb_width                     (const char *str, int col, bool display);
size_t              mutt_mb_width_ceiling             (const wchar_t *s, size_t n, int w1);
```

### md5 (mutt)

```c
void *              mutt_md5                          (const char *string, void *resbuf);
void *              mutt_md5_bytes                    (const void *buffer, size_t len, void *resbuf);
void *              mutt_md5_finish_ctx               (struct Md5Ctx *ctx, void *resbuf);
void                mutt_md5_init_ctx                 (struct Md5Ctx *ctx);
void                mutt_md5_process                  (const char *string, struct Md5Ctx *ctx);
void                mutt_md5_process_bytes            (const void *buffer, size_t len, struct Md5Ctx *ctx);
void                mutt_md5_toascii                  (const void *digest, char *resbuf);
```

### memory (mutt)

```c
void *              mutt_mem_calloc                   (size_t nmemb, size_t size);
void                mutt_mem_free                     (void *ptr);
void *              mutt_mem_malloc                   (size_t size);
void                mutt_mem_realloc                  (void *ptr, size_t size);
```

### mime (email)

```c
const int IndexHex[128];
const char *const BodyTypes[];
const char *const BodyEncodings[];
const char MimeSpecials[];
```

### parameter (email)

```c
bool                mutt_param_cmp_strict             (const struct ParameterList *p1, const struct ParameterList *p2);
void                mutt_param_delete                 (struct ParameterList *p, const char *attribute);
void                mutt_param_free                   (struct ParameterList *p);
void                mutt_param_free_one               (struct Parameter **p);
char *              mutt_param_get                    (const struct ParameterList *p, const char *s);
struct Parameter *  mutt_param_new                    (void);
void                mutt_param_set                    (struct ParameterList *p, const char *attribute, const char *value);
```

### parse (email)

```c
int                 mutt_check_encoding               (const char *c);
int                 mutt_check_mime_type              (const char *s);
char *              mutt_extract_message_id           (const char *s, const char **saveptr);
bool                mutt_is_message_type              (int type, const char *subtype);
bool                mutt_matches_ignore               (const char *s);
void                mutt_parse_content_type           (char *s, struct Body *ct);
struct Body *       mutt_parse_multipart              (FILE *fp, const char *boundary, LOFF_T end_off, bool digest);
void                mutt_parse_part                   (FILE *fp, struct Body *b);
struct Body *       mutt_read_mime_header             (FILE *fp, bool digest);
int                 mutt_rfc822_parse_line            (struct Envelope *e, struct Header *hdr, char *line, char *p, bool user_hdrs, bool weed, bool do_2047);
struct Body *       mutt_rfc822_parse_message         (FILE *fp, struct Body *parent);
struct Envelope *   mutt_rfc822_read_header           (FILE *f, struct Header *hdr, bool user_hdrs, bool weed);
char *              mutt_rfc822_read_line             (FILE *f, char *line, size_t *linelen);
```

### path (mutt)

```c
const char *        mutt_path_basename                (const char *f);
bool                mutt_path_canon                   (char *buf, size_t buflen, const char *homedir);
char *              mutt_path_concat                  (char *d, const char *dir, const char *fname, size_t l);
char *              mutt_path_concatn                 (char *dst, size_t dstlen, const char *dir, size_t dirlen, const char *fname, size_t fnamelen);
char *              mutt_path_dirname                 (const char *path);
void                mutt_path_get_parent              (char *path, char *buf, size_t buflen);
bool                mutt_path_pretty                  (char *buf, size_t buflen, const char *homedir);
size_t              mutt_path_realpath                (char *buf);
bool                mutt_path_tidy                    (char *buf);
bool                mutt_path_tidy_dotdot             (char *buf);
bool                mutt_path_tidy_slash              (char *buf);
int                 mutt_path_to_absolute             (char *path, const char *reference);
```

### regex (mutt)

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

### rfc2047 (email)

```c
void                rfc2047_decode                    (char **pd);
void                rfc2047_decode_addrlist           (struct Address *a);
void                rfc2047_encode                    (char **pd, const char *specials, int col, const char *charsets);
void                rfc2047_encode_addrlist           (struct Address *addr, const char *tag);
```

### rfc2231 (email)

```c
bool Rfc2047Parameters;

void                rfc2231_decode_parameters         (struct ParameterList *p);
int                 rfc2231_encode_string             (char **pd);
```

### sha1 (mutt)

```c
void                mutt_sha1_final                   (unsigned char digest[20], struct Sha1Ctx *context);
void                mutt_sha1_init                    (struct Sha1Ctx *context);
void                mutt_sha1_transform               (uint32_t state[5], const unsigned char buffer[64]);
void                mutt_sha1_update                  (struct Sha1Ctx *context, const unsigned char *data, uint32_t len);
```

### signal (mutt)

```c
void                mutt_sig_allow_interrupt          (int disposition);
void                mutt_sig_block                    (void);
void                mutt_sig_block_system             (void);
void                mutt_sig_empty_handler            (int sig);
void                mutt_sig_exit_handler             (int sig);
void                mutt_sig_init                     (sig_handler_t sig_fn, sig_handler_t exit_fn);
void                mutt_sig_unblock                  (void);
void                mutt_sig_unblock_system           (bool catch);
```

### string (mutt)

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
char *              mutt_str_strcat                   (char *buf, size_t buflen, const char *s);
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

### tags (email)

```c
char *HiddenTags;
struct Hash *TagTransforms;

void                driver_tags_free                  (struct TagHead *head);
char *              driver_tags_get                   (struct TagHead *head);
char *              driver_tags_get_transformed       (struct TagHead *head);
char *              driver_tags_get_transformed_for   (char *name, struct TagHead *head);
char *              driver_tags_get_with_hidden       (struct TagHead *head);
bool                driver_tags_replace               (struct TagHead *head, char *tags);
```

### thread (email)

```c
void                clean_references                  (struct MuttThread *brk, struct MuttThread *cur);
struct Header *     find_virtual                      (struct MuttThread *cur, int reverse);
void                insert_message                    (struct MuttThread **new, struct MuttThread *newparent, struct MuttThread *cur);
bool                is_descendant                     (struct MuttThread *a, struct MuttThread *b);
void                mutt_break_thread                 (struct Header *hdr);
void                thread_hash_destructor            (int type, void *obj, intptr_t data);
void                unlink_message                    (struct MuttThread **old, struct MuttThread *cur);
```

### url (email)

```c
enum UrlScheme      url_check_scheme                  (const char *s);
void                url_free                          (struct Url *u);
int                 url_parse                         (struct Url *u, char *src);
int                 url_pct_decode                    (char *s);
void                url_pct_encode                    (char *dst, size_t l, const char *src);
int                 url_tostring                      (struct Url *u, char *dest, size_t len, int flags);
```

