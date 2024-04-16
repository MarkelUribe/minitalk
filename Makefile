# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 12:41:15 by muribe-l          #+#    #+#              #
#    Updated: 2024/04/16 10:19:39 by muribe-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SNAME = server
CNAME = client

ODIR = ./obj
SOBJ = $(ODIR)/server.o
COBJ = $(ODIR)/client.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o2 -Iincludes
RM = rm -rf
LIBFTNAME = libft.a
LIBFTDIR = ./libs/libft

$(ODIR)/%.o: %.c
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@


$(SNAME): $(SOBJ)
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) $(SOBJ) $(LIBFTDIR)/$(LIBFTNAME) -o $(SNAME)

$(CNAME): $(COBJ)
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) $(COBJ) $(LIBFTDIR)/$(LIBFTNAME) -o $(CNAME)

all: $(CNAME) $(SNAME)

clean:
	make fclean -C $(LIBFTDIR)
	$(RM) $(SOBJ) $(COBJ)

fclean: clean
	$(RM) $(SNAME) $(CNAME)
	make clean -C $(LIBFTDIR)

re: fclean all

.PHONY:	all clean fclean re
