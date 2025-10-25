# === Makefile for Game Hub ===

CXX := clang++
CXXFLAGS := -std=c++17 -Wall -Wextra -I. -Iinclude -Iui -Igames

SRC := $(wildcard src/*.cpp core/*.cpp ui/*.cpp games/**/*.cpp)
OBJ := $(SRC:%.cpp=build/%.o)
DEP := $(OBJ:.o=.d)

TARGET := bin/gamehub

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CXX) $(OBJ) -o $(TARGET)
	@echo " Build complete: $(TARGET)"

build/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build bin
	@echo " Cleaned build files"

