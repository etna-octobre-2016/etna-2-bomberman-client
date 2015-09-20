###################################################
# VARIABLES
###################################################

# Project name
# -------------------------------------------------
NAME=bomberman_client

# Commands
# -------------------------------------------------
CC=gcc
CFLAGS=-W -Wall -Werror -Wextra -std=c11 -I $(SDLDIR)/include -L$(SDLDIR)/build/.libs -lsdl2
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
all: sdl2 $(NAME)

# SDL2 Lib Compilation
# -------------------------------------------------
sdl2:
	cd $(SDLDIR) && ./configure && make && cd $(ROOTDIR) && echo "SDL2 compiling complete !"

# Compilation
# -------------------------------------------------
$(NAME): $(BINDIR)
	$(CC) $(CFLAGS) -o $(BIN) $(SRC)

# Directories
# -------------------------------------------------
$(BINDIR):
	mkdir -p $(BINDIR)

# Utils
# -------------------------------------------------
clean:
	$(RM) $(BINDIR)
