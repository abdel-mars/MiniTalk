/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:38:33 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/05/04 06:50:53 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_message(int pid, const char *s)
{
	size_t	len;
	size_t	i;
	int		j;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		j = 7;
		while (j >= 0)
		{
			if ((s[i] >> j) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep (200);
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("𝙐𝙨𝙖𝙜𝙚: %s <𝙨𝙚𝙧𝙫𝙚𝙧_𝙥𝙞𝙙> <𝙢𝙚𝙨𝙨𝙖𝙜𝙚>\n", argv[0]);
		return (0);
	}
	pid = atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("𝙄𝙣𝙫𝙖𝙡𝙞𝙙 𝙋𝙄𝘿\n");
		return (0);
	}
	ft_message(pid, argv[2]);
	ft_printf("Message sent successfully \n");
	return (0);
}
