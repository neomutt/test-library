#include "config.h"
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "mutt/mutt.h"
#include "email/lib.h"
#include "hcache/hcache.h"
#include "help/help.h"
#include "mailbox.h"

char *C_HelpDocDir;
bool C_HideThreadSubject;
static FILE *fp_random;

static const unsigned char base32[] = "abcdefghijklmnopqrstuvwxyz234567";

void mutt_make_label_hash(struct Mailbox *m)
{
  /* 131 is just a rough prime estimate of how many distinct
   * labels someone might have in a m.  */
  m->label_hash = mutt_hash_new(131, MUTT_HASH_STRDUP_KEYS);
}

int mutt_randbuf(void *buf, size_t buflen)
{
  if (buflen > 1048576)
  {
    mutt_error(_("mutt_randbuf buflen=%zu"), buflen);
    return -1;
  }
/* XXX switch to HAVE_GETRANDOM and getrandom() in about 2017 */
#if defined(SYS_getrandom) && defined(__linux__)
  long ret;
  do
  {
    ret = syscall(SYS_getrandom, buf, buflen, 0, 0, 0, 0);
  } while ((ret == -1) && (errno == EINTR));
  if (ret == buflen)
    return 0;
#endif
  /* let's try urandom in case we're on an old kernel, or the user has
   * configured selinux, seccomp or something to not allow getrandom */
  if (!fp_random)
  {
    fp_random = fopen("/dev/urandom", "rb");
    if (!fp_random)
    {
      mutt_error(_("open /dev/urandom: %s"), strerror(errno));
      return -1;
    }
    setbuf(fp_random, NULL);
  }
  if (fread(buf, 1, buflen, fp_random) != buflen)
  {
    mutt_error(_("read /dev/urandom: %s"), strerror(errno));
    return -1;
  }

  return 0;
}

void mutt_rand_base32(void *buf, size_t buflen)
{
  uint8_t *p = buf;

  if (mutt_randbuf(p, buflen) < 0)
    mutt_exit(1);
  for (size_t pos = 0; pos < buflen; pos++)
    p[pos] = base32[p[pos] % 32];
}

struct Mailbox *mailbox_new(void)
{
  struct Mailbox *m = mutt_mem_calloc(1, sizeof(struct Mailbox));

  m->pathbuf = mutt_buffer_new();

  return m;
}

void mailbox_free(struct Mailbox **ptr)
{
  if (!ptr || !*ptr)
    return;

  struct Mailbox *m = *ptr;

  mutt_buffer_free(&m->pathbuf);
  FREE(&m->desc);
  if (m->mdata && m->free_mdata)
    m->free_mdata(&m->mdata);
  FREE(&m->realpath);
  FREE(ptr);
}

int main()
{
  char *dir = "/home/github/neomutt/test-doc";
  C_HelpDocDir = mutt_str_strdup(dir);
  struct Mailbox *m = mailbox_new();
  m->magic = MUTT_HELP;
  m->pathbuf = mutt_buffer_from(dir);

  int rc = MxHelpOps.mbox_open(m);
  printf("%d\n", rc);
  if (rc != 0)
    return 1;

  rc = MxHelpOps.mbox_close(m);
  printf("%d\n", rc);
  if (rc != 0)
    return 1;

  mailbox_free(&m);
  help_doclist_free();
  FREE(&C_HelpDocDir);
  return 0;
}
