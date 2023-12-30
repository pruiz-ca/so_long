/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 01:42:41 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/18 01:00:24 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_error(char *str)
{
	printf("Error\n%s", str);
	exit (1);
}

void	ft_freemap(char **map)
{
	int		i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

int	ft_exitgame(t_sc *sc)
{
	if (sc->win)
		mlx_destroy_window(sc->mlx, sc->win);
	ft_freemap(sc->map);
	exit(0);
}

void	ft_putimage(t_sc *sc, char *sprite, int i, int j)
{
	int		img[2];

	sc->img = mlx_xpm_file_to_image(sc->mlx, sprite, &img[0], &img[1]);
	mlx_put_image_to_window(sc->mlx, sc->win, sc->img, i * TS, j * TS);
	mlx_destroy_image(sc->mlx, sc->img);
}
