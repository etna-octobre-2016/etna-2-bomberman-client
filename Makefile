###################################################
# VARIABLES
###################################################

# Project name
# -------------------------------------------------
NAME=bomberman_client
LIBMY=libmy.so

# Commands
# -------------------------------------------------
CC=gcc
CFLAGS=-W -Wall -Werror -Wextra -std=c11 -std=gnu99 -g
RM=rm -rf

# Directories
# -------------------------------------------------
BINDIR=./bin
OBJDIR=./obj
LIBSDL=-F/Library/Frameworks -framework SDL2 -F/Library/Frameworks -framework SDL2_image -I/Library/Frameworks/SDL2.framework/Headers/ -I/Library/Frameworks/SDL2_image.framework/Headers/
LIBDIR=./lib
SRCDIR=.
ROOTDIR=`pwd`
# Directories (libmy)
LIBMY_DIR=$(LIBDIR)/my
LIBMY_BINDIR=$(LIBMY_DIR)/bin
LIBMY_SRCDIR=$(LIBMY_DIR)/src
LIBMY_OBJDIR=$(LIBMY_DIR)/obj

# Files
# -------------------------------------------------
BIN=$(BINDIR)/$(NAME)
SRC=$(SRCDIR)/*.c

# Files (libmy)
LIBMY_BIN=$(LIBMY_BINDIR)/$(LIBMY)
LIBMY_SRC:=$(wildcard $(LIBMY_SRCDIR)/*.c)
LIBMY_OBJ:=$(patsubst %.c,%.o,$(LIBMY_SRC))

###################################################
# TARGETS
###################################################

# Default
# -------------------------------------------------
all: $(BINDIR) $(NAME)

# Compilation
# -------------------------------------------------
$(NAME):
	$(CC) $(CFLAGS) $(SRC) $(LIBSDL) -L $(LIBMY_BINDIR) $(LIBMY_BIN) -o $(BIN)
# Directories
# -------------------------------------------------

# Utils
# -------------------------------------------------
# Removes objects files
clean:
	$(RM) $(LIBMY_OBJDIR)

# Removes objects files and binaries
fclean: clean
	$(RM) $(BINDIR) $(LIBMY_BINDIR)

# Removes all & launches compiling
re: fclean libmy all

# Creates binaries directory
$(BINDIR):
	mkdir -p $(BINDIR)
####################################################
# LIBS TARGETS
####################################################

# Generates object files (for libraries)
%.o:%.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

# libmy compiling
libmy: $(LIBMY_BINDIR) $(LIBMY_OBJDIR) $(LIBMY_OBJ)
	mv $(LIBMY_OBJ) $(LIBMY_OBJDIR)
	$(CC) $(CFLAGS) -shared -o $(LIBMY_BIN) $(LIBMY_OBJDIR)/*.o

$(LIBMY_BINDIR):
	mkdir -p $(LIBMY_BINDIR)

$(LIBMY_OBJDIR):
	mkdir -p $(LIBMY_OBJDIR)
