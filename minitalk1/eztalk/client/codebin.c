/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codebin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:56:04 by dafranco          #+#    #+#             */
/*   Updated: 2023/01/13 19:30:59 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_doublen(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str1)
	{
		while (str1 && str1[i])
		{
			i++;
		}
	}
	if (str2)
	{
		while (str2 && str2[j])
		{
			j++;
		}
	}
	return (i + j);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		k;
	char	*str;

	str = malloc(sizeof(char) * (ft_doublen(s1, s2) + 1));
	if (!str)
		return (0);
	i = 0;
	k = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	if (s1)
		free(s1);
	while (s2[k])
	{
		str[i + k] = s2[k];
		k++;
	}
	str[k + i] = '\0';
	return (str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_printbin(char c)
{
	char	*str;
	int		nu;
	int		i;
	int		needle;

	needle = 64;
	nu = (int)c;
	str = malloc(sizeof(char) * 9);
	i = 1;
	str[0] = '0';
	while (needle > 0)
	{
		if (nu >= needle)
		{
			str[i] = '1';
			nu -= needle;
		}
		else if (nu < needle || nu == 0)
			str[i] = '0';
		needle /= 2;
		i++;
	}
	str[8] = '\0';
	return (str);
}

char	*ft_atobi(char *str)
{
	int		i;
	char	*binary;
	char	*a;

	binary = NULL;
	if (ft_strlen(str) < 1)
		return (NULL);
	i = 0;
	while (str[i])
	{
		a = ft_printbin(str[i]);
		binary = ft_strjoin(binary, a);
		i++;
		free(a);
	}
	return (binary);
}
