CPP = g++

TARGET = demo.x86

OBJS = src/Canvas.o\
       src/CoordPair.o\
       src/Line2D.o

SDL2 = -D_REENTRANT -I/usr/include/SDL2 -lSDL2

SRC = src/Canvas.cpp\
      src/Canvas.hpp\
      src/CoordPair.cpp\
      src/CoordPair.hpp\
      src/Line2D.cpp\
      src/Line2D.hpp\
      demo/main.cpp

FLAGS = -O3 -Wall -lm

$(TARGET): $(SRC)
	$(CPP) $(FLAGS) -c src/Canvas.cpp -o src/Canvas.o
	$(CPP) $(FLAGS) -c src/CoordPair.cpp -o src/CoordPair.o
	$(CPP) $(FLAGS) -c src/Line2D.cpp -o src/Line2D.o 
	$(CPP) $(FLAGS) $(OBJS) demo/main.cpp -o $(TARGET) $(SDL2)

run: $(TARGET)
	./$(TARGET)

clean: $(TARGET) $(OBJS)
	rm $(TARGET)
	rm $(OBJS)
