/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: derjavec <derjavec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:03:55 by skanna            #+#    #+#             */
/*   Updated: 2024/05/29 09:24:46 by derjavec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_lst_env
{
	char				*name;
	char				*value;
	struct s_lst_env	*next;
}	t_lst_env;

typedef enum e_subtype
{
	SYMBOL,
	OPEN_S_QUOTES,
	CLOSE_S_QUOTES,
	OPEN_D_QUOTES,
	CLOSE_D_QUOTES,
	TEXT,
	ENV,
	OTHER
}	t_subtype;

typedef struct s_lst_token
{
	t_subtype			sub_type;
	char				*value;
	struct s_lst_token	*next;
	//struct s_lst_token	*prev;
}	t_lst_token;

typedef enum e_type
{
	VAR,
	COMMAND,
	SPECIAL_COMMAND,
	OPS,
	REDIR_IN,
	REDIR_OUT,
	END,
	HEREDOC,
	ARG,
	INIT

}	t_type;

typedef struct s_token
{
	char			*value;
	t_type		type;
	t_lst_token	*sub_token;
	struct s_token	*next;
}	t_token;

typedef struct s_minishell
{
	t_lst_env	*env;
	t_token		*token;
	int			token_count;
	int			last_exit_status;
	int			redirect_in;
	int			redirect_out;
	char		*builtin[6];     //builtin
	char		*input_file;
	char		*output_file;
}	t_minishell;

#endif