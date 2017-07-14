# ------------------------------------------------
# Makefile for C projects
# TODO: hacer una regla para crear las carpetas 
# necesarias
# por ejemplo: make project
# ------------------------------------------------

# project name (generate executable with this name)
TARGET   = out

CC       = clang
# compiling flags here
CFLAGS   = -g -std=c89 -Wall -I. -pedantic -O2
# CFLAGS   = -std=c99 -Wall -I.

LINKER   = clang -o
# linking flags here
LFLAGS   = -Wall -I. -lm
LIBS = -lSDL2 -lGL -lm -lGLU
# change these to proper directories where each file should be
SRCDIR   = src
INCDIR   = inc
OBJDIR   = obj
BINDIR   = bin
TESTDIR  = tests

SOURCES       := $(wildcard $(SRCDIR)/*.c)
SOURCES_TESTS := $(wildcard $(TESTDIR)/*.c)
INCLUDES_TEST := $(wildcard $(TESTDIR)/*.h)
INCLUDES      := $(wildcard $(INCDIR)/*.h)
OBJECTS       := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
RM             = rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS) $(LIBS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(RM) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(RM) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
