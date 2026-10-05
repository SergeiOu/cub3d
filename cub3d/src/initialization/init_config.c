/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:06:29 by mfassad           #+#    #+#             */
/*   Updated: 2026/08/10 16:14:29 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_color(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
	color->is_set = 0;
}

void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->direction = '\0';
	player->count = 0;
}

void	init_config(t_config *config)
{
	config->north = NULL;
	config->south = NULL;
	config->west = NULL;
	config->east = NULL;
	init_color(&config->floor);
	init_color(&config->ceiling);
	config->map = NULL;
	config->map_height = 0;
	config->map_width = 0;
	init_player(&config->player);
}
