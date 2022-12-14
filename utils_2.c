/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgiordan <vgiordan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:02:17 by vgiordan          #+#    #+#             */
/*   Updated: 2022/11/30 13:04:12 by vgiordan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (count);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	*string_to_int_array(char *str, int nb_words)
{
	int		j;
	int		i;
	char	*nombre;
	int		*result;

	j = 0;
	result = malloc((nb_words) * sizeof(int));
	while (j < nb_words)
	{
		i = 0;
		while (*str == ' ' && *str)
			str++;
		nombre = malloc((size_of_nb(str) + 1) * sizeof(char));
		while (*str != ' ' && *str)
			nombre[i++] = *str++;
		nombre[i] = '\0';
		if (ft_atoi(nombre) > 2147483647 || ft_atoi(nombre) < -2147483648)
		{
			free_2e(nombre, result);
			return (NULL);
		}
		result[j++] = (int)ft_atoi(nombre);
		free(nombre);
	}
	return (result);
}

static long	ft_signe(const char *str)
{
	long	i;

	i = 0;
	while ((!(str[i] >= '0' && str[i] <= '9')) && str[i] != '-'
		&& str[i] != '+')
	{
		if (str[i] == '\0')
			return (0);
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] <= '9' && str[i + 1] >= '0')
		{
			if (str[i] == '-')
				return (-1);
			return (1);
		}
		return (0);
	}
	return (1);
}

long	ft_atoi(const char *str)
{
	long	number;
	long	i;

	i = 0;
	number = 0;
	while (!(str[i] >= '0' && str[i] <= '9') && str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
			&& str[i] != '\f' && str[i] != '\v' && str[i] != '\r'
			&& str[i] != '+' && str[i] != '-')
			return (-1);
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * ft_signe(str));
}
