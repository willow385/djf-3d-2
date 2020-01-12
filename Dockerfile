# Referenced from https://github.com/thewtex/docker-opengl/blob/master/Dockerfile
FROM dockcross/base:latest

# main.sh
WORKDIR /home/temp
RUN curl https://libsdl.org/release/SDL2-2.0.10.tar.gz -o SDL2-2.0.10.tar.gz
RUN tar -xvzf SDL2-2.0.10.tar.gz -C .
WORKDIR /home/temp/SDL2-2.0.10/build
RUN cmake ..
# RUN cmake -DCMAKE_INSTALL_PREFIX=/home/user/work/external/SDL2 ..
RUN cmake --build . --target install
WORKDIR /home
RUN rm -rf temp

COPY ./CMakeLists.txt /home/djf-3d-2/CMakeLists.txt
COPY ./djf-3d-2Config.cmake /home/djf-3d-2/djf-3d-2Config.cmake 
COPY ./src /home/djf-3d-2/src
WORKDIR /home/djf-3d-2/build
RUN cmake ..
RUN cmake --build . --target install
COPY ./demo /home/djf-3d-2/demo
WORKDIR /home/djf-3d-2/demo/build
RUN cmake ..

# this will fail since this container can't have a window.
# RUN cmake --build . 