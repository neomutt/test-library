#include "config.h"
#include <errno.h>
#include <locale.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mutt/lib.h"
#include "email/lib.h"

bool C_Autocrypt;

int mutt_autocrypt_process_autocrypt_header(struct Email *e, struct Envelope *env)
{
  return -1;
}

void test_attach(void)
{
  // void                    mutt_actx_add_attach              (struct AttachCtx *actx, struct AttachPtr *attach);
  // void                    mutt_actx_add_body                (struct AttachCtx *actx, struct Body *new_body);
  // void                    mutt_actx_add_fp                  (struct AttachCtx *actx, FILE *fp_new);
  // void                    mutt_actx_entries_free            (struct AttachCtx *actx);
  // void                    mutt_actx_free                    (struct AttachCtx **ptr);
  // struct AttachCtx *      mutt_actx_new                     (void);

  struct AttachCtx *actx = mutt_mem_calloc(1, sizeof(*actx));
  mutt_actx_free(&actx);
}

void test_body(void)
{
  // bool                    mutt_body_cmp_strict              (const struct Body *b1, const struct Body *b2);
  // void                    mutt_body_free                    (struct Body **ptr);
  // char *                  mutt_body_get_charset             (struct Body *b, char *buf, size_t buflen);
  // struct Body *           mutt_body_new                     (void);

  struct Body *b = mutt_body_new();
  mutt_body_free(&b);
}

void test_email(void)
{
  // bool                    email_cmp_strict                  (const struct Email *e1, const struct Email *e2);
  // void                    email_free                        (struct Email **ptr);
  // struct Email *          email_new                         (void);
  // size_t                  email_size                        (const struct Email *e);
  // int                     emaillist_add_email               (struct EmailList *el, struct Email *e);
  // void                    emaillist_clear                   (struct EmailList *el);

  struct Email *e = email_new();
  email_free(&e);
}

void test_email_globals(void)
{
  // bool C_MarkOld;
  // struct Regex *C_ReplyRegex;
  // char *C_SendCharset;
  // char *C_SpamSeparator;
  // bool C_Weed;

  // struct ListHead Ignore;
  // struct RegexList NoSpamList;
  // struct ReplaceList SpamList;
  // struct ListHead UnIgnore;

  C_MarkOld = true;
}

void test_envelope(void)
{
  // void                    mutt_autocrypthdr_free            (struct AutocryptHeader **p);
  // struct AutocryptHeader *mutt_autocrypthdr_new             (void);
  // bool                    mutt_env_cmp_strict               (const struct Envelope *e1, const struct Envelope *e2);
  // void                    mutt_env_free                     (struct Envelope **ptr);
  // void                    mutt_env_merge                    (struct Envelope *base, struct Envelope **extra);
  // struct Envelope *       mutt_env_new                      (void);
  // int                     mutt_env_to_intl                  (struct Envelope *env, const char **tag, char **err);
  // void                    mutt_env_to_local                 (struct Envelope *env);

  struct Envelope *env = mutt_env_new();
  mutt_env_free(&env);
}

void test_from(void)
{
  // bool                    is_from                           (const char *s, char *path, size_t pathlen, time_t *tp);

  char buf[256];
  const char *str = "From rich@flatcap.org Fri Jul 13 20:43:24 2018";
  time_t date = 0;

  is_from(str, buf, sizeof(buf), &date);
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
  // bool                    mutt_param_cmp_strict             (const struct ParameterList *pl1, const struct ParameterList *pl2);
  // void                    mutt_param_delete                 (struct ParameterList *pl, const char *attribute);
  // void                    mutt_param_free                   (struct ParameterList *pl);
  // void                    mutt_param_free_one               (struct Parameter **p);
  // char *                  mutt_param_get                    (const struct ParameterList *pl, const char *s);
  // struct Parameter *      mutt_param_new                    (void);
  // void                    mutt_param_set                    (struct ParameterList *pl, const char *attribute, const char *value);

  mutt_param_cmp_strict(NULL, NULL);
}

void test_parse(void)
{
  // void                    mutt_auto_subscribe               (const char *mailto);
  // int                     mutt_check_encoding               (const char *c);
  // enum ContentType        mutt_check_mime_type              (const char *s);
  // char *                  mutt_extract_message_id           (const char *s, size_t *len);
  // bool                    mutt_is_message_type              (int type, const char *subtype);
  // bool                    mutt_matches_ignore               (const char *s);
  // void                    mutt_parse_content_type           (const char *s, struct Body *ct);
  // bool                    mutt_parse_mailto                 (struct Envelope *e, char **body, const char *src);
  // struct Body *           mutt_parse_multipart              (FILE *fp, const char *boundary, off_t end_off, bool digest);
  // void                    mutt_parse_part                   (FILE *fp, struct Body *b);
  // struct Body *           mutt_read_mime_header             (FILE *fp, bool digest);
  // int                     mutt_rfc822_parse_line            (struct Envelope *env, struct Email *e, char *line, char *p, bool user_hdrs, bool weed, bool do_2047);
  // struct Body *           mutt_rfc822_parse_message         (FILE *fp, struct Body *parent);
  // struct Envelope *       mutt_rfc822_read_header           (FILE *fp, struct Email *e, bool user_hdrs, bool weed);
  // char *                  mutt_rfc822_read_line             (FILE *fp, char *line, size_t *linelen);

  mutt_check_encoding("quoted-printable");
}

void test_rfc2047(void)
{
  // void                    rfc2047_decode                    (char **pd);
  // void                    rfc2047_decode_addrlist           (struct AddressList *al);
  // void                    rfc2047_decode_envelope           (struct Envelope *env);
  // void                    rfc2047_encode                    (char **pd, const char *specials, int col, const char *charsets);
  // void                    rfc2047_encode_addrlist           (struct AddressList *al, const char *tag);
  // void                    rfc2047_encode_envelope           (struct Envelope *env);

  char *str = strdup("한국어 Русский 义勇军");

  mutt_str_replace(&C_Charset, "utf-8");
  rfc2047_encode(&str, MimeSpecials, 0, NULL);

  printf("%s\n", str);
  FREE(&str);
  FREE(&C_Charset);
}

void test_rfc2231(void)
{
  // bool C_Rfc2047Parameters;

  // void                    rfc2231_decode_parameters         (struct ParameterList *pl);
  // size_t                  rfc2231_encode_string             (struct ParameterList *head, const char *attribute, char *value);

  const char *attr = "apple";
  char *value = strdup("한국어 Русский 义勇军");
  struct ParameterList pl = TAILQ_HEAD_INITIALIZER(pl);
  rfc2231_encode_string(&pl, attr, value);
  if (TAILQ_EMPTY(&pl))
    return;
}

void test_tags(void)
{
  // char *C_HiddenTags;
  // struct Hash *TagTransforms;

  // void                    driver_tags_free                  (struct TagList *list);
  // char *                  driver_tags_get                   (struct TagList *list);
  // char *                  driver_tags_get_transformed       (struct TagList *list);
  // char *                  driver_tags_get_transformed_for   (struct TagList *head, const char *name);
  // char *                  driver_tags_get_with_hidden       (struct TagList *list);
  // bool                    driver_tags_replace               (struct TagList *head, char *tags);

  driver_tags_free(NULL);
}

void test_thread(void)
{
  // void                    clean_references                  (struct MuttThread *brk, struct MuttThread *cur);
  // struct Email *          find_virtual                      (struct MuttThread *cur, int reverse);
  // void                    insert_message                    (struct MuttThread **add, struct MuttThread *parent, struct MuttThread *cur);
  // bool                    is_descendant                     (struct MuttThread *a, struct MuttThread *b);
  // void                    mutt_break_thread                 (struct Email *e);
  // void                    thread_hash_destructor            (int type, void *obj, intptr_t data);
  // void                    unlink_message                    (struct MuttThread **old, struct MuttThread *cur);

  is_descendant(NULL, NULL);
}

void test_url(void)
{
  // enum UrlScheme          url_check_scheme                  (const char *str);
  // void                    url_free                          (struct Url **ptr);
  // struct Url *            url_parse                         (const char *src);
  // int                     url_pct_decode                    (char *s);
  // void                    url_pct_encode                    (char *buf, size_t buflen, const char *src);
  // int                     url_tobuffer                      (struct Url *url, struct Buffer *buf, int flags);
  // int                     url_tostring                      (struct Url *url, char *dest, size_t len, int flags);

  url_check_scheme("imaps://host.com");
}

int main()
{
  test_attach();
  test_body();
  test_email();
  test_email_globals();
  test_envelope();
  test_from();
  test_mime();
  test_parameter();
  test_parse();
  test_rfc2047();
  test_rfc2231();
  test_tags();
  test_thread();
  test_url();

  return 0;
}
