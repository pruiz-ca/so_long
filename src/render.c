/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:38:55 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/18 00:36:15 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_scoreboard(t_sc *sc)
{
	int		i[2];
	char	*minsteps;
	char	*steps;

	i[0] = 4;
	while (++i[0] <= 120)
	{
		i[1] = 4;
		while (++i[1] <= 45)
			mlx_pixel_put(sc->mlx, sc->win, i[0], i[1], 0x000000);
	}
	steps = ft_itoa(sc->hero.stps);
	mlx_string_put(sc->mlx, sc->win, 10, 20, 0xFFFFFF, "STEPS: ");
	mlx_string_put(sc->mlx, sc->win, 90, 20, 0xFFFFFF, steps);
	mlx_string_put(sc->mlx, sc->win, 10, 40, 0xFFFFFF, "LOWEST: ");
	if (sc->hero.minstps != -1)
		minsteps = ft_itoa(sc->hero.minstps);
	else
		minsteps = "?";
	mlx_string_put(sc->mlx, sc->win, 90, 40, 0xFFFFFF, minsteps);
	free(steps);
	if (sc->hero.minstps != -1)
		free(minsteps);
}

void	ft_generatemap(t_sc *sc)
{
	int		i;
	int		j;

	j = -1;
	while (++j < sc->mapsize.y)
	{
		i = -1;
		while (++i < sc->mapsize.x)
		{
			if (sc->map[j][i] == '1')
				ft_putimage(sc, WAL, i, j);
			else
				ft_putimage(sc, FLR, i, j);
			if (sc->map[j][i] == 'E')
				ft_putimage(sc, EXT, i, j);
			if (sc->map[j][i] == 'C')
				ft_putimage(sc, COL, i, j);
			if (sc->hero.collect != sc->collecttotal)
				ft_putimage(sc, HRO, sc->hero.pos.x, sc->hero.pos.y);
			else
				ft_putimage(sc, HRO2, sc->hero.pos.x, sc->hero.pos.y);
		}
	}
	ft_scoreboard(sc);
}

void	ft_loadgame(t_sc *sc)
{
	sc->mlx = mlx_init();
	sc->win = mlx_new_window(sc->mlx, sc->res.x, sc->res.y, "so_long");
	ft_generatemap(sc);
	mlx_hook(sc->win, 2, 0, ft_keypress, sc);
	mlx_hook(sc->win, 17, 0, ft_exitgame, sc);
	mlx_loop(sc->mlx);
}
