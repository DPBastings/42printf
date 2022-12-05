/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   carriage.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 14:01:57 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/28 15:23:31 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
/* The contents of this header are as follows:
 * > The carriage struct, with its members:
 *   > (*print): The function which will be used for all printing in the current
 *   invocation. As it stands, there is only one function available (which
 *   prints to a file descriptor); functions to print to strings, newly
 *   allocated string and file streams are set to be added in the future.
 *   > printed: The number of characters printed by the carriage (i.e. the
 *   return value).
 *   > paper: The destination to which (*print) writes (i.e a file descriptor,
 *   but may also be a memory address in the future).
 * > The (*t_printer) type: all printing functions will conform to this type.*/

#ifndef CARRIAGE_H
# define CARRIAGE_H

# include "token.h"
# include <stdarg.h>
# include <sys/types.h>

typedef struct s_carriage
{
	void	(*print)(struct s_carriage *, char *, size_t);
	ssize_t	printed;
	long	paper;
}	t_carriage;

typedef void	(*t_printer)(t_carriage *, t_token *, va_list ap);

int		expand_token(t_carriage *carriage, t_token *token, va_list ap);
void	print(t_carriage *self, char *str, size_t len);
void	sprint(t_carriage *self, char *str, size_t len);
void	asprint(t_carriage *self, char *str, size_t len);
void	pad_left(t_carriage *carriage, t_token *token, size_t len);
void	pad_right(t_carriage *carriage, t_token *token, size_t len);
char	*get_prefix(t_token *token, long value);
void	printnum(t_carriage *carriage, t_token *token, char *str, char *prfx);
void	printchr(t_carriage *carriage, t_token *token, va_list ap);
void	printdec(t_carriage *carriage, t_token *token, va_list ap);
void	printhex(t_carriage *carriage, t_token *token, va_list ap);
void	printlit(t_carriage *carriage, t_token *token, va_list ap);
void	printpercent(t_carriage *carriage, t_token *token, va_list ap);
void	printptr(t_carriage *carriage, t_token *token, va_list ap);
void	printstr(t_carriage *carriage, t_token *token, va_list ap);
void	printstrconst(t_carriage *carriage, t_token *token, char *str);
void	printuns(t_carriage *carriage, t_token *token, va_list ap);

#endif
