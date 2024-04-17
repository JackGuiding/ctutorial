gcc ./src/main.c -c -o ./build/main.o
gcc ./src/test.c -c -o ./build/test.o
gcc ./build/main.o ./build/test.o -o ./bin/main.exe