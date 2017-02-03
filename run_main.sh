make re
gcc main.c -L$PWD -lmy_malloc -o main.out
export LD_LIBRARY_PATH=$PWD
ldd main.out
./main.out
