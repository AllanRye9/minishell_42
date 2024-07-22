#include "minishell.h"

int	ft_handle_separator(char **line, t_token **token_list)
{
	if (!ft_strncmp(*line, "<<", 2))
		return (ft_append_separator(_D_LESS_SIGN, line, token_list) && 1);
	else if (!ft_strncmp(*line, ">>", 2))
		return (ft_append_separator(_D_GREAT_SIGN, line, token_list) && 1);
	else if (!ft_strncmp(*line, "<", 1))
		return (ft_append_separator(_LESS_SIGN, line, token_list) && 1);
	else if (!ft_strncmp(*line, ">", 1))
		return (ft_append_separator(_GREAT_SIGN, line, token_list) && 1);
	else if (!ft_strncmp(*line, "(", 1))
		return (ft_append_separator(T_O_PARENT, line, token_list) && 1);
	else if (!ft_strncmp(*line, ")", 1))
		return (ft_append_separator(T_C_PARENT, line, token_list) && 1);
	else if (!ft_strncmp(*line, "&&", 2))
		return (ft_append_separator(_AND_SIGN, line, token_list) && 1);
	else if (!ft_strncmp(*line, "||", 2))
		return (ft_append_separator(_OR_SIGN, line, token_list) && 1);
	else
		return (ft_append_separator(T_PIPE, line, token_list) && 1);
}

t_token	*ft_tokenization_handler(char *line)
{
	int		error;
	t_token	*token_list;

	error = 0;
	token_list = NULL;
	while (*line)
	{
		if (error)
			return (ft_clear_token_list(&token_list), NULL);
		if (ft_isspace(*line))
			ft_skip_spaces(&line);
		else if (!ft_strncmp(line, "<", 1) || !ft_strncmp(line, ">", 1)
			|| !ft_strncmp(line, "|", 1) || !ft_strncmp(line, "&&", 2)
			|| !ft_strncmp(line, "(", 1) || !ft_strncmp(line, ")", 1))
			error = (!ft_handle_separator(&line, &token_list) && 1);
		else
			error = (!ft_append_identifier(&line, &token_list) && 1);
	}
	return (token_list);
}
