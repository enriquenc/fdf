/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaslyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 19:58:32 by tmaslyan          #+#    #+#             */
/*   Updated: 2018/05/31 19:58:33 by tmaslyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	ft_isupper(char c)
{
	return (c >= 65 && c <= 90);
}

int			hex_to_digit(char *str)
{
	long	result;
	int		nbr;

	pass_spaces((const char **)(&str));
	while (*str == '0' || *str == 'x')
		str++;
	result = 0;
	nbr = 0;
	while (*str)
	{
		if (!ft_isascii(*str))
			break ;
		if (ft_isdigit(*str))
			nbr = *str - '0';
		else if (ft_isalpha(*str))
			nbr = *str - (ft_isupper(*str) ? 'A' - 10 : 'a' - 10);
		else
			break ;
		result *= 16;
		result += nbr;
		str++;
	}
	return (result);
}
