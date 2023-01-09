/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printtoken.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 16:20:46 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/09 17:07:38 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printtoken.h"
#include "../header/token.h"
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
		printf(">     width: %u\n", token->field_width);
		printf("> precision: %d\n", token->precision);
		printf("> specifier: %d\n", token->specifier);
	}
	else
		printf(">   literal: '%c'\n", token->flags);
}
