# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/11 12:41:15 by muribe-l          #+#    #+#              #
#    Updated: 2024/04/23 20:50:03 by muribe-l         ###   ########.fr        #
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

all: $(ODIR) $(CNAME) $(SNAME)

$(ODIR):
	mkdir -p $(ODIR)

$(ODIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SNAME): $(addprefix $(ODIR)/, $(SOBJ))
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) $^ $(LIBFTDIR)/$(LIBFTNAME) -o $@

$(CNAME): $(addprefix $(ODIR)/, $(COBJ))
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) $^ $(LIBFTDIR)/$(LIBFTNAME) -o $@

clean:
	make fclean -C $(LIBFTDIR)
	$(RM) $(addprefix $(ODIR)/, $(SOBJ)) $(addprefix $(ODIR)/, $(COBJ))

fclean: clean
	$(RM) $(SNAME) $(CNAME)
	make clean -C $(LIBFTDIR)

re: fclean all

.PHONY:	all clean fclean re
