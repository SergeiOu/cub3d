#include "cub3d.h"

static void	set_key(t_keys *keys, int keycode, int value)
{
	if (keycode == KEY_W)
		keys->w = value;
	else if (keycode == KEY_A)
		keys->a = value;
	else if (keycode == KEY_S)
		keys->s = value;
	else if (keycode == KEY_D)
		keys->d = value;
	else if (keycode == KEY_LEFT)
		keys->left = value;
	else if (keycode == KEY_RIGHT)
		keys->right = value;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_game(game);
	set_key(&game->keys, keycode, 1);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	set_key(&game->keys, keycode, 0);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 17, 1L << 17, close_game, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 12, 1L << 15, expose_hook, game);
}
