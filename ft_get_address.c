/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:51:02 by rmakoni           #+#    #+#             */
/*   Updated: 2024/11/07 11:25:19 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	reverse_print4(char *snum, int len, int fd)
{
	int	count;
	int	temp;

	count = 0;
	count = write(1, "0x", 2);
	if (count == -1)
		return (-1);
	len--;
	while (len >= 0)
	{
		temp = write(fd, &snum[len], 1);
		if (temp == -1)
			return (-1);
		len--;
		count += temp;
	}
	return (count);
}

char	gethex_letter2(int num, char c)
{
	if (num == 10)
		return (ft_toupper('a', c));
	else if (num == 11)
		return (ft_toupper('b', c));
	else if (num == 12)
		return (ft_toupper('c', c));
	else if (num == 13)
		return (ft_toupper('d', c));
	else if (num == 14)
		return (ft_toupper('e', c));
	else
		return (ft_toupper('f', c));
}

int	ft_gethex2(unsigned long number, char c)
{
	int		r;
	int		i;
	char	hex[100];

	i = 0;
	if (number == 0)
	{
		hex[i++] = '0';
		return (reverse_print4(hex, i, 1));
	}
	while (number > 0)
	{
		r = number % 16;
		if (r < 10)
			hex[i++] = r + '0';
		else
			hex[i++] = gethex_letter2(r, c);
		number /= 16;
	}
	hex[i] = '\0';
	return (reverse_print4(hex, i, 1));
}

int	ft_get_address(void *add)
{
	unsigned long	addr;

	addr = (unsigned long)add;
	return (ft_gethex2(addr, 'x'));
}
