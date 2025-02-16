/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:33:28 by kenito            #+#    #+#             */
/*   Updated: 2023/12/19 22:33:28 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define WIDTH 1920
# define HEIGHT 1080

enum e_keycode
{
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363,
	RESET = 15,
	ESC = 65307
};

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
}	t_game;

int		end_game(t_game *game, int status, char *message);
int		init_game(t_game *game, int fd);
int		init_map(t_game *game, int fd);
int		check_map(t_game *game);
int		check_map_char(t_game *game);
int		check_wall(t_game *game);
char	*remove_char(char *str, char c);
int		free_map(char **map);

#endif