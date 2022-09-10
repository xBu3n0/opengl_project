all: compile

compile:
	g++ *.cpp -o main -lGL -lglfw -lGLEW -lm