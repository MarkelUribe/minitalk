# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 12:41:15 by muribe-l          #+#    #+#              #
#    Updated: 2024/04/18 12:14:36 by muribe-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SNAME = server
CNAME = client

SSRV := server.c
SCLT := client.c

ODIR = ./obj
SOBJ = $(SSRV:.c=.o)
COBJ = $(SCLT:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o2 -Iincludes
RM = rm -rf
LIBFTNAME = libft.a
LIBFTDIR = ./libs/libft

vpath %.o $(OBJS_DIR)

%.o: %.c
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $(ODIR)/$@

all: $(CNAME) $(SNAME)

$(SNAME): $(SOBJ)
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) $(ODIR)/$(SOBJ) $(LIBFTDIR)/$(LIBFTNAME) -o $(SNAME)

$(CNAME): $(COBJ)
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) $(ODIR)/$(COBJ) $(LIBFTDIR)/$(LIBFTNAME) -o $(CNAME)

clean:
	make fclean -C $(LIBFTDIR)
	$(RM) $(ODIR)/$(SOBJ) $(ODIR)/$(COBJ)

fclean: clean
	$(RM) $(SNAME) $(CNAME)
	make clean -C $(LIBFTDIR)

re: fclean all

.PHONY:	all clean fclean re
