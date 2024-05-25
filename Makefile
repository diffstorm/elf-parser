#
# elf-parser application makefile
# Copyright (c) 2019 Eray Ozturk <erayozturk1@gmail.com>
#
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
LDFLAGS = -lfmt

SRC = src/main.cpp src/ElfParser.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = elf-parser

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
