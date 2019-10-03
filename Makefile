SOURCES = $(patsubst %.c,%.o,$(wildcard *.c))
TARGET  = kubemem
CFLAGS  = -Werror -Wall -I./ -g -Os

$(TARGET): $(SOURCES)

clean:
	-rm $(TARGET)
	-rm $(SOURCES)
