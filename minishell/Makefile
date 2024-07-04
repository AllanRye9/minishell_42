# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/03 15:29:57 by sbartoul          #+#    #+#              #
#    Updated: 2024/07/03 15:30:24 by sbartoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

AR = ar rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_bzero.c					\
		ft_atoi.c					\
		ft_calloc.c					\
		ft_isalnum.c				\
		ft_isalpha.c				\
		ft_isascii.c				\
		ft_isdigit.c				\
		ft_isprint.c				\
		ft_itoa.c					\
		ft_memchr.c					\
		ft_memcmp.c					\
		ft_memcpy.c					\
		ft_memmove.c				\
		ft_memset.c					\
		ft_putchar_fd.c				\
		ft_putendl_fd.c				\
		ft_putnbr_fd.c				\
		ft_putstr_fd.c				\
		ft_split.c					\
		ft_strchr.c					\
		ft_strdup.c					\
		ft_striteri.c				\
		ft_strjoin.c				\
		ft_strlcat.c				\
		ft_strlcpy.c				\
		ft_strlen.c					\
		ft_strmapi.c				\
		ft_strncmp.c				\
		ft_strnstr.c				\
		ft_strrchr.c				\
		ft_strtrim.c				\
		ft_substr.c					\
		ft_tolower.c				\
		ft_toupper.c				\

SRCSBONUS = ft_lstnew.c					\
			ft_lstadd_front.c			\
			ft_lstsize.c				\
			ft_lstlast.c				\
			ft_lstadd_back.c			\
			ft_lstdelone.c				\
			ft_lstclear.c				\
			ft_lstiter.c				\
			ft_lstmap.c					\


OBJECTS = ${SRCS:.c=.o}
OBJECTSBONUS = ${SRCSBONUS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}: ${OBJECTS}
				${AR} ${NAME} ${OBJECTS}
bonus: ${NAME} ${OBJECTSBONUS}
		${AR} ${NAME} ${OBJECTSBONUS}

all: ${NAME}
clean:
		${RM} ${OBJECTS} ${OBJECTSBONUS}
fclean: clean
		${RM} ${NAME}
re : fclean all

.PHONY: all clean fclean re