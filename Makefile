CC = clang++
INC =
LIB = -llib/libclang -Ilib

main.exe: source/main.cpp
	$(CC) $(LIB) $^ -o $@

clean:
	del *.exe
