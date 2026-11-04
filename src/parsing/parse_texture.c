/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:28:38 by mfassad           #+#    #+#             */
/*   Updated: 2026/10/05 10:18:35 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**get_texture(t_config *config, t_line_type type)
{
	if (type == LINE_NO)
		return (&config->north);
	if (type == LINE_SO)
		return (&config->south);
	if (type == LINE_WE)
		return (&config->west);
	if (type == LINE_EA)
		return (&config->east);
	return (NULL);
}

static int	get_path_start(char *line)
{
	int	i;

	i = 2;
	while (line[i] == ' ')
		i++;
	return (i);
}

static char	*extract_path(char *line)
{
	int	start;
	int	len;

	start = get_path_start(line);
	if (line[start] == '\0' || line[start] == '\n')
		return (NULL);
	len = ft_strlen(line + start);
	if (len > 0 && line[start + len - 1] == '\n')
		len--;
	if (len == 0)
		return (NULL);
	return (ft_substr(line, start, len));
}

int	parse_texture(char *line, t_line_type type, t_config *config)
{
	char	**texture;
	char	*path;

	texture = get_texture(config, type);
	if (!texture)
		return (0);
	if (*texture)
		return (0);
	path = extract_path(line);
	if (!path)
		return (0);
	if (!texture_file_valid(path))
	{
		free(path);
		return (0);
	}
	*texture = path;
	return (1);
}
