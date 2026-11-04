/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 17:01:13 by mfassad           #+#    #+#             */
/*   Updated: 2026/09/21 15:08:47 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_lines(char *filename)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static int	fill_lines(char *filename, char **lines)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		lines[i++] = line;
		line = get_next_line(fd);
	}
	lines[i] = NULL;
	close(fd);
	return (1);
}

char	**read_file(char *filename)
{
	char	**lines;
	int		count;

	count = count_lines(filename);
	if (count < 0)
		return (NULL);
	lines = malloc(sizeof(char *) * (count + 1));
	if (!lines)
		return (NULL);
	if (!fill_lines(filename, lines))
	{
		free(lines);
		return (NULL);
	}
	return (lines);
}
/*
             read_file()
                  │
                  ▼
            count_lines()
                  │
         open file #1
                  │
        count every line
                  │
           close file
                  │
                  ▼
       malloc count + 1
                  │
                  ▼
            fill_lines()
                  │
         open file #2
                  │
       store every line
                  │
         lines[i] = NULL
                  │
           close file
                  │
                  ▼
            return lines
*/