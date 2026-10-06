/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:18:56 by mfassad           #+#    #+#             */
/*   Updated: 2026/10/05 10:18:57 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_line_len(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		len--;
	return (len);
}

static int	get_map_height(char **lines, int start)
{
	int	height;

	height = 0;
	while (lines[start + height])
		height++;
	return (height);
}

static int	get_map_width(char **lines, int start)
{
	int	i;
	int	len;
	int	max;

	i = start;
	max = 0;
	while (lines[i])
	{
		len = map_line_len(lines[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

static void	free_partial_map(char **map, int count)
{
	while (count > 0)
	{
		count--;
		free(map[count]);
	}
	free(map);
}

int	store_map(char **lines, int start, t_config *config)
{
	int	i;
	int	len;
	int	height;

	height = get_map_height(lines, start);
	config->map = malloc(sizeof(char *) * (height + 1));
	if (!config->map)
		return (0);
	i = 0;
	while (i < height)
	{
		len = map_line_len(lines[start + i]);
		config->map[i] = ft_substr(lines[start + i], 0, len);
		if (!config->map[i])
		{
			free_partial_map(config->map, i);
			config->map = NULL;
			return (0);
		}
		i++;
	}
	config->map[i] = NULL;
	config->map_height = height;
	config->map_width = get_map_width(lines, start);
	return (1);
}
