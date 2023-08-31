# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Werror

# Directories
SRCDIR = src
BINDIR = bin

.PHONY: binary-search insertion-sort clean

binary-search: $(BINDIR)/binary-search

$(BINDIR)/binary-search: $(SRCDIR)/algorithms/searching/binary-search/binary-search.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

run-binary-search: binary-search
	$(BINDIR)/binary-search

insertion-sort: $(BINDIR)/insertion-sort

$(BINDIR)/insertion-sort: $(SRCDIR)/algorithms/sorting/insertion-sort/insertion-sort.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ $<

run-insertion-sort: insertion-sort
	$(BINDIR)/insertion-sort

clean:
	@rm -rf $(BINDIR)/*

