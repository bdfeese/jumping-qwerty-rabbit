CFLAGS += -std=c11 -Wall -Wextra -Wpedantic
LDLIBS := -lpthread

ELVES = $(patsubst %.c,%.elf,$(wildcard *.c))

all:
	$(foreach ELF, $(ELVES), $(CC) $(CFLAGS) \
            $(patsubst %.elf,%.c,$(ELF)) -o $(ELF) $(LDLIBS))

clean:
	$(RM) *.elf
