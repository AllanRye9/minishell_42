NAME		:= minishell
LIBFT		:= libft.a
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
LIBFT_PATH	:= "libft"

BUILT-INS	:= 	built-ins/cd.c \
				built-ins/echo.c \
				built-ins/env_utils.c \
				built-ins/env.c \
				built-ins/exit.c \
				built-ins/export.c \
				built-ins/pwd.c \
				built-ins/unset.c 

TOKENIZING	:= 	tokenizing/tokenizing.c

CLEAN		:=	clean/clean.c

# EXECUTION	:= 	execution/execution.c \
# 				execution/readline.c
 
MAIN		:= 	main/main.c

PARSING		:=	parsing/parsing.c

SIGNALS		:=	signals/signals.c

UTILS		:=	utils/utils.c

SRC			:= 	$(CLEAN) \
				$(EXECUTION) \
				$(BUILT-INS) \
				$(PARSING) \
				$(SIGNALS) \
				$(UTILS) \
				$(TOKENIZING) \
				$(MAIN) \

OBJS		:= $(SRC:.c=.o)

READLINE_PATH:=	/goinfre/homebrew/opt/readline

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -Iinclude -I$(READLINE_PATH)/include

all: $(NAME)

$(LIBFT):
		make -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(LIBFT)
		$(CC) -o $(NAME) $(OBJ) -L$(LIBFT_PATH) -lft -L$(READLINE_PATH)/lib -lreadline

clean:
		$(MAKE) clean -C $(LIBFT_PATH)
		rm -f $(OBJS)

fclean: clean
		$(MAKE) fclean -C $(LIBFT_PATH)
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re