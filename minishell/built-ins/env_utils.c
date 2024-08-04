/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 15:45:59 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/31 16:39:01 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_strcmp(const char *a, const char *b)
{
	int i = 0;
	while(a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}

void	ft_envlst_back(t_env *new_env, t_minishell *g_shell)
{
	t_env	*curr_env;

	if (!g_shell->envlst)
	{
		g_shell->envlst = new_env;
		return ;
	}
	curr_env = g_shell->envlst;
	while (curr_env && curr_env->next)
		curr_env = curr_env->next;
	curr_env->next = new_env;
}

static t_env	*ft_envlst_new(char *key, char *value)
{
	t_env	*new_env;

	new_env = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new_env)
		return (NULL);
	new_env->key = ft_garbage_collector(ft_strdup(key), false);
	if (value)
		new_env->value = ft_garbage_collector(ft_strdup(value), false);
	new_env->next = NULL;
	return (NULL);
}

void	ft_update_envlst(char *key, char *value, bool create, t_minishell *g_shell)
{
	t_env	*envlst;

	envlst = g_shell->envlst;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
		{
			if (value)
				envlst->value = ft_garbage_collector(ft_strdup(value), false);
			return ;
		}
		envlst = envlst->next;
	}
	if (create)
		ft_envlst_back(ft_envlst_new(key, value), g_shell);
}
