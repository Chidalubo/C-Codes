# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -std=c++11

# the build target executable:
TARGET = Matrix
MATRIX = Matrix

TEST = test_matrix

all: $(TARGET)

$(TARGET): $(MATRIX).o   $(TEST).o
	$(CC) $(CFLAGS) -o $(TARGET) $(MATRIX).o   $(TEST).o

$(MATRIX).o: $(MATRIX).cpp $(MATRIX).h
	$(CC) $(CFLAGS) -c $(MATRIX).cpp

$(TEST).o: $(TEST).cpp $(MATRIX).h
	$(CC) $(CFLAGS) -c $(TEST).cpp

clean:
	$(RM) -f $(TARGET) $(MATRIX).o $(TEST).o
