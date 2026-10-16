CC = gcc
BASE = -std=gnu23 -Wall -Wextra -Iinclude -MMD -MP
CFLAGS = $(BASE) -O2
LDFLAGS = -lm
SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=build/%.o)

boid-simulation: $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

build:
	mkdir -p build

debug: CFLAGS = $(BASE) -g -fsanitize=address,undefined
debug: LDFLAGS += -fsanitize=address,undefined
debug: clean boid-simulation

clean:
	rm -rf build boid-simulation

-include $(OBJ:.o=.d)

.PHONY: clean debug