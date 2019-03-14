# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/09 13:44:17 by mverdier          #+#    #+#              #
#    Updated: 2019/03/14 15:58:18 by gfranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors.

ORANGE =	\033[1;33m   #It is actually Yellow, but i changed yellow to orange.

GREEN =		\033[1;32m

RED =		\033[1;31m

RES =		\033[0m

#------------------------------------------------------------------------------#

NAME = 		fractol

SRCDIR =	./srcs

INCDIR =	./includes

OBJDIR =	./objs

SRC =		main.c calcul_complex.c	mandelbrot.c zoom.c julia.c brain.c  \
			parse.c tools.c event_key.c event_mouse.c

INC =		fractol.h

SRCS =		$(SRC:%=$(SRCDIR)/%)

OBJS =		$(SRC:%.c=$(OBJDIR)/%.o)

INCS =		$(INC:%=$(INCDIR)/%)

LIBDIR =	./libft

LIBNAME =	libft.a

LIB =		$(LIBDIR)/$(LIBNAME)

LIBINC =	$(LIBDIR)

#------------------------------------------------------------------------------#

CC =		clang

CFLAGS =	-Wall			\
			-Wextra			\
			-Werror			\
			-g				\

INCFLAGS =	-I $(INCDIR)			\
			-I $(LIBINC)			\
			-I /usr/local/include

LFLAGS =	-L $(LIBDIR) -l$(LIBNAME:lib%.a=%)	\
			-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit	\
			-lpthread

FLAGS =		$(CFLAGS)		\
			$(INCFLAGS)

#------------------------------------------------------------------------------#
# Primary rules

all:
	@$(MAKE) -C $(LIBDIR)
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $@ $^ $(LFLAGS)

$(OBJS): $(INCS) $(LIB)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -o $@ -c $<

clean:
	@$(MAKE) -C $(LIBDIR) fclean
	@rm -rf $(OBJS)
	@rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) -C $(LIBDIR) fclean
	@rm -rf $(NAME)

re: fclean
	@$(MAKE) all

.PHONY: all clean re fclean
