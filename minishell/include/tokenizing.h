/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:42:11 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/18 17:58:01 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZING_H
# define TOKENIZING_H

# include "minishell.h"

typedef enum token_type
{
	IDENDTIFIER,
	INPUT_R,
	OUTPUT_R,
	INPUT_DELI,
	OUTPUT_DELI,
	PIPE,
	O_PARENT,
	C_PARENT,
	AND,
	OR,
	NL
}	t_token_type;

typedef struct token
{
	t_token_type	token_t;
	char			*value;
	struct token	*next;
	struct token	*prev;
}	t_token;

#endif