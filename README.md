# minishell_42

![](https://github.com/AllanRye9/minishell_42/blob/main/minishell.gif)

# Recreation of bash in mini version with following builtins.
- `echo` with option `-n`.
* `cd` with only a relative or absolute path.
+ `pwd` (no flags).
- `export` (no flags).
* `unset` (no flags).
+ `env` (no flags or arguments).
- `exit` (no flags).

# Can handle below redirections.
- `<` redirect input.
- `>` redirect output.
- `<<` heredoc.
- `>>` redirect output in append mode.

# Can handle `$` environment variables.

# Implement pipes (`| character`)

# In interactive mode:
- ctrl-C displays a new prompt on a new line. ◦ ctrl-D exits the shell.
- ctrl-\ does nothing.

# Have a working history

# Only one global variable is allowed to indicate the received signal.