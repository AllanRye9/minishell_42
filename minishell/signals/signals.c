#include "../include/minishell.h"

void	sig_handler(int code)
{
	if (code == 2)
	{
		printf("\nminishell>>> \b");;
	}
	else if (code == 3)
		return ;
}
