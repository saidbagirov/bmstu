CFLAGS = -std=c99 -Wall -Werror -pedantic -c
LIBFLAGS = $(CFLAGS) -D ARR_EXPORTS -c

.PHONY: clean unit

libdyn.dll: dlib.o
	gcc -shared $^ -Wl,--subsystem,windows -o $@
app.exe: main.o
	gcc $^ -L. -ldyn -o $@
unit: unit_tests.exe
	./$^
unit_tests.exe: check_main.o
	gcc -o $@ $^ -lcheck

check_main.o: ./unit_tests/check_main.c d_lib.h
	gcc $(CFLAGS) $<
main.o: main.c dlib.h
	gcc $(CFLAGS) $<
dlib.o: dlib.c dlib.h
	gcc $(LIBFLAGS) $< -o $@

clean:
	rm -f *.o *.dll *.exe