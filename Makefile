# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Source files (excluding main.c)
SRCS = $(filter-out $(SRCDIR)/main.c,$(wildcard $(SRCDIR)/algorithms/**/*.c)) $(SRCDIR)/other_source_files.c

# Object files
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

# Executable name
TARGET = $(BINDIR)/my_program

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS) $(SRCDIR)/main.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR) $(BINDIR)

