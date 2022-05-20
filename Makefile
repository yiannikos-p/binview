CC=clang
CFLAGS= -I -ls
DEPS=

%.o: %.c $(DEPS)
	$(CC) -c -c $@ $< $(CFLAGS)

binview: binview.c
	$(CC) -o binview binview.c
