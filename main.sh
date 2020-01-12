gcc -lSDL2
returnVal=$?
if [ $returnVal -ne 0 ] && [ ! -d external/SDL2 ]; then
    mkdir temp
    curl https://libsdl.org/release/SDL2-2.0.10.tar.gz -o temp/SDL2.tar.gz
    mkdir -p external/SDL2
    tar -xvzf temp/SDL2.tar.gz -C external/
    rm -rf temp
    cd external/SDL2-2.0.10
    mkdir build
    cd build
    # if installing locally, gotta add the directory where lib/cmake/SDL2Config.cmake is to CMAKE_PREFIX_PATH in the line before find_package in CMakeLists.txt
    # cmake -DCMAKE_INSTALL_PREFIX=external/SDL2 .. 
    cmake .. 
    cmake --build . --target install
    cd ../../../
fi

if [ ! -d build ]; then
    mkdir build
fi

# build project
cd build
cmake ..
cmake --build . --target install 

# build demo
cd ../
mkdir -p demo/build
cd demo/build
cmake ..
cmake --build . 
