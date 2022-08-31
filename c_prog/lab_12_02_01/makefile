# Переменные
CFLAGS = -std=c99 -Wall -Werror -pedantic -c
#LFLAGS = -lsubunit -lpthread -lrt -lm
S = ./src/
O = ./out/
I = ./inc/
# $@ - цель
# $^ - список зависимостей
# $< - первая зависимость
.PHONY: clean unit



unit: unit_tests.exe
	./$^

static: app_static.exe

dynamic: libdynamic.so app_dynamic.exe

unit_tests.exe: $(O)check_main.obj libstatic.a
	gcc -o $@ $^ -lcheck $(LFLAGS)

app_dynamic.exe: $(O)main.obj
	gcc -o $@ $^ -L . -l dynamic

libdynamic.so: $(O)key.obj $(O)mysort.obj $(O)inout.obj
	gcc -o $@ $^ -shared $(LFLAGS)

app_static.exe: $(O)main.obj libstatic.a
	gcc -o $@ $^ $(LFLAGS)
		
libstatic.a: $(O)key.obj $(O)mysort.obj $(O)inout.obj
	ar rcs $@ $^

$(O)check_main.obj: ./unit_tests/check_main.c $(I)key.h $(I)mysort.h
	gcc $(CFLAGS) $< -o $@

$(O)main.obj: $(S)main.c $(I)key.h $(I)mysort.h $(I)inout.h
	gcc $(CFLAGS) $< -o $@

$(O)key.obj: $(S)key.c $(I)key.h $(I)error_codes.h
	gcc $(CFLAGS) $< -o $@ -fpic

$(O)mysort.obj: $(S)mysort.c $(I)mysort.h 
	gcc $(CFLAGS) $< -o $@ -fpic

$(O)inout.obj: $(S)inout.c $(I)inout.h 
	gcc $(CFLAGS) $< -o $@ -fpic

clean:
	rm -f $(O)*.obj *.exe *.a *.so