/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 14:51:59 by mfassad           #+#    #+#             */
/*   Updated: 2026/08/12 14:52:09 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '\n' || line[i] == '\0')
		return (1);
	return (0);
}

static int	is_map_line(char *line)
{
	int	i;
	int	has_map_char;

	i = 0;
	has_map_char = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == '0' || line[i] == '1'
			|| line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
			has_map_char = 1;
		else if (line[i] != ' ')
			return (0);
		i++;
	}
	return (has_map_char);
}

static char	*skip_indent(char *line)
{
	while (*line == ' ')
		line++;
	return (line);
}

t_line_type	identify_line(char *line)
{
	char	*s;

	if (!line)
		return (LINE_INVALID);
	if (is_empty_line(line))
		return (LINE_EMPTY);
	s = skip_indent(line);
	if (ft_strncmp(s, "NO ", 3) == 0)
		return (LINE_NO);
	if (ft_strncmp(s, "SO ", 3) == 0)
		return (LINE_SO);
	if (ft_strncmp(s, "WE ", 3) == 0)
		return (LINE_WE);
	if (ft_strncmp(s, "EA ", 3) == 0)
		return (LINE_EA);
	if (ft_strncmp(s, "F ", 2) == 0)
		return (LINE_F);
	if (ft_strncmp(s, "C ", 2) == 0)
		return (LINE_C);
	if (is_map_line(line))
		return (LINE_MAP);
	return (LINE_INVALID);
}
