/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:05:30 by dafranco          #+#    #+#             */
/*   Updated: 2023/01/30 21:01:33 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return(i);
}

char	*stock_char(char *str, char c, int d)
{
	char	*newstr;
	int		len;
	int		i;

	i = 0;
	newstr = NULL;
	if (str != NULL)
	{
		len = ft_strlen(str);
		newstr = calloc(len + 1, sizeof(char));
		while (str[i])
		{
			newstr[i] = str[i];
			i++;
		}
	}
	else
		newstr = calloc(2, sizeof(char));
	newstr[i] = c;
	free (str);
	if (i == 1)
		printf("%s", newstr);
	return (newstr);
}
