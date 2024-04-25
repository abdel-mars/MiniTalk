/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdel-ma <abdel-ma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:38:33 by abdel-ma          #+#    #+#             */
/*   Updated: 2024/04/25 19:00:40 by abdel-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char *ft_str_to_bit(const char *str)
{
    size_t len = strlen(str);
    char *binary = (char *)calloc(len * 8 + 1, sizeof(char));
    if (binary == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    size_t i = 0;
    size_t j = 0;
    while (i < len)
    {
        unsigned char c = str[i];
        int bit = 7;
        while (bit >= 0)
        {
            binary[j++] = ((c >> bit) & 1) ? '1' : '0';
            bit--;
        }
        i++;
    }
    return binary;
}

static void ft_message(int pid, const char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '1')
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i++;
        usleep(80);
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <server_pid> <message>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    if (pid <= 0)
    {
        fprintf(stderr, "Invalid PID\n");
        return 1;
    }

    char *bits = ft_str_to_bit(argv[2]);
    ft_message(pid, bits);

    free(bits);
    return 0;
}
