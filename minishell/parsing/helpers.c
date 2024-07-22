#include "minishell.h"

bool	ft_get_io_list(t_io_node **io_list)
{
	t_token_type		redir_type;
	t_io_node			*tmp_io_node;

	if (G_shell_.parse_err.type)
		return (false);
	while (G_shell_.curr_token && ft_is_redir(G_shell_.curr_token->type))
	{
		redir_type = G_shell_.curr_token->type;
		ft_get_next_token();
		if (!G_shell_.curr_token)
			return (parse_err_type(E_SYNTAX), false);
		if (G_shell_.curr_token->type != _IDENTIFIER)
			return (parse_err_type(E_SYNTAX), false);
		tmp_io_node = ft_new_io_node(redir_type, G_shell_.curr_token->value);
		if (!tmp_io_node)
			return (parse_err_type(E_MEM), false);
		ft_append_io_node(io_list, tmp_io_node);
		ft_get_next_token();
	}
	return (true);
}

bool	ft_join_args(char **args)
{
	char	*to_free;

	if (G_shell_.parse_err.type)
		return (false);
	if (!*args)
		*args = ft_strdup("");
	if (!*args)
		return (false);
	while (G_shell_.curr_token
		&& G_shell_.curr_token->type == _IDENTIFIER)
	{
		to_free = *args;
		*args = ft_strjoin_with(*args, G_shell_.curr_token->value, ' ');
		if (!*args)
			return (free(to_free), false);
		free(to_free);
		ft_get_next_token();
	}
	return (true);
}

t_node	*ft_get_cmd(void)
{
	t_node	*node;

	if (G_shell_.parse_err.type)
		return (NULL);
	node = create_new_node(N_COMMANDS);
	if (!node)
		return (parse_err_type(E_MEM), NULL);
	while (G_shell_.curr_token
		&& (G_shell_.curr_token->type == _IDENTIFIER
			|| ft_is_redir(G_shell_.curr_token->type)))
	{
		if (G_shell_.curr_token->type == _IDENTIFIER)
		{
			if (!ft_join_args(&(node->args)))
				return (ft_clear_cmd_node(node), parse_err_type(E_MEM), NULL);
		}
		else if (ft_is_redir(G_shell_.curr_token->type))
		{
			if (!ft_get_io_list(&(node->io_list)))
				return (free(node->args), free(node), NULL);
		}
	}
	return (node);
}
