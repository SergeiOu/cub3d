/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:36:11 by mfassad           #+#    #+#             */
/*   Updated: 2026/10/05 10:35:33 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 34);
		return (1);
	}
	if (!validate_filename(argv[1]))
	{
		write(2, "Error\nInvalid file extension\n", 29);
		return (1);
	}
	init_config(&game.config);
	if (!parse_file(argv[1], &game.config))
	{
		write(2, "Error\nInvalid configuration\n", 28);
		free_config(&game.config);
		return (1);
	}
	free_config(&game.config);
	return (0);
}
