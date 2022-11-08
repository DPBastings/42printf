/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 16:11:11 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/08 13:57:36 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define FLAGS "#0- +"
# define FLAG_ALTERNATIVE 01
# define FLAG_ZEROPADDING 02
# define FLAG_LEFTALIGN 04
# define FLAG_SPACE 010
# define FLAG_SIGNED 020

# define SPECIFIERS "diuxXcsp%"
# define SPEC_DEC 'd'
# define SPEC_INT 'i'
# define SPEC_UNS 'u'
# define SPEC_HEXLOW 'x'
# define SPEC_HEXUPP 'X'
# define SPEC_CHR 'c'
# define SPEC_STR 's'
# define SPEC_PTR 'p'
# define SPEC_PERCENT '%'

#include "../libft/libft.h"

typedef struct s_converter
{
	char	flags;
	int		field_width;
	int		precision;
	char	specifier;
}	t_converter;

t_converter	*get_converter(char const **format);
t_list		*parser(char const *format);

#endif
