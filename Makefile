CC = clang++
LIBRARY = -lclang -Ilib
INCLUDE = -Isource/Parser -Isource/Parser/FunctionObj
ODIR = out
_OBJECTS = main.o Parser.o FunctionObj.o
OBJECTS = $(addprefix $(ODIR)/, $(_OBJECTS))
SOURCE = source

FLAGS = -g -Qunused-arguments $(LIBRARY) $(INCLUDE)

main: $(_OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(ODIR)/$@

# First Level Objects
%.o: $(SOURCE)/%.cpp
	$(CC) $(FLAGS) -c $^ -o $(ODIR)/$@

# Parser Objects
%.o: $(SOURCE)/Parser/%.cpp
	$(CC) $(FLAGS) -c $^ -o $(ODIR)/$@

# FunctionObj Objects
%.o: $(SOURCE)/Parser/FunctionObj/%.cpp
	$(CC) $(FLAGS) -c $^ -o $(ODIR)/$@

.PHONY: clean
.PHONY: tests

tests:
	$(CC) -Itest/unit-tests/include -lgtest -o out/tests/TestMain test/unit-tests/TestMain.cpp

clean:
	rm -rf out/main
	rm -rf out/*.o
