NAME			:= minishell

LIBFT			:= libft.a
LIBFT_PATH		:= lib/libft

CC				:= cc

CFLAGS			:= -Wall -Werror -Wextra -g

BUILTINS		:=	built-ins/cd.c \
					built-ins/echo.c \
					built-ins/env_utils.c \
					built-ins/env_val.c \
					built-ins/env.c \
					built-ins/errors.c \
					built-ins/exit.c \
					built-ins/export.c \
					built-ins/pwd.c \
					built-ins/unset.c

CLEAN			:=	clean/clean.c

EXEC			:=	execution/check.c \
					execution/cmd.c \
					execution/errors.c \
					execution/exec_builtin.c \
					execution/exec.c \
					execution/get_path.c \
					execution/here_doc.c \
					execution/in_out_append.c \
					execution/init_tree.c	\
					execution/utils.c		\

PARSING			:=	parsing/clear.c \
					parsing/err.c \
					parsing/expression.c \
					parsing/grammar.c \
					parsing/nodes.c \
					parsing/utils.c \
					parsing/parser.c	\
					parsing/new_node.c	\

TOKENIZATION	:=	tokenization/appenders.c \
					tokenization/handlers.c \
					tokenization/clear.c \
					tokenization/token_utils.c \
					tokenization/tokenizer.c

EXPANDER		:= expander/asteric.c \
					expander/expander.c \
					expander/free_arr.c \
					expander/globber_utils.c \
					expander/globber.c \
					expander/handle_emptyquotes.c \
					expander/handle_wildcard.c	\
					expander/heredoc_expander.c \
					expander/quotes.c \
					expander/split_expand.c 

START			:=  start/start.c

SIGNALS			:= 	signals/signals.c

SRCS			:=	$(PARSING)\
					$(TOKENIZATION)\
					$(BUILTINS)\
					$(CLEAN)\
					$(EXEC)\
					$(START)\
					$(SIGNALS)\
					$(EXPANDER)\

OBJS			:=	$(SRCS:.c=.o)

READLINE_PATH	:=	$(HOME)/homebrew/opt/readline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -Iinclude -I$(READLINE_PATH)/include

all: $(NAME)

install_deps:
	@/bin/bash -c "$(shell curl -fsSL https://raw.githubusercontent.com/kube/42homebrew/master/install.sh)"
	@brew install readline

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): install_deps $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_PATH) -lft -L$(READLINE_PATH)/lib -lreadline -lhistory

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re install_deps