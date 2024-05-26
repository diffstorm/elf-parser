#
# elf-parser application makefile
# Copyright (c) 2019 Eray Ozturk <erayozturk1@gmail.com>
#
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -g0 -O2 -s -fdata-sections -ffunction-sections -Wl,--gc-sections
LDFLAGS = -lfmt
STRIP := strip

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/elf-parser

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	$(STRIP) -R .comment -R *.note* -s -x -X -v $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
