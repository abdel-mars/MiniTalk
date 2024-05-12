/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:38:33 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/05/12 17:49:26 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_message(int pid, char c)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if ((c >> j) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(550);
		j--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("𝙐𝙨𝙖𝙜𝙚: %s <𝙨𝙚𝙧𝙫𝙚𝙧_𝙥𝙞𝙙> <𝙢𝙚𝙨𝙨𝙖𝙜𝙚>\n", argv[0]);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("𝙄𝙣𝙫𝙖𝙡𝙞𝙙 𝙋𝙄𝘿\n");
		return (0);
	}
	i = 0;
	while (argv[2][i])
	{
		ft_message(pid, argv[2][i]);
		usleep(450);
		i++;
	}
	ft_printf("Message sent successfully \n");
	return (0);
}
