#include "cub3d.h"

int	is_wall(t_game *game, int x, int y)
{
	t_config	*cfg;

	cfg = &game->config;
	if (y < 0 || y >= cfg->map_height || x < 0)
		return (1);
	if (x >= (int)ft_strlen(cfg->map[y]))
		return (1);
	return (cfg->map[y][x] == '1');
}

static void	init_ray(t_game *game, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2.0 * x / WIN_W - 1.0;
	ray->dir_x = game->cam.dir_x + game->cam.plane_x * camera_x;
	ray->dir_y = game->cam.dir_y + game->cam.plane_y * camera_x;
	ray->map_x = (int)game->cam.pos_x;
	ray->map_y = (int)game->cam.pos_y;
	ray->delta_x = 1e30;
	ray->delta_y = 1e30;
	if (ray->dir_x != 0)
		ray->delta_x = fabs(1.0 / ray->dir_x);
	if (ray->dir_y != 0)
		ray->delta_y = fabs(1.0 / ray->dir_y);
}

static void	init_steps(t_game *game, t_ray *ray)
{
	ray->step_x = 1;
	ray->side_x = (ray->map_x + 1.0 - game->cam.pos_x) * ray->delta_x;
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_x = (game->cam.pos_x - ray->map_x) * ray->delta_x;
	}
	ray->step_y = 1;
	ray->side_y = (ray->map_y + 1.0 - game->cam.pos_y) * ray->delta_y;
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_y = (game->cam.pos_y - ray->map_y) * ray->delta_y;
	}
}

static void	run_dda(t_game *game, t_ray *ray)
{
	while (!is_wall(game, ray->map_x, ray->map_y))
	{
		if (ray->side_x < ray->side_y)
		{
			ray->side_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
}

void	cast_ray(t_game *game, t_ray *ray, int x)
{
	init_ray(game, ray, x);
	init_steps(game, ray);
	run_dda(game, ray);
	if (ray->side == 0)
		ray->dist = ray->side_x - ray->delta_x;
	else
		ray->dist = ray->side_y - ray->delta_y;
	ray->line_h = (int)(WIN_H / ray->dist);
	ray->start = -ray->line_h / 2 + WIN_H / 2;
	ray->end = ray->line_h / 2 + WIN_H / 2;
	if (ray->start < 0)
		ray->start = 0;
	if (ray->end > WIN_H - 1)
		ray->end = WIN_H - 1;
}
