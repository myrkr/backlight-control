SOURCES = $(wildcard *.c)
OBJS = $(SOURCES:.c=.o)
CFLAGS = -W -Wall -Wextra
LDFLAGS = -lm

all: $(OBJS)

clean:
	rm $(OBJS)

.PHONY: all clean

