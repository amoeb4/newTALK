/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binarizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:24:50 by dafranco          #+#    #+#             */
/*   Updated: 2023/01/13 18:40:40 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

int	ft_binarizer_len(int argc, char **argv)
{
	int		len;
	int		j;

	len = 1;
	j = argc - 1;
	while (j >= 2)
	{
		len += ft_strlen(argv[j]);
		j--;
	}
	return (len);
}

char	*ft_binarizer_msg(int argc, char **argv)
{
	char	*str;
	char	*msg;
	int		j;
	int		len;

	j = 0;
	len = ft_binarizer_len(argc, argv);
	str = ft_calloc((len + 2) + (len * 8), sizeof(char));
	while (j < len)
	{
		str[j] = '0';
		j++;
	}
	str[j] = '1';
	len = 2;
	while (len < argc - 1)
	{
		msg = ft_strjoin(msg, ft_atobi(argv[len]));
		len++;
	}
	str = ft_strjoin(str, msg);
	free(msg);
	return (str);
}
