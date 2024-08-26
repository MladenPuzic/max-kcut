FROM ubuntu:latest

RUN echo 'Installing packages'
RUN apt-get update -y
RUN apt-get install g++ -y
RUN apt-get install git -y
RUN apt-get install cmake -y
RUN apt-get install ninja-build -y

RUN echo 'Copy workdir'
COPY . /max_kcut
WORKDIR /max_kcut

RUN echo 'Generate CMake files'
RUN cmake -G Ninja -B build/ -S .

RUN echo 'Build with Ninja'
RUN ninja -C build/

RUN echo 'DONE!!!'
WORKDIR /max_kcut/build/
CMD ["./max_kcut"]
