/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:03:16 by skanna            #+#    #+#             */
/*   Updated: 2024/07/01 15:35:06 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**no_env(t_mini *mini)
{
	char	**envp;
	char	cwd[1024];

	envp = malloc(4 * sizeof(char *));
	if (envp == NULL)
		return (ft_error(mini, NULL, strerror(errno)), NULL);
	if (getcwd(cwd, 1024) == NULL)
		return (ft_error(mini, NULL, strerror(errno)), NULL);
	envp[0] = ft_strjoin("PWD=", cwd);
	if (!envp[0])
		return (free_tab(envp), ft_error(mini, NULL, strerror(errno)), NULL);
	envp[1] = ft_strdup("SHLVL=1");
	if (!envp[1])
		return (free_tab(envp), ft_error(mini, NULL, strerror(errno)), NULL);
	envp[2] = ft_strdup("PATH=/usr/bin/");
	if (!envp[2])
		return (free_tab(envp), ft_error(mini, NULL, strerror(errno)), NULL);
	envp[3] = NULL;
	return (envp);
}

static t_mini	*init_minishell(char **envp)
{
	t_mini	*mini;

	mini = malloc(sizeof(t_mini));
	if (mini == NULL)
	{
		ft_error(mini, NULL, strerror(errno));
		exit(1);
	}
	ft_bzero(mini, sizeof(t_mini));
	if (envp[0] == NULL)
		envp = no_env(mini);
	mini->env = fill_env_struct(envp, mini);
	return (mini);
}

void	parse_and_execute(t_mini *mini, char *input)
{
	lexer(input, mini);
	parser(mini);
	if (!mini->error)
	{
		execution(mini);
		if (mini->error)
			mini->exit_status = 1;
	}
}

static void	minishell(t_mini *mini)
{
	char	*input;

	while (!mini->should_exit)
	{
		mini->error = 0;
		input = readline("minishell$ ");
		if (!input)
			break ;
		if (*input)
		{
			add_history(input);
			parse_and_execute(mini, input);
		}
		clean_token_list(&(mini->token));
		clean_fd(mini);
		mini->token = NULL;
		free(input);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	*mini;
	int		final_status;

	if (argc != 1 || argv[1])
		return (0);
	mini = init_minishell(envp);
	minishell(mini);
	final_status = mini->exit_status;
	clean_minishell(mini);
	return (final_status);
}

//valgrind --suppressions=s.supp --track-origins=yes --show-leak-kinds=all --track-fds=yes ./minishell 
