# Переменные
CFLAGS = -std=c99 -Wall -Werror -pedantic -c
LFLAGS = -lsubunit -lpthread -lrt -lm
S = ./src/
O = ./out/
I = ./inc/
# $@ - цель
# $^ - список зависимостей
# $< - первая зависимость
.PHONY: clean unit



libfib.so: $(O)libfib.o
	gcc -o $@ $^ -shared $(LFLAGS)

$(O)check_main.o: ./unit_tests/check_main.c $(I)libfib.h
	gcc $(CFLAGS) $< -o $@

$(O)libfib.o: $(S)libfib.c $(I)libfib.h 
	gcc $(CFLAGS) $< -o $@ -fpic

clean:
	rm -f $(O)*.o *.exe *.a *.so
	
unit: unit_tests.exe
	LD_LIBRARY_PATH="." ./$^

unit_tests.exe: $(O)check_main.o 
	gcc -o $@ $^ -L. -lfib -lcheck $(LFLAGS)
	