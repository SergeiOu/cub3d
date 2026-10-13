#include "cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 17, 1L << 17, close_game, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
}
