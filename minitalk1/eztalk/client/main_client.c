/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:04:47 by dafranco          #+#    #+#             */
/*   Updated: 2023/01/30 21:13:08 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include "minitalk.h"

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

int	send_pid(char *msg, char *pid_server, char *pid)
{
	int	i;
	int	pid_len;

	i = 0;
	pid_len = ft_strlen(pid) * 8;
	while (i < pid_len)
	{
		if (msg[i] == '0')
		{
			kill(ft_atoi(pid_server), SIGUSR1);
		}
		else if (msg[i] == '1')
		{
			kill(ft_atoi(pid_server), SIGUSR2);
		}
		i++;
		usleep(500);
	}
	kill(ft_atoi(pid_server), SIGUSR2);
	return (pid_len);
}

void	valid(int sig)
{
	if (sig == SIGUSR2)
	{
		printf("\nMessage recu.");
		return ;
	}
	if (sig == SIGUSR1)
		return ;
}

int	main(int argc, char **argv)
{
	int		i;
	char	*msg;
	char	*pid;

	pid = ft_itoa(getpid());
	if (argc <= 1)
		return (0);
	msg = ft_binarizer_msg(argc, argv, pid);
	i = send_pid(msg, argv[1], pid);
	while (msg[i])
	{
		if (msg[i] == '0')
		{
			signal(SIGUSR1, valid);
			if (kill(ft_atoi(argv[1]), SIGUSR1) == -1)
				kill(ft_atoi(argv[1]), SIGUSR1);
		}
		else if (msg[i] == '1')
		{
			signal(SIGUSR1, valid);
			if (kill(ft_atoi(argv[1]), SIGUSR2) == -1)
				kill(ft_atoi(argv[1]), SIGUSR2);
		}
		usleep(2000);
		i++;
	}
	kill(ft_atoi(argv[1]), SIGUSR1);
	usleep(500);
	kill(ft_atoi(argv[1]), SIGUSR1);
	usleep(500);
	kill(ft_atoi(argv[1]), SIGUSR1);
	usleep(500);
	kill(ft_atoi(argv[1]), SIGUSR1);
	usleep(500);
	kill(ft_atoi(argv[1]), SIGUSR1);
	usleep(500);
	kill(ft_atoi(argv[1]), SIGUSR1);
	usleep(500);
	kill(ft_atoi(argv[1]), SIGUSR1);
	usleep(500);
	kill(ft_atoi(argv[1]), SIGUSR1);
	free(msg);
	return (0);
}
