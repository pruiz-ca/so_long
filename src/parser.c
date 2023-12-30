/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 23:25:57 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/18 00:35:56 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_countlines(char *filepath)
{
	int		fd;
	int		n_lines;
	char	*line;

	n_lines = 0;
	fd = open(filepath, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		n_lines++;
	}
	free(line);
	close(fd);
	return (n_lines);
}

void	ft_savemap(t_sc *sc)
{
	int		i;
	char	*line;

	i = 0;
	while (get_next_line(sc->file, &line) > 0)
	{
		sc->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	sc->map[i] = NULL;
	sc->mapsize.x = ft_strlen(sc->map[0]);
	free(line);
}

void	ft_initvars(t_sc *sc)
{
	sc->hero.stps = 0;
	sc->hero.minstps = -1;
	sc->collecttotal = 0;
	sc->hero.collect = 0;
	sc->res.x = sc->mapsize.x * TS;
	sc->res.y = sc->mapsize.y * TS;
	if (!ft_strncmp(sc->filepath, "maps/00.ber", 12))
		sc->hero.minstps = 19;
	if (!ft_strncmp(sc->filepath, "maps/01.ber", 12))
		sc->hero.minstps = 65;
	if (!ft_strncmp(sc->filepath, "maps/02.ber", 12))
		sc->hero.minstps = 59;
}

void	ft_parse(t_sc *sc)
{
	sc->mapsize.y = ft_countlines(sc->filepath);
	sc->map = (char **)malloc(sizeof(char *) * (sc->mapsize.y + 1));
	if (!sc->map)
		exit(12);
	ft_savemap(sc);
	ft_initvars(sc);
	close(sc->file);
}
