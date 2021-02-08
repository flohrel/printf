###############
## Variables ##
###############

NAME		=	libftprintf.a

VPATH		=	src
OBJDIR		=	obj
LIBDIR		=	libft
INCLDIR		=	includes

SRC			=	main.c \
				flag.c \
				parse.c \
				format.c \
				format_utils.c \
				format_utils2.c \
				format_float.c \
				display.c
LIB			=	libft.a
OBJ			=	$(SRC:%.c=$(OBJDIR)/%.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
INCFLAGS	=	-I./$(INCLDIR)
LFLAGS		=	-L./$(LIBDIR) -lft
AR			=	ar
ARFLAGS		=	rcs
RM			=	/bin/rm -rf


###########
## Rules ##
###########

.PHONY:			all bonus clean fclean re

all:			$(NAME)

$(OBJDIR)/%.o:	%.c | $(OBJDIR)
				$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME):		$(OBJ)
				make -C $(LIBDIR)
				cp $(LIBDIR)/$(LIB) ./$(NAME)
				$(AR) $(ARFLAGS) $@ $^

$(OBJDIR):
				mkdir $(OBJDIR)

bonus:
				@make all OBJ="$(OBJ) $(BOBJ)"

clean:
				$(RM) $(OBJ) $(BOBJ)

fclean:			clean
				$(RM) $(NAME) $(OBJDIR)

re:				fclean all
