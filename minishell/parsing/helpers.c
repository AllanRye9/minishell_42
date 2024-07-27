#include "../include/minishell.h"

bool	ft_get_io_list(t_io_node **io_list, t_minishell *lst)
{
	t_token_type		redir_type;
	t_io_node			*tmp_io_node;

	if (lst->parse_error.error_type)
		return (false);
	while (lst->curr_token && ft_is_redir(lst->curr_token->token_t))
	{
		redir_type = lst->curr_token->token_t;
		ft_get_next_token(lst);
		if (!lst->curr_token || lst->curr_token->token_t != IDENDTIFIER)
			return (parse_err_type(SYNTAX_ERROR, lst), false);
		tmp_io_node = ft_new_io_node(redir_type, lst->curr_token->value);
		if (!tmp_io_node)
			return (parse_err_type(MEM_ERROR, lst), false);
		ft_append_io_node(io_list, tmp_io_node);
		ft_get_next_token(lst);
	}
	return (true);
}

bool	ft_join_args(char **args, t_minishell *to_join)
{
	char	*to_free;

	if (to_join->parse_error.error_type)
		return (false);
	if (!*args)
		*args = ft_strdup("");
	if (!*args)
		return (false);
	while (to_join->curr_token
		&& to_join->curr_token->token_t == IDENDTIFIER)
	{
		to_free = *args;
		*args = ft_strjoin_with(*args, to_join->curr_token->value, ' ');
		if (!*args)
			return (free(to_free), false);
		free(to_free);
		ft_get_next_token(to_join);
	}
	return (true);
}

t_node	*ft_get_cmd(t_minishell *cmds)
{
	t_node	*node;

	if (cmds->parse_error.error_type)
		return (NULL);
	node = create_new_node(N_COMMANDS);
	if (!node)
		return (parse_err_type(MEM_ERROR, cmds), NULL);
	while (cmds->curr_token
		&& (cmds->curr_token->token_t == IDENDTIFIER
			|| ft_is_redir(cmds->curr_token->token_t)))
	{
		if (cmds->curr_token->token_t == IDENDTIFIER)
		{
			if (!ft_join_args(&(node->arg), cmds))
				return (ft_clear_cmd_node(node), parse_err_type(MEM_ERROR, cmds), NULL);
		}
		else if (ft_is_redir(cmds->curr_token->token_t))
		{
			if (!ft_get_io_list(&(node->io_list), cmds))
				return (free(node->arg), free(node), NULL);
		}
	}
	return (node);
}
