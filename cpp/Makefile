EXT := cpp
CPPFLAGS := -std=c++11 -g
BIN_DIR := bin
SRCS := $(wildcard *.$(EXT))
TARGETS := $(SRCS:%.$(EXT)=$(BIN_DIR)/%)


all: $(TARGETS)


$(TARGETS): $(BIN_DIR)/% : %.$(EXT) headers.hpp
	@mkdir -p $(BIN_DIR)
	g++ $(CPPFLAGS) $< -o $@
