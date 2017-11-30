SOURCE=./source/
INCLUDE=./include/
BUILD=./build/
BIN=main

COMPILER=g++
CFLAGS=-std=c++11 -g -Wall -Wextra -Wfatal-errors
BOX=valgrind
BFLAGS=--leak-check=full --show-leak-kinds=all --track-origins=yes

TIME=time
IN= < tests/0.in
OUT=

all: clean compile

clean:
	@find -name "*.swp" -exec rm -rf {} \;
	@find -name "*~" -exec rm -rf {} \;
	@rm -rf $(BUILD)

compile:
	@mkdir -p $(BUILD)
	@$(COMPILER) $(SOURCE)* -I $(INCLUDE) -o $(BUILD)$(BIN)

test-compile:
	mkdir -p $(BUILD)
	$(COMPILER) $(SOURCE)* -I $(INCLUDE) -o $(BUILD)$(BIN) $(CFLAGS)

run:
	@$(BUILD)$(PROGRAM)

test-run:
	$(TIME) $(BOX) $(BFLAGS) $(BUILD)$(PROGRAM) $(IN) $(OUT)

.PHONY: all clean compile run
