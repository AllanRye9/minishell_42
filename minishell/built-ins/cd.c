#include "../include/minishell.h"

char	*find_home(t_sysvar *sysvar, char *path)
{
	int	i;

	while (sysvar->env[i])
	{
		if (!ft_strncmp(sysvar->env[i], path, ft_strlen(path)))
			return (ft_substr(sysvar->env[i], ft_strlen(path), ft_strlen(sysvar->env[i]) - ft_strlen(path)));
		i++;
	}
	return (NULL);
}
 
int	change_dir(t_sysvar *sys_var, char *path)
{
	char	*dir;
	int		ret_value;

	dir = find_home(sys_var, path);
}

int	change_dir(t_sysvar *sysvar, char *path)
{
	int	ret_val;

	if (!path)
		ret_val = change_dir(sysvar, "HOME=");
	else if (ft_strncmp(path, "-", 1) == 0)
		ret_val = change_dir(sysvar, "OLDPWD=");
	else
	{
		ret_val = chdir(path);
		if (ret_val == -1)
		{
			ft_putstr_fd("Error:", STDERR_FILENO);
			ft_putstr_fd(path, STDERR_FILENO);
		}
	}
	if (ret_val == -1)
		return (EXIT_FAILURE);
	change_path(sysvar);
	add_path_to_env(sysvar);
	return (EXIT_SUCCESS);
}
