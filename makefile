CPP = g++

TARGET = demo.x86

OBJS = obj/Canvas.o\
       obj/CoordPair.o\
       obj/CoordTriple.o\
       obj/Perspective.o

SDL2 = -D_REENTRANT -I/usr/include/SDL2 -lSDL2

SRC = src/Canvas.cpp\
      src/Canvas.hpp\
      src/CoordPair.cpp\
      src/CoordPair.hpp\
      src/CoordTriple.cpp\
      src/CoordTriple.hpp\
      src/Perspective.cpp\
      src/Perspective.hpp\
      demo/main.cpp

FLAGS = -O3 -Wall -lm -std=c++11

$(TARGET): $(SRC)
	$(CPP) $(FLAGS) -c src/CoordPair.cpp -o obj/CoordPair.o
	$(CPP) $(FLAGS) -c src/Perspective.cpp -o obj/Perspective.o
	$(CPP) $(FLAGS) -c src/Canvas.cpp -o obj/Canvas.o
	$(CPP) $(FLAGS) -c src/CoordTriple.cpp -o obj/CoordTriple.o
	$(CPP) $(FLAGS) $(OBJS) demo/main.cpp -o $(TARGET) $(SDL2)

run: $(TARGET)
	./$(TARGET)

clean: $(TARGET) $(OBJS)
	rm $(TARGET)
	rm $(OBJS)
