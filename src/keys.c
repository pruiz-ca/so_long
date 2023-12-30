/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 16:58:40 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/18 17:41:24 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_nextlevel(t_sc *sc)
{
	if (sc->hero.stps > sc->hero.minstps && sc->hero.minstps != -1)
		printf("You lose :(\n");
	else if (sc->hero.minstps != -1)
		printf("You win!\U0001F947\n");
	ft_exitgame(sc);
}

void	ft_collect(t_sc *sc)
{
	if (sc->map[sc->hero.pos.y][sc->hero.pos.x] == 'C')
	{
		sc->map[sc->hero.pos.y][sc->hero.pos.x] = '0';
		sc->hero.collect++;
	}
}

void	ft_move(int *axis, int value, int *steps)
{
	*axis += value;
	(*steps)++;
	if (*steps == INT_MAX)
		ft_error("You are too tired. Go rest, please\n");
	printf("%d\n", *steps);
}

int	ft_keypress(int key, t_sc *sc)
{
	if (key == KEY_ESCAPE)
		ft_exitgame(sc);
	else if (key == KEY_W && sc->map[sc->hero.pos.y - 1][sc->hero.pos.x] != '1')
		ft_move(&sc->hero.pos.y, -1, &sc->hero.stps);
	else if (key == KEY_S && sc->map[sc->hero.pos.y + 1][sc->hero.pos.x] != '1')
		ft_move(&sc->hero.pos.y, +1, &sc->hero.stps);
	else if (key == KEY_A && sc->map[sc->hero.pos.y][sc->hero.pos.x - 1] != '1')
		ft_move(&sc->hero.pos.x, -1, &sc->hero.stps);
	else if (key == KEY_D && sc->map[sc->hero.pos.y][sc->hero.pos.x + 1] != '1')
		ft_move(&sc->hero.pos.x, +1, &sc->hero.stps);
	else
		return (1);
	ft_collect(sc);
	ft_generatemap(sc);
	if (sc->map[sc->hero.pos.y][sc->hero.pos.x] == 'E'
		&& sc->hero.collect == sc->collecttotal)
		ft_nextlevel(sc);
	return (1);
}
