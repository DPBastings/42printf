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
# include <stddef.h>

void	*ft_calloc(size_t n, size_t size);
int		ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlcat(char *dst, char const *src, size_t size);
char	*ft_strchr(char const *str, int c);
char	*ft_strdup(char const *str);
size_t	ft_strlen(char const *str);
int		misc_atoi(char const **str);
char	*misc_itostr(unsigned long number, t_token *token, char const *digits);

#endif
