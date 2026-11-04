#include "cub3d.h"

static void	try_move(t_game *game, double dx, double dy)
{
	t_camera	*cam;
	double		margin_x;
	double		margin_y;

	cam = &game->cam;
	margin_x = HIT_MARGIN;
	margin_y = HIT_MARGIN;
	if (dx < 0)
		margin_x = -HIT_MARGIN;
	if (dy < 0)
		margin_y = -HIT_MARGIN;
	if (!is_wall(game, (int)(cam->pos_x + dx + margin_x), (int)cam->pos_y))
		cam->pos_x += dx;
	if (!is_wall(game, (int)cam->pos_x, (int)(cam->pos_y + dy + margin_y)))
		cam->pos_y += dy;
}

static void	move_player(t_game *game)
{
	t_camera	*cam;
	double		forward;
	double		side;

	cam = &game->cam;
	forward = (game->keys.w - game->keys.s) * MOVE_SPEED;
	side = (game->keys.d - game->keys.a) * MOVE_SPEED;
	if (forward != 0 && side != 0)
	{
		forward *= M_SQRT1_2;
		side *= M_SQRT1_2;
	}
	try_move(game, cam->dir_x * forward - cam->dir_y * side,
		cam->dir_y * forward + cam->dir_x * side);
}

static void	rotate_player(t_game *game, double angle)
{
	t_camera	*cam;
	double		old_dir_x;
	double		old_plane_x;

	cam = &game->cam;
	old_dir_x = cam->dir_x;
	cam->dir_x = cam->dir_x * cos(angle) - cam->dir_y * sin(angle);
	cam->dir_y = old_dir_x * sin(angle) + cam->dir_y * cos(angle);
	old_plane_x = cam->plane_x;
	cam->plane_x = cam->plane_x * cos(angle) - cam->plane_y * sin(angle);
	cam->plane_y = old_plane_x * sin(angle) + cam->plane_y * cos(angle);
}

void	update_player(t_game *game)
{
	move_player(game);
	if (game->keys.right)
		rotate_player(game, ROT_SPEED);
	if (game->keys.left)
		rotate_player(game, -ROT_SPEED);
}
