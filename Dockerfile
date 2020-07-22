FROM ubuntu:latest

RUN apt-get update

RUN apt-get -qy install bison
RUN apt-get -qy install flex
RUN apt-get -qy install gcc
RUN apt-get -qy install default-jre

RUN mkdir autouml-dev

WORKDIR /autouml-dev/
