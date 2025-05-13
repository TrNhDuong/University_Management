# Compiler and flags
CXX = g++-13
CXXFLAGS = -std=c++2b 
# Name of execution file
TARGET = run

# List of source files
SRC = *.cpp Entity/*.cpp Command/*.cpp

# Default command: compile everything
all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean command
clean:
	rm -f $(TARGET)

# Compile and run command
run: all
	./$(TARGET)
