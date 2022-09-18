

# The main make command for the project, use `make` to compile and `make run` to run the executable
all: main-compile main-link

main-compile:
	g++ -Isrc/include -c main.cpp -o "object files/main.o"

main-link:
	g++ "object files/main.o" -o "executables/main" -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

run:
	./"executables/main.exe"


# Simple main file for testing if sfml works, this is for windows computers
sfml: compile-sfml link-sfml

compile-sfml:
	g++ -Isrc/include -c sfml-test.cpp -o "object files/sfml-test.o"

link-sfml:
	g++ "object files/sfml-test.o" -o "executables/sfml-test" -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

sfml-run:
	./"executables/sfml-test.exe"