#include "../inc/cub3d.h"

int	check_map(t_game *game)
{
    int len;
    game->width = 0;
    game->height = 0;
    while (game->map[game->height])
    {
        len = (int)ft_strlen(game->map[game->height]);
        if (len > game->width)
            game->width = len;
        game->height++;
    }
    if (check_map_char(game))
        return (1);
    if (check_wall(game))
        return (1);
    return (0);
}

int	check_map_char(t_game *game)
{
    char    valid[7] = {'1', '0', 'N', 'W', 'E', 'S', ' '};
    int	    i;
    int	    j;

    i = 0;
    while (i < game->height)
    {
        j = 0;
        while (game->map[i][j])
        {
            if (!ft_strchr(valid, game->map[i][j]) && printf("Invalid character in map: %c\n", game->map[i][j]))
                return (1);
            j++;
        }
        i++;
    }
    if (count_char(game->map, 'N') + count_char(game->map, 'W')
        + count_char(game->map, 'E') + count_char(game->map, 'S') != 1)
    {
        return (1);
    }
    return (0);
}

int	check_wall(t_game *game)
{
    int	i;
    int	j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (i == 0 || i == game->height - 1 || j == 0
                || j == game->width - 1)
            {
                if (game->map[i][j] != '1' && game->map[i][j] != ' ')
                    return (printf("i = %d, j = %d\n", i, j));
            }
            else if (game->map[i][j] != '1' && game->map[i][j] != ' ')
            {
                if (game->map[i + 1][j] == ' ' || game->map[i][j + 1] == ' '
                    || game->map[i - 1][j] == ' ' || game->map[i][j - 1] == ' ')
                    return (printf("i = %d, j = %d\n", i, j));
            }
            j++;
        }
        i++;
    }
    return (0);
}


int	count_char(char **map, char c)
{
    int	num;
    int	i;
    int	j;

    i = 0;
    num = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == c)
                num++;
            j++;
        }
        i++;
    }
    return (num);
}