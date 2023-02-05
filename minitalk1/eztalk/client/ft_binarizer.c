/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:24:50 by dafranco          #+#    #+#             */
/*   Updated: 2023/01/13 19:37:21 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include <signal.h>
#include <stdio.h>

int	ft_binarizer_len(int argc, char **argv)
{
	int		len;
	int		j;

	len = 0;
	j = argc - 1;
	while (j >= 2)
	{
		len += ft_strlen(argv[j]);
		j--;
	}
	return (len);
}

char	*ft_binarizer_msg(int argc, char **argv, char *pid)
{
	char	*str;
	int		len;
	char	*tmp;

	len = ft_binarizer_len(argc, argv) + ft_strlen(pid);
	str = ft_calloc((len * 8) + 1, sizeof(char));
	len = 1;
	while (len < argc)
	{
		if (len == 1)
			tmp = ft_atobi(pid);
		else
			tmp = ft_atobi(argv[len]);
		str = ft_strjoin(str, tmp);
		len++;
		free(tmp);
	}
	return (str);
}
