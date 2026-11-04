/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 17:27:53 by mfassad           #+#    #+#             */
/*   Updated: 2026/10/05 10:10:27 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	skip_spaces(char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
}

static int	parse_component(char *line, int *i, int *value)
{
	int	number;
	int	has_digit;

	number = 0;
	has_digit = 0;
	skip_spaces(line, i);
	while (ft_isdigit(line[*i]))
	{
		has_digit = 1;
		number = number * 10 + (line[*i] - '0');
		if (number > 255)
			return (0);
		(*i)++;
	}
	if (!has_digit)
		return (0);
	skip_spaces(line, i);
	*value = number;
	return (1);
}

static int	parse_rgb(char *line, t_color *color)
{
	int	i;
	int	value[3];
	int	j;

	i = 1;
	j = 0;
	while (j < 3)
	{
		if (!parse_component(line, &i, &value[j]))
			return (0);
		if (j < 2 && line[i] != ',')
			return (0);
		if (j < 2)
			i++;
		j++;
	}
	skip_spaces(line, &i);
	if (line[i] != '\n' && line[i] != '\0')
		return (0);
	color->r = value[0];
	color->g = value[1];
	color->b = value[2];
	return (1);
}

int	parse_color(char *line, t_line_type type, t_config *config)
{
	t_color	*color;

	if (type == LINE_F)
		color = &config->floor;
	else if (type == LINE_C)
		color = &config->ceiling;
	else
		return (0);
	if (color->is_set)
		return (0);
	if (!parse_rgb(line, color))
		return (0);
	color->is_set = 1;
	return (1);
}
