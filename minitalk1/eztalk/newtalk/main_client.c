/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:04:47 by dafranco          #+#    #+#             */
/*   Updated: 2023/01/11 17:45:11 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "minitalk.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (c);
	return (0);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	int		n;

	ptr = NULL;
	if (size >= 2147483424)
		return (ptr);
	n = nmemb * size;
	ptr = (void *)malloc(n);
	if (ptr != NULL)
		ft_bzero(ptr, n);
	else
		return (NULL);
	return (ptr);
}

int	main(int argc, char **argv)
{
	int		i;
	char	*msg;

	i = 0;
	if (argc > 1)
	{
		while (i >= 0)
		{
			usleep(50000);
			kill(ft_atoi(argv[1]), SIGUSR1);
			i--;
			if (i == 0)
				kill(ft_atoi(argv[1]), SIGUSR2);
		}
		while (1)
		{
			usleep(50000);
			return (0);
		}
		free(msg);
	}
	return (0);
}
