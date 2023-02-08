/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:08:07 by dafranco          #+#    #+#             */
/*   Updated: 2023/01/30 21:04:06 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"

static int	g_pid_client = 0;

void	sig_handler(int signum)
{
	if (g_pid_client > 0)
	{
		if (signum == SIGUSR1)
			stock_bin('0');
		else if (signum == SIGUSR2)
			stock_bin('1');
		return ;
	}
	else
	{
		if (signum == SIGUSR1)
			stock_pid('0');
		else if (signum == SIGUSR2)
			stock_pid('1');
		printf("%d", g_pid_client);
	}
}

void	stock_pid(char c)
{
	char 				*str1;
	static int			i = 0;
	int				num;

	printf("%d", g_pid_client);
	if (i == 0)
	{
		if (c == '1')
		{
			g_pid_client *= -1;
			return ;
		}
		str1 = NULL;
		str1 = calloc(9, sizeof(char));
	}
	if (i < 8)
	{
		str1[i] = c;
		i++;
	}
	if (i == 8)
	{
		num = (int)ft_bitoa(str1) - 48;
		g_pid_client = (g_pid_client * 10) - num;
		free(str1);
		i = 0;
	}
}

char	*stock_bin(char c)
{
	char 				*str;
	static int			i = 0;
	static int			d = 0;
	char				*newstr;
	char				word;

	if (i == 0)
	{
		str = NULL;
		str = calloc(9, sizeof(char));
	}
	if (i < 8)
	{
		str[i] = c;
		i++;
	}
	if (i == 8)
	{
		word = ft_bitoa(str);
		free(str);
		if (d == 0)
			newstr = NULL;
		if (word == '\0')
		{
			newstr = stock_char(newstr, word, 1);
			kill(g_pid_client, SIGUSR2);
			g_pid_client = 0;
			i = 0;
			d = 0;
			return(NULL);
		}
		newstr = stock_char(newstr, word, 0);
		i = 0;
		d++;
	}
	return (NULL);
}

int	main(void)
{
	struct sigaction	sig1;
//	char	*str = "0011011110101010101010101010101010101010100000000k";
//	int i = 0;

	sig1.sa_handler = sig_handler;
	sig1.sa_flags = SA_SIGINFO;
	sigemptyset(&sig1.sa_mask);
	printf("%d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sig1, NULL);
		sigaction(SIGUSR2, &sig1, NULL);
	}

/*		while (str[i])
		{
			if (str[i] == '0')
			{
				kill(getpid(), SIGUSR1);
			}
			else if (str[i] == '1')
			{
				kill(getpid(), SIGUSR2);
			}
			i++;
			if (str[i] == 'k')
			{
				i = 0;
			}
		}
*/	return (0);
}
