#include "../include/minishell.h"
 
void	change_home_dir(t_sysvar *sys_var, char *str)
{
	char	*dir;

	dir = get_dir(str, sys_var);
}

int	change_dir(t_sysvar *sys_var, t_cmds *cmds)
{
	if (!cmds->str[1])
		change_home_dir(sys_var, "HOME=");
}
