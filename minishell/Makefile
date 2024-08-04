NAME			:= minishell

LIBFT			:= libft.a
LIBFT_PATH		:= "lib/libft"

CC				:= cc

CFLAGS			:= -Wall -Werror -Wextra

BUILTINS		:=	built-ins/cd.c \
					built-ins/echo.c \
					built-ins/env_utils.c \
					built-ins/env.c \
					built-ins/exit.c \
					built-ins/export.c \
					built-ins/pwd.c \
					built-ins/unset.c

CLEAN			:=	clean/clean.c

EXEC			:=	exec/error_msg.c \
					exec/exec_builtin.c \
					exec/exec_redirect.c \
					exec/exec_utils.c \
					exec/exec.c \
					exec/exist_check.c \
					exec/ft_exec_simple_cmd.c \
					exec/ft_get_path.c \
					exec/init_tree.c

PARSING			:=	parsing/clear.c \
					parsing/err.c \
					parsing/expression.c \
					parsing/grammar.c \
					parsing/nodes.c \
					parsing/utils.c \
					parsing/parser.c

TOKENIZATION	:=	tokenization/appenders.c \
					tokenization/handlers.c \
					tokenization/clear.c \
					tokenization/utils.c \
					tokenization/tokenizer.c

EXPANDER		:= expander/asteric.c \
					expander/expander.c \
					expander/free_arr.c \
					expander/globber_utils.c \
					expander/globber.c \
					expander/handle_emptyquotes.c \
					expaner_wildcard.c \
					expander/heredoc_expander.c \
					expander/quotes.c \
					expander/split_expand.c 

START			:=  start/main.c

SIGNALS			:= 	signals/signals.c

SRCS			:=	$(BUILTINS)\
					$(CLEAN)\
					$(EXEC)\
					$(PARSING)\
					$(TOKENIZATION)\
					$(START)\
					$(SIGNALS)\
					$(EXPANDER)\

OBJS		:=		$(SRCS:.c=.o)

READLINE_PATH:=	/goinfre/homebrew/opt/readline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude -I$(READLINE_PATH)/include

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -L$(READLINE_PATH)/lib -lreadline

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
