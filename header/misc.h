/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 11:44:16 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/28 15:16:34 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H

# include "token.h"

int		misc_atoi(char const **str);
char	*misc_itostr(unsigned long number, t_token *token, char const *digits);

#endif
