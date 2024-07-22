#include "minishell.h"

void	parse_err_type(t_parse_err_type type)
{
	G_shell_.parse_err.type = type;
}

void	handle_parsing_err(void)
{
	t_parse_err_type	type;
	t_token_type		token_type;
	char				**types;

	types = (char *[]){"_IDENTIFIER",
		"<", ">", "<<", ">>", "|", "(", ")", "&&", "||", "newline"};
	type = G_shell_.parse_err.type;
	(void)token_type;
	(void)types;
	if (type)
	{
		if (type == E_SYNTAX)
		{
			if (!G_shell_.curr_token)
				token_type = T_NL;
			else
				token_type = G_shell_.curr_token->type;
			ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
			ft_putstr_fd(types[token_type], 2);
			ft_putstr_fd("'\n", 2);
			G_shell_.exit_s = 258;
		}
		ft_clear_ast(&G_shell_.ast);
		ft_bzero(&G_shell_.parse_err, sizeof(t_parse_err));
	}
}
