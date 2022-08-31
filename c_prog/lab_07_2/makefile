# Переменные
CFLAGS = -std=c99 -Wall -Werror -pedantic -c
S = ./src/
O = ./out/
I = ./inc/
# $@ - цель
# $^ - список зависимостей
# $< - первая зависимость
.PHONY: clean unit
app.exe: $(O)main.obj $(O)key.obj $(O)mysort.obj $(O)inout.obj
	gcc -o $@ $^
unit: unit_tests.exe
	./$^
#  -lsubunit -lpthread -lrt -lm
unit_tests.exe: $(O)check_main.obj $(O)key.obj $(O)mysort.obj
	gcc -o $@ $^ -lcheck
$(O)check_main.obj: ./unit_tests/check_main.c $(I)key.h $(I)mysort.h
	gcc $(CFLAGS) $< -o $@
$(O)main.obj: $(S)main.c $(I)key.h $(I)mysort.h $(I)inout.h
	gcc $(CFLAGS) $< -o $@
$(O)key.obj: $(S)key.c $(I)key.h $(I)error_codes.h
	gcc $(CFLAGS) $< -o $@
$(O)mysort.obj: $(S)mysort.c $(I)mysort.h 
	gcc $(CFLAGS) $< -o $@
$(O)inout.obj: $(S)inout.c $(I)inout.h 
	gcc $(CFLAGS) $< -o $@
clean:
	rm -f $(O)*.obj *.exe