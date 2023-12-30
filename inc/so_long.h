/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 07:43:54 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/18 17:41:23 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx/mlx.h"
# include "keycodes.h"
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# define TS 64
# define WAL "./sprites/wall.xpm"
# define FLR "./sprites/floor.xpm"
# define COL "./sprites/redbull.xpm"
# define EXT "./sprites/imac.xpm"
# define HRO "./sprites/stouf.xpm"
# define HRO2 "./sprites/stoufboss.xpm"

typedef struct s_res
{
	int			x;
	int			y;
}				t_res;

typedef struct s_hero
{
	t_res		pos;
	int			stps;
	int			minstps;
	int			collect;
}				t_hero;

typedef struct s_sc
{
	t_res		res;
	t_res		mapsize;
	int			file;
	char		*filepath;
	char		**map;
	void		*mlx;
	void		*win;
	void		*img;
	t_hero		hero;
	t_res		exit;
	int			collecttotal;
}				t_sc;

/* UTILS */
int			ft_error(char *str);
void		ft_freemap(char **map);
int			ft_exitgame(t_sc *sc);
void		ft_putimage(t_sc *sc, char *sprite, int i, int j);

/* RENDER */
void		ft_scoreboard(t_sc *sc);
void		ft_generatemap(t_sc *sc);
void		ft_loadgame(t_sc *sc);

/* PARSER */
int			ft_countlines(char *filepath);
void		ft_savemap(t_sc *sc);
void		ft_initvars(t_sc *sc);
void		ft_parse(t_sc *sc);

/* KEYS */
void		ft_nextlevel(t_sc *sc);
void		ft_collect(t_sc *sc);
void		ft_move(int *axis, int value, int *steps);
int			ft_keypress(int keycode, t_sc *sc);

/* CHECK */
void		ft_checklinelength(t_sc *sc);
void		ft_checkflags(t_sc *sc, int i, int j, int *epcflags);
void		ft_checkmap(t_sc *sc);
void		ft_checkfiles(t_sc *sc, char *argv);

#endif
