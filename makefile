CXXFLAGS = -Wall -g
FLAG_SFML = -lsfml-graphics -lsfml-window -lsfml-system
DIR_SRC = src
DIR_HD = hd
DIR_OBJ = obj
OBJ= $(DIR_OBJ)/main.o

Snake: $(OBJ)
	g++ $^ -o $@ $(CXXFLAGS) $(FLAG_SFML)

$(DIR_OBJ)/main.o: $(DIR_SRC)/main.cpp
	g++ -o $@ -c $< $(CXXFLAGS)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.cpp $(DIR_HD)/%.h
	g++ -o $@ -c $< $(CXXFLAGS)

clean:
	rm -rf obj/*.o *~

CLEAN:
	rm -rf obj/*.o *~ Snake
