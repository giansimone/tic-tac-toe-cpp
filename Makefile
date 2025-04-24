CXX = clang++
CXXFLAGS = -std=c++20 -Wall -Wextra -Wpedantic
DEBUG_FLAGS = -g -DDEBUG

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin

$(shell mkdir -p $(BUILD_DIR) $(BIN_DIR))

PROJECT_NAME = tictactoe
TARGET = $(BIN_DIR)/$(PROJECT_NAME)

SRCS = $(wildcard $(SRC_DIR)/*.cc) $(wildcard $(SRC_DIR)/**/*.cc)
OBJS = $(patsubst $(SRC_DIR)/%.cc,$(BUILD_DIR)/%.o,$(SRCS))

INCLUDES = -I$(INCLUDE_DIR)
LDFLAGS = 
LDLIBS = 

all: $(TARGET)

debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: all

$(TARGET): $(OBJS)
	@echo "Linking $@..."
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)
	@echo "Build complete: $@"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc
	@echo "Compiling $<..."
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

DEPS := $(OBJS:.o=.d)
$(BUILD_DIR)/%.d: $(SRC_DIR)/%.cc
	@mkdir -p $(@D)
	@$(CXX) $(INCLUDES) -MM $< | \
		sed 's,\($*\)\.o[ :]*,$(BUILD_DIR)/\1.o $@ : ,g' > $@

-include $(DEPS)

clean:
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*

distclean: clean
	@echo "Performing deep clean..."
	rm -f $(DEPS)

.PHONY: all debug clean distclean