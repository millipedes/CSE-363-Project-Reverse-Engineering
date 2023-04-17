CC=gcc -g -Wall -Wextra
FILE_NAME=ordering
PROJECT_NAME=01_heaps_algorithm

all:
	$(CC) $(FILE_NAME).c -o $(FILE_NAME)

ghidra:
	r2 ordering < <(cat test.txt -)

clean:
	rm $(FILE_NAME)
