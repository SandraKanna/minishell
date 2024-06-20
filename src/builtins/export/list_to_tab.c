/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deniseerjavec <deniseerjavec@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:03:22 by skanna            #+#    #+#             */
/*   Updated: 2024/06/20 11:12:27 by deniseerjav      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*join_env(t_lst_env *env)
{
	char	*name;
	char	*value;
	char	*joint_a;
	char	*joint_b;

	name = ft_strdup(env->name);
	value = ft_strdup(env->value);
	if (name == NULL || value == NULL)
		return (NULL);
	joint_a = ft_strjoin_char(name, '=');
	if (joint_a == NULL)
		return (NULL);
	joint_b = ft_strjoin_free(joint_a, value);
	if (joint_b == NULL)
		return (NULL);
	return (joint_b);
}

char	**list_to_tab(t_mini *mini)
{
	t_lst_env	*tmp;
	char		**env;
	int			i;

	env = malloc((count_elements(mini) + 1) * sizeof(char *));
	if (env == NULL)
		ft_error("Malloc in export cmd", mini);
	i = 0;
	tmp = mini->env;
	while (tmp)
	{
		env[i] = join_env(tmp);
		if (env[i] == NULL)
		{
			free_tab(env);
			ft_error("Malloc in export cmd", mini);
		}
		tmp = tmp->next;
		i++;
	}
	env[i] = NULL;
	mini->mod_env = 1;
	return (env);
}