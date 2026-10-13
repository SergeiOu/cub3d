#include "cub3d.h"

static void	set_direction(t_camera *cam, double dir_x, double dir_y)
{
	cam->dir_x = dir_x;
	cam->dir_y = dir_y;
	cam->plane_x = -dir_y * FOV_SCALE;
	cam->plane_y = dir_x * FOV_SCALE;
}

void	init_camera(t_game *game)
{
	t_player	*player;
	t_camera	*cam;

	player = &game->config.player;
	cam = &game->cam;
	cam->pos_x = player->x + 0.5;
	cam->pos_y = player->y + 0.5;
	if (player->direction == 'N')
		set_direction(cam, 0, -1);
	else if (player->direction == 'S')
		set_direction(cam, 0, 1);
	else if (player->direction == 'E')
		set_direction(cam, 1, 0);
	else
		set_direction(cam, -1, 0);
}
