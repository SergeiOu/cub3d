/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 10:15:24 by mfassad           #+#    #+#             */
/*   Updated: 2026/10/05 10:16:49 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_texture(t_line_type type)
{
	return (type == LINE_NO || type == LINE_SO
		|| type == LINE_WE || type == LINE_EA);
}

static int	is_color(t_line_type type)
{
	return (type == LINE_F || type == LINE_C);
}

static int	handle_config(char *line, t_line_type type,
		t_config *config, t_parse_state *state)
{
	if (type == LINE_EMPTY)
		return (1);
	if (is_texture(type))
		return (parse_texture(line, type, config));
	if (is_color(type))
		return (parse_color(line, type, config));
	if (type == LINE_MAP)
	{
		if (!config_complete(config))
			return (0);
		*state = PARSE_MAP;
		return (1);
	}
	return (0);
}

static int	handle_map(t_line_type type)
{
	if (type != LINE_MAP)
		return (0);
	return (1);
}

int	handle_line(char *line, t_line_type type,
		t_config *config, t_parse_state *state)
{
	if (*state == PARSE_CONFIG)
		return (handle_config(line, type, config, state));
	return (handle_map(type));
}
