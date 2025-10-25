# Compiler
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Include directories
INCLUDES = -Isrc/core -Isrc/ui -Isrc/games -Iinclude

# Source files
SRCS = src/main.cpp \
       src/utils.cpp \
       src/ui/TextUI.cpp \
       src/games/connect4/Connect4Game.cpp \
       src/games/connect4/Connect4AI.cpp \
       src/games/tictactoe/TicTacToeGame.cpp \
       src/games/tictactoe/TicTacToeAI.cpp

# Object files (build/*.o)
OBJS = $(patsubst src/%.cpp,build/%.o,$(SRCS))

# Target executable
TARGET = build/connect4-ai

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile source files to object files
build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean build files
clean:
	rm -rf build

# Run files
run: all
	./build/connect4-ai

