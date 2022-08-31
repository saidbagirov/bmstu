# Переменные
CFLAGS = -std=c99 -Wall -Werror -pedantic -c
S = ./src/
O = ./out/
I = ./inc/
# $@ - цель
# $^ - список зависимостей
# $< - первая зависимость

.PHONY: clean unit
unit: unit_tests.exe
	./$^
unit_tests.exe: $(O)check_main.obj $(O)my_snprintf.obj 
	gcc -o $@ $^ -lcheck 
$(O)check_main.obj: ./unit_tests/check_main.c $(I)my_snprintf.h
	gcc $(CFLAGS) $< -o $@
$(O)my_snprintf.obj: $(S)my_snprintf.c $(I)my_snprintf.h
	gcc $(CFLAGS) $< -o $@
clean:
	rm -f $(O)*.obj *.exe