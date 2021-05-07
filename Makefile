
# the compiler:
CC = g++

# compiler flags:
CFLAGS  = -g -std=gnu++11 -Wall

# the build target executable:
TARGET = basic_visitor_pattern

#all: $(TARGET)

$(TARGET): app_animal_visitor.hpp animal_library.hpp
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp

test:
	

clean:
	$(RM) $(TARGET)