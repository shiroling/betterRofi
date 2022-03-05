all: main.cpp
	g++ main.cpp src/popen3.c src/fileUtils.cpp src/rofiContainer.cpp -o main

rofiContainer: rofiContainer.cpp
	g++ -c src/rofiContainer.cpp -o obj/rofiContainer.o

popen3: popen3.c
	gcc -c src/popen3.c -o obj/popen3.o

fileUtils: fileUtils.cpp
	g++ -c src/fileUtils.cpp -o obj/fileUtils.o
