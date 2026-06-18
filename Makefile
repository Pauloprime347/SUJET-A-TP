CC=gcc
CFLAGS=-Wall

all: bibliotheque

bibliotheque: main.o livre.o fichier.o
	$(CC) main.o livre.o fichier.o -o bibliotheque

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

livre.o: livre.c
	$(CC) $(CFLAGS) -c livre.c

fichier.o: fichier.c
	$(CC) $(CFLAGS) -c fichier.c

clean:
	rm -f *.o bibliotheque