/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 11:44:16 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 13:49:33 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H

# include "token.h"
# include <stddef.h>

int		misc_atoi(char const **str);
char	*misc_itostr(unsigned long number, t_token *token, char const *digits);
size_t	misc_itoa(unsigned long number, char *array, char const *digits);

#endif
