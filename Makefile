CFLAGS = -Wall -Wconversion -Wextra -static

debug:
	gcc -std=gnu2x -g -L/usr/lib64 -o daemonize ${shell find . -name '*.c'} $(CFLAGS) -DDEBUG -fsanitize=address -fno-optimize-sibling-calls

release:
	gcc -std=gnu2x -O3 -L/usr/lib64 -o daemonize ${shell find . -name '*.c'} $(CFLAGS)

clean:
	rm -rf *.o daemonize