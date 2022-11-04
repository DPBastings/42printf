/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dbasting <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 15:19:59 by dbasting      #+#    #+#                 */
/*   Updated: 2022/10/24 13:28:39 by dbasting      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

static int	setminus(int n, char *array)
{
	if (n < 0)
	{
		array[0] = '-';
		return (-n);
	}
	return (n);
}

static size_t	digitcount(int n)
{
	size_t	digits;

	digits = 1;
	if (n < 0)
	{
		n = -n;
		digits++;
	}
	while (n > 9)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	size_t	index;
	char	*string;

	if (n == INT_MIN)
		string = ft_strdup("-2147483648");
	else if (n == 0)
		string = ft_strdup("0");
	else
	{
		index = digitcount(n);
		string = malloc((index + 1) * sizeof(char));
		if (string)
		{
			string[index--] = '\0';
			n = setminus(n, string);
			while (n)
			{
				string[index--] = '0' + n % 10;
				n /= 10;
			}
		}
	}
	return (string);
}
