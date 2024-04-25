/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:38:28 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/04/25 19:02:30 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	convert_to_char(char *s)
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

static void ft_handle(int sig)
{
    static char bits[9] = {0}; // Initialize to zeros
    static int bitcount = 0;

    if (sig == SIGUSR1)
        bits[bitcount++] = '0';
    else if (sig == SIGUSR2)
        bits[bitcount++] = '1';

    if (bitcount == 8)
    {
        convert_to_char(bits);
        bitcount = 0;
    }
}

int main()
{
    printf("PID SERVER IS: %u\n", getpid());

    signal(SIGUSR1, ft_handle);
    signal(SIGUSR2, ft_handle);

    while (1)
    {
        pause();
    }

}
