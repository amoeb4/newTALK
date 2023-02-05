#include "minitalk.h"

static void	digits(int n, int cnt, char *res)
{
	char	c;

	res[cnt] = '\0';
	if (n < 0)
	{
		if (n == -2147483648)
		{
			cnt--;
			res[cnt] = '8';
			n = -214748364;
		}
		n *= -1;
		res[0] = '-';
	}
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		c = n % 10 + '0';
		res[cnt - 1] = c;
		n /= 10;
		cnt--;
	}
}

static int	decimals(int n)
{
	int		t;

	t = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
		t = 1;
	while (n != 0)
	{
		n /= 10;
		t++;
	}
	return (t);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		cnt;

	cnt = decimals(n);
	res = (char *)malloc(sizeof(char) * (cnt + 1));
	if (res == 0)
		return (NULL);
	digits(n, cnt, res);
	return (res);
}
