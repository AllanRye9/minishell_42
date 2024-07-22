#include "minishell.h"

t_node	*ft_term(void)
{
	t_node	*node;

	if (G_shell_.parse_err.type)
		return (NULL);
	if (token_type() || G_shell_.curr_token->type == T_C_PARENT)
		return (parse_err_type(E_SYNTAX), NULL);
	else if (G_shell_.curr_token->type == T_O_PARENT)
	{
		ft_get_next_token();
		node = ft_expression(0);
		if (!node)
			return (parse_err_type(E_MEM), NULL);
		if (!G_shell_.curr_token
			|| G_shell_.curr_token->type != T_C_PARENT)
			return (parse_err_type(E_SYNTAX), node);
		ft_get_next_token();
		return (node);
	}
	else
		return (ft_get_cmd());
}

t_node	*ft_expression(int min_prec)
{
	t_node			*left;
	t_node			*right;
	int				n_prec;
	t_token_type	op;

	if (G_shell_.parse_err.type || !G_shell_.curr_token)
		return (NULL);
	left = ft_term();
	if (!left)
		return (NULL);
	while (token_type() && ft_curr_token_prec() >= min_prec)
	{
		op = G_shell_.curr_token->type;
		ft_get_next_token();
		if (!G_shell_.curr_token)
			return (parse_err_type(E_SYNTAX), left);
		n_prec = ft_prec(op) + 1;
		right = ft_expression(n_prec);
		if (!right)
			return (left);
		left = ft_merge(op, left, right);
		if (!left)
			return (ft_clear_ast(&left), ft_clear_ast(&right), NULL);
	}
	return (left);
}

t_node	*ft_merge(t_token_type op, t_node *left, t_node *right)
{
	t_node	*node;

	if (G_shell_.parse_err.type)
		return (NULL);
	node = create_new_node(get_node_type(op));
	if (!node)
		return (parse_err_type(E_MEM), NULL);
	node->left = left;
	node->right = right;
	return (node);
}

t_node	*ft_parse(void)
{
	t_node	*ast;

	G_shell_.curr_token = G_shell_.tokens;
	ast = ft_expression(0);
	if (G_shell_.curr_token)
		return (parse_err_type(E_SYNTAX), ast);
	return (ast);
}
