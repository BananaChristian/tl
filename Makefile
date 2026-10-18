.DEFAULT_GOAL := all

CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Iinclude -g
DEPFLAGS = -MMD -MP

BUILD = build
TARGET = $(BUILD)/tl
SRC = $(wildcard src/*.c src/**/*.c)
OBJ = $(patsubst src/%.c,$(BUILD)/%.o,$(SRC))
DEP = $(OBJ:.o=.d)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

$(BUILD)/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEP)

run: all
	./$(TARGET)

clean:
	rm -rf $(BUILD)



