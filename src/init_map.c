/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenito <kenito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:31:04 by kenito            #+#    #+#             */
/*   Updated: 2023/12/19 22:31:04 by kenito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	parse_texture(t_game *game, char *line)
{
    char *path;

    if (line[0] == '\n')
        return (1);
    if (ft_strnstr(line, "NO ", 3) || ft_strnstr(line, "SO ", 3)
        || ft_strnstr(line, "WE ", 3) || ft_strnstr(line, "EA ", 3))
        path = ft_strtrim(line + 3, "\n");
    else if (ft_strnstr(line, "F ", 2) || ft_strnstr(line, "C ", 2))
        path = ft_strtrim(line + 2, "\n");
    else
        return (0);
    if (!path)
        end_game(game, EXIT_FAILURE, "Failed to allocate memory.");
    if (ft_strnstr(line, "NO ", 3))
        game->img->north = xpm_alpha(game, path);
    else if (ft_strnstr(line, "SO ", 3))
        game->img->south = xpm_alpha(game, path);
    else if (ft_strnstr(line, "WE ", 3))
        game->img->west = xpm_alpha(game, path);
    else if (ft_strnstr(line, "EA ", 3))
        game->img->east = xpm_alpha(game, path);
    // printf("path: %s\n", path);
    return (1);
}

int	init_map(t_game *game, int fd)
{
    char *line;
    char *new_line;

    line = get_next_line(fd);
    while (line && parse_texture(game, line))
    {
        free(line);
        line = get_next_line(fd);
    }
    if (!line)
        end_game(game, EXIT_FAILURE, "Cannot read map.");
    while ((new_line = get_next_line(fd)))
    {
        line = join_n_free(line, new_line);
        free(new_line);
        if (!line)
            end_game(game, EXIT_FAILURE, "Failed to allocate memory.");
    }
    line = remove_char(line, '\r');
    game->map = ft_split(line, '\n');
    free(line);
    return (check_map(game));
}

char	*remove_char(char *str, char c)
{
	int (i) = 0;
	int (j) = 0;
	while (str[i])
		if (str[i++] != c)
			j++;
	char *(new_str) = (char *)malloc(sizeof(char) * (j + 1));
	if (!new_str)
		end_game(NULL, EXIT_FAILURE, "Failed to allocate memory.");
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

int	free_map(char **map)
{
	int (i) = 0;
	while (map[i])
		free(map[i++]);
	free(map);
	return (0);
}

int	print_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			printf("%c", map[i][j]);
		printf("\n");
	}
	return (0);
}
