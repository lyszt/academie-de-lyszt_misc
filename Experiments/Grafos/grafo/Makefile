CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -MMD -MP

SRC_DIR := src
BUILD_DIR := build
BIN := grafo

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all clean run

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(BUILD_DIR) $(BIN)

-include $(DEPS)
