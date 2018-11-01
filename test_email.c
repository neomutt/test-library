#include "config.h"
#include <errno.h>
#include <locale.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mutt/mutt.h"
#include "email/lib.h"

void test_address(void)
{
  // int AddressError;
  // const char *const AddressErrors[];
  // const char AddressSpecials[];

  // struct Address *    mutt_addr_append                  (struct Address **a, struct Address *b, bool prune);
  // void                mutt_addr_cat                     (char *buf, size_t buflen, const char *value, const char *specials);
  // bool                mutt_addr_cmp                     (struct Address *a, struct Address *b);
  // bool                mutt_addr_cmp_strict              (const struct Address *a, const struct Address *b);
  // struct Address *    mutt_addr_copy                    (struct Address *addr);
  // struct Address *    mutt_addr_copy_list               (struct Address *addr, bool prune);
  // const char *        mutt_addr_for_display             (struct Address *a);
  // void                mutt_addr_free                    (struct Address **p);
  // int                 mutt_addr_has_recips              (struct Address *a);
  // bool                mutt_addr_is_intl                 (struct Address *a);
  // bool                mutt_addr_is_local                (struct Address *a);
  // int                 mutt_addr_mbox_to_udomain         (const char *mbox, char **user, char **domain);
  // struct Address *    mutt_addr_new                     (void);
  // struct Address *    mutt_addr_parse_list              (struct Address *top, const char *s);
  // struct Address *    mutt_addr_parse_list2             (struct Address *p, const char *s);
  // void                mutt_addr_qualify                 (struct Address *addr, const char *host);
  // int                 mutt_addr_remove_from_list        (struct Address **a, const char *mailbox);
  // bool                mutt_addr_search                  (struct Address *a, struct Address *lst);
  // void                mutt_addr_set_intl                (struct Address *a, char *intl_mailbox);
  // void                mutt_addr_set_local               (struct Address *a, char *local_mailbox);
  // bool                mutt_addr_valid_msgid             (const char *msgid);
  // size_t              mutt_addr_write                   (char *buf, size_t buflen, struct Address *addr, bool display);
  // void                mutt_addr_write_single            (char *buf, size_t buflen, struct Address *addr, bool display);
  // struct Address *    mutt_addrlist_dedupe              (struct Address *addr);
  // int                 mutt_addrlist_to_intl             (struct Address *a, char **err);
  // int                 mutt_addrlist_to_local            (struct Address *a);

  struct Address *a = mutt_addr_new();
  mutt_addr_free(&a);
}

void test_attach(void)
{
  // void                mutt_actx_add_attach              (struct AttachCtx *actx, struct AttachPtr *attach);
  // void                mutt_actx_add_body                (struct AttachCtx *actx, struct Body *new_body);
  // void                mutt_actx_add_fp                  (struct AttachCtx *actx, FILE *new_fp);
  // void                mutt_actx_free                    (struct AttachCtx **pactx);
  // void                mutt_actx_free_entries            (struct AttachCtx *actx);

  struct AttachCtx *actx = mutt_mem_calloc(1, sizeof(*actx));
  mutt_actx_free(&actx);
}

void test_body(void)
{
  // bool                mutt_body_cmp_strict              (const struct Body *b1, const struct Body *b2);
  // void                mutt_body_free                    (struct Body **p);
  // struct Body *       mutt_body_new                     (void);

  struct Body *b = mutt_body_new();
  mutt_body_free(&b);
}

void test_email(void)
{
  // bool                mutt_email_cmp_strict            (const struct Email *e1, const struct Email *e2);
  // void                mutt_email_free                  (struct Email **e);
  // struct Email *      mutt_email_new                   (void);

  struct Email *e = mutt_email_new();
  mutt_email_free(&e);
}

void test_email_globals(void)
{
  // bool MarkOld;
  // struct Regex *ReplyRegex;
  // char *SendCharset;
  // char *SpamSeparator;
  // bool Weed;

  // struct ListHead Ignore;
  // struct RegexList NoSpamList;
  // struct ReplaceList SpamList;
  // struct ListHead UnIgnore;

  MarkOld = true;
}

void test_envelope(void)
{
  // bool                mutt_env_cmp_strict               (const struct Envelope *e1, const struct Envelope *e2); void                mutt_env_free                     (struct Envelope **p);
  // void                mutt_env_free                     (struct Envelope **p);
  // void                mutt_env_merge                    (struct Envelope *base, struct Envelope **extra);
  // struct Envelope *   mutt_env_new                      (void);
  // int                 mutt_env_to_intl                  (struct Envelope *env, const char **tag, char **err);
  // void                mutt_env_to_local                 (struct Envelope *e);

  struct Envelope *env = mutt_env_new();
  mutt_env_free(&env);
}

void test_from(void)
{
  // bool                is_from                           (const char *s, char *path, size_t pathlen, time_t *tp);

  char buf[256];
  const char *str = "From rich@flatcap.org Fri Jul 13 20:43:24 2018";
  time_t date = 0;

  is_from(str, buf, sizeof(buf), &date);
}

void test_idna(void)
{
  // bool IdnDecode;
  // bool IdnEncode;

  // char *              mutt_idna_intl_to_local           (const char *user, const char *domain, int flags);
  // char *              mutt_idna_local_to_intl           (const char *user, const char *domain);
  // const char *        mutt_idna_print_version           (void);
  // int                 mutt_idna_to_ascii_lz             (const char *input, char **output, int flags);

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

void test_mime(void)
{
  // const int IndexHex[];
  // const char *const BodyTypes[];
  // const char *const BodyEncodings[];
  // const char MimeSpecials[];

  printf("%s\n", BodyEncodings[0]);
}

void test_parameter(void)
{
  // bool                mutt_param_cmp_strict             (const struct ParameterList *p1, const struct ParameterList *p2);
  // void                mutt_param_delete                 (struct ParameterList *p, const char *attribute);
  // void                mutt_param_free                   (struct ParameterList *p);
  // void                mutt_param_free_one               (struct Parameter **p);
  // char *              mutt_param_get                    (const struct ParameterList *p, const char *s);
  // struct Parameter *  mutt_param_new                    (void);
  // void                mutt_param_set                    (struct ParameterList *p, const char *attribute, const char *value);

  mutt_param_cmp_strict(NULL, NULL);
}

void test_parse(void)
{
  // int                 mutt_check_encoding               (const char *c);
  // int                 mutt_check_mime_type              (const char *s);
  // char *              mutt_extract_message_id           (const char *s, const char **saveptr);
  // bool                mutt_is_message_type              (int type, const char *subtype);
  // bool                mutt_matches_ignore               (const char *s);
  // void                mutt_parse_content_type           (char *s, struct Body *ct);
  // struct Body *       mutt_parse_multipart              (FILE *fp, const char *boundary, off_t end_off, bool digest);
  // void                mutt_parse_part                   (FILE *fp, struct Body *b);
  // struct Body *       mutt_read_mime_header             (FILE *fp, bool digest);
  // int                 mutt_rfc822_parse_line            (struct Envelope *env, struct Email *e, char *line, char *p, bool user_hdrs, bool weed, bool do_2047);
  // struct Body *       mutt_rfc822_parse_message         (FILE *fp, struct Body *parent);
  // struct Envelope *   mutt_rfc822_read_header           (FILE *f, struct Email *e, bool user_hdrs, bool weed);
  // char *              mutt_rfc822_read_line             (FILE *f, char *line, size_t *linelen);

  mutt_check_encoding("quoted-printable");
}

void test_path(void)
{
  // bool                mutt_path_abbr_folder             (char *buf, size_t buflen, const char *folder);
  // const char *        mutt_path_basename                (const char *f);
  // bool                mutt_path_canon                   (char *buf, size_t buflen, const char *homedir);
  // char *              mutt_path_concat                  (char *d, const char *dir, const char *fname, size_t l);
  // char *              mutt_path_concatn                 (char *dst, size_t dstlen, const char *dir, size_t dirlen, const char *fname, size_t fnamelen);
  // char *              mutt_path_dirname                 (const char *path);
  // bool                mutt_path_parent                  (char *buf, size_t buflen);
  // bool                mutt_path_pretty                  (char *buf, size_t buflen, const char *homedir);
  // size_t              mutt_path_realpath                (char *buf);
  // bool                mutt_path_tidy                    (char *buf);
  // bool                mutt_path_tidy_dotdot             (char *buf);
  // bool                mutt_path_tidy_slash              (char *buf);
  // int                 mutt_path_to_absolute             (char *path, const char *reference);

  mutt_path_basename("/home/mutt/file");
}

void test_rfc2047(void)
{
  // void                rfc2047_decode                    (char **pd);
  // void                rfc2047_decode_addrlist           (struct Address *a);
  // void                rfc2047_encode                    (char **pd, const char *specials, int col, const char *charsets);
  // void                rfc2047_encode_addrlist           (struct Address *addr, const char *tag);

  char *str = strdup("한국어 Русский 义勇军");

  mutt_str_replace(&Charset, "utf-8");
  rfc2047_encode(&str, MimeSpecials, 0, NULL);

  printf("%s\n", str);
  FREE(&str);
  FREE(&Charset);
}

void test_rfc2231(void)
{
  // bool Rfc2047Parameters;

  // void                rfc2231_decode_parameters         (struct ParameterList *p);
  // int                 rfc2231_encode_string             (char **pd);

  char *str = strdup("한국어 Русский 义勇军");
  rfc2231_encode_string(&str);
}

void test_tags(void)
{
  // char *HiddenTags;
  // struct Hash *TagTransforms;

  // void                driver_tags_free                  (struct TagHead *head);
  // char *              driver_tags_get                   (struct TagHead *head);
  // char *              driver_tags_get_transformed       (struct TagHead *head);
  // char *              driver_tags_get_transformed_for   (char *name, struct TagHead *head);
  // char *              driver_tags_get_with_hidden       (struct TagHead *head);
  // bool                driver_tags_replace               (struct TagHead *head, char *tags);

  driver_tags_free(NULL);
}

void test_thread(void)
{
  // void                clean_references                  (struct MuttThread *brk, struct MuttThread *cur);
  // struct Email *      find_virtual                      (struct MuttThread *cur, int reverse);
  // void                insert_message                    (struct MuttThread **new, struct MuttThread *newparent, struct MuttThread *cur);
  // bool                is_descendant                     (struct MuttThread *a, struct MuttThread *b);
  // void                mutt_break_thread                 (struct Email *e);
  // void                thread_hash_destructor            (int type, void *obj, intptr_t data);
  // void                unlink_message                    (struct MuttThread **old, struct MuttThread *cur);

  is_descendant(NULL, NULL);
}

void test_url(void)
{
  // enum UrlScheme      url_check_scheme                  (const char *s);
  // void                url_free                          (struct Url *u);
  // int                 url_parse                         (struct Url *u, char *src);
  // int                 url_pct_decode                    (char *s);
  // void                url_pct_encode                    (char *buf, size_t buflen, const char *src);
  // int                 url_tostring                      (struct Url *u, char *buf, size_t buflen, int flags);

  url_check_scheme("imaps://host.com");
}

int main()
{
  test_address();
  test_attach();
  test_body();
  test_email();
  test_email_globals();
  test_envelope();
  test_from();
  test_idna();
  test_mime();
  test_parameter();
  test_parse();
  test_path();
  test_rfc2047();
  test_rfc2231();
  test_tags();
  test_thread();
  test_url();

  return 0;
}
