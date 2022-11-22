/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printdec.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/08 16:12:09 by dbasting      #+#    #+#                 */
/*   Updated: 2022/11/21 14:51:15 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "carriage.h"
#include "misc.h"
#include "../libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

/*static void print_precision(t_carriage *carriage, size_t len)
{
	while (len--)
		print(carriage, "0", 1);
}*/

void	printnum(t_carriage *carriage, t_token *token, char *string, char *prefix)
{
	size_t	string_len;
	size_t	prefix_len;
	
	string_len = ft_strlen(string);
	prefix_len = ft_strlen(prefix);
	if (HAS_FLAG(token, FLAG_ZEROPADDING))
		print(carriage, prefix, prefix_len);
	pad_left(carriage, token, prefix_len + string_len);
	if (!(HAS_FLAG(token, FLAG_ZEROPADDING)))
		print(carriage, prefix, prefix_len);
	print(carriage, string, string_len);	
	pad_right(carriage, token, prefix_len + string_len);
	free(prefix);
	free(string);
}

void	printdec(t_carriage *carriage, t_token *token, va_list ap)
{
	int		number;
	char	*string;
	char	*prefix;

	number = va_arg(ap, int);
	prefix = get_prefix(token, number);
	if (prefix == NULL)
		return ;
	if (number < 0)
		number *= -1;
	string = misc_itostr((unsigned long) number, token, "0123456789");
	if (string == NULL)
		return (free(prefix));
	printnum(carriage, token, string, prefix);
}

void	printuns(t_carriage *carriage, t_token *token, va_list ap)
{
	unsigned int	number;
	char			*string;
	char			*prefix;
	
	number = va_arg(ap, unsigned int);
	prefix = get_prefix(token, number);
	if (prefix == NULL)
		return ;
	string = misc_itostr((unsigned long) number, token, "0123456789");
	if (string == NULL)
		return (free(prefix));
	printnum(carriage, token, string, prefix);
}
