###############
## Variables ##
###############

NAME		=	libftprintf.a

VPATH		=	src src/format src/parse
OBJDIR		=	obj
LIBDIR		=	libft
INCLDIR		=	incld

SRC			=	main.c \
				flag.c \
				parse.c \
				parse2.c \
				format.c \
				format2.c \
				format3.c \
				format4.c \
				format5.c \
				lenmod.c \
				display.c
LIB			=	libft.a
OBJ			=	$(SRC:%.c=$(OBJDIR)/%.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
INCFLAGS	=	-I./$(INCLDIR) -I./$(LIBDIR)/$(INCLDIR)
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
