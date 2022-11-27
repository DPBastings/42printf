/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 16:11:11 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 17:27:11 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* This header contains the following:
 * > Flags: a constant string containing all glyphs used as conversion flags.
 * For every flag, an integer value (corresponding to a single bit) is assigned
 * as well (so that multiple flags can be combined in a single byte).
 *
 * > Specifiers: a constant string containing all glyphs used as conversion
 * specifiers. This is supplemented by an enumeration of constants denoting
 * these same specifiers (which is mainly used in pairing printing functions
 * to specifiers.
 *
 * > The t_token struct, to hold all information conveyed by the conversion
 * format (it is returned by the parser).
 */

#ifndef TOKEN_H
# define TOKEN_H

# include <sys/types.h>

# define FLAGS 				"#0- +"
# define FLAG_ALTERNATIVE	1
# define FLAG_ZEROPADDING	2
# define FLAG_LEFTALIGN		4
# define FLAG_SPACE			8
# define FLAG_SIGNED		16

# define SPECIFIERS 		"diuxXcsp%"

typedef enum e_specifiers
{
	SPEC_LIT,
	SPEC_DEC,
	SPEC_INT,
	SPEC_UNS,
	SPEC_HEXLOW,
	SPEC_HEXUPP,
	SPEC_CHR,
	SPEC_STR,
	SPEC_PTR,
	SPEC_PERCENT
}	t_specifiers;

typedef struct s_token
{
	unsigned char	flags;
	unsigned int	field_width;
	int				precision;
	unsigned char	specifier;
}	t_token;

int		has_flag(t_token *token, int flag);
t_token	*ignore_flags(t_token *token);
int		is_int_conversion(t_token *token);
t_token	*parser(char const **format);
t_token	*parse_conversion(char const **format);
t_token	*parse_literal(char const **format);
void	set_flag(t_token *token, int flag);
void	unset_flag(t_token *token, int flag);

#endif
