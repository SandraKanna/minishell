/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:03:55 by skanna            #+#    #+#             */
/*   Updated: 2024/05/15 20:58:28 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <signal.h>
# include <errno.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <curses.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "structures.h"
# include "../libft/Includes/libft_extended.h"

# define SIGNAL

//src
t_minishell		*init_minishell(char **envp);
t_lst_env		*env_fill_structure(char **envp, t_minishell *minishell);
char			*get_env_value(t_lst_env *env, char *name);
void			tokenize_input(char *input, t_minishell *minishell);

//utils
void			ft_error(char *msg, t_minishell *minishell);
char			**ft_split_1st_token(char const *s, char c);
char			**pars_path(t_minishell *minishell);
void			clean_token(t_minishell *minishell);
void			clean_minishell(t_minishell *minishell);
t_lst_env		*ft_new_node(char *name, char *value);
t_lst_env		*ft_last(t_lst_env *lst);
void			ft_add_back(t_lst_env **lst, t_lst_env *new);

//exec
void			execution(t_minishell *minishell);
void			execute_special_command(t_minishell *minishell, char *command);

//builtin fucntions
void			export_command(t_minishell *minishell);
void			env_command(t_minishell *minishell);
void			exit_cmd(t_minishell *minishell, char *input);

#endif