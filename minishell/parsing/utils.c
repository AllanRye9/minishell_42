#include "../include/minishell.h"

void	ft_get_next_token(t_minishell *next_ptr)
{
	next_ptr->curr_token = next_ptr->curr_token->next;
}

bool	token_type(t_minishell *token)
{
	t_token_type	type;

	if (!token->curr_token)
		return (false);
	type = token->curr_token->token_t;
	if (type == PIPE || type == AND || type == OR)
		return (true);
	return (false);
}

bool	ft_is_redir(t_token_type type)
{
	if (type == INPUT_R || type == OUTPUT_R
		|| type == INPUT_DELI || type == OUTPUT_DELI)
		return (true);
	return (false);
}

int	ft_prec(t_token_type type)
{
	if (type == OR || type == AND)
		return (0);
	return (1);
}

int	ft_curr_token_prec(t_minishell *ptr)
{
	return (ft_prec(ptr->curr_token->token_t));
}
