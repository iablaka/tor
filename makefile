build: src/*.c
	cc -o ./bin/tor src/tor.c src/init.c -Wall
