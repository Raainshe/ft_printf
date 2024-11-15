/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:50:39 by rmakoni           #+#    #+#             */
/*   Updated: 2024/11/07 11:24:48 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	count;
	int	temp;

	i = 0;
	if (s == NULL)
	{
		s = "(null)";
	}
	count = 0;
	while (s[i] != '\0')
	{
		temp = write(fd, &s[i], 1);
		if (temp == -1)
			return (temp);
		count += temp;
		i++;
	}
	return (count);
}
