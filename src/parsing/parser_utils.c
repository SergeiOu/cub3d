/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 15:42:08 by mfassad           #+#    #+#             */
/*   Updated: 2026/10/05 10:18:08 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_config(t_config *config)
{
	int	i;

	free(config->north);
	free(config->south);
	free(config->west);
	free(config->east);
	if (config->map)
	{
		i = 0;
		while (config->map[i])
		{
			free(config->map[i]);
			i++;
		}
		free(config->map);
	}
}

void	free_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	set_player(t_config *config, int y, int x)
{
	config->player.x = x;
	config->player.y = y;
	config->player.direction = config->map[y][x];
	config->player.count++;
}
