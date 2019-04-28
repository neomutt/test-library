NEO	?= ../neo
CC	= gcc
RM	= rm -fr

OUT	= test_conn test_email test_hcache test_lib test_maildir test_mbox test_address test_date test_imap

CFLAGS	+= -DDEBUG
CFLAGS	+= -Wall
CFLAGS	+= -Wno-unused-parameter
CFLAGS	+= -g
CFLAGS	+= -O0
CFLAGS	+= -I$(NEO)
CFLAGS	+= -fno-omit-frame-pointer

LDFLAGS	+= -L$(NEO)

# CFLAGS	+= -fsanitize=undefined
# LDFLAGS	+= -fsanitize=undefined

# CFLAGS	+=-fsanitize=address -fsanitize-recover=address
# LDFLAGS	+=-fsanitize=address -fsanitize-recover=address

CONN_LDFLAGS	= -lconn -lgnutls
ADDR_LDFLAGS	= -laddress
EMAIL_LDFLAGS	= -lemail
HCACHE_LDFLAGS	= -lhcache -ltokyocabinet -lkyotocabinet -lgdbm -lqdbm -ldb-5.3 -llmdb
IMAP_LDFLAGS	= -limap
MAILDIR_LDFLAGS	= -lmaildir
MBOX_LDFLAGS	= -lmbox
MUTT_LDFLAGS	= -lmutt -lidn -lidn2

all:	$(NEO) $(OUT)

test_conn: test_conn.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(CONN_LDFLAGS) $(EMAIL_LDFLAGS) $(ADDR_LDFLAGS) $(MUTT_LDFLAGS)

test_email: test_email.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(EMAIL_LDFLAGS) $(ADDR_LDFLAGS) $(MUTT_LDFLAGS)

test_hcache: test_hcache.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(HCACHE_LDFLAGS) $(EMAIL_LDFLAGS) $(ADDR_LDFLAGS) $(MUTT_LDFLAGS)

test_date: test_date.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(MUTT_LDFLAGS)

test_imap: test_imap.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(MUTT_LDFLAGS)

test_address: test_address.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(EMAIL_LDFLAGS) $(ADDR_LDFLAGS) $(MUTT_LDFLAGS)

test_lib: test_lib.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(MUTT_LDFLAGS)

test_maildir: test_maildir.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(MAILDIR_LDFLAGS) $(EMAIL_LDFLAGS) $(ADDR_LDFLAGS) $(MUTT_LDFLAGS)

test_mbox: test_mbox.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(MBOX_LDFLAGS) $(EMAIL_LDFLAGS) $(ADDR_LDFLAGS) $(MUTT_LDFLAGS)

clean:
	$(RM) $(OUT) cache tmp

