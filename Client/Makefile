CC      =       gcc -g
CFLAGS  =       -W -Wall -Werror
LDFLAGS =
SRC 	= 	main.c 	\
		functions/my_bomberman_part_1.c \
		functions/my_bomberman_part_2.c \
		functions/my_bomberman_part_3.c \
		libmy/my_putchar.c \
		libmy/my_strlen.c \
		libmy/my_putstr.c \
		libmy/my_strcmp.c \
		libmy/my_strcpy.c \
		libmy/my_str_isnum.c \
		libmy/my_getnbr.c \
		libmy/my_getchar.c
OBJ     =       $(SRC:%.c=%.o)
OUTPUT  =       bomber_man_client

all: $(OUTPUT)

bomber_man_client: 	$(OBJ)
			$(CC) -o $@ $^ $(LDFLAGS)

main.o: headers/my_bomberman.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o functions/*.o libmy/*.o

mrproper: clean
	rm -rf $(OUTPUT)
