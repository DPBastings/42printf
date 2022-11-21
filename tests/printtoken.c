/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printtoken.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 16:20:46 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 16:24:18 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "headers/token.h"
#include <stdio.h>

void	printtoken(t_token *token)
{
	printf("token at %p:\n", token);
	if (token->specifier)
	{
		printf(">     flags: ");
		if (token->flags & FLAG_ALTERNATIVE)
			printf("# ");
		if (token->flags & FLAG_ZEROPADDING)
			printf("0 ");
		if (token->flags & FLAG_LEFTALIGN)
			printf("- ");
		if (token->flags & FLAG_SPACE)
			printf("space ");
		if (token->flags & FLAG_SIGNED)
			printf("+");
		printf("\n");
		printf(">     width: %zu\n", token->field_width);
		printf("> precision: %zd\n", token->precision);
		printf("> specifier: %d\n", token->specifier);
	}
	else
		printf(">   literal: '%c'\n", token->flags);
}
