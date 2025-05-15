# Compiler and flags
CC = gcc
AR = ar
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -g -O2 -Iinclude

# Directories
SRCDIR := src
INCDIR := include
BUILDDIR := obj
LIBDIR := lib

# Files
SRC := $(wildcard $(SRCDIR)/*.c)
OBJ := $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(SRC))
LIBNAME := qsort
STATICLIB := $(LIBDIR)/lib$(LIBNAME).a

all: $(STATICLIB)

$(STATICLIB): $(OBJ) | $(LIBDIR)
	$(AR) $(ARFLAGS) $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR) $(LIBDIR):
	mkdir -p $@

clean:
	rm -rf $(BUILDDIR) $(LIBDIR)
