#include <libft.h>

static int	length(int n)
{
	int i;

	i = 0;
	while (n != 0 || i == 0)
	{
		++i;
		n = n / 10;
	}
	return (i);
}

static void	write(char *str, int n, int j, int l)
{
	if (j == 1)
	{
		++l;
		str[0] = '-';
	}
	if (n == 0)
	{
		str[0] = '0';
		return ;
	}
	while (n != 0 || l == 1)
	{
		str[l--] = '0' + n % 10;
		n /= 10;
	}
}

static	void	str_min(char *str)
{
	str[0] = '-';
	str[1] = '2';
	write(str + 2, 147483648, 0, 8);
}

char	*ft_itoa(int n)
{
	int		l;
	int		j;
	char	*str;

	j = 0;
	if (n < 0)
	{
		j = 1;
		n *= -1;
	}
	l = length(n);
	if (!(str = (char *)malloc(sizeof(char) * l + 1 + j)))
		return (NULL);
	str[l + j] = '\0';
	if (n == -2147483648)
		str_min(str);
	else
		write(str, n, j, l - 1);
	return (str);
}
