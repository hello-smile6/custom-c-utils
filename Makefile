utils = yes mkfifo kill
CFLAGS = -Wall -ansi -g3 -Werror=int-conversion -Og -Werror=all
tests = mkfifo
.PHONY: all yes clean mkfifo kill tests test/mkfifo
all: $(utils) tests

yes: out/yes

out/yes: yes.c common.h | out
	gcc $(CFLAGS) yes.c -o out/yes

out:
	mkdir out

clean: | out
	find out/ -type f -delete
	find test/out/ -type f -delete


mkfifo: out/mkfifo

out/mkfifo: mkfifo.c common.h | out
	gcc $(CFLAGS) mkfifo.c -o out/mkfifo

kill: out/kill

out/kill: kill.c common.h signal-wrapper.h | out
	gcc $(CFLAGS) kill.c -o out/kill

tests: | test test/out/$(tests)
	

test/out: | test
	mkdir test/out

test:
	mkdir test

test/out/mkfifo: test/mkfifo.c out/mkfifo | test/out
	gcc $(CFLAGS) test/mkfifo.c -o test/out/mkfifo
	test/out/mkfifo