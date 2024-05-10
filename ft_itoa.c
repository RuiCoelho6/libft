/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:54:19 by rpires-c          #+#    #+#             */
/*   Updated: 2024/05/07 12:04:09 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *result(char *str, int digits, int num, int flag)
{
	if (flag == 1)
	{
		while (digits > 0)
			{
				str[digits] = (num % 10) + '0';
				num /= 10;
				digits--;
			}
		str[0] = '-';
	}
	else
	{
		while(digits >= 0)
			{
				str[digits] = (num % 10) + '0';
				num /= 10;
				digits--;
			}
	}
	return (str);
}

static void check_negative(int *flag, int *num, int *digits, int n)
{
	*flag = 0;
	
	if(n < 0)
	{
		*flag = 1;
		*num *= -1;
		*digits += 1;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int	flag;
	int	digits;
	int	num;

	num = n;
    digits = 1;
	if (n == -2147483648)
	{
		if (!(str = malloc(12 * sizeof(char))))
			return (NULL);
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	check_negative(&flag, &num, &digits, n);
	while (n /= 10)
		digits++;
	if (!(str = malloc((digits + 1) * sizeof(char))))
		return (NULL);
	str[digits--] = '\0';
	result(str, digits, num, flag);
	return (str);
}

// int main()
// {
// 	char *str = ft_itoa(-5642);
//     free(str);
// 	printf("%s", ft_itoa(-2147483648));
//     return(0);
// }