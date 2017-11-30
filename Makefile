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

COLOR=-e "\033[0;31m"
NOCOLOR="\033[0;0m"

all: clean compile

clean:
	@echo $(COLOR) [CLEAN] $(NOCOLOR)
	@find -name "*.swp" -exec rm -rf {} \;
	@find -name "*~" -exec rm -rf {} \;
	@rm -rf $(BUILD)

compile:
	@echo $(COLOR) [COMPILE] $(NOCOLOR)
	@mkdir -p $(BUILD)
	@$(COMPILER) $(SOURCE)* -I $(INCLUDE) -o $(BUILD)$(BIN)

test-compile:
	@echo $(COLOR) [COMPILE] $(NOCOLOR)
	mkdir -p $(BUILD)
	$(COMPILER) $(SOURCE)* -I $(INCLUDE) -o $(BUILD)$(BIN) $(CFLAGS)

run:
	@echo $(COLOR) [RUN] $(NOCOLOR)
	@$(BUILD)$(PROGRAM)

test-run:
	@echo $(COLOR) [RUN] $(NOCOLOR)
	$(TIME) $(BOX) $(BFLAGS) $(BUILD)$(PROGRAM) $(IN) $(OUT)

.PHONY: all clean compile run
