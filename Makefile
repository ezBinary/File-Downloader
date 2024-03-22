# Makefile for FileDownloader project
# Works on macOS & linux

CC = g++
FLAGS = -Wall -std=c++11
LIBS = -lcurl

all: FileDownloader

FileDownloader: main.o downloader.o console.o
	$(CC) $(FLAGS) $^ -o $@ $(LIBS)

main.o: main.cpp
	$(CC) $(FLAGS) -c $<

downloader.o: downloader.cpp
	$(CC) $(FLAGS) -c $<

console.o: console.cpp
	$(CC) $(FLAGS) -c $<

clean:
	rm -f *.o FileDownloader
