# Test Code for NeoMutt Libraries

## Notes

- They work for me, YMMV
- They may get deleted without warning
- They expect NeoMutt to be built in `../neo`

## Samples

- `test_conn` looks up a hostname
- `test_hcache` creates an entry in the header cache and retrieves it
- `test_lib` calls a function from each of the library source files

## Library (477 functions)

There are now four libraries: libaddress, libcore, libemail and libmutt.

### account (core)

```c
void                    account_free                      (struct Account **ptr);
bool                    account_mailbox_add               (struct Account *a, struct Mailbox *m);
bool                    account_mailbox_remove            (struct Account *a, struct Mailbox *m);
struct Account *        account_new                       (const char *name, struct ConfigSubset *sub);
```

### address (address)

```c
const char AddressSpecials[];

void                    mutt_addr_cat                     (char *buf, size_t buflen, const char *value, const char *specials);
bool                    mutt_addr_cmp                     (const struct Address *a, const struct Address *b);
struct Address *        mutt_addr_copy                    (const struct Address *addr);
struct Address *        mutt_addr_create                  (const char *personal, const char *mailbox);
const char *            mutt_addr_for_display             (const struct Address *a);
void                    mutt_addr_free                    (struct Address **ptr);
struct Address *        mutt_addr_new                     (void);
bool                    mutt_addr_to_intl                 (struct Address *a);
bool                    mutt_addr_to_local                (struct Address *a);
bool                    mutt_addr_uses_unicode            (const char *str);
bool                    mutt_addr_valid_msgid             (const char *msgid);
size_t                  mutt_addr_write                   (struct Buffer *buf, struct Address *addr, bool display);
void                    mutt_addrlist_append              (struct AddressList *al, struct Address *a);
void                    mutt_addrlist_clear               (struct AddressList *al);
void                    mutt_addrlist_copy                (struct AddressList *dst, const struct AddressList *src, bool prune);
int                     mutt_addrlist_count_recips        (const struct AddressList *al);
void                    mutt_addrlist_dedupe              (struct AddressList *al);
bool                    mutt_addrlist_equal               (const struct AddressList *ala, const struct AddressList *alb);
int                     mutt_addrlist_parse               (struct AddressList *al, const char *s);
int                     mutt_addrlist_parse2              (struct AddressList *al, const char *s);
void                    mutt_addrlist_prepend             (struct AddressList *al, struct Address *a);
void                    mutt_addrlist_qualify             (struct AddressList *al, const char *host);
int                     mutt_addrlist_remove              (struct AddressList *al, const char *mailbox);
void                    mutt_addrlist_remove_xrefs        (const struct AddressList *a, struct AddressList *b);
bool                    mutt_addrlist_search              (const struct AddressList *haystack, const struct Address *needle);
int                     mutt_addrlist_to_intl             (struct AddressList *al, char **err);
int                     mutt_addrlist_to_local            (struct AddressList *al);
bool                    mutt_addrlist_uses_unicode        (const struct AddressList *al);
size_t                  mutt_addrlist_write               (const struct AddressList *al, struct Buffer *buf, bool display);
void                    mutt_addrlist_write_file          (const struct AddressList *al, FILE *fp, const char *header);
size_t                  mutt_addrlist_write_list          (const struct AddressList *al, struct ListHead *list);
size_t                  mutt_addrlist_write_wrap          (const struct AddressList *al, struct Buffer *buf, const char *header);
```

### atoi (mutt)

```c
const char *            mutt_str_atoi                     (const char *str, int *dst);
const char *            mutt_str_atol                     (const char *str, long *dst);
const char *            mutt_str_atos                     (const char *str, short *dst);
const char *            mutt_str_atoui                    (const char *str, unsigned int *dst);
const char *            mutt_str_atoul                    (const char *str, unsigned long *dst);
const char *            mutt_str_atoull                   (const char *str, unsigned long long *dst);
const char *            mutt_str_atous                    (const char *str, unsigned short *dst);
```

### base64 (mutt)

```c
const int Index64[];

int                     mutt_b64_buffer_decode            (struct Buffer *buf, const char *in);
size_t                  mutt_b64_buffer_encode            (struct Buffer *buf, const char *in, size_t len);
int                     mutt_b64_decode                   (const char *in, char *out, size_t olen);
size_t                  mutt_b64_encode                   (const char *in, size_t inlen, char *out, size_t outlen);
```

### body (email)

```c
bool                    mutt_body_cmp_strict              (const struct Body *b1, const struct Body *b2);
void                    mutt_body_free                    (struct Body **ptr);
char *                  mutt_body_get_charset             (struct Body *b, char *buf, size_t buflen);
struct Body *           mutt_body_new                     (void);
```

### buffer (mutt)

```c
int                     buf_add_printf                    (struct Buffer *buf, const char *fmt, ...);
size_t                  buf_addch                         (struct Buffer *buf, char c);
size_t                  buf_addstr                        (struct Buffer *buf, const char *s);
size_t                  buf_addstr_n                      (struct Buffer *buf, const char *s, size_t len);
void                    buf_alloc                         (struct Buffer *buf, size_t new_size);
char                    buf_at                            (const struct Buffer *buf, size_t offset);
int                     buf_coll                          (const struct Buffer *a, const struct Buffer *b);
size_t                  buf_concat_path                   (struct Buffer *buf, const char *dir, const char *fname);
size_t                  buf_concatn_path                  (struct Buffer *buf, const char *dir, size_t dirlen, const char *fname, size_t fnamelen);
size_t                  buf_copy                          (struct Buffer *dst, const struct Buffer *src);
void                    buf_dealloc                       (struct Buffer *buf);
void                    buf_dequote_comment               (struct Buffer *buf);
struct Buffer *         buf_dup                           (const struct Buffer *buf);
const char *            buf_find_char                     (const struct Buffer *buf, const char c);
const char *            buf_find_string                   (const struct Buffer *buf, const char *s);
void                    buf_fix_dptr                      (struct Buffer *buf);
void                    buf_free                          (struct Buffer **ptr);
struct Buffer *         buf_init                          (struct Buffer *buf);
size_t                  buf_insert                        (struct Buffer *buf, size_t offset, const char *s);
bool                    buf_is_empty                      (const struct Buffer *buf);
bool                    buf_istr_equal                    (const struct Buffer *a, const struct Buffer *b);
size_t                  buf_len                           (const struct Buffer *buf);
void                    buf_lower                         (struct Buffer *buf);
struct Buffer           buf_make                          (size_t size);
struct Buffer *         buf_new                           (const char *str);
int                     buf_printf                        (struct Buffer *buf, const char *fmt, ...);
void                    buf_reset                         (struct Buffer *buf);
void                    buf_seek                          (struct Buffer *buf, size_t offset);
size_t                  buf_startswith                    (const struct Buffer *buf, const char *prefix);
bool                    buf_str_equal                     (const struct Buffer *a, const struct Buffer *b);
size_t                  buf_strcpy                        (struct Buffer *buf, const char *s);
size_t                  buf_strcpy_n                      (struct Buffer *buf, const char *s, size_t len);
char *                  buf_strdup                        (const struct Buffer *buf);
size_t                  buf_substrcpy                     (struct Buffer *buf, const char *beg, const char *end);
void                    buf_upper                         (struct Buffer *buf);
```

### charset (mutt)

```c
bool CharsetIsUtf8;
wchar_t ReplacementChar;

void                    mutt_ch_cache_cleanup             (void);
void                    mutt_ch_canonical_charset         (char *buf, size_t buflen, const char *name);
const char *            mutt_ch_charset_lookup            (const char *chs);
int                     mutt_ch_check                     (const char *s, size_t slen, const char *from, const char *to);
bool                    mutt_ch_check_charset             (const char *cs, bool strict);
char *                  mutt_ch_choose                    (const char *fromcode, const struct Slist *charsets, const char *u, size_t ulen, char **d, size_t *dlen);
bool                    mutt_ch_chscmp                    (const char *cs1, const char *cs2);
int                     mutt_ch_convert_nonmime_string    (const struct Slist *const assumed_charset, const char *charset, char **ps);
int                     mutt_ch_convert_string            (char **ps, const char *from, const char *to, uint8_t flags);
int                     mutt_ch_fgetconv                  (struct FgetConv *fc);
void                    mutt_ch_fgetconv_close            (struct FgetConv **ptr);
struct FgetConv *       mutt_ch_fgetconv_open             (FILE *fp, const char *from, const char *to, uint8_t flags);
char *                  mutt_ch_fgetconvs                 (char *buf, size_t buflen, struct FgetConv *fc);
const char *            mutt_ch_get_default_charset       (const struct Slist *const assumed_charset);
char *                  mutt_ch_get_langinfo_charset      (void);
size_t                  mutt_ch_iconv                     (iconv_t cd, const char **inbuf, size_t *inbytesleft, char **outbuf, size_t *outbytesleft, const char **inrepls, const char *outrepl, int *iconverrno);
const char *            mutt_ch_iconv_lookup              (const char *chs);
iconv_t                 mutt_ch_iconv_open                (const char *tocode, const char *fromcode, uint8_t flags);
bool                    mutt_ch_lookup_add                (enum LookupType type, const char *pat, const char *replace, struct Buffer *err);
void                    mutt_ch_lookup_remove             (void);
void                    mutt_ch_set_charset               (const char *charset);
```

### command (core)

```c
struct Command *        command_get                       (const char *s);
size_t                  commands_array                    (struct Command **first);
void                    commands_cleanup                  (void);
void                    commands_register                 (const struct Command *cmds, const size_t num_cmds);
```

### config_cache (core)

```c
const struct Slist *    cc_assumed_charset                (void);
const char *            cc_charset                        (void);
const char *            cc_maildir_field_delimiter        (void);
void                    config_cache_cleanup              (void);
```

### config_type (address)

```c
struct Address *        address_new                       (const char *addr);
const struct Address *  cs_subset_address                 (const struct ConfigSubset *sub, const char *name);
```

### date (mutt)

```c
time_t                  mutt_date_add_timeout             (time_t now, time_t timeout);
int                     mutt_date_check_month             (const char *s);
struct tm               mutt_date_gmtime                  (time_t t);
int                     mutt_date_local_tz                (time_t t);
struct tm               mutt_date_localtime               (time_t t);
size_t                  mutt_date_localtime_format        (char *buf, size_t buflen, const char *format, time_t t);
size_t                  mutt_date_localtime_format_locale (char *buf, size_t buflen, const char *format, time_t t, locale_t loc);
void                    mutt_date_make_date               (struct Buffer *buf, bool local);
int                     mutt_date_make_imap               (char *buf, size_t buflen, time_t timestamp);
time_t                  mutt_date_make_time               (struct tm *t, bool local);
int                     mutt_date_make_tls                (char *buf, size_t buflen, time_t timestamp);
void                    mutt_date_normalize_time          (struct tm *tm);
time_t                  mutt_date_now                     (void);
uint64_t                mutt_date_now_ms                  (void);
time_t                  mutt_date_parse_date              (const char *s, struct Tz *tz_out);
time_t                  mutt_date_parse_imap              (const char *s);
void                    mutt_date_sleep_ms                (size_t ms);
```

### dispatcher (core)

```c
const char *            dispatcher_get_retval_name        (int rv);
```

### email (email)

```c
bool                    email_cmp_strict                  (const struct Email *e1, const struct Email *e2);
void                    email_free                        (struct Email **ptr);
struct Email *          email_new                         (void);
size_t                  email_size                        (const struct Email *e);
struct ListNode *       header_add                        (struct ListHead *hdrlist, const char *header);
struct ListNode *       header_find                       (const struct ListHead *hdrlist, const char *header);
void                    header_free                       (struct ListHead *hdrlist, struct ListNode *target);
struct ListNode *       header_set                        (struct ListHead *hdrlist, const char *header);
struct ListNode *       header_update                     (struct ListNode *hdr, const char *header);
```

### envelope (email)

```c
void                    mutt_autocrypthdr_free            (struct AutocryptHeader **ptr);
struct AutocryptHeader *mutt_autocrypthdr_new             (void);
bool                    mutt_env_cmp_strict               (const struct Envelope *e1, const struct Envelope *e2);
void                    mutt_env_free                     (struct Envelope **ptr);
void                    mutt_env_merge                    (struct Envelope *base, struct Envelope **extra);
struct Envelope *       mutt_env_new                      (void);
bool                    mutt_env_notify_send              (struct Email *e, enum NotifyEnvelope type);
int                     mutt_env_to_intl                  (struct Envelope *env, const char **tag, char **err);
void                    mutt_env_to_local                 (struct Envelope *env);
```

### envlist (mutt)

```c
void                    envlist_free                      (char ***envp);
char **                 envlist_init                      (char **envp);
bool                    envlist_set                       (char ***envp, const char *name, const char *value, bool overwrite);
bool                    envlist_unset                     (char ***envp, const char *name);
```

### exit (mutt)

```c
void                    mutt_exit                         (int code);
```

### file (mutt)

```c
const char FilenameSafeChars[];

void                    buf_file_expand_fmt_quote         (struct Buffer *dest, const char *fmt, const char *src);
void                    buf_quote_filename                (struct Buffer *buf, const char *filename, bool add_outer);
int                     mutt_file_check_empty             (const char *path);
int                     mutt_file_chmod                   (const char *path, mode_t mode);
int                     mutt_file_chmod_add               (const char *path, mode_t mode);
int                     mutt_file_chmod_add_stat          (const char *path, mode_t mode, struct stat *st);
int                     mutt_file_chmod_rm                (const char *path, mode_t mode);
int                     mutt_file_chmod_rm_stat           (const char *path, mode_t mode, struct stat *st);
int                     mutt_file_copy_bytes              (FILE *fp_in, FILE *fp_out, size_t size);
int                     mutt_file_copy_stream             (FILE *fp_in, FILE *fp_out);
time_t                  mutt_file_decrease_mtime          (const char *fp, struct stat *st);
void                    mutt_file_expand_fmt              (struct Buffer *dest, const char *fmt, const char *src);
int                     mutt_file_fclose                  (FILE **fp);
FILE *                  mutt_file_fopen                   (const char *path, const char *mode);
int                     mutt_file_fsync_close             (FILE **fp);
long                    mutt_file_get_size                (const char *path);
long                    mutt_file_get_size_fp             (FILE *fp);
void                    mutt_file_get_stat_timespec       (struct timespec *dest, struct stat *st, enum MuttStatType type);
bool                    mutt_file_iter_line               (struct MuttFileIter *iter, FILE *fp, ReadLineFlags flags);
int                     mutt_file_lock                    (int fd, bool excl, bool timeout);
bool                    mutt_file_map_lines               (mutt_file_map_t func, void *user_data, FILE *fp, ReadLineFlags flags);
int                     mutt_file_mkdir                   (const char *path, mode_t mode);
int                     mutt_file_open                    (const char *path, uint32_t flags);
DIR *                   mutt_file_opendir                 (const char *path, enum MuttOpenDirMode mode);
size_t                  mutt_file_quote_filename          (const char *filename, char *buf, size_t buflen);
char *                  mutt_file_read_keyword            (const char *file, char *buf, size_t buflen);
char *                  mutt_file_read_line               (char *line, size_t *size, FILE *fp, int *line_num, ReadLineFlags flags);
int                     mutt_file_rename                  (const char *oldfile, const char *newfile);
void                    mutt_file_resolve_symlink         (struct Buffer *buf);
int                     mutt_file_rmtree                  (const char *path);
const char *            mutt_file_rotate                  (const char *path, int count);
int                     mutt_file_safe_rename             (const char *src, const char *target);
void                    mutt_file_sanitize_filename       (char *path, bool slash);
int                     mutt_file_sanitize_regex          (struct Buffer *dest, const char *src);
bool                    mutt_file_seek                    (FILE *fp, off_t offset, int whence);
void                    mutt_file_set_mtime               (const char *from, const char *to);
int                     mutt_file_stat_compare            (struct stat *st1, enum MuttStatType st1_type, struct stat *st2, enum MuttStatType st2_type);
int                     mutt_file_stat_timespec_compare   (struct stat *st, enum MuttStatType type, struct timespec *b);
int                     mutt_file_symlink                 (const char *oldpath, const char *newpath);
int                     mutt_file_timespec_compare        (struct timespec *a, struct timespec *b);
void                    mutt_file_touch_atime             (int fd);
void                    mutt_file_unlink                  (const char *s);
void                    mutt_file_unlink_empty            (const char *path);
int                     mutt_file_unlock                  (int fd);
```

### filter (mutt)

```c
pid_t                   filter_create                     (const char *cmd, FILE **fp_in, FILE **fp_out, FILE **fp_err, char **envlist);
pid_t                   filter_create_fd                  (const char *cmd, FILE **fp_in, FILE **fp_out, FILE **fp_err, int fdin, int fdout, int fderr, char **envlist);
int                     filter_wait                       (pid_t pid);
```

### from (email)

```c
bool                    is_from                           (const char *s, char *path, size_t pathlen, time_t *tp);
```

### globals (email)

```c
struct HashTable *AutoSubscribeCache;
struct ListHead Ignore;
struct RegexList MailLists;
struct ListHead MailToAllow;
struct RegexList NoSpamList;
struct ReplaceList SpamList;
struct RegexList SubscribedLists;
struct ListHead UnIgnore;
struct RegexList UnMailLists;
struct RegexList UnSubscribedLists;
```

### group (address)

```c
bool                    mutt_group_match                  (struct Group *g, const char *s);
void                    mutt_grouplist_add                (struct GroupList *gl, struct Group *group);
void                    mutt_grouplist_add_addrlist       (struct GroupList *gl, struct AddressList *al);
int                     mutt_grouplist_add_regex          (struct GroupList *gl, const char *s, uint16_t flags, struct Buffer *err);
void                    mutt_grouplist_cleanup            (void);
void                    mutt_grouplist_clear              (struct GroupList *gl);
void                    mutt_grouplist_destroy            (struct GroupList *gl);
void                    mutt_grouplist_init               (void);
int                     mutt_grouplist_remove_addrlist    (struct GroupList *gl, struct AddressList *al);
int                     mutt_grouplist_remove_regex       (struct GroupList *gl, const char *s);
struct Group *          mutt_pattern_group                (const char *pat);
```

### hash (mutt)

```c
void                    mutt_hash_delete                  (struct HashTable *table, const char *strkey, const void *data);
void *                  mutt_hash_find                    (const struct HashTable *table, const char *strkey);
struct HashElem *       mutt_hash_find_bucket             (const struct HashTable *table, const char *strkey);
struct HashElem *       mutt_hash_find_elem               (const struct HashTable *table, const char *strkey);
void                    mutt_hash_free                    (struct HashTable **ptr);
struct HashElem *       mutt_hash_insert                  (struct HashTable *table, const char *strkey, void *data);
void                    mutt_hash_int_delete              (struct HashTable *table, unsigned int intkey, const void *data);
void *                  mutt_hash_int_find                (const struct HashTable *table, unsigned int intkey);
struct HashElem *       mutt_hash_int_insert              (struct HashTable *table, unsigned int intkey, void *data);
struct HashTable *      mutt_hash_int_new                 (size_t num_elems, HashFlags flags);
struct HashTable *      mutt_hash_new                     (size_t num_elems, HashFlags flags);
void                    mutt_hash_set_destructor          (struct HashTable *table, hash_hdata_free_t fn, intptr_t fn_data);
struct HashElem *       mutt_hash_typed_insert            (struct HashTable *table, const char *strkey, int type, void *data);
struct HashElem *       mutt_hash_walk                    (const struct HashTable *table, struct HashWalkState *state);
```

### idna (address)

```c
char *                  mutt_idna_intl_to_local           (const char *user, const char *domain, uint8_t flags);
char *                  mutt_idna_local_to_intl           (const char *user, const char *domain);
const char *            mutt_idna_print_version           (void);
int                     mutt_idna_to_ascii_lz             (const char *input, char **output, uint8_t flags);
```

### list (mutt)

```c
void                    mutt_list_clear                   (struct ListHead *h);
bool                    mutt_list_compare                 (const struct ListHead *ah, const struct ListHead *bh);
struct ListNode *       mutt_list_find                    (const struct ListHead *h, const char *data);
void                    mutt_list_free                    (struct ListHead *h);
void                    mutt_list_free_type               (struct ListHead *h, list_free_t fn);
struct ListNode *       mutt_list_insert_after            (struct ListHead *h, struct ListNode *n, char *s);
struct ListNode *       mutt_list_insert_head             (struct ListHead *h, char *s);
struct ListNode *       mutt_list_insert_tail             (struct ListHead *h, char *s);
bool                    mutt_list_match                   (const char *s, struct ListHead *h);
size_t                  mutt_list_str_split               (struct ListHead *head, const char *src, char sep);
```

### logging (mutt)

```c
log_dispatcher_t MuttLogger;

int                     log_disp_file                     (time_t stamp, const char *file, int line, const char *function, enum LogLevel level, const char *format, ...);
int                     log_disp_null                     (time_t stamp, const char *file, int line, const char *function, enum LogLevel level, const char *format, ...);
int                     log_disp_queue                    (time_t stamp, const char *file, int line, const char *function, enum LogLevel level, const char *format, ...);
int                     log_disp_terminal                 (time_t stamp, const char *file, int line, const char *function, enum LogLevel level, const char *format, ...);
void                    log_file_close                    (bool verbose);
int                     log_file_open                     (bool verbose);
bool                    log_file_running                  (void);
int                     log_file_set_filename             (const char *file, bool verbose);
int                     log_file_set_level                (enum LogLevel level, bool verbose);
void                    log_file_set_version              (const char *version);
int                     log_queue_add                     (struct LogLine *ll);
void                    log_queue_empty                   (void);
void                    log_queue_flush                   (log_dispatcher_t disp);
int                     log_queue_save                    (FILE *fp);
void                    log_queue_set_max_size            (int size);
```

### mailbox (core)

```c
void                    mailbox_changed                   (struct Mailbox *m, enum NotifyMailbox action);
struct Mailbox *        mailbox_find                      (const char *path);
struct Mailbox *        mailbox_find_name                 (const char *name);
void                    mailbox_free                      (struct Mailbox **ptr);
void                    mailbox_gc_add                    (struct Email *e);
void                    mailbox_gc_run                    (void);
int                     mailbox_gen                       (void);
const char *            mailbox_get_type_name             (enum MailboxType type);
struct Mailbox *        mailbox_new                       (void);
bool                    mailbox_set_subset                (struct Mailbox *m, struct ConfigSubset *sub);
void                    mailbox_size_add                  (struct Mailbox *m, const struct Email *e);
void                    mailbox_size_sub                  (struct Mailbox *m, const struct Email *e);
void                    mailbox_update                    (struct Mailbox *m);
```

### mapping (mutt)

```c
const char *            mutt_map_get_name                 (int val, const struct Mapping *map);
int                     mutt_map_get_value                (const char *name, const struct Mapping *map);
int                     mutt_map_get_value_n              (const char *name, size_t len, const struct Mapping *map);
```

### mbyte (mutt)

```c
bool OptLocales;

void                    buf_mb_wcstombs                   (struct Buffer *dest, const wchar_t *wstr, size_t wlen);
int                     mutt_mb_charlen                   (const char *s, int *width);
int                     mutt_mb_filter_unprintable        (char **s);
bool                    mutt_mb_get_initials              (const char *name, char *buf, size_t buflen);
bool                    mutt_mb_is_display_corrupting_utf8(wchar_t wc);
bool                    mutt_mb_is_lower                  (const char *s);
bool                    mutt_mb_is_shell_char             (wchar_t ch);
size_t                  mutt_mb_mbstowcs                  (wchar_t **pwbuf, size_t *pwbuflen, size_t i, const char *buf);
int                     mutt_mb_wcswidth                  (const wchar_t *s, size_t n);
int                     mutt_mb_wcwidth                   (wchar_t wc);
int                     mutt_mb_width                     (const char *str, int col, bool indent);
size_t                  mutt_mb_width_ceiling             (const wchar_t *s, size_t n, int w1);
```

### md5 (mutt)

```c
void *                  mutt_md5                          (const char *str, void *buf);
void *                  mutt_md5_bytes                    (const void *buffer, size_t len, void *resbuf);
void *                  mutt_md5_finish_ctx               (struct Md5Ctx *md5ctx, void *resbuf);
void                    mutt_md5_init_ctx                 (struct Md5Ctx *md5ctx);
void                    mutt_md5_process                  (const char *str, struct Md5Ctx *md5ctx);
void                    mutt_md5_process_bytes            (const void *buf, size_t buflen, struct Md5Ctx *md5ctx);
void                    mutt_md5_toascii                  (const void *digest, char *resbuf);
```

### memory (mutt)

```c
void *                  mutt_mem_calloc                   (size_t nmemb, size_t size);
void                    mutt_mem_free                     (void *ptr);
void *                  mutt_mem_malloc                   (size_t size);
void                    mutt_mem_realloc                  (void *ptr, size_t size);
```

### message (core)

```c
void                    message_free                      (struct Message **ptr);
struct Message *        message_new                       (void);
```

### mime (email)

```c
const char *const BodyEncodings[];
const char *const BodyTypes[];
const int IndexHex[];
const char MimeSpecials[];
```

### neomutt (core)

```c
struct NeoMutt *NeoMutt;

bool                    neomutt_account_add               (struct NeoMutt *n, struct Account *a);
bool                    neomutt_account_remove            (struct NeoMutt *n, const struct Account *a);
void                    neomutt_free                      (struct NeoMutt **ptr);
void                    neomutt_mailboxlist_clear         (struct MailboxList *ml);
size_t                  neomutt_mailboxlist_get_all       (struct MailboxList *head, struct NeoMutt *n, enum MailboxType type);
struct NeoMutt *        neomutt_new                       (struct ConfigSet *cs);
```

### notify (mutt)

```c
void                    notify_free                       (struct Notify **ptr);
struct Notify *         notify_new                        (void);
bool                    notify_observer_add               (struct Notify *notify, enum NotifyType type, observer_t callback, void *global_data);
bool                    notify_observer_remove            (struct Notify *notify, const observer_t callback, const void *global_data);
void                    notify_observer_remove_all        (struct Notify *notify);
bool                    notify_send                       (struct Notify *notify, enum NotifyType event_type, int event_subtype, void *event_data);
void                    notify_set_parent                 (struct Notify *notify, struct Notify *parent);
```

### parameter (email)

```c
bool                    mutt_param_cmp_strict             (const struct ParameterList *pl1, const struct ParameterList *pl2);
void                    mutt_param_delete                 (struct ParameterList *pl, const char *attribute);
void                    mutt_param_free                   (struct ParameterList *pl);
void                    mutt_param_free_one               (struct Parameter **p);
char *                  mutt_param_get                    (const struct ParameterList *pl, const char *s);
struct Parameter *      mutt_param_new                    (void);
void                    mutt_param_set                    (struct ParameterList *pl, const char *attribute, const char *value);
```

### parse (email)

```c
void                    mutt_auto_subscribe               (const char *mailto);
int                     mutt_check_encoding               (const char *c);
enum ContentType        mutt_check_mime_type              (const char *s);
char *                  mutt_extract_message_id           (const char *s, size_t *len);
bool                    mutt_is_message_type              (int type, const char *subtype);
bool                    mutt_matches_ignore               (const char *s);
void                    mutt_parse_content_type           (const char *s, struct Body *ct);
bool                    mutt_parse_mailto                 (struct Envelope *env, char **body, const char *src);
struct Body *           mutt_parse_multipart              (FILE *fp, const char *boundary, off_t end_off, bool digest);
void                    mutt_parse_part                   (FILE *fp, struct Body *b);
struct Body *           mutt_read_mime_header             (FILE *fp, bool digest);
int                     mutt_rfc822_parse_line            (struct Envelope *env, struct Email *e, const char *name, size_t name_len, const char *body, bool user_hdrs, bool weed, bool do_2047);
struct Body *           mutt_rfc822_parse_message         (FILE *fp, struct Body *parent);
struct Envelope *       mutt_rfc822_read_header           (FILE *fp, struct Email *e, bool user_hdrs, bool weed);
size_t                  mutt_rfc822_read_line             (FILE *fp, struct Buffer *buf);
```

### path (mutt)

```c
bool                    mutt_path_abbr_folder             (struct Buffer *path, const char *folder);
const char *            mutt_path_basename                (const char *path);
bool                    mutt_path_canon                   (struct Buffer *path, const char *homedir, bool is_dir);
char *                  mutt_path_concat                  (char *dest, const char *dir, const char *file, size_t dlen);
char *                  mutt_path_dirname                 (const char *path);
char *                  mutt_path_escape                  (const char *src);
const char *            mutt_path_getcwd                  (struct Buffer *cwd);
bool                    mutt_path_parent                  (struct Buffer *path);
bool                    mutt_path_pretty                  (struct Buffer *path, const char *homedir, bool is_dir);
size_t                  mutt_path_realpath                (struct Buffer *path);
bool                    mutt_path_tidy                    (struct Buffer *path, bool is_dir);
bool                    mutt_path_tidy_dotdot             (char *buf);
bool                    mutt_path_tidy_slash              (char *buf, bool is_dir);
bool                    mutt_path_tilde                   (struct Buffer *path, const char *homedir);
bool                    mutt_path_to_absolute             (char *path, const char *reference);
```

### pool (mutt)

```c
void                    buf_pool_cleanup                  (void);
struct Buffer *         buf_pool_get                      (void);
void                    buf_pool_release                  (struct Buffer **ptr);
```

### prex (mutt)

```c
regmatch_t *            mutt_prex_capture                 (enum Prex which, const char *str);
void                    mutt_prex_cleanup                 (void);
```

### qsort_r (mutt)

```c
void                    mutt_qsort_r                      (void *base, size_t nmemb, size_t size, sort_t compar, void *sdata);
```

### random (mutt)

```c
uint32_t                mutt_rand32                       (void);
uint64_t                mutt_rand64                       (void);
void                    mutt_rand_base32                  (char *buf, size_t buflen);
```

### regex (mutt)

```c
bool                    mutt_regex_capture                (const struct Regex *regex, const char *str, size_t nmatch, regmatch_t matches());
struct Regex *          mutt_regex_compile                (const char *str, uint16_t flags);
void                    mutt_regex_free                   (struct Regex **ptr);
bool                    mutt_regex_match                  (const struct Regex *regex, const char *str);
struct Regex *          mutt_regex_new                    (const char *str, uint32_t flags, struct Buffer *err);
int                     mutt_regexlist_add                (struct RegexList *rl, const char *str, uint16_t flags, struct Buffer *err);
void                    mutt_regexlist_free               (struct RegexList *rl);
bool                    mutt_regexlist_match              (struct RegexList *rl, const char *str);
struct RegexNode *      mutt_regexlist_new                (void);
int                     mutt_regexlist_remove             (struct RegexList *rl, const char *str);
int                     mutt_replacelist_add              (struct ReplaceList *rl, const char *pat, const char *templ, struct Buffer *err);
char *                  mutt_replacelist_apply            (struct ReplaceList *rl, char *buf, size_t buflen, const char *str);
void                    mutt_replacelist_free             (struct ReplaceList *rl);
bool                    mutt_replacelist_match            (struct ReplaceList *rl, char *buf, size_t buflen, const char *str);
struct Replace *        mutt_replacelist_new              (void);
int                     mutt_replacelist_remove           (struct ReplaceList *rl, const char *pat);
```

### rfc2047 (email)

```c
void                    rfc2047_decode                    (char **pd);
void                    rfc2047_decode_addrlist           (struct AddressList *al);
void                    rfc2047_decode_envelope           (struct Envelope *env);
void                    rfc2047_encode                    (char **pd, const char *specials, int col, const struct Slist *charsets);
void                    rfc2047_encode_addrlist           (struct AddressList *al, const char *tag);
void                    rfc2047_encode_envelope           (struct Envelope *env);
```

### rfc2231 (email)

```c
void                    rfc2231_decode_parameters         (struct ParameterList *pl);
size_t                  rfc2231_encode_string             (struct ParameterList *head, const char *attribute, char *value);
```

### signal (mutt)

```c
void                    mutt_sig_allow_interrupt          (bool allow);
void                    mutt_sig_block                    (void);
void                    mutt_sig_block_system             (void);
void                    mutt_sig_empty_handler            (int sig);
void                    mutt_sig_exit_handler             (int sig);
void                    mutt_sig_init                     (sig_handler_t sig_fn, sig_handler_t exit_fn, sig_handler_t segv_fn);
void                    mutt_sig_unblock                  (void);
void                    mutt_sig_unblock_system           (bool restore);
```

### slist (mutt)

```c
struct Slist *          slist_add_list                    (struct Slist *list, const struct Slist *add);
struct Slist *          slist_add_string                  (struct Slist *list, const char *str);
bool                    slist_compare                     (const struct Slist *a, const struct Slist *b);
struct Slist *          slist_dup                         (const struct Slist *list);
struct Slist *          slist_empty                       (struct Slist **list);
void                    slist_free                        (struct Slist **ptr);
bool                    slist_is_empty                    (const struct Slist *list);
bool                    slist_is_member                   (const struct Slist *list, const char *str);
struct Slist *          slist_new                         (uint32_t flags);
struct Slist *          slist_parse                       (const char *str, uint32_t flags);
struct Slist *          slist_remove_string               (struct Slist *list, const char *str);
int                     slist_to_buffer                   (const struct Slist *list, struct Buffer *buf);
```

### state (mutt)

```c
void                    state_attach_puts                 (struct State *state, const char *t);
const char *            state_attachment_marker           (void);
void                    state_mark_attach                 (struct State *state);
void                    state_mark_protected_header       (struct State *state);
void                    state_prefix_put                  (struct State *state, const char *buf, size_t buflen);
void                    state_prefix_putc                 (struct State *state, char c);
int                     state_printf                      (struct State *state, const char *fmt, ...);
const char *            state_protected_header_marker     (void);
int                     state_putws                       (struct State *state, const wchar_t *ws);
```

### string (mutt)

```c
int                     mutt_istr_cmp                     (const char *a, const char *b);
bool                    mutt_istr_equal                   (const char *a, const char *b);
const char *            mutt_istr_find                    (const char *haystack, const char *needle);
int                     mutt_istr_remall                  (char *str, const char *target);
size_t                  mutt_istr_startswith              (const char *str, const char *prefix);
int                     mutt_istrn_cmp                    (const char *a, const char *b, size_t num);
bool                    mutt_istrn_equal                  (const char *a, const char *b, size_t num);
const char *            mutt_istrn_rfind                  (const char *haystack, size_t haystack_length, const char *needle);
void                    mutt_str_adjust                   (char **ptr);
void                    mutt_str_append_item              (char **str, const char *item, char sep);
int                     mutt_str_asprintf                 (char **strp, const char *fmt, ...);
char *                  mutt_str_cat                      (char *buf, size_t buflen, const char *s);
int                     mutt_str_cmp                      (const char *a, const char *b);
int                     mutt_str_coll                     (const char *a, const char *b);
size_t                  mutt_str_copy                     (char *dest, const char *src, size_t dsize);
void                    mutt_str_dequote_comment          (char *str);
char *                  mutt_str_dup                      (const char *str);
bool                    mutt_str_equal                    (const char *a, const char *b);
const char *            mutt_str_find_word                (const char *src);
const char *            mutt_str_getenv                   (const char *name);
bool                    mutt_str_inline_replace           (char *buf, size_t buflen, size_t xlen, const char *rstr);
bool                    mutt_str_is_ascii                 (const char *str, size_t len);
size_t                  mutt_str_len                      (const char *a);
char *                  mutt_str_lower                    (char *str);
size_t                  mutt_str_lws_len                  (const char *s, size_t n);
size_t                  mutt_str_lws_rlen                 (const char *s, size_t n);
const char *            mutt_str_next_word                (const char *s);
void                    mutt_str_remove_trailing_ws       (char *s);
char *                  mutt_str_replace                  (char **p, const char *s);
char *                  mutt_str_sep                      (char **stringp, const char *delim);
char *                  mutt_str_skip_email_wsp           (const char *s);
char *                  mutt_str_skip_whitespace          (const char *p);
size_t                  mutt_str_startswith               (const char *str, const char *prefix);
const char *            mutt_str_sysexit                  (int err_num);
char *                  mutt_str_upper                    (char *str);
char *                  mutt_strn_cat                     (char *d, size_t l, const char *s, size_t sl);
char *                  mutt_strn_copy                    (char *dest, const char *src, size_t len, size_t dsize);
char *                  mutt_strn_dup                     (const char *begin, size_t len);
bool                    mutt_strn_equal                   (const char *a, const char *b, size_t num);
const char *            mutt_strn_rfind                   (const char *haystack, size_t haystack_length, const char *needle);
```

### tags (email)

```c
struct HashTable *TagFormats;
struct HashTable *TagTransforms;

void                    driver_tags_add                   (struct TagList *list, char *new_tag);
void                    driver_tags_cleanup               (void);
void                    driver_tags_free                  (struct TagList *list);
char *                  driver_tags_get                   (struct TagList *list);
char *                  driver_tags_get_transformed       (struct TagList *list);
char *                  driver_tags_get_transformed_for   (struct TagList *head, const char *name);
char *                  driver_tags_get_with_hidden       (struct TagList *list);
void                    driver_tags_init                  (void);
bool                    driver_tags_replace               (struct TagList *head, const char *tags);
```

### thread (email)

```c
void                    clean_references                  (struct MuttThread *brk, struct MuttThread *cur);
struct Email *          find_virtual                      (struct MuttThread *cur, bool reverse);
void                    insert_message                    (struct MuttThread **add, struct MuttThread *parent, struct MuttThread *cur);
bool                    is_descendant                     (const struct MuttThread *a, const struct MuttThread *b);
void                    mutt_break_thread                 (struct Email *e);
void                    unlink_message                    (struct MuttThread **old, struct MuttThread *cur);
```

### tmp (core)

```c
void                    buf_mktemp_full                   (struct Buffer *buf, const char *prefix, const char *suffix, const char *src, int line);
FILE *                  mutt_file_mkstemp_full            (const char *file, int line, const char *func);
```

### url (email)

```c
enum UrlScheme          url_check_scheme                  (const char *str);
void                    url_free                          (struct Url **ptr);
struct Url *            url_parse                         (const char *src);
int                     url_pct_decode                    (char *s);
void                    url_pct_encode                    (char *buf, size_t buflen, const char *src);
int                     url_tobuffer                      (struct Url *url, struct Buffer *buf, uint8_t flags);
int                     url_tostring                      (struct Url *url, char *dest, size_t len, uint8_t flags);
```

