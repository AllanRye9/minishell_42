#include "../include/minishell.h"

void	ft_clear_io_list(t_io_node **lst)
{
	t_io_node	*curr_node;
	t_io_node	*next;

	curr_node = *lst;
	if (!curr_node)
		return ;
	while (curr_node)
	{
		free(curr_node->value);
		ft_free_char2(curr_node -> expanded_value);
		next = curr_node->next;
		free(curr_node);
		curr_node = next;
	}
	*lst = NULL;
}

void	ft_clear_cmd_node(t_node *node)
{
	if (!node)
		return ;
	ft_clear_io_list(&(node -> io_list));
	free(node -> arg);
	ft_free_char2(node -> expanded_args);
}

void	ft_recursive_clear(t_node *node)
{
	if (!node)
		return ;
	if (node->node_type == N_COMMANDS)
		ft_clear_cmd_node(node);
	else
	{
		if (node->prev)
			ft_recursive_clear(node->prev);
		if (node->next)
			ft_recursive_clear(node->next);
	}
	free(node);
}

void	ft_clear_ast(t_node **ast, t_minishell *lst)
{
	ft_recursive_clear(*ast);
	*ast = NULL;
	ft_clear_token_list(&lst->tokens);
}
