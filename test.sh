make
gcc main.c -L$PWD -lmy_malloc
export LD_LIBRARY_PATH=$PWD
ldd a.out
./a.out
