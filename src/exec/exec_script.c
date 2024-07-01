/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_script.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:03:22 by skanna            #+#    #+#             */
/*   Updated: 2024/07/01 16:59:58 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_shebang(t_mini *mini, int script)
{
	char    *line;
	char    *shebang;

	shebang = NULL;
	while (1)
	{
		line = get_next_line(script);
		if (!line)
			break ;
		else if (ft_strncmp(line, "#!", 2) == 0)
		{
			shebang = ft_strdup(line + 2);
			if (!shebang)
				return (ft_error(mini, NULL, strerror(errno)), NULL);
			shebang[ft_strlen(shebang) - 1] = '\0';
			break ;
		}
		else if (strncmp(line, "#", 1) != 0)
		{
			shebang = ft_strdup("/bin/sh");
			if (!shebang)
				return (ft_error(mini, NULL, strerror(errno)), NULL);
		}
		free(line);
	}
	return (shebang);
}

static char	*get_script_name(t_token *tmp)
{
	char	*name;

	name = NULL;
	if (ft_strncmp(tmp->cmd_tab[0], "./", 2) == 0)
		name = tmp->cmd_tab[0] + 2;
	else if (ft_strncmp(tmp->cmd_tab[0], "sh", ft_strlen(tmp->cmd_tab[0])) == 0
		|| ft_strncmp(tmp->cmd_tab[0], "bash", ft_strlen(tmp->cmd_tab[0])) == 0)
		name = tmp->cmd_tab[1];
	return (name);
}

static void	init_args(char **args)
{
	static char	empty[] = "";

	args[0] = empty;
	args[1] = empty;
	args[2] = empty;
}

int	exec_script(t_mini *mini, t_token *tmp)
{
	int		script;
	char	*name;
	char	*args[3];

	name = get_script_name(tmp);
	init_args(args);
	if (name)
	{
		script = open(name, O_RDONLY);
		if (script == -1)
		{
        printf("Debug: Attempted to open '%s', result = %d, errno = %d (%s)\n", name, script, errno, strerror(errno));			
			if (errno == EISDIR)
				return (ft_error(mini, " Is a directory", NULL), 1);
			else
				return (ft_error(mini, NULL, strerror(errno)), 1);
		}
		if (ft_strncmp(name + ft_strlen(name) - 3, ".sh", 3) == 0)
			args[0] = get_shebang(mini, script);
		close(script);
		if (!args[0])
			return (1);
		args[1] = name;
		args[2] = NULL;
		if (execve(args[0], args, mini->env_char) == -1)
		{
			printf("Debug: execve failed, errno = %d (%s)\n", errno, strerror(errno));
			if (errno == EISDIR)
				ft_error(mini, " Is a directory", NULL);
			else
				ft_error(mini, NULL, strerror(errno));
			return (close(script), 1);
		}
	}
	return (0);
}
