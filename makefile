build: tor.c init.c
	cc -o ./bin/tor tor.c init.c -Wall
