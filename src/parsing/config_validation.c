/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 13:13:10 by mfassad           #+#    #+#             */
/*   Updated: 2026/10/05 10:10:03 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	config_complete(t_config *config)
{
	if (!config->north)
		return (0);
	if (!config->south)
		return (0);
	if (!config->west)
		return (0);
	if (!config->east)
		return (0);
	if (!config->floor.is_set)
		return (0);
	if (!config->ceiling.is_set)
		return (0);
	return (1);
}
