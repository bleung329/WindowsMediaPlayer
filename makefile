all: player.c
	gcc -o "playa" player.c
run: all
	./playa