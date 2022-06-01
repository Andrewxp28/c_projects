CC=gcc
CFLAGS=-Wall -g
LDFLAGS=
EXE_MAIN=main
OBJ_MAIN=bst.o utils.o ll.o person.o book.o

$(EXE_MAIN): main.c $(OBJ_MAIN)
	$(CC) $(CFLAGS) -o $(EXE_MAIN) $< $(OBJ_MAIN) $(LDFLAGS)


#%.o: %.c %.h
#	$(CC) $(CFLAGS) -c -o $@ $< $(CLFLAGS)


bst.o: trees/bst.c trees/bst.h utils/utils.h
	$(CC) $(CFLAGS) -c -o bst.o trees/bst.c

utils.o: utils/utils.c utils/utils.h
	$(CC) $(CFLAGS) -c -o utils.o utils/utils.c

ll.o: lists/ll.c lists/ll.h utils/utils.h
	$(CC) $(CFLAGS) -c -o ll.o lists/ll.c

person.o: person.c person.h trees/bst.c trees/bst.h utils/utils.h
	$(CC) $(CFLAGS) -c -o person.o person.c

book.o: book.c book.h
	$(CC) $(CFLAGS) -c -o book.o book.c

clean:
	rm -f *.o $(EXE_MAIN)

format:
	clang-format -i *.c *.h

