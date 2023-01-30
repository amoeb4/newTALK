#include <signal.h>

int ft_isdigit(char c)
{
	if(c >= 48 && c <= 57)
		return(c);
	return(0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	int				nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	if (!str[i])
		return (0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
		sign = -1;
	while (ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

int main(int argc, char **argv)
{
	kill(ft_atoi(argv[1]), SIGUSR1);
	kill(ft_atoi(argv[1]), SIGUSR1);
	kill(ft_atoi(argv[1]), SIGUSR1);
	kill(ft_atoi(argv[1]), SIGUSR2);
	return(0);
}
