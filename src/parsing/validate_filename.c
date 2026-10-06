/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_filename.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 16:23:50 by mfassad           #+#    #+#             */
/*   Updated: 2026/10/05 10:19:03 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_filename(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len <= 4)
		return (0);
	if (filename[len - 4] != '.'
		|| filename[len - 3] != 'c'
		|| filename[len - 2] != 'u'
		|| filename[len - 1] != 'b')
		return (0);
	return (1);
}
