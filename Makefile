#====================================================================================================
# For the tests add '-mac' to the end to compile for mac
# 	For example 'make sfml'     becomes 'make sfml-mac'
# 	And         'make sfml-run' becomes 'make sfml-run-mac'
# 
# Here are the main make commands
# 	Use 'make' to compile the project
# 	Use 'make run' to run the compiled project
# 
# 	Use 'make mac' to compile the project for mac
# 	Use 'make mac-run' to run the compiled project for mac
#
# Here are the current test commands
# 	'make sfml' to check if SFML works
# 	'make Tmovement' to run a basic test for movement
# 	'make Tcollision' to run a basic test for collision
#====================================================================================================

# The main make command for the project, use 'make' to compile and 'make run' to run the executable
all: main-compile main-link

main-compile:
	g++ -Isrc/include -c main.cpp -o "object files/main.o"

main-link:
	g++ "object files/main.o" -o "executables/main.exe" -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

run:
	./"executables/main.exe"

mac:
	g++ main.cpp -o "executables/main-mac" -lsfml-graphics -lsfml-window -lsfml-system

mac-run:
	./"executables/main-mac"


# Simple main file for testing if sfml works, this is for windows computers
sfml: compile-sfml link-sfml

compile-sfml:
	g++ -Isrc/include -c "tests/sfml-works.cpp" -o "object files/sfml-works.o"

link-sfml:
	g++ "object files/sfml-works.o" -o "executables/sfml-works.exe" -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

sfml-run:
	./"executables/sfml-works.exe"

sfml-mac:
	g++ "tests/sfml-works.cpp" -o "executables/sfml-works-mac" -lsfml-graphics -lsfml-window -lsfml-system

sfml-run-mac:
	./"executables/sfml-works-mac"


# A test for moving an object around the screen
Tmovement: compile-Tmovement link-Tmovement

compile-Tmovement:
	g++ -Isrc/include -c "tests/Tmovement-test.cpp" -o "object files/Tmovement-test.o"

link-Tmovement:
	g++ "object files/Tmovement-test.o" -o "executables/Tmovement-test.exe" -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

Tmovement-run:
	./"executables/Tmovement-test.exe"

Tmovement-mac:
	g++ "tests/Tmovement-test.cpp" -o "executables/Tmovement-test-mac" -lsfml-graphics -lsfml-window -lsfml-system

Tmovement-run-mac:
	./"executables/Tmovement-test-mac"


# A test for checking for collisions between shapes
Tcollision: compile-Tcollision link-Tcollision

compile-Tcollision:
	g++ -Isrc/include -c "tests/Tcollision-test.cpp" -o "object files/Tcollision-test.o"

link-Tcollision:
	g++ "object files/Tcollision-test.o" -o "executables/Tcollision-test.exe" -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

Tcollision-run:
	./"executables/Tcollision-test.exe"

Tcollision-mac:
	g++ "tests/Tcollision-test.cpp" -o "executables/Tcollision-test-mac" -lsfml-graphics -lsfml-window -lsfml-system

Tcollision-run-mac:
	./"executables/Tcollision-test-mac"
