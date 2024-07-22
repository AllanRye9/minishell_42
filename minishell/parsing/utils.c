#include "minishell.h"

void	ft_get_next_token(void)
{
	G_shell_.curr_token = G_shell_.curr_token->next;
}

bool	token_type(void)
{
	t_token_type	type;

	if (!G_shell_.curr_token)
		return (false);
	type = G_shell_.curr_token->type;
	if (type == T_PIPE || type == _AND_SIGN || type == _OR_SIGN)
		return (true);
	return (false);
}

bool	ft_is_redir(t_token_type type)
{
	if (type == _LESS_SIGN || type == _GREAT_SIGN
		|| type == _D_LESS_SIGN || type == _D_GREAT_SIGN)
		return (true);
	return (false);
}

int	ft_prec(t_token_type type)
{
	if (type == _OR_SIGN || type == _AND_SIGN)
		return (0);
	return (1);
}

int	ft_curr_token_prec(void)
{
	return (ft_prec(G_shell_.curr_token->type));
}
