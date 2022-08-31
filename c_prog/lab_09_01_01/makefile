# Переменные
CFLAGS = -std=c99 -Wall -Werror -pedantic -c
S = ./src/
O = ./out/
I = ./inc/
# $@ - цель
# $^ - список зависимостей
# $< - первая зависимость

.PHONY: clean unit
app.exe: $(O)main.obj $(O)my_functions.obj
	gcc -o $@ $^ 
unit: unit_tests.exe
	./$^
unit_tests.exe: $(O)check_main.obj $(O)my_functions.obj 
	gcc -o $@ $^ -lcheck 
$(O)check_main.obj: ./unit_tests/check_main.c $(I)my_functions.h
	gcc $(CFLAGS) $< -o $@
$(O)main.obj: $(S)main.c $(I)my_functions.h
	gcc $(CFLAGS) $< -o $@
$(O)my_functions.obj: $(S)my_functions.c $(I)my_functions.h
	gcc $(CFLAGS) $< -o $@
clean:
	rm -f $(O)*.obj *.exe