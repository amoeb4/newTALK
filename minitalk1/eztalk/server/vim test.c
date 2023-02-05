#include <signal.h>
#include <strings.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int u = 0;
	int i = 0;
	char	*str = "0011011110101010101010101010101010101010100000000k";
	while (str[i])
	{
		if (str[i] == '0')
		{
			if (kill(atoi(argv[1]), SIGUSR1) == -1)
				if (kill(atoi(argv[1]), SIGUSR1) == -1)
				{
					printf("%d", u);
					return (0);
				}
		}
		else if (str[i] == '1')
		{
			if (kill(atoi(argv[1]), SIGUSR2) == -1)
				if (kill(atoi(argv[1]), SIGUSR2) == -1)
				{
					printf("%d", u);
					return (0);
				}
		}
		i++;
		u++;
		if (str[i] == 'k')
		{
			i = 0;
		}
		usleep(1000);
	}
	return (0);
}
