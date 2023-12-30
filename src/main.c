/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <pruiz-ca@student.42madrid.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 07:34:52 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/07/17 23:53:38 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	t_sc	sc;

	if (argc != 2)
		ft_error("One valid map only\n");
	ft_checkfiles(&sc, argv[1]);
	ft_parse(&sc);
	ft_checkmap(&sc);
	ft_loadgame(&sc);
	return (0);
}
