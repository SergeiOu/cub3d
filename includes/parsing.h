/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 15:37:01 by mfassad           #+#    #+#             */
/*   Updated: 2026/08/10 16:05:02 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 225,30,0

111111
100001
10N001
111111
*/
/*
game.config
│
├── north  = "./textures/north.xpm"
├── south  = "./textures/south.xpm"
├── west   = "./textures/west.xpm"
├── east   = "./textures/east.xpm"
│
├── floor
│   ├── r = 220
│   ├── g = 100
│   └── b = 0
│
├── ceiling
│   ├── r = 225
│   ├── g = 30
│   └── b = 0
│
├── map
│   ├── "111111"
│   ├── "100001"
│   ├── "10N001"
│   └── "111111"
│
└── player
    ├── x = 2
    ├── y = 2
    ├── direction = 'N'
    └── count = 1
*/
