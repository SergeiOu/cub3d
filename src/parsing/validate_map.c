/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 00:00:00 by mfassad           #+#    #+#             */
/*   Updated: 2026/10/05 10:17:54 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_walkable(char c)
{
	return (c == '0' || is_player(c));
}

static int	is_outside(t_config *config, int y, int x)
{
	int	len;

	if (y < 0 || y >= config->map_height)
		return (1);
	if (x < 0)
		return (1);
	len = ft_strlen(config->map[y]);
	if (x >= len)
		return (1);
	if (config->map[y][x] == ' ')
		return (1);
	return (0);
}

static int	is_cell_closed(t_config *config, int y, int x)
{
	if (is_outside(config, y - 1, x))
		return (0);
	if (is_outside(config, y + 1, x))
		return (0);
	if (is_outside(config, y, x - 1))
		return (0);
	if (is_outside(config, y, x + 1))
		return (0);
	return (1);
}

int	validate_map(t_config *config)
{
	int	x;
	int	y;

	y = 0;
	while (y < config->map_height)
	{
		x = 0;
		while (config->map[y][x])
		{
			if (is_player(config->map[y][x]))
				set_player(config, y, x);
			if (is_walkable(config->map[y][x])
				&& !is_cell_closed(config, y, x))
				return (0);
			x++;
		}
		y++;
	}
	if (config->player.count != 1)
		return (0);
	return (1);
}
