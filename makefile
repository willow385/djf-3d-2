CPP = g++

TARGET = demo.x86

OBJS = src/Canvas.o\
       src/CoordTriple.o

SDL2 = -D_REENTRANT -I/usr/include/SDL2 -lSDL2

SRC = src/Canvas.cpp\
      src/Canvas.hpp\
      src/CoordTriple.cpp\
      src/CoordTriple.hpp\
      demo/main.cpp

FLAGS = -O3 -Wall -lm -std=c++11

$(TARGET): $(SRC)
	$(CPP) $(FLAGS) -c src/Canvas.cpp -o src/Canvas.o
	$(CPP) $(FLAGS) -c src/CoordTriple.cpp -o src/CoordTriple.o
	$(CPP) $(FLAGS) $(OBJS) demo/main.cpp -o $(TARGET) $(SDL2)

run: $(TARGET)
	./$(TARGET)

clean: $(TARGET) $(OBJS)
	rm $(TARGET)
	rm $(OBJS)
