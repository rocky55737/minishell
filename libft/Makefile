# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhong <rhong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 14:45:33 by rhong             #+#    #+#              #
#    Updated: 2022/09/26 19:36:28 by rhong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror

SRCS = ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c ./ft_strlen.c ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memmove.c ./ft_strlcpy.c ./ft_strlcat.c ./ft_toupper.c ./ft_tolower.c ./ft_strchr.c ./ft_strrchr.c ./ft_strncmp.c ./ft_memchr.c ./ft_memcmp.c ./ft_strnstr.c ./ft_atoi.c ./ft_calloc.c ./ft_strdup.c ./ft_substr.c ./ft_strcmp.c ./ft_strtrim.c ./ft_split.c ./ft_itoa.c ./ft_strmapi.c ./ft_striteri.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c

SRCS_B = ./ft_lstnew.c ./ft_lstadd_front.c ./ft_lstsize.c ./ft_lstlast.c ./ft_lstadd_back.c ./ft_lstdelone.c ./ft_lstclear.c ./ft_lstiter.c ./ft_lstmap.c

HEADER = libft.h

AR = ar
ARFLAGS = -rcs
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

ifdef WITH_BONUS
	TOTAL_OBJS = $(OBJS) $(OBJS_B)
else
	TOTAL_OBJS = $(OBJS)
endif

all : $(NAME) $(HEADER)

$(NAME): $(TOTAL_OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(OBJS) $(OBJS_B)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

bonus :
	make WITH_BONUS=1

.PHONY: all clean fclean re bonus
