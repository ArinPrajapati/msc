# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Input source file from command line or default to main.cpp
FILE ?= main.cpp
TARGET = $(basename $(FILE))

# Default target: build and run
all: $(TARGET)
	./$(TARGET)

# Compile target
$(TARGET): $(FILE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(FILE)

# Clean up build files
clean:
	rm -f $(TARGET)

