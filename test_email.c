#include "config.h"
#include <errno.h>
#include <locale.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mutt/lib.h"
#include "config/lib.h"
#include "email/lib.h"
#include "core/lib.h"

#define CONFIG_INIT_TYPE(CS, NAME)                                             \
  extern const struct ConfigSetType Cst##NAME;                                 \
  cs_register_type(CS, &Cst##NAME)

void nm_edata_free(void **ptr)
{
}

int mutt_autocrypt_process_autocrypt_header(struct Email *e, struct Envelope *env)
{
  return -1;
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
  // struct ListNode *       header_add                        (struct ListHead *hdrlist, const char *header);
  // struct ListNode *       header_find                       (const struct ListHead *hdrlist, const char *header);
  // void                    header_free                       (struct ListHead *hdrlist, struct ListNode *target);
  // struct ListNode *       header_set                        (struct ListHead *hdrlist, const char *header);
  // struct ListNode *       header_update                     (struct ListNode *hdr, const char *header);

  struct Email *e = email_new();
  email_free(&e);
}

void test_envelope(void)
{
  // void                    mutt_autocrypthdr_free            (struct AutocryptHeader **ptr);
  // struct AutocryptHeader *mutt_autocrypthdr_new             (void);
  // bool                    mutt_env_cmp_strict               (const struct Envelope *e1, const struct Envelope *e2);
  // void                    mutt_env_free                     (struct Envelope **ptr);
  // void                    mutt_env_merge                    (struct Envelope *base, struct Envelope **extra);
  // struct Envelope *       mutt_env_new                      (void);
  // bool                    mutt_env_notify_send              (struct Email *e, enum NotifyEnvelope type);
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

void test_globals(void)
{
  // struct HashTable *AutoSubscribeCache;
  // struct ListHead Ignore;
  // struct RegexList MailLists;
  // struct ListHead MailToAllow;
  // struct RegexList NoSpamList;
  // struct ReplaceList SpamList;
  // struct RegexList SubscribedLists;
  // struct ListHead UnIgnore;
  // struct RegexList UnMailLists;
  // struct RegexList UnSubscribedLists;

  AutoSubscribeCache = NULL;
}

void test_mime(void)
{
  // const char *const BodyEncodings[];
  // const char *const BodyTypes[];
  // const int IndexHex[];
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
  // bool                    mutt_parse_mailto                 (struct Envelope *env, char **body, const char *src);
  // struct Body *           mutt_parse_multipart              (FILE *fp, const char *boundary, off_t end_off, bool digest);
  // void                    mutt_parse_part                   (FILE *fp, struct Body *b);
  // struct Body *           mutt_read_mime_header             (FILE *fp, bool digest);
  // int                     mutt_rfc822_parse_line            (struct Envelope *env, struct Email *e, const char *name, size_t name_len, const char *body, bool user_hdrs, bool weed, bool do_2047);
  // struct Body *           mutt_rfc822_parse_message         (FILE *fp, struct Body *parent);
  // struct Envelope *       mutt_rfc822_read_header           (FILE *fp, struct Email *e, bool user_hdrs, bool weed);
  // size_t                  mutt_rfc822_read_line             (FILE *fp, struct Buffer *buf);

  mutt_check_encoding("quoted-printable");
}

void test_rfc2047(void)
{
  // void                    rfc2047_decode                    (char **pd);
  // void                    rfc2047_decode_addrlist           (struct AddressList *al);
  // void                    rfc2047_decode_envelope           (struct Envelope *env);
  // void                    rfc2047_encode                    (char **pd, const char *specials, int col, const struct Slist *charsets);
  // void                    rfc2047_encode_addrlist           (struct AddressList *al, const char *tag);
  // void                    rfc2047_encode_envelope           (struct Envelope *env);

  setlocale(LC_ALL, "");

  static struct ConfigDef Vars[] = {
    // clang-format off
    { "assumed_charset", DT_SLIST|SLIST_SEP_COLON|SLIST_ALLOW_EMPTY, 0, 0, NULL, 0, 0 },
    { "charset", DT_STRING|DT_NOT_EMPTY|DT_CHARSET_SINGLE, IP "utf-8", 0, NULL, 0, 0},
    { "maildir_field_delimiter", DT_STRING, IP ":", 0, NULL, 0, 0 },
    { "send_charset", DT_SLIST|SLIST_SEP_COLON|SLIST_ALLOW_EMPTY|DT_CHARSET_STRICT, IP "us-ascii:iso-8859-1:utf-8", 0, NULL, },
    { NULL },
    // clang-format on
  };

  struct ConfigSet *cs = cs_new(50);
  CONFIG_INIT_TYPE(cs, Bool);
  CONFIG_INIT_TYPE(cs, Slist);
  CONFIG_INIT_TYPE(cs, String);

  NeoMutt = neomutt_new(cs);

  cs_register_variables(cs, Vars, DT_NO_FLAGS);

  char *str = strdup("한국어 Русский 义勇军");

  rfc2047_encode(&str, MimeSpecials, 0, NULL);

  printf("%s\n", str);
  FREE(&str);

  config_cache_cleanup();
  neomutt_free(&NeoMutt);
  cs_free(&cs);
}

void test_rfc2231(void)
{
  // void                    rfc2231_decode_parameters         (struct ParameterList *pl);
  // size_t                  rfc2231_encode_string             (struct ParameterList *head, const char *attribute, char *value);

  setlocale(LC_ALL, "");

  static struct ConfigDef Vars[] = {
    // clang-format off
    { "assumed_charset", DT_SLIST|SLIST_SEP_COLON|SLIST_ALLOW_EMPTY, 0, 0, NULL, 0, 0 },
    { "charset", DT_STRING|DT_NOT_EMPTY|DT_CHARSET_SINGLE, IP "utf-8", 0, NULL, 0, 0},
    { "maildir_field_delimiter", DT_STRING, IP ":", 0, NULL, 0, 0 },
    { "send_charset", DT_SLIST|SLIST_SEP_COLON|SLIST_ALLOW_EMPTY|DT_CHARSET_STRICT, IP "us-ascii:iso-8859-1:utf-8", 0, NULL, },
    { NULL },
    // clang-format on
  };

  struct ConfigSet *cs = cs_new(50);
  CONFIG_INIT_TYPE(cs, Bool);
  CONFIG_INIT_TYPE(cs, Slist);
  CONFIG_INIT_TYPE(cs, String);

  NeoMutt = neomutt_new(cs);

  cs_register_variables(cs, Vars, DT_NO_FLAGS);

  const char *attr = "apple";
  char *value = strdup("한국어 Русский 义勇军");
  struct ParameterList pl = TAILQ_HEAD_INITIALIZER(pl);
  rfc2231_encode_string(&pl, attr, value);
  if (TAILQ_EMPTY(&pl))
    return;

  mutt_param_free(&pl);
  free(value);
  value = NULL;

  config_cache_cleanup();
  neomutt_free(&NeoMutt);
  cs_free(&cs);
}

void test_tags(void)
{
  // struct HashTable *TagFormats;
  // struct HashTable *TagTransforms;

  // void                    driver_tags_add                   (struct TagList *list, char *new_tag);
  // void                    driver_tags_cleanup               (void);
  // void                    driver_tags_free                  (struct TagList *list);
  // char *                  driver_tags_get                   (struct TagList *list);
  // char *                  driver_tags_get_transformed       (struct TagList *list);
  // char *                  driver_tags_get_transformed_for   (struct TagList *head, const char *name);
  // char *                  driver_tags_get_with_hidden       (struct TagList *list);
  // void                    driver_tags_init                  (void);
  // bool                    driver_tags_replace               (struct TagList *head, const char *tags);

  driver_tags_free(NULL);
}

void test_thread(void)
{
  // void                    clean_references                  (struct MuttThread *brk, struct MuttThread *cur);
  // struct Email *          find_virtual                      (struct MuttThread *cur, bool reverse);
  // void                    insert_message                    (struct MuttThread **add, struct MuttThread *parent, struct MuttThread *cur);
  // bool                    is_descendant                     (const struct MuttThread *a, const struct MuttThread *b);
  // void                    mutt_break_thread                 (struct Email *e);
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
  // int                     url_tobuffer                      (struct Url *url, struct Buffer *buf, uint8_t flags);
  // int                     url_tostring                      (struct Url *url, char *dest, size_t len, uint8_t flags);

  url_check_scheme("imaps://host.com");
}

int main()
{
  test_body();
  test_email();
  test_envelope();
  test_from();
  test_globals();
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
