
EXT := cpp
SRCS := $(shell ls *.$(EXT))
BIN_DIR = bin
TARGETS := $(patsubst %, $(BIN_DIR)/%, $(SRCS:.$(EXT)=))


all: $(TARGETS)


$(BIN_DIR)/%: %.$(EXT)
	@mkdir -p bin
	g++ -std=c++11 $^ -g -o $@
