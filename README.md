# Test Code for NeoMutt Libraries

## Notes

- They work for me, YMMV
- They may get deleted without warning
- They expect NeoMutt to be built in `../neo`

## Samples

- `test_conn` looks up a hostname
- `test_hcache` creates an entry in the header cache and retrieves it
- `test_lib` calls a function from each of the library source files

## Library (415 functions)

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
int AddressError;
const char *const AddressErrors[];
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
bool                    mutt_addr_valid_msgid             (const char *msgid);
size_t                  mutt_addr_write                   (char *buf, size_t buflen, struct Address *addr, bool display);
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
bool                    mutt_addrlist_search              (const struct Address *needle, const struct AddressList *haystack);
int                     mutt_addrlist_to_intl             (struct AddressList *al, char **err);
int                     mutt_addrlist_to_local            (struct AddressList *al);
size_t                  mutt_addrlist_write               (char *buf, size_t buflen, const struct AddressList *al, bool display);
```

### attach (email)

```c
void                    mutt_actx_add_attach              (struct AttachCtx *actx, struct AttachPtr *attach);
void                    mutt_actx_add_body                (struct AttachCtx *actx, struct Body *new_body);
void                    mutt_actx_add_fp                  (struct AttachCtx *actx, FILE *fp_new);
void                    mutt_actx_entries_free            (struct AttachCtx *actx);
void                    mutt_actx_free                    (struct AttachCtx **ptr);
struct AttachCtx *      mutt_actx_new                     (void);
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
struct Body *           mutt_body_new                     (void);
```

### buffer (mutt)

```c
int                     mutt_buffer_add_printf            (struct Buffer *buf, const char *fmt, ...);
size_t                  mutt_buffer_addch                 (struct Buffer *buf, char c);
size_t                  mutt_buffer_addstr                (struct Buffer *buf, const char *s);
size_t                  mutt_buffer_addstr_n              (struct Buffer *buf, const char *s, size_t len);
void                    mutt_buffer_alloc                 (struct Buffer *buf, size_t new_size);
size_t                  mutt_buffer_concat_path           (struct Buffer *buf, const char *dir, const char *fname);
size_t                  mutt_buffer_concatn_path          (struct Buffer *buf, const char *dir, size_t dirlen, const char *fname, size_t fnamelen);
size_t                  mutt_buffer_copy                  (struct Buffer *dst, const struct Buffer *src);
void                    mutt_buffer_dealloc               (struct Buffer *buf);
void                    mutt_buffer_fix_dptr              (struct Buffer *buf);
struct Buffer *         mutt_buffer_init                  (struct Buffer *buf);
bool                    mutt_buffer_is_empty              (const struct Buffer *buf);
size_t                  mutt_buffer_len                   (const struct Buffer *buf);
struct Buffer           mutt_buffer_make                  (size_t size);
int                     mutt_buffer_printf                (struct Buffer *buf, const char *fmt, ...);
void                    mutt_buffer_reset                 (struct Buffer *buf);
size_t                  mutt_buffer_strcpy                (struct Buffer *buf, const char *s);
size_t                  mutt_buffer_strcpy_n              (struct Buffer *buf, const char *s, size_t len);
char *                  mutt_buffer_strdup                (struct Buffer *buf);
size_t                  mutt_buffer_substrcpy             (struct Buffer *buf, const char *beg, const char *end);
```

### charset (mutt)

```c
char *C_AssumedCharset;
char *C_Charset;
bool CharsetIsUtf8;
wchar_t ReplacementChar;
const struct MimeNames PreferredMimeNames[];

void                    mutt_ch_canonical_charset         (char *buf, size_t buflen, const char *name);
const char *            mutt_ch_charset_lookup            (const char *chs);
int                     mutt_ch_check                     (const char *s, size_t slen, const char *from, const char *to);
bool                    mutt_ch_check_charset             (const char *cs, bool strict);
char *                  mutt_ch_choose                    (const char *fromcode, const char *charsets, const char *u, size_t ulen, char **d, size_t *dlen);
bool                    mutt_ch_chscmp                    (const char *cs1, const char *cs2);
int                     mutt_ch_convert_nonmime_string    (char **ps);
int                     mutt_ch_convert_string            (char **ps, const char *from, const char *to, int flags);
int                     mutt_ch_fgetconv                  (struct FgetConv *fc);
void                    mutt_ch_fgetconv_close            (struct FgetConv **fc);
struct FgetConv *       mutt_ch_fgetconv_open             (FILE *fp, const char *from, const char *to, int flags);
char *                  mutt_ch_fgetconvs                 (char *buf, size_t buflen, struct FgetConv *fc);
char *                  mutt_ch_get_default_charset       (void);
char *                  mutt_ch_get_langinfo_charset      (void);
size_t                  mutt_ch_iconv                     (iconv_t cd, const char **inbuf, size_t *inbytesleft, char **outbuf, size_t *outbytesleft, const char **inrepls, const char *outrepl, int *iconverrno);
const char *            mutt_ch_iconv_lookup              (const char *chs);
iconv_t                 mutt_ch_iconv_open                (const char *tocode, const char *fromcode, int flags);
bool                    mutt_ch_lookup_add                (enum LookupType type, const char *pat, const char *replace, struct Buffer *err);
void                    mutt_ch_lookup_remove             (void);
void                    mutt_ch_set_charset               (const char *charset);
```

### date (mutt)

```c
time_t                  mutt_date_add_timeout             (time_t now, long timeout);
int                     mutt_date_check_month             (const char *s);
time_t                  mutt_date_epoch                   (void);
uint64_t                mutt_date_epoch_ms                (void);
struct tm               mutt_date_gmtime                  (time_t t);
bool                    mutt_date_is_day_name             (const char *s);
time_t                  mutt_date_local_tz                (time_t t);
struct tm               mutt_date_localtime               (time_t t);
size_t                  mutt_date_localtime_format        (char *buf, size_t buflen, const char *format, time_t t);
char *                  mutt_date_make_date               (char *buf, size_t buflen);
int                     mutt_date_make_imap               (char *buf, size_t buflen, time_t timestamp);
time_t                  mutt_date_make_time               (struct tm *t, bool local);
int                     mutt_date_make_tls                (char *buf, size_t buflen, time_t timestamp);
void                    mutt_date_normalize_time          (struct tm *tm);
time_t                  mutt_date_parse_date              (const char *s, struct Tz *tz_out);
time_t                  mutt_date_parse_imap              (const char *s);
void                    mutt_date_sleep_ms                (size_t ms);
```

### email (email)

```c
bool                    email_cmp_strict                  (const struct Email *e1, const struct Email *e2);
void                    email_free                        (struct Email **ptr);
struct Email *          email_new                         (void);
size_t                  email_size                        (const struct Email *e);
int                     emaillist_add_email               (struct EmailList *el, struct Email *e);
void                    emaillist_clear                   (struct EmailList *el);
```

### email_globals (email)

```c
bool C_MarkOld;
struct Regex *C_ReplyRegex;
char *C_SendCharset;
char *C_SpamSeparator;
bool C_Weed;

struct ListHead Ignore;
struct RegexList NoSpamList;
struct ReplaceList SpamList;
struct ListHead UnIgnore;
```

### envelope (email)

```c
void                    mutt_autocrypthdr_free            (struct AutocryptHeader **p);
struct AutocryptHeader *mutt_autocrypthdr_new             (void);
bool                    mutt_env_cmp_strict               (const struct Envelope *e1, const struct Envelope *e2);
void                    mutt_env_free                     (struct Envelope **ptr);
void                    mutt_env_merge                    (struct Envelope *base, struct Envelope **extra);
struct Envelope *       mutt_env_new                      (void);
int                     mutt_env_to_intl                  (struct Envelope *env, const char **tag, char **err);
void                    mutt_env_to_local                 (struct Envelope *env);
```

### envlist (mutt)

```c
void                    mutt_envlist_free                 (void);
char **                 mutt_envlist_getlist              (void);
void                    mutt_envlist_init                 (char *envp[]);
bool                    mutt_envlist_set                  (const char *name, const char *value, bool overwrite);
bool                    mutt_envlist_unset                (const char *name);
```

### exit (mutt)

```c
void                    mutt_exit                         (int code);
```

### file (mutt)

```c
char *C_Tmpdir;

void                    mutt_buffer_file_expand_fmt_quote (struct Buffer *dest, const char *fmt, const char *src);
void                    mutt_buffer_quote_filename        (struct Buffer *buf, const char *filename, bool add_outer);
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
void                    mutt_file_get_stat_timespec       (struct timespec *dest, struct stat *sb, enum MuttStatType type);
bool                    mutt_file_iter_line               (struct MuttFileIter *iter, FILE *fp, int flags);
int                     mutt_file_lock                    (int fd, bool excl, bool timeout);
bool                    mutt_file_map_lines               (mutt_file_map_t func, void *user_data, FILE *fp, int flags);
int                     mutt_file_mkdir                   (const char *path, mode_t mode);
FILE *                  mutt_file_mkstemp_full            (const char *file, int line, const char *func);
int                     mutt_file_open                    (const char *path, int flags);
size_t                  mutt_file_quote_filename          (const char *filename, char *buf, size_t buflen);
char *                  mutt_file_read_keyword            (const char *file, char *buf, size_t buflen);
char *                  mutt_file_read_line               (char *line, size_t *size, FILE *fp, int *line_num, int flags);
int                     mutt_file_rename                  (const char *oldfile, const char *newfile);
int                     mutt_file_rmtree                  (const char *path);
int                     mutt_file_safe_rename             (const char *src, const char *target);
void                    mutt_file_sanitize_filename       (char *path, bool slash);
int                     mutt_file_sanitize_regex          (struct Buffer *dest, const char *src);
void                    mutt_file_set_mtime               (const char *from, const char *to);
int                     mutt_file_stat_compare            (struct stat *sba, enum MuttStatType sba_type, struct stat *sbb, enum MuttStatType sbb_type);
int                     mutt_file_stat_timespec_compare   (struct stat *sba, enum MuttStatType type, struct timespec *b);
int                     mutt_file_symlink                 (const char *oldpath, const char *newpath);
int                     mutt_file_timespec_compare        (struct timespec *a, struct timespec *b);
void                    mutt_file_touch_atime             (int fd);
void                    mutt_file_unlink                  (const char *s);
void                    mutt_file_unlink_empty            (const char *path);
int                     mutt_file_unlock                  (int fd);
```

### from (email)

```c
bool                    is_from                           (const char *s, char *path, size_t pathlen, time_t *tp);
```

### group (address)

```c
bool                    mutt_group_match                  (struct Group *g, const char *s);
void                    mutt_grouplist_add                (struct GroupList *gl, struct Group *group);
void                    mutt_grouplist_add_addrlist       (struct GroupList *gl, struct AddressList *al);
int                     mutt_grouplist_add_regex          (struct GroupList *gl, const char *s, int flags, struct Buffer *err);
void                    mutt_grouplist_clear              (struct GroupList *gl);
void                    mutt_grouplist_destroy            (struct GroupList *gl);
void                    mutt_grouplist_free               (void);
void                    mutt_grouplist_init               (void);
int                     mutt_grouplist_remove_addrlist    (struct GroupList *gl, struct AddressList *al);
int                     mutt_grouplist_remove_regex       (struct GroupList *gl, const char *s);
struct Group *          mutt_pattern_group                (const char *pat);
```

### hash (mutt)

```c
void                    mutt_hash_delete                  (struct Hash *table, const char *strkey, const void *data);
void *                  mutt_hash_find                    (const struct Hash *table, const char *strkey);
struct HashElem *       mutt_hash_find_bucket             (const struct Hash *table, const char *strkey);
struct HashElem *       mutt_hash_find_elem               (const struct Hash *table, const char *strkey);
void                    mutt_hash_free                    (struct Hash **ptr);
struct HashElem *       mutt_hash_insert                  (struct Hash *table, const char *strkey, void *data);
void                    mutt_hash_int_delete              (struct Hash *table, unsigned int intkey, const void *data);
void *                  mutt_hash_int_find                (const struct Hash *table, unsigned int intkey);
struct HashElem *       mutt_hash_int_insert              (struct Hash *table, unsigned int intkey, void *data);
struct Hash *           mutt_hash_int_new                 (size_t nelem, HashFlags flags);
struct Hash *           mutt_hash_new                     (size_t nelem, HashFlags flags);
void                    mutt_hash_set_destructor          (struct Hash *table, hashelem_free_t fn, intptr_t fn_data);
struct HashElem *       mutt_hash_typed_insert            (struct Hash *table, const char *strkey, int type, void *data);
struct HashElem *       mutt_hash_walk                    (const struct Hash *table, struct HashWalkState *state);
```

### history (mutt)

```c
short C_History;
char *C_HistoryFile;
bool C_HistoryRemoveDups;
short C_SaveHistory;

void                    mutt_hist_add                     (enum HistoryClass hclass, const char *str, bool save);
bool                    mutt_hist_at_scratch              (enum HistoryClass hclass);
void                    mutt_hist_free                    (void);
void                    mutt_hist_init                    (void);
char *                  mutt_hist_next                    (enum HistoryClass hclass);
char *                  mutt_hist_prev                    (enum HistoryClass hclass);
void                    mutt_hist_read_file               (void);
void                    mutt_hist_reset_state             (enum HistoryClass hclass);
void                    mutt_hist_save_scratch            (enum HistoryClass hclass, const char *str);
int                     mutt_hist_search                  (const char *search_buf, enum HistoryClass hclass, char **matches);
```

### idna (address)

```c
bool C_IdnDecode;
bool C_IdnEncode;

char *                  mutt_idna_intl_to_local           (const char *user, const char *domain, int flags);
char *                  mutt_idna_local_to_intl           (const char *user, const char *domain);
const char *            mutt_idna_print_version           (void);
int                     mutt_idna_to_ascii_lz             (const char *input, char **output, int flags);
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
struct ListHead         mutt_list_str_split               (const char *src, char sep);
```

### logging (mutt)

```c
log_dispatcher_t MuttLogger;

int                     log_disp_file                     (time_t stamp, const char *file, int line, const char *function, enum LogLevel level, ...);
int                     log_disp_null                     (time_t stamp, const char *file, int line, const char *function, enum LogLevel level, ...);
int                     log_disp_queue                    (time_t stamp, const char *file, int line, const char *function, enum LogLevel level, ...);
int                     log_disp_terminal                 (time_t stamp, const char *file, int line, const char *function, enum LogLevel level, ...);
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
void                    mailbox_changed                   (struct Mailbox *m, enum MailboxNotification action);
struct Mailbox *        mailbox_find                      (const char *path);
struct Mailbox *        mailbox_find_name                 (const char *name);
void                    mailbox_free                      (struct Mailbox **ptr);
struct Mailbox *        mailbox_new                       (void);
void                    mailbox_size_add                  (struct Mailbox *m, const struct Email *e);
void                    mailbox_size_sub                  (struct Mailbox *m, const struct Email *e);
void                    mailbox_update                    (struct Mailbox *m);
```

### mapping (mutt)

```c
const char *            mutt_map_get_name                 (int val, const struct Mapping *map);
int                     mutt_map_get_value                (const char *name, const struct Mapping *map);
```

### mbyte (mutt)

```c
bool OptLocales;

int                     mutt_mb_charlen                   (const char *s, int *width);
int                     mutt_mb_filter_unprintable        (char **s);
bool                    mutt_mb_get_initials              (const char *name, char *buf, size_t buflen);
bool                    mutt_mb_is_display_corrupting_utf8(wchar_t wc);
bool                    mutt_mb_is_lower                  (const char *s);
bool                    mutt_mb_is_shell_char             (wchar_t ch);
size_t                  mutt_mb_mbstowcs                  (wchar_t **pwbuf, size_t *pwbuflen, size_t i, char *buf);
void                    mutt_mb_wcstombs                  (char *dest, size_t dlen, const wchar_t *src, size_t slen);
int                     mutt_mb_wcswidth                  (const wchar_t *s, size_t n);
int                     mutt_mb_wcwidth                   (wchar_t wc);
int                     mutt_mb_width                     (const char *str, int col, bool display);
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

### mime (email)

```c
const int IndexHex[];
const char *const BodyTypes[];
const char *const BodyEncodings[];
const char MimeSpecials[];
```

### neomutt (core)

```c
struct NeoMutt *NeoMutt;

bool                    neomutt_account_add               (struct NeoMutt *n, struct Account *a);
bool                    neomutt_account_remove            (struct NeoMutt *n, struct Account *a);
void                    neomutt_free                      (struct NeoMutt **ptr);
void                    neomutt_mailboxlist_clear         (struct MailboxList *ml);
struct MailboxList      neomutt_mailboxlist_get_all       (struct NeoMutt *n, enum MailboxType magic);
struct NeoMutt *        neomutt_new                       (struct ConfigSet *cs);
```

### notify (mutt)

```c
void                    notify_free                       (struct Notify **ptr);
struct Notify *         notify_new                        (void *object, enum NotifyType type);
bool                    notify_observer_add               (struct Notify *notify, enum NotifyType type, int subtype, observer_t callback, intptr_t data);
bool                    notify_observer_remove            (struct Notify *notify, observer_t callback, intptr_t data);
bool                    notify_send                       (struct Notify *notify, int type, int subtype, intptr_t data);
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
char *                  mutt_extract_message_id           (const char *s, const char **saveptr);
bool                    mutt_is_message_type              (int type, const char *subtype);
bool                    mutt_matches_ignore               (const char *s);
void                    mutt_parse_content_type           (const char *s, struct Body *ct);
int                     mutt_parse_mailto                 (struct Envelope *e, char **body, const char *src);
struct Body *           mutt_parse_multipart              (FILE *fp, const char *boundary, off_t end_off, bool digest);
void                    mutt_parse_part                   (FILE *fp, struct Body *b);
struct Body *           mutt_read_mime_header             (FILE *fp, bool digest);
int                     mutt_rfc822_parse_line            (struct Envelope *env, struct Email *e, char *line, char *p, bool user_hdrs, bool weed, bool do_2047);
struct Body *           mutt_rfc822_parse_message         (FILE *fp, struct Body *parent);
struct Envelope *       mutt_rfc822_read_header           (FILE *fp, struct Email *e, bool user_hdrs, bool weed);
char *                  mutt_rfc822_read_line             (FILE *fp, char *line, size_t *linelen);
```

### path (mutt)

```c
bool                    mutt_path_abbr_folder             (char *buf, size_t buflen, const char *folder);
const char *            mutt_path_basename                (const char *f);
bool                    mutt_path_canon                   (char *buf, size_t buflen, const char *homedir);
char *                  mutt_path_concat                  (char *d, const char *dir, const char *fname, size_t l);
char *                  mutt_path_dirname                 (const char *path);
char *                  mutt_path_escape                  (const char *src);
const char *            mutt_path_getcwd                  (struct Buffer *cwd);
bool                    mutt_path_parent                  (char *buf, size_t buflen);
bool                    mutt_path_pretty                  (char *buf, size_t buflen, const char *homedir);
size_t                  mutt_path_realpath                (char *buf);
bool                    mutt_path_tidy                    (char *buf);
bool                    mutt_path_tidy_dotdot             (char *buf);
bool                    mutt_path_tidy_slash              (char *buf);
bool                    mutt_path_to_absolute             (char *path, const char *reference);
```

### pool (mutt)

```c
void                    mutt_buffer_pool_free             (void);
struct Buffer *         mutt_buffer_pool_get              (void);
void                    mutt_buffer_pool_release          (struct Buffer **pbuf);
```

### regex (mutt)

```c
bool                    mutt_regex_capture                (const struct Regex *regex, const char *str, size_t nmatch, regmatch_t matches[]);
struct Regex *          mutt_regex_compile                (const char *str, int flags);
void                    mutt_regex_free                   (struct Regex **r);
bool                    mutt_regex_match                  (const struct Regex *regex, const char *str);
struct Regex *          mutt_regex_new                    (const char *str, int flags, struct Buffer *err);
int                     mutt_regexlist_add                (struct RegexList *rl, const char *str, int flags, struct Buffer *err);
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
void                    rfc2047_encode                    (char **pd, const char *specials, int col, const char *charsets);
void                    rfc2047_encode_addrlist           (struct AddressList *al, const char *tag);
void                    rfc2047_encode_envelope           (struct Envelope *env);
```

### rfc2231 (email)

```c
bool C_Rfc2047Parameters;

void                    rfc2231_decode_parameters         (struct ParameterList *pl);
struct ParameterList    rfc2231_encode_string             (const char *attribute, char *value);
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
void                    slist_free                        (struct Slist **list);
bool                    slist_is_member                   (const struct Slist *list, const char *str);
struct Slist *          slist_parse                       (const char *str, int flags);
struct Slist *          slist_remove_string               (struct Slist *list, const char *str);
```

### string (mutt)

```c
void                    mutt_str_adjust                   (char **p);
void                    mutt_str_append_item              (char **str, const char *item, char sep);
int                     mutt_str_asprintf                 (char **strp, const char *fmt, ...);
int                     mutt_str_atoi                     (const char *str, int *dst);
int                     mutt_str_atol                     (const char *str, long *dst);
int                     mutt_str_atos                     (const char *str, short *dst);
int                     mutt_str_atoui                    (const char *str, unsigned int *dst);
int                     mutt_str_atoul                    (const char *str, unsigned long *dst);
int                     mutt_str_atoull                   (const char *str, unsigned long long *dst);
void                    mutt_str_dequote_comment          (char *s);
const char *            mutt_str_find_word                (const char *src);
const char *            mutt_str_getenv                   (const char *name);
bool                    mutt_str_inline_replace           (char *buf, size_t buflen, size_t xlen, const char *rstr);
bool                    mutt_str_is_ascii                 (const char *str, size_t len);
bool                    mutt_str_is_email_wsp             (char c);
size_t                  mutt_str_lws_len                  (const char *s, size_t n);
size_t                  mutt_str_lws_rlen                 (const char *s, size_t n);
const char *            mutt_str_next_word                (const char *s);
int                     mutt_str_remall_strcasestr        (char *str, const char *target);
void                    mutt_str_remove_trailing_ws       (char *s);
void                    mutt_str_replace                  (char **p, const char *s);
const char *            mutt_str_rstrnstr                 (const char *haystack, size_t haystack_length, const char *needle);
char *                  mutt_str_skip_email_wsp           (const char *s);
char *                  mutt_str_skip_whitespace          (const char *p);
size_t                  mutt_str_startswith               (const char *str, const char *prefix, enum CaseSensitivity cs);
int                     mutt_str_strcasecmp               (const char *a, const char *b);
const char *            mutt_str_strcasestr               (const char *haystack, const char *needle);
char *                  mutt_str_strcat                   (char *buf, size_t buflen, const char *s);
const char *            mutt_str_strchrnul                (const char *s, char c);
int                     mutt_str_strcmp                   (const char *a, const char *b);
int                     mutt_str_strcoll                  (const char *a, const char *b);
char *                  mutt_str_strdup                   (const char *str);
size_t                  mutt_str_strfcpy                  (char *dest, const char *src, size_t dsize);
const char *            mutt_str_stristr                  (const char *haystack, const char *needle);
size_t                  mutt_str_strlen                   (const char *a);
char *                  mutt_str_strlower                 (char *s);
int                     mutt_str_strncasecmp              (const char *a, const char *b, size_t l);
char *                  mutt_str_strncat                  (char *d, size_t l, const char *s, size_t sl);
int                     mutt_str_strncmp                  (const char *a, const char *b, size_t l);
size_t                  mutt_str_strnfcpy                 (char *dest, const char *src, size_t n, size_t dsize);
char *                  mutt_str_substr_copy              (const char *begin, const char *end, char *buf, size_t buflen);
char *                  mutt_str_substr_dup               (const char *begin, const char *end);
const char *            mutt_str_sysexit                  (int err_num);
int                     mutt_str_word_casecmp             (const char *a, const char *b);
```

### tags (email)

```c
char *C_HiddenTags;
struct Hash *TagTransforms;

void                    driver_tags_free                  (struct TagList *list);
char *                  driver_tags_get                   (struct TagList *list);
char *                  driver_tags_get_transformed       (struct TagList *list);
char *                  driver_tags_get_transformed_for   (struct TagList *head, const char *name);
char *                  driver_tags_get_with_hidden       (struct TagList *list);
bool                    driver_tags_replace               (struct TagList *head, char *tags);
```

### thread (email)

```c
void                    clean_references                  (struct MuttThread *brk, struct MuttThread *cur);
struct Email *          find_virtual                      (struct MuttThread *cur, int reverse);
void                    insert_message                    (struct MuttThread **add, struct MuttThread *parent, struct MuttThread *cur);
bool                    is_descendant                     (struct MuttThread *a, struct MuttThread *b);
void                    mutt_break_thread                 (struct Email *e);
void                    thread_hash_destructor            (int type, void *obj, intptr_t data);
void                    unlink_message                    (struct MuttThread **old, struct MuttThread *cur);
```

### url (email)

```c
enum UrlScheme          url_check_scheme                  (const char *s);
void                    url_free                          (struct Url **u);
struct Url *            url_parse                         (const char *src);
int                     url_pct_decode                    (char *s);
void                    url_pct_encode                    (char *buf, size_t buflen, const char *src);
int                     url_tobuffer                      (struct Url *u, struct Buffer *buf, int flags);
int                     url_tostring                      (struct Url *u, char *dest, size_t len, int flags);
```

