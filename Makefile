all: spaceshoota

spaceshoota: shoota.o projectiles.o saucer.o
	gcc -o spaceshoota shoota.o projectiles.o saucer.o

shoota.o: shoota.c structure.h
	gcc -c shoota.c

projectiles.o: projectiles.c saucer.h
	gcc -c projectiles.c

saucer.o: saucer.c saucer.h
	gcc -c saucer.c

clean:
	rm -f *.o spaceshoota

#all of my phony targets
.PHONY: all clean