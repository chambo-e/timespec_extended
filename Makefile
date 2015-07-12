##
## Made by Emmanuel Chambon
## chambo_e  <chambon.emmanuel@gmail.com>
##
## Started on  Wed Apr  8 22:49:16 2015 Emmanuel Chambon
## Last update Sun Jul 12 21:53:16 2015 Emmanuel Chambon
##

DEBUG		=	yes

CC		=	gcc

RM		=	rm -fr

BIN		=	libspec.so

SRC		=	timespec_extended.c	\
			timespec_add.c		\
			timespec_sub.c		\
			timespec_cmp.c		\
			timespec_lib.c

OBJ_DIR		=	obj/

SRC_DIR		=	src/

INC_DIR		=	include/

CFLAGS		=	-std=c11 -W -Wall -Wextra -I$(INC_DIR) -fPIC

ifeq ($(DEBUG),yes)

CFLAGS 		+= 	-g3

else

CFLAGS		+= 	-O3

endif

BUILD_PRINT	=	\e[1;34mBuilding\e[0m \e[1;33m$<\e[0m

OBJS		=	$(patsubst %.c,${OBJ_DIR}%.o, $(SRC))

FIRST		:=	$(shell test -d $(OBJ_DIR) || mkdir $(OBJ_DIR))

$(OBJ_DIR)%.o	:	$(patsubst %.c, ${SRC_DIR}%.c, %.c)
			@echo -e "$(BUILD_PRINT)" && $(CC) $(CFLAGS) -c $< -o $@

$(BIN)		:	$(OBJS)
			$(CC) $(OBJS) -shared -o $(BIN)

all		:
			@$(MAKE) --no-print-directory $(BIN)
			$(clean)

clean		:
			$(RM) $(OBJS) $(OBJ_DIR)

fclean		:	clean
			$(RM) $(BIN)

re		:	fclean all
