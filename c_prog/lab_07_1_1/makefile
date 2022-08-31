CC := gcc
S := ./src/
O := ./out/
I := ./inc/
CFLAGS := -std=c99 -Wall -Werror -pedantic -Wvla -ggdb

app.exe : $(O)input_func.o $(O)output_func.o $(O)filter_func.o $(O)sort_func.o $(O)main.o
	$(CC) -o app.exe $(O)output_func.o $(O)filter_func.o $(O)input_func.o $(O)sort_func.o $(O)main.o

unit: unit_tests.exe
	./$^
#  -lsubunit -lpthread -lrt -lm
unit_tests.exe: $(O)check_main.o $(O)filter_func.o $(O)sort_func.o
	gcc -o $@ $^ -lcheck

$(O)main.o : $(S)main.c 
	$(CC) $(CFLAGS) -c $(S)main.c -o $@

$(O)check_main.o: ./unit_tests/check_main.c $(I)filter_func.h $(I)sort_func.h
	gcc $(CFLAGS) -c $< -o $@

$(O)input_func.o : $(S)input_func.c $(I)input_func.h
	$(CC) $(CFLAGS) -c $(S)input_func.c -o $@

$(O)filter_func.o : $(S)filter_func.c $(I)filter_func.h
	$(CC) $(CFLAGS) -c $(S)filter_func.c -o $@

$(O)sort_func.o : $(S)sort_func.c $(I)sort_func.h
	$(CC) $(CFLAGS) -c $(S)sort_func.c -o $@

$(O)output_func.o : $(S)output_func.c $(I)output_func.h
	$(CC) $(CFLAGS) -c $(S)output_func.c -o $@

.PHONY : clean
clean :
	rm $(O)*.o *.exe
