/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeterso <mpeterso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:19:10 by mpeterso          #+#    #+#             */
/*   Updated: 2023/08/03 17:53:31 by mpeterso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>
# include "./gnl/get_next_line.h"

# define INFILE_ERR "\033[31mInfile Error\n\e[0m"
# define OUTFILE_ERR "\033[31mOutfile Error\n\e[0m"
# define PIPE_ERR "\033[31mPipe Error\n\e[0m"
# define FORK_ERR "\033[31mFork Error\n\e[0m"
# define CMD_ERR "\033[31mCommand Error\n\e[0m"
# define EXECVE_ERR "\033[31mExecve Error\n\e[0m"
# define HEREDOC_ERR "\033[31mHeredoc Error\n\e[0m"
# define ENVP_ERR "\033[31mENVP Path Error\n\e[0m"

typedef struct s_ppxbonus
{
	int		infile;
	int		outfile;
	int		heredoc;
	char	*path;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		cmd_nbs;
	int		pipe_nbs;
	int		*end;
	int		index;
	pid_t	pid;
}	t_ppxbonus;


int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
int 	args_eval(char *argv, t_ppxbonus *pipex);
void    here_doc(char *argv, t_ppxbonus *pipex);
void	get_infile(char **argv, t_ppxbonus *pipex);
void	get_outfile(char *argv, t_ppxbonus *pipex);
void	free_pipe(t_ppxbonus *pipex);
void	free_child(t_ppxbonus *pipex);
void	free_parent(t_ppxbonus *pipex);
void    child(t_ppxbonus pipex, char **argv, char **envp);
char	*get_path(char **envp);
void	leaks(void);
void	error_exit(char *err);
void	close_ends(t_ppxbonus *pipex);

#endif