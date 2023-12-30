/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 03:49:29 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/18 00:36:56 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_checklinelength(t_sc *sc)
{
	int		i;

	i = -1;
	while (sc->map[++i])
		if (ft_strlen(sc->map[i]) != (size_t)sc->mapsize.x)
			ft_error("Map must be rectangular\n");
}

void	ft_checkflags(t_sc *sc, int x, int y, int epcflags[2])
{
	if ((y == 0 || y == sc->mapsize.y - 1 || x == 0
			|| x == sc->mapsize.x - 1) && sc->map[y][x] != '1')
		ft_error("The map must be completely surrounded by a wall\n");
	if (sc->map[y][x] == 'E')
	{
		epcflags[0]++;
		sc->exit.x = x;
		sc->exit.y = y;
	}
	else if (sc->map[y][x] == 'P')
	{
		epcflags[1]++;
		sc->hero.pos.x = x;
		sc->hero.pos.y = y;
	}
	else if (sc->map[y][x] == 'C')
		sc->collecttotal++;
	else if (sc->map[y][x] != '0' && sc->map[y][x] != '1')
		ft_error("Map has invalid characters\n");
}

void	ft_checkmap(t_sc *sc)
{
	int		y;
	int		x;
	int		epcflags[2];

	y = -1;
	epcflags[0] = 0;
	epcflags[1] = 0;
	ft_checklinelength(sc);
	while (sc->map[++y])
	{
		x = -1;
		while (sc->map[y][++x])
			ft_checkflags(sc, x, y, epcflags);
	}
	if (epcflags[0] < 1 || epcflags[1] != 1 || sc->collecttotal < 1)
		ft_error("Invalid number of elements\n");
}

void	ft_checkfiles(t_sc *sc, char *argv)
{
	char	*ext;

	sc->filepath = argv;
	ext = ft_strrchr(sc->filepath, '.');
	if (!ext || ft_strncmp(ext, ".ber", 5))
		ft_error("Invalid map extension\n");
	sc->file = open(sc->filepath, O_RDONLY);
	if (sc->file < 0)
		ft_error("File doesn't exist\n");
}
