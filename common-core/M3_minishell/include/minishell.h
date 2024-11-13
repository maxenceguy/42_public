/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguy <mguy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:30:31 by lbutel            #+#    #+#             */
/*   Updated: 2024/08/01 00:42:12 by mguy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <aio.h>
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define METACHARS "\'\"<>| \t$"

# define SUCCESS 0
# define COMMAND_NOT_FOUND 127
# define EXECUTION_FAILED 126
# define SYNTAX_ERROR 258
# define PERMISSION_DENIED 126
# define GEN_ERROR 1

extern int	g_signal;
// export struct
typedef struct s_export
{
	char	*str;
	char	*key;
	char	*value;
	int		i;
}				t_export;

// echo struct, just for ft_echo
typedef struct s_echo
{
	int		n_flag;
	int		start_index;
	int		i;
	char	*str;
	char	*final;
	char	*tmp;
}				t_echo;

typedef enum e_token_type
{
	NONE,
	TEXT,
	EXPANDED_TEXT,
	LAST_PROCESS_STATUS,
	QUOTE,
	DOUBLE_QUOTE,
	REDIRECT_IN,
	REDIRECT_OUT,
	APPEND,
	HEREDOC,
	PIPE,
	DOLLAR,
}					t_token_type;

typedef struct s_node
{
	t_token_type	type;
	char			*str;
	char			*fd;
	bool			access_error;
	int				code_error;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_command
{
	int					ifd_in;
	char				*fd_in;
	int					ifd_out;
	char				*fd_out;
	int					append;
	char				*heredoc_file;
	char				**args;
	bool				access_error;
	struct s_command	*next;
	struct s_command	*prev;
	int					error_code;
}					t_command;

typedef struct s_gen
{
	t_command	*command;
	t_env		*env;
	char		**t_env;
	t_node		*node;
	int			error_code;
	pid_t		child_pid;
	bool		canceled_hrdoc;
	int			stdin_fd;
	int			stdout_fd;
}					t_gen;

typedef struct s_pipes
{
	t_command	*cmd;
	t_command	*current;
	int			num_cmds;
	int			pipe_fds[2];
	int			prev_fd;
	pid_t		pid;

}					t_pipes;

// get_env 
void			get_env(t_gen *gen, char **arr);
void			print_list(t_env *head);
void			free_list(t_env *head);

// tokenizer.c
t_node			*tokenize_command(char *str);
bool			write_here_file(t_gen *gen, int temp_fd, bool flag);
void			create_outfile(t_node *node);
t_command		*head_cmd(t_command *command);

// get_next_token.c
t_node			*get_next_token(char *str);
// heredoc.c
t_node			*heredoc_parser(t_node *node, t_gen *gen);
// heredoc_exec.c
t_node			*heredoc(t_node *node, bool flag, t_gen *gen);
char			*heredoc_expand(char *line, t_gen *gen);
// heredoc_expand_last_process
char			*heredoc_expand_last_process(char *line, int i, t_gen *gen);
void			breakheredoc(void);
// expander.c
t_node			*expand_command(t_node *node, t_gen *gen);

// demote_tokens.c
t_node			*demote_tokens(t_node *node);
t_node			*join_tokens(t_node *node, t_token_type delimiter);
char			*meta_to_text(t_token_type type);
t_node			*demote_to_next_quote(t_node *node, t_token_type type);

// redirection_parser.c
t_node			*redirection_parser(t_node *node);
void			create_outfile(t_node *node);

// pop node.c
void			pop_node(t_node *node);
t_node			*head_node(t_node *node);
void			free_all_node(t_node *node);
void			pop_cmd(t_command *command);
void			dollar_or_process(t_node *node);

// joiner.c
t_node			*joiner(t_node *node);
t_node			*transform_expanded_text(t_node *node);
t_node			*split_expanded_text(t_node *node);

// token_to_command.c
int				tokens_to_command(t_node *node, t_gen *gen);

// token_to_command_utils.c
t_command		*add_command(t_command *command);
int				lexer_parser(t_gen *gen, char *line);
t_node			*go_to_last(t_node *node);
bool			is_in_quote(t_node *node, t_token_type type);
bool			check_quotes(t_node *node, t_token_type type, t_node *end);

// token_to_command_bis.c
t_command		*case_acces_error(t_gen *gen);
int				lexer(t_node *node, t_gen *gen, t_node *last);
void			unlink_all(t_node *node);

// ft_echo 
int				exec_echo(char **cmd);

//ft_cd
int				ft_cd(t_gen *gen, char *path);
char			*ft_getenv(t_env *env, char *key);

// exec
void			execute_commands(t_gen *gen);
char			*find_in_path(t_env *env, t_command *cmd);

// tab2d
char			**env_in_tab(t_env *head);

// uncomplete function
void			free_exit(void);

// // redirect
// int				handle_redirections(t_command *cmd);

// signal
void			setup_signal_handlers(void);
int				handle_signals(t_gen *gen);

// ft_pwd
int				ft_pwd(t_gen *gen, char **args);

// ft_export
int				ft_export(t_gen *gen, char *key, char *value);
int				exec_export(t_gen *gen, char **tab);

// ft_unset
int				ft_unset(t_gen *gen, char **tab);

// // builtins
// int				is_builtin(t_gen *gen);

char			*token_to_str(t_node *token);

//free_cmd
void			free_cmd(t_gen *gen);

// pipes
void			execute_pipeline(t_gen *gen);

// ft_exit
int				ft_exit(t_gen *gen);

// pat_tools
char			**split_path(char *path);

// main
void			handler(int signo);
void			printcommands(t_command *command);

void			error_code(t_gen *gen, bool value);
char			**list_to_tab(t_gen *gen, t_env *list);

void			display_exit(int error, char *msg, t_gen *gen);
bool			is_builtin(char *cmd);
void			run_builtin(t_command *current, t_gen *gen);
bool			is_builtin2(char *cmd);
void			run_builtin2(t_command *current, t_gen *gen);
void			error_exit(int error_code, t_gen *gen);
int				handle_redirections(t_command *cmd, t_gen *gen);
int				ft_echo(char **cmd, t_gen *gen);
void			exec_command(t_command *cmd, t_gen *gen);
int				check_n(char **cmd, int *start_index, int *n_flag);
void			free_list(t_env *head);

#endif /* MINISHELL_H */
