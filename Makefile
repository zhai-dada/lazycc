CFLAGS=-std=c11 -g -static

stupidcc:stupidcc.c
	gcc $(CFLAGS) $< -o $@

test:stupidcc
	./test.sh

clean:
	rm -f stupidcc *.o *~ tmp* a.out

.PHONY: test clean