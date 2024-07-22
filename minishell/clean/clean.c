#include "minishell.h"

static void	ft_clear_envlst(void)
{
	t_env	*envlst;
	t_env	*envlst_tofree;

	envlst = G_shell_.envlst;
	while (envlst)
	{
		envlst_tofree = envlst;
		envlst = envlst->next;
		free(envlst_tofree);
	}
	G_shell_.envlst = NULL;
}

void	ft_clean(void)
{
	clear_data(NULL, true);
	ft_clear_ast(&G_shell_.ast);
	ft_clear_envlst();
	rl_clear_history();
	tcsetattr(STDIN_FILENO, TCSANOW, &G_shell_.original_terminal);
}
