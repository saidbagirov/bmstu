CC = gcc
CFLAGS = -std=c99 -Wall -pedantic
FUNC_C = functions/*.c
FUNC_O = functions/*.o
OBJ = $(patsubst %.c, %.o, $(wildcard $(FUNC_C)))
OBJ_MAIN = $(patsubst %.c, %.o, $(wildcard *.c))
app.exe: $(OBJ) $(OBJ_MAIN)
	$(CC) -o $@ $^ -lm
run:
	./app.exe
clean:
	rm *.o *.exe $(FUNC_O)