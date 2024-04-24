/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:28:44 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/04/23 18:59:41 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		*p++ = 0;
		n--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (!count || !size)
	{
		tmp = malloc(1);
		ft_bzero(tmp, 1);
		return (tmp);
	}
	if (count > 0 && SIZE_MAX / count < size)
		return (NULL);
	tmp = malloc(count * size);
	if (tmp == NULL)
		return (tmp);
	ft_bzero(tmp, size * count);
	return (tmp);
}

int	ft_isspace(int c)
{
	return (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if ((unsigned long)res * 10 + (*str - 48)
			> 9223372036854775807 && sign == 1)
			return (-1);
		else if ((unsigned long)res * 10 + (*str - 48)
			> (unsigned long)9223372036854775807 + 1 && sign == -1)
			return (0);
		res = res * 10 + (*str - 48);
		str++;
	}
	return (res * sign);
}

