###############
## Variables ##
###############

NAME		=	libftprintf.a

SRCDIR		=	src
INCDIR		=	incld
OBJDIR		=	obj
LIBDIR		=	lib

SRC			=	printf.c \
				parse.c \
				format.c \
				display.c
OBJ			=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
INCFLAGS	=	-I./$(INCDIR)
AR			=	ar
ARFLAGS		=	rcs
RM			=	/bin/rm -rf


###########
## Rules ##
###########

.PHONY:			all bonus clean fclean re

all:			$(NAME)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR)
				$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@ -L./$(LIBDIR) -lft

$(NAME):		$(OBJ)
				$(AR) $(ARFLAGS) $@ $^

bonus:
				@make all OBJ="$(OBJ) $(BOBJ)"

clean:
				$(RM) $(OBJ) $(BOBJ)

fclean:			clean
				$(RM) $(OBJDIR) $(NAME)

re:				fclean all
