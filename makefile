# If you want to use a different C++ compiler, you may have
# to change some other stuff first. I tested this with
# Clang and it works just fine.
CPP = g++

MODEL ?= demo/utah_teapot.obj

DEMO = bin/demo.x86

OBJS = obj/Canvas.o\
       obj/CoordPair.o\
       obj/CoordTriple.o\
       obj/Perspective.o\
       obj/Scene.o\
       obj/Model3d.o

SRC = src/Canvas.cpp\
      src/Canvas.h\
      src/CoordPair.cpp\
      src/CoordPair.h\
      src/CoordTriple.cpp\
      src/CoordTriple.h\
      src/Perspective.cpp\
      src/Perspective.h\
      src/KeyboardState.h\
      src/Model3d.cpp\
      src/Model3d.h\
      src/Scene.h\
      src/Scene.cpp

FLAGS = -O3 -Wall -lm -std=c++11 -fPIC

LD_FLAGS = -ldjf-3d-2 -lSDL2

$(OBJS): $(SRC)
	$(CPP) $(FLAGS) -c src/CoordPair.cpp -o obj/CoordPair.o
	$(CPP) $(FLAGS) -c src/Perspective.cpp -o obj/Perspective.o
	$(CPP) $(FLAGS) -c src/Canvas.cpp -o obj/Canvas.o
	$(CPP) $(FLAGS) -c src/CoordTriple.cpp -o obj/CoordTriple.o
	$(CPP) $(FLAGS) -c src/Model3d.cpp -o obj/Model3d.o
	$(CPP) $(FLAGS) -c src/Scene.cpp -o obj/Scene.o

$(DEMO): demo/main.cpp
	$(CPP) $(FLAGS) demo/main.cpp -o $(DEMO) $(LD_FLAGS)

demo: $(DEMO)

run-demo: $(DEMO)
	./$(DEMO) $(MODEL)

clean: $(DEMO)
	rm $(DEMO)

install: $(OBJS) install.sh
	./install.sh

uninstall: uninstall.sh
	./uninstall.sh