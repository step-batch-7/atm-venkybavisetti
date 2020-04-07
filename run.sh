#! /bin/bash

rm -rf *.o
gcc -c *.c
gcc -o a.out *.o && ./a.out
rm -rf *.o