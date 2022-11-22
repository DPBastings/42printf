/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   carriage.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:01:57 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 14:21:53 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARRIAGE_H
# define CARRIAGE_H

# include "token.h"
# include <stdarg.h>
# include <sys/types.h>

typedef struct s_carriage
{
	void (	*write)(struct s_carriage *, t_token *, void *);
	ssize_t	written;
	int		paper;
}	t_carriage;

typedef void (*t_printer)(t_carriage *, t_token *, va_list ap);

void	expand_token(t_carriage *carriage, t_token *token, va_list ap);
void	print(t_carriage *self, char *str, size_t len);
void	pad_left(t_carriage *carriage, t_token *token, size_t len);
void	pad_right(t_carriage *carriage, t_token *token, size_t len);
char	*get_prefix(t_token *token, long value);
void	printnum(t_carriage *carriage, t_token *token, char *buffer, char *prefix);
void	printchr(t_carriage *carriage, t_token *token, va_list ap);
void	printdec(t_carriage *carriage, t_token *token, va_list ap);
void	printhex(t_carriage *carriage, t_token *token, va_list ap);
void	printlit(t_carriage *carriage, t_token *token, va_list ap);
void	printpercent(t_carriage *carriage, t_token *token, va_list ap);
void	printptr(t_carriage *carriage, t_token *token, va_list ap);
void	printstr(t_carriage *carriage, t_token *token, va_list ap);
void	printuns(t_carriage *carriage, t_token *token, va_list ap);

#endif
