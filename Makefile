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
SDLDIR=~/Library/Frameworks/SDL2.framework
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

# Compilation
# -------------------------------------------------
$(NAME): $(BINDIR)
	$(CC) $(CFLAGS) $(SDLDIR)/SDL2 -o $(BIN) $(SRC)

# Game start
# -------------------------------------------------
start:
	$(BINDIR)/$(NAME)

# Directories
# -------------------------------------------------
$(BINDIR):
	mkdir -p $(BINDIR)

# Utils
# -------------------------------------------------
clean:
	$(RM) $(BINDIR)
