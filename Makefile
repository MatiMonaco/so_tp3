CC=gcc
CFLAGS= -Wall -s -fvisibility=hidden

all: asm client server

asm: asm.asm
	nasm -f elf64 asm.asm -o asm.o

client: client.c
	@$(CC) $(CFLAGS) client.c -o client

server: server.c
	@$(CC) $(CFLAGS) server.c asm.o -o server

clean:
	rm client server asm.o

.PHONY: all clean