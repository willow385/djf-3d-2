CPP = g++

TARGET = demo.x86

OBJS = src/Canvas.o

SDL2 = -D_REENTRANT -I/usr/include/SDL2 -lSDL2

SRC = src/Canvas.cpp src/Canvas.hpp demo/main.cpp

FLAGS = -O3 -Wall

$(TARGET): $(OBJS) $(SRC)
	$(CPP) $(FLAGS) -c src/Canvas.cpp -o src/Canvas.o
	$(CPP) $(FLAGS) $(OBJS) demo/main.cpp -o $(TARGET) $(SDL2)

run: $(TARGET)
	./$(TARGET)

clean: $(TARGET) $(OBJS)
	rm $(TARGET)
	rm $(OBJS)
