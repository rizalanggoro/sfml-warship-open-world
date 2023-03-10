# only change this lines
SFML_DIR=D:\sdk\SFML-gcc
CLEAR_TERMINAL=clear

# ---------------------------------------------------- #
CC=g++
LIB_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp sources/*.cpp
OBJECTS_1=$(SOURCES:.cpp=.o)
OBJECTS_2=$(OBJECTS_1:sources/*.o=*.o)
OBJECTS=$(OBJECTS_2:main.o=)

all: init compile link clear_objects run
# all: init clean compile link run
# all: init clean compile link clean_objects run

init:
	$(CLEAR_TERMINAL)
	@echo "Getting resources..."
	@echo "sources   ->" $(SOURCES)
	@echo "objects_1 ->" $(OBJECTS_1)
	@echo "objects_2 ->" $(OBJECTS_2)
	@echo "objects   ->" $(OBJECTS)
	@echo -e

compile:
	$(CC) -c $(SOURCES) -I "$(SFML_DIR)\include" 
	@echo "Compiling..."
	@echo -e

link:
	$(CC) $(OBJECTS) -o main -L "$(SFML_DIR)\lib" $(LIB_FLAGS)
	@echo "Linking..."
	@echo -e

clear_objects:
	@echo "Cleaning objects..."
	rm -f *.o
	@echo -e

clear:
	rm -f main
	@echo "Removing main executable..."
	@echo -e
	@echo "Cleaning objects..."
	rm -f *.o
	@echo -e

run: 
	@echo "Running executable..."
	.\main.exe
