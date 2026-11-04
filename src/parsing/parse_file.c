/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 15:22:32 by mfassad           #+#    #+#             */
/*   Updated: 2026/10/05 10:16:33 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_lines(char **lines, t_config *config,
		t_parse_state *state, int *map_start)
{
	t_line_type	type;
	int			i;

	i = 0;
	while (lines[i])
	{
		type = identify_line(lines[i]);
		if (!handle_line(lines[i], type, config, state))
			return (0);
		if (type == LINE_MAP && *map_start == -1)
			*map_start = i;
		i++;
	}
	return (1);
}

static int	finish_parsing(char **lines, int map_start, t_config *config)
{
	if (!config_complete(config) || map_start == -1)
		return (0);
	if (!store_map(lines, map_start, config))
		return (0);
	if (!validate_map(config))
		return (0);
	return (1);
}

int	parse_file(char *filename, t_config *config)
{
	t_parse_state	state;
	char			**lines;
	int				map_start;
	int				status;

	lines = read_file(filename);
	if (!lines)
		return (0);
	state = PARSE_CONFIG;
	map_start = -1;
	status = parse_lines(lines, config, &state, &map_start);
	if (status)
		status = finish_parsing(lines, map_start, config);
	free_lines(lines);
	return (status);
}

/* 
			main loop 
				|
			check_state 
		/					\
	config 			->  	map 
/		|		\			 |
empty color texture 	find map start -> check all lines are LINE_MAP

!!!!!!! before changing state config should be complete !!!!!!!!

*/