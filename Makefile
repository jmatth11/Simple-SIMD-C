

.PHONY: all
all:
	gcc -march=x86-64 -mavx -mavx2 -mf16c -msse4.1 -msse4.2 -mavx512f -O2 -Wall main.c -o test

