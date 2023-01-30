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
	static int			k = 0;

	if (k == 0)
		str = calloc(9, sizeof(char));
	if (k < 8)
	{
		str[k] = c;
		k++;
	}
	if (k == 8)
	{
		ft_bitoa(str);
		free(str);
		k = 0;
	}	
	return (NULL);
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_handler = sig_handler;
	printf("%d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR2, &sig, NULL);
		sigaction(SIGUSR1, &sig, NULL);
	}
	return (0);
}
