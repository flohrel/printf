###############
## Variables ##
###############

NAME		=	libftprintf.a

VPATH		:=	src
OBJDIR		:=	obj
LIBDIR		:=	lib

SRC			:=	printf.c \
				parse.c \
				format.c \
				display.c
OBJ			=	$(SRC:%.c=$(OBJDIR)/%.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -03 -0fast -fsanitize=address -g3
INCFLAGS	=	-I./incld
LFLAGS		=	-L./$(LIBDIR) -lft
AR			=	ar
ARFLAGS		=	rcs
RM			=	/bin/rm -rf


###########
## Rules ##
###########

.PHONY:			all bonus clean fclean re

all:			$(NAME)

$(OBJDIR)/%.o:	%.c
				$(CC) $(CFLAGS) -c $< $(INCFLAGS) -o $@ $(LFLAGS)

$(NAME):		$(OBJ)
				$(AR) $(ARFLAGS) $@ $^

bonus:
				@make all OBJ="$(OBJ) $(BOBJ)"

clean:
				$(RM) $(OBJ) $(BOBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all
