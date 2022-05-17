/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-der <mvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 10:34:50 by mvan-der      #+#    #+#                 */
/*   Updated: 2022/05/17 16:41:31 by mvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>

static int	ft_minmax(long int nbr)
{
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (-1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	size_t		i;
	int			sign;
	long int	number;

	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	number = 0;
	while (nptr[i] != '\0' && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	if (ft_minmax(number) == -1)
		return (-1);
	return (sign * number);
}
