###############
## Variables ##
###############

NAME		=	libftprintf.a

SRCDIR		=	src
INCDIR		=	incld
OBJDIR		=	obj

SRC			:=	$(wildcard $(SRCDIR)/*.c)
OBJ			:=	$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
INCFLAGS	=	-I./$(INCDIR)
AR			=	ar
ARFLAGS		=	rcs
RM			=	/bin/rm -rf


###########
## Rules ##
###########

.PHONY:			all bonus clean fclean re so

all:			$(NAME)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c | $(OBJDIR)
				$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME):		$(OBJ)
				$(AR) $(ARFLAGS) $@ $^

$(OBJDIR):
				mkdir $@

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(OBJDIR) $(NAME)

re:				fclean all
