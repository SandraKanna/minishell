/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_special_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deniseerjavec <deniseerjavec@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:03:22 by skanna            #+#    #+#             */
/*   Updated: 2024/05/21 10:30:11 by deniseerjav      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_special_command(t_minishell *minishell, char *command)
{
	if (ft_strncmp(command, "export", 6) == 0)
		export_command(minishell);
	else if (ft_strncmp(command, "env", 3) == 0)
		env_command(minishell);
	else if (ft_strncmp(command, "echo", 4) == 0)
		echo_command(minishell);
	else
		printf("special command not yet coded\n");
}