#include "../include/minishell.h"

int ft_identify_separators(char **line, char **token_list)
{
    if (!ft_strncmp(*line, "<<", 2))
		return (ft_append_separators(T_DLESS, line, token_list) && 1);
	else if (!ft_strncmp(*line, ">>", 2))
		return (ft_append_separators(T_DGREAT, line, token_list) && 1);
	else if (!ft_strncmp(*line, "<", 1))
		return (ft_append_separators(T_LESS, line, token_list) && 1);
	else if (!ft_strncmp(*line, ">", 1))
		return (ft_append_separators(T_GREAT, line, token_list) && 1);
	else if (!ft_strncmp(*line, "(", 1))
		return (ft_append_separators(T_O_PARENT, line, token_list) && 1);
	else if (!ft_strncmp(*line, ")", 1))
		return (ft_append_separators(T_C_PARENT, line, token_list) && 1);
	else if (!ft_strncmp(*line, "&&", 2))
		return (ft_append_separators(T_AND, line, token_list) && 1);
	else if (!ft_strncmp(*line, "||", 2))
		return (ft_append_separators(T_OR, line, token_list) && 1);
	else
		return (ft_append_separators(T_PIPE, line, token_list) && 1);
}

t_token *ft_token_handler(char *line, t_minishell *g)
{
    int error;
    t_token *token_list;
    
    error = 0;
    token_list = NULL;
    while(*line)
    {
        if(error)
            return (ft_clear_token_list(&token_list), NULL);
        if(ft_is_space(*line))
            ft_skip_spaces(&line);
        else if (!ft_strncmp(line, "<", 1) || !ft_strncmp(line, ">", 1)
			|| !ft_strncmp(line, "|", 1) || !ft_strncmp(line, "&&", 2)
			|| !ft_strncmp(line, "(", 1) || !ft_strncmp(line, ")", 1))
		    error = (!ft_identify_separators(&line, &token_list) && 1);
		else
		    error = (!ft_append_identifiers(&line, &token_list, g) && 1);
    }
    return (token_list);
}
