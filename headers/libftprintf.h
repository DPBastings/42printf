/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 13:23:18 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/04 15:06:33 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define SPECIFIERS "cspdiuxX%"
# define FLAGS "-0.# +"
# include <stdarg.h>

int	ft_dprintf(int fd, const char *format, ...);
int	ft_printf(const char *format, ...);

#endif
