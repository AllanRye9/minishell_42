#include "minishell.h"

static int heredoc_exp_writer(char *s, size_t i, int fd, t_minishell *G_shell_)
{
    size_t start;
    char c;

    start = ++i;
    if (s[i] == '?')
        return (ft_putnbr_fd(G_shell_->exit_s, fd), 2);
    while(s[i] && s[i] != '$' && s[i] != ' ')
        i++;
    if(i != start)
    {
        c = ft_garbage_collector(ft_substr(s, start, i), false);
        c = ft_get_envlst_val(c, G_shell_);
        if(c)
            ft_putstr_fd(c, fd);
    }
    return (i);
}

void ft_heredoc_exp(char *s, int fd, t_minishell *G_shell_)
{
    size_t i;

    i = 0;
    while(s[i])
    {
        if(s[i] == '$')
            i += ft_heredoc_exp_writer(s, i, fd, G_shell_);
        else
            i += (ft_putchar_fd(s, fd), 1);
    }
    ft_putchar_fd('\n', fd);
}