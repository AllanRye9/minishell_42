#ifndef TOKENIZING_H
# define TOKENIZING_H

# define PROMPT "minishell$ "

typedef enum e_token_type
{
	_IDENTIFIER,
	_LESS_SIGN,
	_GREAT_SIGN,
	_D_LESS_SIGN,
	_D_GREAT_SIGN,
	T_PIPE,
	T_O_PARENT,
	T_C_PARENT,
	_AND_SIGN,
	_OR_SIGN,
	T_NL,
}	t_token_type;

typedef struct s_token
{
	t_token_type		type;
	char				*value;
	struct s_token		*next;
	struct s_token		*prev;
}	t_token;

// tokenizer_appenders.c
int		ft_append_separator(t_token_type type, char **line,
			t_token **token_list);
int		ft_append_identifier(char **line, t_token **token_list);

// tokenizer_handlers.c
int		ft_handle_separator(char **line, t_token **token_list);
t_token	*ft_tokenization_handler(char *line);

// tokenizer_lst.c
t_token	*ft_new_token(char *value, t_token_type type);
void	ft_token_list_add_back(t_token **lst, t_token *new_token);
void	ft_clear_token_list(t_token **lst);

// tokenizer_utils.c
int		ft_is_quote(char c);
int		ft_is_separator(char *s);
void	ft_skip_spaces(char **line);
bool	ft_skip_quotes(char *line, size_t *i);
void	ft_print_quote_err(char c);

// tokenizer.c
t_token	*ft_tokenize(void);

#endif
