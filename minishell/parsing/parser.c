#include "../include/minishell.h"

t_node	*ft_term(t_minishell *passed)
{
	t_node	*node;

	if (passed->parse_error.error_type)
		return (NULL);
	if (token_type(passed) || passed->curr_token->token_t == C_PARENT)
		return (parse_err_type(SYNTAX_ERROR, passed), NULL);
	else if (passed->curr_token->token_t == O_PARENT)
	{
		ft_get_next_token(passed);
		node = ft_expression(0, passed);
		if (!node)
			return (parse_err_type(MEM_ERROR, passed), NULL);
		if (!passed->curr_token
			|| passed->curr_token->token_t != C_PARENT)
			return (parse_err_type(SYNTAX_ERROR, passed), node);
		ft_get_next_token(passed);
		return (node);
	}
	else
		return (ft_get_cmd(passed));
}

t_node	*ft_expression(int min_prec, t_minishell *passed)
{
	t_node			*left;
	t_node			*right;
	int			n_prec;
	t_token_type		op;

	if (passed->parse_error.error_type || !passed->curr_token)
		return (NULL);
	left = ft_term(passed);
	if (!left)
		return (NULL);
	while (token_type(passed) && ft_curr_token_prec(passed) >= min_prec)
	{
		op = passed->curr_token->token_t;
		ft_get_next_token(passed);
		if (!passed->curr_token)
			return (parse_err_type(SYNTAX_ERROR, passed), left);
		n_prec = ft_prec(op) + 1;
		right = ft_expression(n_prec, passed);
		if (!right)
			return (left);
		left = ft_merge(op, left, right);
		if (!left)
			return (ft_clear_ast(&left, passed), ft_clear_ast(&right, passed), NULL);
	}
	return (left);
}

t_node	*ft_merge(t_token_type op, t_node *left, t_node *right, t_minishell *G_shell_)
{
	t_node	*node;

	if (G_shell_->parse_error.error_type)
		return (NULL);
	node = create_new_node(get_node_type(op));
	if (!node)
		return (parse_err_type(MEM_ERROR, G_shell_), NULL);
	node->prev = left;
	node->next = right;
	return (node);
}

t_node	*ft_parse(t_minishell *G_shell_)
{
	t_node	*ast;

	G_shell_->curr_token = G_shell_->tokens;
	ast = ft_expression(0, G_shell_);
	if (G_shell_->curr_token)
		return (parse_err_type(SYNTAX_ERROR, G_shell_), ast);
	return (ast);
}
