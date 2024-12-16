NAME=3sat-3dm

build:
	mkdir -p bin
	g++ -Wall -o bin/${NAME} src/*.cpp

test:
	./bin/${NAME} 3sat.json

all: build test