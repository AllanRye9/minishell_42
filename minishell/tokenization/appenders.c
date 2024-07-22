#include "minishell.h"

int	ft_append_separator(t_token_type type, char **line,
	t_token **token_list)
{
	t_token	*token;

	token = ft_new_token(NULL, type);
	if (!token)
		return (0);
	ft_token_list_add_back(token_list, token);
	(*line)++;
	if (type == _D_LESS_SIGN || type == _D_GREAT_SIGN || type == _OR_SIGN || type == _AND_SIGN)
		(*line)++;
	return (1);
}

int	ft_append_identifier(char **line, t_token **token_list)
{
	char	*tem;
	char	*value;
	t_token	*token;
	size_t	i;

	tem = *line;
	i = 0;
	while (tem[i] && !ft_is_separator(tem + i))
	{
		if (ft_is_quote(tem[i]))
		{
			if (!ft_skip_quotes(tem, &i))
				return (ft_print_quote_err(tem[i]), 0);
		}
		else
			i++;
	}
	value = ft_substr(tem, 0, i);
	if (!value)
		return (0);
	token = ft_new_token(value, _IDENTIFIER);
	if (!token)
		return (free(value), 0);
	*line += i;
	return (ft_token_list_add_back(token_list, token), 1);
}
