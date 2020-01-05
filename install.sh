#!/bin/sh

if [ ! -d "/usr/include/SDL2" ]; then
    echo "Error! You don't seem to have SDL2 installed!"
    echo "You will need to have SDL2 installed on your"
    echo "machine to use djf-3d-2."
fi

# Create the library.
ar -cvq libdjf-3d-2.a obj/*.o

# Move it to the appropriate location.
mv libdjf-3d-2.a /usr/lib/

# Put the headers in the appropriate location for GCC to
# find them.
mkdir /usr/include/djf-3d-2/
cp src/*.h /usr/include/djf-3d-2/

# Let the user know how to use it.
echo "\
Remember to pass the options '-ldjf-3d-2 -lSDL2' when\
 compiling a program that will use djf-3d-2. They MUST be\
 in that specific order.";