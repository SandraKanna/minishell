/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:03:16 by skanna            #+#    #+#             */
/*   Updated: 2024/06/04 12:57:16 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst_env	*ft_lstnew_env(char *name, char *value)
{
	t_lst_env	*new;

	new = malloc(sizeof(t_lst_env));
	if (!new)
		return (NULL);
	new->name = ft_strdup(name);
	if (new->name == NULL)
		return (NULL);
	new->value = ft_strdup(value);
	if (new->value == NULL)
		return (NULL);
	new->next = NULL;
	return (new);
}

t_lst_env	*ft_lstlast_env(t_lst_env *lst)
{
	t_lst_env	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

void	ft_lstadd_back_env(t_lst_env **lst, t_lst_env *new)
{
	t_lst_env	*current;

	if (lst && new)
	{
		current = *lst;
		if (current == NULL)
		{
			*lst = new;
			return ;
		}
		while (current ->next != NULL)
		{
			current = current ->next;
		}
		current ->next = new;
	}
	return ;
}

t_lst_env	*fill_env_struct(char **envp, t_minishell *minishell)
{
	char		**split_envp;
	t_lst_env	*lst_env;
	t_lst_env	*new_node;
	int			i;

	lst_env = NULL;
	i = 0;
	while (envp[i])
	{
		split_envp = split_env_vars(envp[i], '=');
		if (split_envp == NULL)
			ft_error("Malloc error in split", minishell);
		new_node = ft_lstnew_env(split_envp[0], split_envp[1]);
		if (new_node == NULL)
			ft_error("Malloc error in new_node", minishell);
		ft_lstadd_back_env(&lst_env, new_node);
		free_tab(split_envp);
		i++;
	}
	return (lst_env);
}