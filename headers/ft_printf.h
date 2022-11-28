/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 13:23:18 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/28 15:15:49 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

int	ft_printf(char const *format, ...);
int	ft_dprintf(int fd, char const *format, ...);
int	ft_vprintf(char const *format, va_list ap);
int	ft_vdprintf(int fd, char const *format, va_list ap);

#endif
