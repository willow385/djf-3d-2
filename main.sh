if [ ! -d external/SDL2-2.0.10/SDL2 ]; then
    mkdir temp
    curl https://libsdl.org/release/SDL2-2.0.10.tar.gz -o temp/SDL2.tar.gz
    mkdir -p external/SDL2
    tar -xvzf temp/SDL2.tar.gz -C external/
    rm -rf temp
    cd external/SDL2-2.0.10
    mkdir build
    cd build
    ../configure --prefix=$PWD/../SDL2
    make install
    cd ../../../
fi

if [ ! -d build ]; then
    mkdir build
fi

cd build
cmake ..
cmake --build . -v
