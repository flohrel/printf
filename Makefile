###############
## Variables ##
###############

NAME		=	libftprintf.a

VPATH		=	src
OBJDIR		=	obj
LIBDIR		=	libft
INCLDIR		=	incld

SRC			=	printf.c \
				parse.c \
				format.c \
				set_char.c \
				set_hex.c \
				set_int.c \
				set_str.c \
				set_uint.c \
				set_ul.c
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
