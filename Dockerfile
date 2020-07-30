FROM ubuntu:latest

RUN apt-get -qy update

RUN apt-get -qy install cmake
RUN apt-get -qy install clang
RUN apt-get -qy install libclang-dev

RUN apt-get -qy install googletest
RUN mkdir /usr/src/googletest/build
RUN cd /usr/src/googletest/build && cmake -DBUILD_SHARED_LIBS=ON .. && make
RUN cp -ra /usr/src/googletest/build/lib/*.so /usr/lib/
RUN ldconfig

RUN mkdir autouml-dev

WORKDIR /autouml-dev/
