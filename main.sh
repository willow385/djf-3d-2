echo '#include<SDL2/SDL.h> 
int main(){ ; }' >> test.c
gcc test.c -o test.o -lSDL2 
returnVal=$?
rm test.c

SDL2_PATH=""
if [ $returnVal -ne 0 ] && [ ! -d external/SDL2 ]; then
    SDL2_PATH="$PWD/external/SDL2"
    mkdir temp
    curl https://libsdl.org/release/SDL2-2.0.10.tar.gz -o temp/SDL2.tar.gz
    mkdir -p external/SDL2
    tar -xvzf temp/SDL2.tar.gz -C external/
    rm -rf temp
    cd external/SDL2-2.0.10
    mkdir build
    cd build
    cmake -DCMAKE_INSTALL_PREFIX=${SDL2_PATH} .. 
    cmake --build . --target install
    cd ../../../
fi

if [ ! -d build ]; then
    mkdir build
fi

# build project
cd build
cmake -DSDL2_PATH="${SDL2_PATH}" ..
cmake --build . --target install 

# build demo
cd ../
mkdir -p demo/build
cd demo/build
cmake ..
cmake --build . 
