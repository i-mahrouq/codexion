#include "codexion.h"


#include <stdio.h>


int is_nbr(const char *str)
{
    int i;

    i = 0;
    if (!str || !str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

long	ft_atoi(const char *str)
{
	int		i;
	size_t	r;
	size_t	b_r;

	i = 0;
	r = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		b_r = r;
		r = r * 10 + str[i] - '0';
		i++;
		if ((r > 2147483647 || b_r != r / 10))
			return (9999999999);
	}
	return ((int)(r));
}

int is_valid(const char **input)
{
	int i;
	long n;

	n = ft_atoi(input[1]);
	if (!is_nbr(input[1]) || n == 0 || n == 9999999999)
		return 0;
	i = 2;
	while (i < 8)
	{
		if(is_nbr(input[i]))
		{	
			n = ft_atoi(input[i]);
			if (n == 9999999999)
				return 0;
		}
		else
			return (0);
		i++;
	}
	if (ft_strcmp(input[8], "fifo") != 0 && ft_strcmp(input[8], "edf") != 0)
        return (0);
	return (1);
}