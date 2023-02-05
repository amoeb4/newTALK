/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interpreter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:21:59 by dafranco          #+#    #+#             */
/*   Updated: 2023/01/11 11:51:52 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

size_t	stock_length(size_t i)
{
	size_t	len;

	len = 0;
	if (sig_handler(SIGUSR1))
		len++;
	if (sig_handler(SIGUSR2) || i == 0)
		return (len);
}

void	sig_handler(int signum)
{
	if (SIGUSR1)
		stock_length(1);
	if (SIGUSR2)
		stock_length(0);
}

char	*ft_interpreter(int signum)
{
	char	*str;
	int		sigcount;

	sigcount = 0;
	if (SIGUSR1 || SIGUSR2)
		sigcount++;
	str = malloc(sizeof(sigcount) + 1);
	*str = '\0';
	return (str);
}

//char	*stock_msg(int signum, size_t len)
//{
//	static char	*message;
//	struct
//	message = calloc(len + 1, 1);
//}

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
