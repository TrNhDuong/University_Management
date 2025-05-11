# Compiler and flags
CXX = g++-13
CXXFLAGS = -std=c++23

# Name of execution file
TARGET = run.exe

# List of source files
SRC = *.cpp

# Default command: compile everything
all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean command
clean:
	rm -f $(TARGET)

# Compile and run command
run: all
	./$(TARGET)
