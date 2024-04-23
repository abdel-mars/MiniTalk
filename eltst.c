#include <unistd.h>
#include <signal.h>
#include <stdio.h>



static void sig_usr(int sig) {
    if (sig == SIGUSR1) {
        printf("from SIGUSR1 hello mars\n");
    } else if (sig == SIGUSR2) {
        printf("from SIGUSR2 hello ssam\n");
    } else {
        printf("Received Signal %d\n", sig);
    }
}

int main(void) {
    printf("%d\n", getpid());
    if (signal(SIGUSR1, sig_usr) == SIG_ERR) {
        printf("Can't catch SIGUSR1\n");
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR) {
        printf("Can't catch SIGUSR2\n");
    }
    while (1);

    {
        pause();
    }
}

//..............................................................

/*#include "minitalk.h"

char	*ft_str_to_bit(char *str, size_t i)
{
	char	*binary;
	int		c;
	int		bytes;
    size_t  j;

	i = ft_strlen(str);
	binary = ft_calloc(i * 8 + 1, sizeof(char));
	if (binary == NULL)
		return (NULL);
        j = 0;
	while (i + 1 != 0)
	{
		c = str[i - 1];
		bytes = 8;
       while (bytes > 0)
		{
			if (c % 2 == 1)
                binary[ft_strlen(str) * 8 - j - 1] = '1';
            else if (c % 2 == 0)
				binary[ft_strlen(str) * 8 - j - 1] = '0';
			c /= 2;
			j++;
			bytes--;
		}
		i--;
	}
	return (binary);
}

void    ft_message(int pid, char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '1')
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i++;
        usleep(80);
            
    }
    
}

int main (int ac, char **av)
{
    int pid;
    char *bits;
    
    if (ac != 3)
    {
        ft_printf("you should put 3 arguments\n");
        return (0);
    }
    pid = ft_atoi(av[1]);
    bits = ft_str_to_bit(av[2], 0);
    // if (!pid)
    //     ft_printf("wrong PID\n");
    // if (!bits)
    // {
    //     ft_printf("something went wrong in allocation\n");
    //     return (0);
    // }
    if (bits == NULL)
    {
        ft_printf("Allocation Problem\n");
        return (0);
        
    }
    ft_message(pid, bits);
        printf("hello\n");

    // free(bits);
}*/



// servaear

/*#include "minitalk.h"

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
}*/