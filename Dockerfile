FROM ubuntu:latest

RUN apt-get -qy update

RUN apt-get -qy install make
RUN apt-get -qy install clang
RUN apt-get -qy install libclang-10-dev

RUN mkdir autouml-dev

WORKDIR /autouml-dev/
