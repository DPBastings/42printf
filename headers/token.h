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

# define HAS_FLAG(token, flag)		token->flags & flag ? 1 : 0
# define SET_FLAG(token, flag)		token->flags |= flag
# define UNSET_FLAG(token, flag)	token->flags &= ~flag

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

# define SPEC_IS_SIGNED(token)		(token->specifier == SPEC_DEC\
										|| token->specifier == SPEC_INT)
# define SPEC_IS_HEX(token)			(token->specifier == SPEC_HEXLOW\
										|| token->specifier == SPEC_HEXUPP)
# define SPEC_IS_UNSIGNED(token)	(token->specifier == SPEC_UNS\
										|| SPEC_IS_HEX(token))	
# define SPEC_IS_INTEGER(token)		(SPEC_IS_SIGNED(token) || SPEC_IS_UNSIGNED(token))

typedef struct s_token
{
	unsigned char	flags;
	unsigned int	field_width;
	int				precision;
	unsigned char	specifier;
}	t_token;

t_token	*ignore_flags(t_token *token);
t_token	*parser(char const **format);
t_token	*parse_conversion(char const **format);
t_token	*parse_literal(char const **format);

#endif
