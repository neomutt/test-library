NEO	?= ../neo
CC	= gcc
RM	= rm -fr

OUT	= test_conn test_email test_hcache test_lib test_maildir test_mbox

CFLAGS	+= -DDEBUG
CFLAGS	+= -Wall
CFLAGS	+= -Wno-unused-parameter
CFLAGS	+= -g
CFLAGS	+= -O0
CFLAGS	+= -I$(NEO)
CFLAGS	+= -fno-omit-frame-pointer

LDFLAGS	+= -L$(NEO)

CONN_LDFLAGS	= -lconn -lemail -lidn2 -lgnutls
EMAIL_LDFLAGS	= -lemail -lidn2
HCACHE_LDFLAGS	= -lhcache -lemail -ltokyocabinet -lkyotocabinet -lgdbm -lqdbm -ldb-5.3 -llmdb
MAILDIR_LDFLAGS	= -lmaildir
MBOX_LDFLAGS	= -lmbox
MUTT_LDFLAGS	= -lmutt -lidn2

all:	$(NEO) $(OUT)

test_conn: test_conn.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(CONN_LDFLAGS) $(MUTT_LDFLAGS)

test_email: test_email.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(EMAIL_LDFLAGS) $(MUTT_LDFLAGS)

test_hcache: test_hcache.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(HCACHE_LDFLAGS) $(MUTT_LDFLAGS)

test_lib: test_lib.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(MUTT_LDFLAGS)

test_maildir: test_maildir.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(MAILDIR_LDFLAGS) $(EMAIL_LDFLAGS) $(MUTT_LDFLAGS)

test_mbox: test_mbox.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(MBOX_LDFLAGS) $(EMAIL_LDFLAGS) $(MUTT_LDFLAGS)

clean:
	$(RM) $(OUT) cache tmp

