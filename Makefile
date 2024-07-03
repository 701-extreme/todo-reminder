
CC=gcc
FLAGS=-Wall -Werror -g -fsanitize=address
LDFLAGS = -lm
OBJS=main.o display.o
TARGET=reminder
MAIN_SOURCE=main.c display.c
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(FLAGS) $^ -o $@ $(LDFLAGS)

.PHONY:
build: $(OBJS)
	$(CC) $(FLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

.PHONY:
clean:
	rm -f $(OBJS)
	rm -f $(TARGET)
	rm -rf *.out

