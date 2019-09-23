SOURCES = $(patsubst %.c,%.o,$(wildcard *.c))
TARGET  = kubemem
CFLAGS  = -Werror -Wall -I./

$(TARGET): $(SOURCES)

clean:
	-rm $(TARGET)
	-rm $(SOURCES)
