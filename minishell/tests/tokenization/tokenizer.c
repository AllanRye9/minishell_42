#include "minishell.h"

t_token	*ft_tokenize(void)
{
	char	*line;
	t_token	*token_list;

	line = G_shell_.line;
	token_list = ft_tokenization_handler(line);
	free(line);
	G_shell_.line = NULL;
	return (token_list);
}
