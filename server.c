/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:38:28 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/04/23 19:58:33 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_convert(char *s)
{
	unsigned char c;
	size_t	i;
	
	i = 0;
	c = 0;
	while (s[i])
	{
		c = c << 1;
		
		if (s[i] == '1')
		c += 1;
		i++;
	}
	write (1, &c, 1);
}

void	ft_handle(int sig)
{
	static char *bits;
	static int bitcount;

	bits = NULL;
	bitcount = 0;
	if (bits == NULL)
	{
		ft_calloc(bits[bitcount], 9);
	}
	else if (sig == SIGUSR1)
		bits[bitcount++] = '0';
	else if (sig == SIGUSR2)
		bits[bitcount++] = '1';
	else if (bitcount == 8)
	{
		bits[bitcount] = '\0';
		ft_convert(bits);
		// free (bits);
		// bits = NULL;
	}
}

int	main()
{
	ft_printf("PID SERVER IS : %u\n", getpid());
	while(1)
	{
		signal(SIGUSR1, ft_handle);
		signal(SIGUSR2, ft_handle);
		pause();
	}
	return (0);
}