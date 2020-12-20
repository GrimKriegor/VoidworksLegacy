FROM alpine:3.13

ENV \
  CC=x86_64-w64-mingw32-gcc \
  CXX=x86_64-w64-mingw32-g++

RUN apk add --no-cache \
  make \
  cmake \
  mingw-w64-gcc

WORKDIR /mod

VOLUME /mod

CMD sh -c "\
    mkdir -p build \
    && cd build    \
    && cmake ..    \
    && make        \
  "
