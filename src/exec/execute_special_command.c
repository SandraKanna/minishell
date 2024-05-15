/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_special_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skanna <skanna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:03:22 by skanna            #+#    #+#             */
/*   Updated: 2024/05/15 16:21:41 by skanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_special_command(t_minishell *minishell, char *command)
{
	if (ft_strncmp(command, "export", ft_strlen(command)) == 0)
		export_command(minishell);
	else if (ft_strncmp(command, "env", ft_strlen(command)) == 0)
		env_command(minishell);
	else
		printf("special command not yet coded\n");
}