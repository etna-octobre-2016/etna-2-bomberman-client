###################################################
# VARIABLES
###################################################

# Project name
# -------------------------------------------------
NAME=bomberman_client

# Commands
# -------------------------------------------------
CC=gcc
CFLAGS=-W -Wall -Werror -Wextra -std=c11
RM=rm -rf

# Directories
# -------------------------------------------------
BINDIR=./bin
OBJDIR=./obj
SDLDIR=./lib/sdl2
SRCDIR=./src
ROOTDIR=`pwd`

# Files
# -------------------------------------------------
BIN=$(BINDIR)/$(NAME)
SRC=$(SRCDIR)/*.c


###################################################
# TARGETS
###################################################

# Default
# -------------------------------------------------
all: $(NAME)

# SDL2 Lib Compilation
# -------------------------------------------------
sdl2:
	cd $(SDLDIR) && ./configure && make && cd $(ROOTDIR) && echo "SDL2 compiling complete !"

# Libraries
# -------------------------------------------------
libs: sdl2

# Compilation
# -------------------------------------------------
$(NAME): $(BINDIR)
	$(CC) $(CFLAGS) -I$(SDLDIR)/include -o $(BIN) $(SDLDIR)/build/.libs/libSDL2.a $(SRC)

# Directories
# -------------------------------------------------
$(BINDIR):
	mkdir -p $(BINDIR)

# Utils
# -------------------------------------------------
clean:
	$(RM) $(BINDIR)
