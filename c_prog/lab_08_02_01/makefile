# Переменные
CFLAGS = -std=c99 -Wall -Werror -pedantic -c
S = ./src/
O = ./out/
I = ./inc/
# $@ - цель
# $^ - список зависимостей
# $< - первая зависимость

.PHONY: clean unit
app.exe: $(O)main.obj $(O)matrix.obj
	gcc -o $@ $^
unit: unit_tests.exe
	./$^
unit_tests.exe: $(O)check_main.obj $(O)matrix.obj
	gcc -o $@ $^ -lcheck
$(O)check_main.obj: ./unit_tests/check_main.c $(I)matrix.h
	gcc $(CFLAGS) $< -o $@
$(O)main.obj: $(S)main.c $(I)matrix.h
	gcc $(CFLAGS) $< -o $@
$(O)matrix.obj: $(S)matrix.c $(I)matrix.h
	gcc $(CFLAGS) $< -o $@
clean:
	rm -f $(O)*.obj *.exe