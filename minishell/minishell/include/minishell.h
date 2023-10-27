/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: yasaidi <yasaidi@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/10/18 18:47:08 by yasaidi           #+#    #+#             */
/*   Updated: 2023/10/18 18:47:08 by yasaidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termcap.h>
# include <unistd.h>
# define CMD_NOT_FOUND 127
# define CMD_NOT_EXECUTABLE 126
# define MINISHELL "minishell-> "
# define HEREDOCNAME "/tmp/.minishell_heredoc_"
# define ERR_PARS_EXEC "parsing error: no command to execute!"
# define ERROR_HEREDOC_DELIM "here-document delimited by end-of-file: wanted"

typedef struct s_io_fds
{
	char	*infile;
	char	*outfile;
	int		fd_in;
	int		fd_out;
	int		stdin_backup;
	int		stdout_backup;
	char	*heredoc_delim;
	bool	herequotes;
}	t_io_fds;

typedef struct s_command
{
	char				*command;
	char				*path;
	char				**args;
	bool				pipe_output;
	int					*pipe_fd;
	t_io_fds			*io_fds;
	struct s_command	*next;
	struct s_command	*prev;
}	t_command;

typedef struct s_token
{
	char				*str;
	char				*str_backup;
	bool				var_exists;
	int					type;
	int					status;
	bool				join;
	struct s_token		*prev;
	struct s_token		*next;
}	t_token;

typedef struct s_data
{
	char		*input;
	char		**env;
	char		*working_dir;
	char		*old_working_dir;
	t_command	*cmd;
	t_token		*token;
	pid_t		pid;
}	t_data;

extern int	g_excode;
int			cd_builtin(t_data *data, char **args);
int			echo_builtin(t_data *data, char **args);
int			env_builtin(t_data *data, char **args);
int			exit_builtin(t_data *data, char **args);
int			export_builtin(t_data *data, char **args);
int			pwd_builtin(t_data *data, char **args);
int			unset_builtin(t_data *data, char **args);
int			count_env(char **env);
int			envvar_index(char **env, char *var);
char		*envvar_value(char **env, char *var);
bool		set_var(t_data *data, char *key, char *value);
bool		delete_var(t_data *data, int idx);
int			is_envvar_flag(char *var);
int			exec_prep(t_data *data);
int			exec(t_data *data, t_command *cmd);
int			bltin_exec(t_data *data, t_command *cmd);
int			why_cmd_not_found(t_data *data, t_command *cmd);
char		*get_cmd_path(t_data *data, char *name);
bool		cmd_is_dir(char *cmd);
bool		fd_for_pipes(t_command *cmds, t_command *c);
bool		pipe_builder(t_data *data);
void		pipe_closer(t_command *cmds, t_command *skip_cmd);
void		fd_closer(t_command *cmds, bool backup);
bool		io_check(t_io_fds *io);
bool		io_redirect(t_io_fds *io);
bool		io_backup(t_io_fds *io);
char		*what_var(char *str);
int			var_syntax(char c);
char		*get_val(t_token *tok, char *str, t_data *data);
int			var_replace(t_token **tok_lst, char *value, int i);
char		*replace_var_hdoc(char *str, char *value, int idx);
int			expand_var(t_data *data, t_token **tok_list);
char		*expand_var_heredoc(t_data *data, char *str);
void		cpy_value(char *new, char *value, int *j);
char		*name_to_value(char *old, char *value, int size_new, int idx);
int			handle_quotes(t_data *data);
bool		does_str_have_quotes(char *str);
int			count_len(char *str, int count, int i);
int			remove_quotes(t_token **tok_lst);
int			var_len(char *str);
int			input_parsing(t_data *data);
int			tokenmaker(t_data *data, char *str);
int			store_token(int *i, char *str, int start, t_data *data);
int			what_separator(char *str, int i);
int			what_quotes(int status, char *str, int i);
t_token		*new_node_list(char *str, char *cpy, int type, int status);
void		addback_node(t_token **node, t_token *new_node);
int			check_2_tokens(t_token **tok_list);
int			is_it_var(t_token **token);
void		del_one_node(t_token *tok_lst, void (*del)(void *));
void		list_wipe(t_token **tok_lst, void (*del)(void *));
t_command	*get_last_cmd(t_command *cmd);
void		addback_cmd(t_command **cmd_lst, t_command *new_node);
t_command	*new_node_cmd(int value);
int			set_args_echo(t_token **tok_lst, t_command *last_cmd);
void		del_nonex_var(t_token **tokens);
char		**cpy_args_echo(int len, char **new_tab, t_command *last_cmd,
				t_token *tmp);
int			arg_count_echo(t_token *temp);
int			alloc_args_echo(t_token **tok_lst, t_command *last_cmd);
char		*var_join(t_token **token_node);
int			get_args(t_token **tok_lst, t_command *last_cmd);
void		cmd_parser(t_data *data, t_token *token);
void		parse_word(t_command **cmd, t_token **tok_lst);
void		parse_input(t_command **last_cmd, t_token **token_lst);
bool		clean_file(t_io_fds *io, bool infile);
void		parse_trunc(t_command **last_cmd, t_token **token_lst);
void		parse_pipe(t_command **cmd, t_token **tok_lst);
void		parse_append(t_command **last_cmd, t_token **token_lst);
void		parse_heredoc(t_data *data, t_command **last_cmd,
				t_token **tol_lst);
bool		fill_heredoc(t_data *data, t_io_fds *io, int fd);
void		del_cmd(t_command *lst, void (*del)(void *));
void		wipe_cmd(t_command **lst, void (*del)(void *));
void		free_io(t_io_fds *io);
void		ign_sigquit(void);
void		cmd_in_shell_sig(void);
void		nl_on_sig(int signal);
void		base_minishell_sig(void);
void		prompt_reset(int signo);
char		*err_join(char *str, char *add);
int			cmd_error_msg(char *cmd, char *detail, char *error_msg, int excode);
void		gen_err_msg(char *errmsg, char *detail, int quotes);
void		exit_shell(t_data *data, int exno);
void		free_tabs(char **tab);
void		free_ptr(void *ptr);
void		free_datastruct(t_data *data, int flag_histclear);
int			datastruct_init(t_data *data, char **env);
void		io_init(t_command *cmd);
char		*ft_itoa(int n);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strjoin_pro(char *s1, char *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
bool		is_space(char *str);
int			detecte_quote(char *str);
void		miniloop(t_data *data);

enum e_quotes
{
	DEFAULT,
	SGLQUOTES,
	DBLQUOTES
};

enum e_token_types
{
	SPACES = 1,
	WORD,
	VAR,
	PIPE,
	INPUT,
	HEREDOC,
	APPEND,
	TRUNC,
	END,
};

#endif