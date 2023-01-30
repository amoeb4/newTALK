/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:08:07 by dafranco          #+#    #+#             */
/*   Updated: 2023/01/11 11:58:41 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "minitalk.h"

int	stock_length(int i, int k)
{
	static int	len = 0;

	if (k == 1)
	{
		len = 0;
		return (len);
	}
	if (i == 0)
		return (len);
	if (i == 1)
		len--;
	if (i == 2)
	{
		len *= -1;
		return (len);
	}
	return (len);
}

void	sig_handler_len(int signum)
{
	if (signum == SIGUSR1)
		stock_lenght(1, 0);
	if (signum == SIGUSR2)
		stock_lenght(2, 0);
	return ;
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR1)
		stock_bin('0');
	if (signum == SIGUSR2)
		stock_bin('1');
	return ;
}

char	*stock_bin(char c)
{
	char 				*str;
	char				*msg;
	static int			i = -1;
	static int			flag = 0;
	int					len;

	len = stock_lenght(0, 0);
	if (i == 0 && len > 0)
		str = calloc(8 * len, sizeof(char));
	if (i < 8 && len > 0)
	{
		str[i] = c;
		i++;
	}
	if (i == 8 && len > 0)
	{
		if (flag == 0)
			msg = calloc(len + 1, sizeof(char));
		msg[i] = ft_bitoa(str);
		free(str);
		flag++;
		i = 0;
		if (flag == len)
			printf("%s", msg);
	}	
	return (NULL);
}

int	main(void)
{
	struct sigaction	sig;
	int					k;

	sig.sa_handler = sig_handler_len;
	sigaction(SIGUSR2, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);
	printf("%d\n", getpid());
	while (1)
	{
		k = stock_length(0, 0);
		if (k > 0)
			break;
	}
	sig.sa_handler = sig_handler;
	while (1)
	{
		sigaction(SIGUSR2, &sig, NULL);
		sigaction(SIGUSR1, &sig, NULL);
	}
	return (0);
}
