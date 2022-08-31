S := ./src/
O := ./out/
I := ./inc/
CFLAGS := -std=c99 -Wall -Werror -pedantic -Wvla -ggdb

app.exe : $(O)inout.o $(O)main.o $(O)matrixtosqr.o $(O)matrixtoonesize.o $(O)multiple.o
	gcc -o app.exe $(O)inout.o $(O)main.o $(O)matrixtosqr.o $(O)matrixtoonesize.o $(O)multiple.o

unit: unit_tests.exe
	./$^
#  -lsubunit -lpthread -lrt -lm
unit_tests.exe: $(O)check_main.o $(O)inout.o $(O)multiple.o $(O)matrixtosqr.o
#$(O)main.o  $(O)matrixtoonesize.o
	gcc -o $@ $^ -lcheck

$(O)main.o : $(S)main.c 
	gcc $(CFLAGS) -c $(S)main.c -o $@

$(O)check_main.o : ./unit_tests/check_main.c $(I)inout.h $(I)multiple.h
#$(I)matrixtoonesize.h $(I)matrixtosqr.h 
	gcc $(CFLAGS) -c $< -o $@

$(O)inout.o: $(S)inout.c $(I)inout.h
	gcc $(CFLAGS) -c $< -o $@

$(O)multiple.o: $(S)multiple.c $(I)multiple.h
	gcc $(CFLAGS) -c $< -o $@

$(O)matrixtosqr.o: $(S)matrixtosqr.c $(I)matrixtosqr.h
	gcc $(CFLAGS) -c $< -o $@

$(O)matrixtoonesize.o: $(S)matrixtoonesize.c $(I)matrixtoonesize.h
	gcc $(CFLAGS) -c $< -o $@

.PHONY : clean
clean :
	rm $(O)*.o *.exe
