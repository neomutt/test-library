#include "config.h"
#include <errno.h>
#include <locale.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mutt/mutt.h"
#include "email/email.h"

void test_address(void)
{
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

void test_envelope(void)
{
  // bool                mutt_env_cmp_strict               (const struct Envelope *e1, const struct Envelope *e2);
  // void                mutt_env_free                     (struct Envelope **p);
  // void                mutt_env_merge                    (struct Envelope *base, struct Envelope **extra);
  // struct Envelope *   mutt_env_new                      (void);
  // int                 mutt_env_to_intl                  (struct Envelope *env, char **tag, char **err);
  // void                mutt_env_to_local                 (struct Envelope *e);

  struct Envelope *env = mutt_env_new();
  mutt_env_free(&env);
}

void test_header(void)
{
  // bool                mutt_header_cmp_strict            (const struct Header *h1, const struct Header *h2);
  // void                mutt_header_free                  (struct Header **h);
  // struct Header *     mutt_header_new                   (void);

  struct Header *hdr = mutt_header_new();
  mutt_header_free(&hdr);
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

void test_tags(void)
{
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
  // struct Header *     find_virtual                      (struct MuttThread *cur, int reverse);
  // void                insert_message                    (struct MuttThread **new, struct MuttThread *newparent, struct MuttThread *cur);
  // int                 is_descendant                     (struct MuttThread *a, struct MuttThread *b);
  // void                mutt_break_thread                 (struct Header *hdr);
  // void                thread_hash_destructor            (int type, void *obj, intptr_t data);
  // void                unlink_message                    (struct MuttThread **old, struct MuttThread *cur);

  is_descendant(NULL, NULL);
}

int main()
{
  test_address();
  test_attach();
  test_body();
  test_envelope();
  test_header();
  test_parameter();
  test_tags();
  test_thread();

  return 0;
}
