/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasalced </var/mail/lasalced>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 15:28:20 by lasalced          #+#    #+#             */
/*   Updated: 2015/03/24 16:10:23 by lasalced         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;

void	draw(void *mlx, void *win)
{
	int	x;
	int	y;

	y = 100;
	while (y < 200)
	{
		x = 100;
		while (x < 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

int		expose_hook(t_env *e)
{
	draw(e->mlx, e->win);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
	printf("key : %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		main()
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "42");
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
