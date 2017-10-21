all: node_tester.c player.c
	gcc -o "nodes" node_tester.c
	gcc -o "playa" player.c
run: all
	./nodes
	./playa
