/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dafranco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:50:42 by dafranco          #+#    #+#             */
/*   Updated: 2023/01/11 11:51:19 by dafranco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_bitoa(char *str)
{
	int	count;

	count = 0;
	if (str[7] == '1')
		count += 1;
	if (str[6] == '1')
		count += 2;
	if (str[5] == '1')
		count += 4;
	if (str[4] == '1')
		count += 8;
	if (str[3] == '1')
		count += 16;
	if (str[2] == '1')
		count += 32;
	if (str[1] == '1')
		count += 64;
	if (str[0] == '1')
		count += 128;
	return ((char)count);
}
