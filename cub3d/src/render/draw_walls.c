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

static int	get_tex_x(t_game *game, t_ray *ray, t_tex *tex)
{
	int	tex_x;

	if (ray->side == 0)
		ray->wall_x = game->cam.pos_y + ray->dist * ray->dir_y;
	else
		ray->wall_x = game->cam.pos_x + ray->dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	tex_x = (int)(ray->wall_x * tex->width);
	if ((ray->side == 0 && ray->dir_x > 0)
		|| (ray->side == 1 && ray->dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

static int	tex_color(t_tex *tex, int tex_x, int tex_y)
{
	char	*src;

	if (tex_y >= tex->height)
		tex_y = tex->height - 1;
	src = tex->addr + (tex_y * tex->line_len + tex_x * (tex->bpp / 8));
	return (*(unsigned int *)src);
}

static void	draw_column(t_game *game, t_ray *ray, int x)
{
	t_tex	*tex;
	double	step;
	double	tex_pos;
	int		y;

	tex = &game->tex[wall_side(ray)];
	ray->tex_x = get_tex_x(game, ray, tex);
	step = (double)tex->height / ray->line_h;
	tex_pos = (ray->start - WIN_H / 2.0 + ray->line_h / 2.0) * step;
	y = ray->start;
	while (y <= ray->end)
	{
		put_pixel(&game->img, x, y,
			tex_color(tex, ray->tex_x, (int)tex_pos));
		tex_pos += step;
		y++;
	}
}

void	draw_walls(t_game *game)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WIN_W)
	{
		cast_ray(game, &ray, x);
		draw_column(game, &ray, x);
		x++;
	}
}
