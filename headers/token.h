/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/07 16:11:11 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/14 17:07:33 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* This header contains the following:
 * > Flags: a constant string containing all glyphs used as conversion flags. For every flag, an integer value (corresponding to a single bit) is assigned as well (so that multiple flags can be combined in a single byte).
 *
 * > Specifiers: a constant string containing all glyphs used as conversion specifiers, as well as the subset of 'integer' specifiers. This is supplemented by an enumeration of constants denoting these same specifiers (which is mainly used in pairing printing functions to specifiers.
 *
 * > The t_token struct, to hold all information conveyed by the conversion format (it is returned by the parser).
 */

#ifndef TOKEN_H
# define TOKEN_H

# include <sys/types.h>

# define FLAGS 				"#0- +"
# define FLAG_ALTERNATIVE	(1 << 0)
# define FLAG_ZEROPADDING	(1 << 1)
# define FLAG_LEFTALIGN		(1 << 2)
# define FLAG_SPACE			(1 << 3)
# define FLAG_SIGNED		(1 << 4)

# define SPECIFIERS 		"diuxXcsp%"
# define SPECIFIERS_INT 	"diuxX"

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
	SPEC_PERCENT
}	t_specifiers;

typedef struct s_token
{
	unsigned char	flags;
	size_t			field_width;
	ssize_t			precision;
	unsigned char	specifier;
}	t_token;

t_token	*ignore_flags(t_token *token);
t_token	*parser(char const **format);
t_token	*parse_conversion(char const **format);
t_token	*parse_literal(char const **format);

#endif
