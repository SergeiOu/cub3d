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

static int	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 34);
		return (0);
	}
	if (!validate_filename(argv[1]))
	{
		write(2, "Error\nInvalid file extension\n", 29);
		return (0);
	}
	return (1);
}

static int	init_game(t_game *game, char *path)
{
	ft_bzero(game, sizeof(t_game));
	init_config(&game->config);
	if (!parse_file(path, &game->config))
	{
		write(2, "Error\nInvalid configuration\n", 28);
		free_config(&game->config);
		return (0);
	}
	if (!init_window(game) || !load_textures(game))
	{
		write(2, "Error\nWindow or texture initialization failed\n", 46);
		destroy_window(game);
		free_config(&game->config);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!check_args(argc, argv) || !init_game(&game, argv[1]))
		return (1);
	init_camera(&game);
	setup_hooks(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
