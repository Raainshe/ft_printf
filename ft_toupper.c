/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:14:51 by rmakoni           #+#    #+#             */
/*   Updated: 2024/11/07 11:24:43 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_toupper(int c, char x)
{
	if (x == 'x')
		return (c);
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}