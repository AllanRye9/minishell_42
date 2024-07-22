#include "minishell.h"

t_node_type	get_node_type(t_token_type type)
{
	if (type == _AND_SIGN)
		return (N_AND);
	if (type == _OR_SIGN)
		return (N_OR);
	return (N_PIPE);
}

t_io_type	ft_get_io_type(t_token_type type)
{
	if (type == _LESS_SIGN)
		return (IO_IN);
	if (type == _GREAT_SIGN)
		return (IO_OUT);
	if (type == _D_LESS_SIGN)
		return (_HEREDOC);
	return (_APPEND);
}

t_node	*create_new_node(t_node_type type)
{
	t_node	*new_node;

	new_node = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->type = type;
	return (new_node);
}

t_io_node	*ft_new_io_node(t_token_type type, char *value)
{
	t_io_node	*new_node;

	new_node = (t_io_node *)ft_calloc(1, sizeof(t_io_node));
	if (!new_node)
		return (NULL);
	new_node->type = ft_get_io_type(type);
	new_node->value = ft_strdup(value);
	if (!new_node->value)
		return (free(new_node), NULL);
	return (new_node);
}

void	ft_append_io_node(t_io_node **lst, t_io_node *new)
{
	t_io_node	*curr_node;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	curr_node = *lst;
	while (curr_node && curr_node -> next)
		curr_node = curr_node -> next;
	curr_node -> next = new;
}
