# minishell_42
                                  __              ___    ___
 /'\_/`\  __          __         /\ \            /\_ \  /\_ \
/\      \/\_\    ___ /\_\    ____\ \ \___      __\//\ \ \//\ \
\ \ \__\ \/\ \ /' _ `\/\ \  /',__\\ \  _ `\  /'__`\\ \ \  \ \ \
 \ \ \_/\ \ \ \/\ \/\ \ \ \/\__, `\\ \ \ \ \/\  __/ \_\ \_ \_\ \_
  \ \_\\ \_\ \_\ \_\ \_\ \_\/\____/ \ \_\ \_\ \____\/\____\/\____\
   \/_/ \/_/\/_/\/_/\/_/\/_/\/___/   \/_/\/_/\/____/\/____/\/____/

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