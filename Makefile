# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 12:41:15 by muribe-l          #+#    #+#              #
#    Updated: 2024/04/23 19:45:55 by muribe-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SNAME = server
CNAME = client

SSRV := server.c
SCLT := client.c

ODIR = ./obj
SOBJ = $(ODIR)/$(SSRV:.c=.o)
COBJ = $(ODIR)/$(SCLT:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -o2 -Iincludes
RM = rm -rf
LIBFTNAME = libft.a
LIBFTDIR = ./libs/libft

all: $(CNAME) $(SNAME)

vpath %.o $(OBJS_DIR)

%.o: %.c
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $(ODIR)/$@


$(SNAME): $(SOBJ)
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) $(SOBJ) $(LIBFTDIR)/$(LIBFTNAME) -o $(SNAME)

$(CNAME): $(COBJ)
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) $(COBJ) $(LIBFTDIR)/$(LIBFTNAME) -o $(CNAME)

clean:
	make fclean -C $(LIBFTDIR)
	$(RM) $(ODIR)/$(SOBJ) $(ODIR)/$(COBJ)

fclean: clean
	$(RM) $(SNAME) $(CNAME)
	make clean -C $(LIBFTDIR)

re: fclean all

.PHONY:	all clean fclean re
