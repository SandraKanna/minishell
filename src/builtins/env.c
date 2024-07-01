/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <derjavec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:03:22 by skanna            #+#    #+#             */
/*   Updated: 2024/07/01 15:22:47 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


// static int	path_exits(t_lst_env *env)
// {
// 	while (env)
// 	{
// 		if (ft_strlen(env->name) == 4 && ft_strncmp(env->name, "PATH", 4) == 0)
// 			return (1);
// 		env = env->next;
// 	}
// 	return (0);
// }

void	env_command(t_mini *minishell)
{
	t_lst_env	*temp;

	temp = minishell->env;
	// if (!path_exits(temp))
	// {
	// 	ft_putstr_fd("env: command not found\n", 2);
	// 	error_cleanup(minishell);
	// 	minishell->exit_status = 127;
	// 	return ;
	// }
	while (temp)
	{
		printf("%s=%s\n", temp->name, temp->value);
		temp = temp->next;
	}
}
