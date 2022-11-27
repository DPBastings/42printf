#include "token.h"

int	has_flag(t_token *token, int flag)
{
	return (token->flags & flag);
}

void	set_flag(t_token *token, int flag)
{
	token->flags |= flag;
}

void	unset_flag(t_token *token, int flag)
{
	token->flags &= ~flag;
}

int	is_int_conversion(t_token *token)
{
	return (token->specifier == SPEC_DEC
			|| token->specifier == SPEC_INT
			|| token->specifier == SPEC_UNS
			|| token->specifier == SPEC_HEXLOW
			|| token->specifier == SPEC_HEXUPP);
}
