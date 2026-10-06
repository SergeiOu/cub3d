/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 13:37:13 by mfassad           #+#    #+#             */
/*   Updated: 2026/10/05 10:20:49 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <get_next_line.h>
# include <libft.h>

typedef enum e_line_type
{
	LINE_EMPTY,
	LINE_NO,
	LINE_SO,
	LINE_WE,
	LINE_EA,
	LINE_F,
	LINE_C,
	LINE_MAP,
	LINE_INVALID
}	t_line_type;

typedef enum e_parse_state
{
	PARSE_CONFIG,
	PARSE_MAP
}	t_parse_state;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	is_set; // to detect duplicate
}	t_color;

typedef struct s_player
{
	int		x;
	int		y;
	char	direction; // can be N S E W
	int		count; // should be one 
}	t_player;

typedef struct s_config
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	t_color		floor;
	t_color		ceiling;
	char		**map;
	int			map_height;
	int			map_width;
	t_player	player;
}	t_config;

typedef struct s_game
{
	t_config	config;
}	t_game;

void			init_color(t_color *color);
void			init_player(t_player *player);
void			init_config(t_config *config);

int				validate_filename(char *filename);
int				parse_file(char *filename, t_config *config);

t_line_type		identify_line(char *line);

int				texture_file_valid(char *path);
int				parse_texture(char *line, t_line_type type,
					t_config *config);
void			free_config(t_config *config);

char			**read_file(char *filename);
void			free_lines(char **lines);

int				parse_color(char *line, t_line_type type,
					t_config *config);
int				config_complete(t_config *config);

int				store_map(char **lines, int start, t_config *config);
int				validate_map(t_config *config);
int				handle_line(char *line, t_line_type type,
					t_config *config, t_parse_state *state);

void			set_player(t_config *config, int y, int x);

#endif