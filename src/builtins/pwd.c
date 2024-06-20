/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deniseerjavec <deniseerjavec@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:52:20 by skanna            #+#    #+#             */
/*   Updated: 2024/06/20 11:23:54 by deniseerjav      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd_cmd(t_mini *mini)
{
	char	cwd[1024];
	int		size;

	size = 1024;
	if (getcwd(cwd, size) == NULL)
	{
		ft_error("pwd error", mini);
	}
	printf("%s\n", cwd);
}
