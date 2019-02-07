CC=gcc
SRC=test_jeu.c test_alignement.c
OBJ=$(SRC:.c=.o)

test_p6:	$(OBJ)
	$(CC) $(OBJ) -o $@

test_alignement.o: test_alignement.h
test_jeu.o: test_alignement.h

%.o:	%.c
	$(CC) -c -Wall $< 

clean:
	rm *.o test_p6
