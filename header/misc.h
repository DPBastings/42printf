/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   misc.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 11:44:16 by dbasting      #+#    #+#                 */
/*   Updated: 2023/01/16 15:32:19 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISC_H
# define MISC_H

# include "token.h"
# include <stddef.h>

int		misc_atoi(char const **str);
void	*misc_calloc(size_t n, size_t size);
int		misc_isdigit(int c);
char	*misc_itostr(unsigned long number, t_token *token, char const *digits);
void	*misc_memset(void *b, int c, size_t len);
size_t	misc_strlcat(char *dst, char const *src, size_t size);
char	*misc_strchr(char const *str, int c);
char	*misc_strdup(char const *str);
size_t	misc_strlen(char const *str);

#endif
