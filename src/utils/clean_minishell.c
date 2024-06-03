/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <derjavec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:24:31 by derjavec          #+#    #+#             */
/*   Updated: 2024/06/03 14:17:43 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_env(t_minishell *minishell)
{
	t_lst_env	*current;
	t_lst_env	*next;

	current = minishell->env;
	while (current)
	{
		next = current->next;
		free(current->name);
		free(current->value);
		current->name = NULL;
		current->value = NULL;
		free(current);
		current = next;
	}
	minishell->env = NULL;
}

void	clean_subtokens(t_token *sub_token)
{
	t_token	*temp;

	while (sub_token)
	{
		temp = sub_token;
		sub_token = sub_token->next;
		if (temp->value)
		{
			free(temp->value);
			temp->value = NULL;
		}	
		free(temp);
	}
}

void	clean_token_list(t_token *token)
{
	t_token	*temp;

	if (token == NULL)
		return ;
	while (token)
	{
		temp = token->next;
		if (token->value)
		{
			free(token->value);
			token->value = NULL;
		}	
		if (token->sub_token)
		{
			clean_subtokens(token->sub_token);
			token->sub_token = NULL;
		}	
		free(token);
		token = temp;
	}
}

void	clean_minishell(t_minishell *minishell)
{
	if (minishell->env)
		clean_env(minishell);
	if (minishell->token)
		clean_token_list(minishell->token);
	if (minishell->output_file)
		free(minishell->output_file);
	if (minishell->input_file)
		free(minishell->input_file);
	free(minishell);
}
