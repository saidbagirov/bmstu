CFLAGS = -std=c99 -Wall -Werror -pedantic -c

.PHONY: clean unit

libslib.a: slib.o
	ar rc $@ $^
	ranlib $@
app.exe: main.o
	gcc $^ -L. -lslib -o $@
unit: unit_tests.exe
	./$^
unit_tests.exe: check_main.o
	gcc -o $@ $^ -lcheck

check_main.o: ./unit_tests/check_main.c slib.h
	gcc $(CFLAGS) $<
main.o: main.c slib.h
	gcc $(CFLAGS) $<
slib.o: slib.c slib.h
	gcc $(CFLAGS) $<

clean:
	rm -f *.a *.o *.exe