OBJS = lux.o tsl2561.o backlight.o main.o
CFLAGS = -W -Wall -Wextra
CXXFLAGS = -W -Wall -Wextra
LDFLAGS = -lm
BINARY = backlight-control


all: $(BINARY)

$(BINARY): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJS) $(BINARY)

.PHONY: all clean

