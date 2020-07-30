CC = clang++
INC = -Ilib -Isource/Parser -Isource/Parser/FunctionObj
LIB = -lclang

main.out: source/main.cpp source/Parser/Parser.cpp source/Parser/FunctionObj/FunctionObj.cpp
	$(CC) $(LIB) $(INC) $^ -o out/$@

clean:
	rm out/*.out

