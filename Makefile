CC = clang++
INC = -Ilib
LIB = -lclang

main.out: source/main.cpp
	$(CC) $(LIB) $(INC) $^ -o $@

clean:
	del *.exe
