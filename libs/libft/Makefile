# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muribe-l <muribe-l@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 15:15:27 by muribe-l          #+#    #+#              #
#    Updated: 2024/04/10 16:52:30 by muribe-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ar rcs
RM = rm -f

NAME = libft.a
SOURCES = ft_calloc.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlen.c ft_tolower.c ft_atoi.c \
ft_isascii.c ft_memcmp.c ft_strchr.c ft_strncmp.c ft_toupper.c ft_bzero.c \
ft_isdigit.c ft_memcpy.c ft_strlcat.c ft_strnstr.c ft_isalnum.c ft_isprint.c \
ft_memmove.c ft_strlcpy.c ft_strrchr.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_hex.c ft_atol.c ft_atodbl.c

BONUSSRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
ft_lstmap_bonus.c

BONUSOBJ = $(patsubst %.c,$(ODIR)/%.o,$(BONUSSRC))

OBJECTS = $(patsubst %.c,$(ODIR)/%.o,$(SOURCES))
ODIR = ./obj

CC = cc
CFLAGS = -Wall -Wextra -Werror -o2

all: $(NAME)

$(NAME): $(OBJECTS)
	$(LIB) $(NAME) $(OBJECTS)

bonus: $(OBJECTS) $(BONUSOBJ)
	$(LIB) $(NAME) $(BONUSOBJ) $(OBJECTS)

$(ODIR)/%.o: %.c
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(BONUSOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

rebonus: fclean bonus