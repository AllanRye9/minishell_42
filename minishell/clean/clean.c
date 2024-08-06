#include "minishell.h"

static void	ft_clear_envlst(t_minishell *G_shell_)
{
	t_env	*envlst;
	t_env	*envlst_tofree;

	envlst = G_shell_->envlst;
	while (envlst)
	{
		envlst_tofree = envlst;
		envlst = envlst->next;
		free(envlst_tofree);
	}
	G_shell_->envlst = NULL;
}

void	ft_clean(t_minishell *G_shell_)
{
	ft_garbage_collector(NULL, true);
	ft_clear_astree(&G_shell_->ast, G_shell_);
	ft_clear_envlst(G_shell_);
	rl_clear_history();
	tcsetattr(STDIN_FILENO, TCSANOW, &g_sig_handler.original_term);
}
