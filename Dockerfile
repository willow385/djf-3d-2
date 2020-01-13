# Referenced from https://github.com/thewtex/docker-opengl/blob/master/Dockerfile
FROM dockcross/base:latest

WORKDIR /home/djf-3d-2
COPY ./main.sh /home/djf-3d-2/main.sh
COPY ./CMakeLists.txt /home/djf-3d-2/CMakeLists.txt
COPY ./djf-3d-2Config.cmake.in /home/djf-3d-2/djf-3d-2Config.cmake.in
COPY ./src /home/djf-3d-2/src
COPY ./demo /home/djf-3d-2/demo
