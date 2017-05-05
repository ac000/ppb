CC=gcc
CFLAGS=-Wall -g -std=c99 -O2
LDFLAGS=

ppb: ppb.c
	 $(CC) $(CFLAGS) -o ppb ppb.c -lac

clean:
	rm -f ppb
