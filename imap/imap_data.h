#ifndef IMAP_DATA_H
#define IMAP_DATA_H

#include "mutt/list.h"

typedef void * header_cache_t;

/* number of entries in the hash table */
#define IMAP_CACHE_LEN 10

enum ImapCaps
{
  IMAP4 = 0,
  IMAP4REV1,
  STATUS,
  ACL,           /**< RFC2086: IMAP4 ACL extension */
  NAMESPACE,     /**< RFC2342: IMAP4 Namespace */
  ACRAM_MD5,     /**< RFC2195: CRAM-MD5 authentication */
  AGSSAPI,       /**< RFC1731: GSSAPI authentication */
  AUTH_ANON,     /**< AUTH=ANONYMOUS */
  STARTTLS,      /**< RFC2595: STARTTLS */
  LOGINDISABLED, /**<           LOGINDISABLED */
  IDLE,          /**< RFC2177: IDLE */
  SASL_IR,       /**< SASL initial response draft */
  ENABLE,        /**< RFC5161 */
  X_GM_EXT1,     /**< https://developers.google.com/gmail/imap/imap-extensions */

  CAPMAX
};

enum ImapCommandType
{
  IMAP_CT_NONE = 0,
  IMAP_CT_LIST,
  IMAP_CT_STATUS
};

struct ImapCache
{
  unsigned int uid;
  char *path;
};

struct ImapData
{
  struct Connection *conn;
  bool recovering;
  unsigned char state;
  unsigned char status;
  /* let me explain capstr: SASL needs the capability string (not bits).
   * we have 3 options:
   *   1. rerun CAPABILITY inside SASL function.
   *   2. build appropriate CAPABILITY string by reverse-engineering from bits.
   *   3. keep a copy until after authentication.
   * I've chosen (3) for now. (2) might not be too bad, but it involves
   * tracking all possible capabilities. bah. (1) I don't like because
   * it's just no fun to get the same information twice */
  char *capstr;
  unsigned char capabilities[(CAPMAX + 7) / 8];
  unsigned int seqno;
  time_t lastread; /**< last time we read a command for the server */
  char *buf;
  unsigned int blen;

  /* If nonzero, we can send UTF-8, and the server will use UTF8 rather
   * than mUTF7 */
  int unicode;

  /* if set, the response parser will store results for complicated commands
   * here. */
  enum ImapCommandType cmdtype;
  void *cmddata;

  /* command queue */
  struct ImapCommand *cmds;
  int cmdslots;
  int nextcmd;
  int lastcmd;
  struct Buffer *cmdbuf;

  /* cache ImapStatus of visited mailboxes */
  struct ListHead mboxcache;

  /* The following data is all specific to the currently SELECTED mbox */
  char delim;
  struct Context *ctx;
  char *mailbox;
  unsigned short check_status;
  unsigned char reopen;
  unsigned int new_mail_count; /**< Set when EXISTS notifies of new mail */
  struct ImapCache cache[IMAP_CACHE_LEN];
  struct Hash *uid_hash;
  unsigned int uid_validity;
  unsigned int uidnext;
  struct Header **msn_index;   /**< look up headers by (MSN-1) */
  unsigned int msn_index_size; /**< allocation size */
  unsigned int max_msn;        /**< the largest MSN fetched so far */
  struct BodyCache *bcache;

  /* all folder flags - system AND custom flags */
  struct ListHead flags;
#ifdef USE_HCACHE
  header_cache_t *hcache;
#endif
};

#endif
