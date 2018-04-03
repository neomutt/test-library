NEO	?= ../neo
CC	= gcc
RM	= rm -fr

OUT	= test_lib test_hcache test_conn

CFLAGS	+= -DDEBUG
CFLAGS	+= -Wall
CFLAGS	+= -Wno-unused-parameter
CFLAGS	+= -g
CFLAGS	+= -O0
CFLAGS	+= -I$(NEO)
CFLAGS	+= -fno-omit-frame-pointer

LDFLAGS	+= -L$(NEO)

MUTT_LDFLAGS	= -lmutt -lidn
HCACHE_LDFLAGS	= -lhcache -ltokyocabinet -lkyotocabinet -lgdbm -lqdbm -ldb-5.3 -llmdb
CONN_LDFLAGS	= -lconn -lidn -lgnutls

all:	$(NEO) $(OUT)

test_lib: test_lib.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(MUTT_LDFLAGS)

test_hcache: test_hcache.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(HCACHE_LDFLAGS) $(MUTT_LDFLAGS)

test_conn: test_conn.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(CONN_LDFLAGS) $(MUTT_LDFLAGS)

clean:
	$(RM) $(OUT) cache tmp

