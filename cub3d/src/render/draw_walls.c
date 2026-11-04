#include "cub3d.h"

int	wall_side(t_ray *ray)
{
	if (ray->side == 0 && ray->dir_x > 0)
		return (TEX_EAST);
	if (ray->side == 0)
		return (TEX_WEST);
	if (ray->dir_y > 0)
		return (TEX_SOUTH);
	return (TEX_NORTH);
}

static int	debug_color(int side)
{
	if (side == TEX_NORTH)
		return (0x3060FF);
	if (side == TEX_SOUTH)
		return (0xFF3030);
	if (side == TEX_WEST)
		return (0x30C030);
	return (0xFFD020);
}

void	draw_walls(t_game *game)
{
	t_ray	ray;
	int		x;
	int		y;

	x = 0;
	while (x < WIN_W)
	{
		cast_ray(game, &ray, x);
		y = ray.start;
		while (y <= ray.end)
		{
			put_pixel(&game->img, x, y, debug_color(wall_side(&ray)));
			y++;
		}
		x++;
	}
}
