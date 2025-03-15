# include "../inc/cub3d.h"

int end_game(t_game *game, int status, char *message)
{
    if (status)
    {
        printf("Error\n");
        if (message)
            printf("%s\n", message);
    }
    else if (message)
        printf("%s\n", message);
    if (game)
    {
        if (game->map)
            free_map(game->map);
        if (game->win)
            mlx_destroy_window(game->mlx, game->win);
        if (game->mlx)
            free(game->mlx);
        free(game);
    }
    exit(status);
}

int close_window(t_game *game)
{
    end_game(game, EXIT_SUCCESS, NULL);
    return (0);
}
