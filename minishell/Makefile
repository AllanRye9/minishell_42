NAME		:= minishell

LIBFT		:= libft.a
LIBFT_PATH	:= "lib/libft"

CC			:= cc

CFLAGS		:= -Wall -Werror -Wextra

BUILTINS	:=	builtins/cd.c \
				builtins/echo.c \
				builtins/env_utils.c \
				builtins/env.c \
				builtins/exit.c \
				builtins/export.c \
				builtins/pwd.c \
				builtins/unset.c

CLEANING	:=	cleaning/ft_clean_ms.c

EXEC		:=	exec/error_msg.c \
				exec/exec_builtin.c \
				exec/exec_redirect.c \
				exec/exec_utils.c \
				exec/exec.c \
				exec/exist_check.c \
				exec/ft_exec_simple_cmd.c \
				exec/ft_get_path.c \
				exec/init_tree.c

UTILS	:=	utils/ft_asterisker.c \
				utils/ft_clean_empty_strs.c \
				utils/ft_expand_utils.c \
				utils/ft_expand.c \
				utils/ft_expander_split.c \
				utils/ft_globber_utils.c \
				utils/ft_globber.c \
				utils/ft_strip_quotes.c \
				utils/heredoc_expander.c

PARSING		:=	parsing/parser_clear.c \
				parsing/parser_err.c \
				parsing/parser_helpers.c \
				parsing/parser_nodes.c \
				parsing/utils.c \
				parsing/parser.c

TOKENIZATION	:=	tokenization/appenders.c \
					tokenization/handlers.c \
					tokenization/tokenize_lists.c \
					tokenization/utils.c \
					tokenization/tokenizer.c

START		:=  start/main.c

SIGNALS		:= signals/signals.c

SRCS		:=	$(BUILTINS)\
				$(CLEANING)\
				$(EXEC)\
				$(UTILS)\
				$(PARSING)\
				$(TOKENIZATION)\
				$(START)\
				$(SIGNALS)\

OBJS		:=	$(SRCS:.c=.o)

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
