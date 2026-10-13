#include "cub3d.h"

static void	draw_background(t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < WIN_H)
	{
		if (y < WIN_H / 2)
			color = rgb_to_int(game->config.ceiling);
		else
			color = rgb_to_int(game->config.floor);
		x = 0;
		while (x < WIN_W)
		{
			put_pixel(&game->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_frame(t_game *game)
{
	draw_background(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.ptr, 0, 0);
}

int	expose_hook(t_game *game)
{
	render_frame(game);
	return (0);
}
