NAME		:= minishell
LIBFT		:= libft.a
CC			:= cc
FLAGS		:= -Wall -Wextra -Werror
LIBFT_PATH	:= "libft"

BUILT-INS	:= 	built-ins/cd.c \
				built-ins/pwd.c \
# 				built-ins/env_utils.c \
# 				built-ins/env.c \
# 				built-ins/exit.c \
# 				built-ins/export.c \
# 				built-ins/echo.c \
# 				built-ins/unset.c 

SYSTEM		:= 	system/system.c

# CLEAN		:=	clean/clean.c

EXECUTION	:= 	execution/execution.c \
# 				execution/readline.c
 
START		:= 	start/start.c

PARSING		:=	parsing/parsing.c \
				parsing/pipe.c \
				parsing/input.c \

# SIGNALS		:=	signals/signals.c

UTILS		:=	utils/utils.c

SRC			:= 	$(UTILS) \
				$(START) \
				$(BUILT-INS) \
				$(PARSING) \
				$(EXECUTION) \
				$(SYSTEM)

OBJS		:= $(SRC:.c=.o)

READLINE_PATH	:= /path/lib/readline
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -Iinclude -I$(READLINE_PATH)/include

all: $(NAME)

$(LIBFT):
		make -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(OBJS) -L$(LIBFT_PATH) -lft -L$(READLINE_PATH)/lib -lreadline -o $(NAME)

clean:
		$(MAKE) clean -C $(LIBFT_PATH)
		rm -f $(OBJS)

fclean: clean
		$(MAKE) fclean -C $(LIBFT_PATH)
		rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re