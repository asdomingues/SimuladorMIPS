SOURCE=./source/
INCLUDE=./include/
BUILD=./build/
BIN=main

COMPILER=g++
CFLAGS=-std=c++11 -g -Wall -Wextra -Wfatal-errors -Wno-parentheses
BOX=valgrind
BFLAGS=--leak-check=full --show-leak-kinds=all --track-origins=yes

TIME=time
IN= < registrador.in
OUT=

COLOR=-e "\033[0;36m"
NOCOLOR="\033[0;0m"

all: clean test-compile

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
	@$(BUILD)$(BIN)

test-run:
	@echo $(COLOR) [RUN] $(NOCOLOR)
	$(TIME) $(BOX) $(BFLAGS) $(BUILD)$(BIN) $(IN) $(OUT)

#.PHONY: all clean compile run
