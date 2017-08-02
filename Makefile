NEO	?= ../neo
CC	= gcc
RM	= rm -fr

OUT	= test_lib test_hcache

CFLAGS	+= -DDEBUG
CFLAGS	+= -Wall
CFLAGS	+= -Wno-unused-parameter
CFLAGS	+= -g
CFLAGS	+= -O0
CFLAGS	+= -I$(NEO)
CFLAGS	+= -fno-omit-frame-pointer

LIB_LDFLAGS = -L$(NEO)/lib -llib
HC_LDFLAGS = -L$(NEO)/hcache -lhcache -ltokyocabinet -lkyotocabinet -lgdbm -lqdbm -ldb-5.3 -llmdb

all:	$(OUT)

test_lib: test_lib.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(LIB_LDFLAGS)

test_hcache: test_hcache.c
	$(CC) -o $@ $< $(CFLAGS) $(LDFLAGS) $(HC_LDFLAGS) $(LIB_LDFLAGS)

clean:
	$(RM) $(OUT) cache tmp

