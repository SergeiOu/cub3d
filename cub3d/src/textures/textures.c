#include "cub3d.h"

static int	load_one(t_game *game, t_tex *tex, char *path)
{
	tex->ptr = mlx_xpm_file_to_image(game->mlx, path,
			&tex->width, &tex->height);
	if (!tex->ptr)
		return (0);
	tex->addr = mlx_get_data_addr(tex->ptr, &tex->bpp,
			&tex->line_len, &tex->endian);
	if (!tex->addr)
		return (0);
	return (1);
}

int	load_textures(t_game *game)
{
	if (!load_one(game, &game->tex[TEX_NORTH], game->config.north))
		return (0);
	if (!load_one(game, &game->tex[TEX_SOUTH], game->config.south))
		return (0);
	if (!load_one(game, &game->tex[TEX_WEST], game->config.west))
		return (0);
	if (!load_one(game, &game->tex[TEX_EAST], game->config.east))
		return (0);
	return (1);
}

void	destroy_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->tex[i].ptr)
			mlx_destroy_image(game->mlx, game->tex[i].ptr);
		game->tex[i].ptr = NULL;
		i++;
	}
}
