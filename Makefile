# Compiler and flags
CXX = g++-13
CXXFLAGS = -std=c++23 -Wall

# Name of execution file
TARGET = run

# List of source files
SRC = main.cpp manageSystem.cpp faculty.cpp instructor.cpp baseEntity.cpp student.cpp menu.cpp

# Default command: compile everything
all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Clean command
clean:
	rm -f $(TARGET)

# Compile and run command
run: all
	./$(TARGET)
