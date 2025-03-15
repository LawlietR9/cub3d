#include "../inc/cub3d.h"

t_game  *init_game(t_game *game, int fd)
{
    if (fd < 0)
        end_game(game, EXIT_FAILURE, "File not found.");
    game->mlx = mlx_init();
    if (!game->mlx)
        end_game(game, EXIT_FAILURE, "mlx_init() failed.");
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3d");
    if (!game->win)
        end_game(game, EXIT_FAILURE, "mlx_new_window() failed.");
    game->img = (t_img *)malloc(sizeof(t_img));
    if (init_map(game, fd))
        end_game(game, EXIT_FAILURE, "Invalid Map.");
    print_map(game->map);
    close(fd);
    return (game);
}

int	main(int argc, char **argv)
{
    if (argc != 2 || !ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
        end_game(NULL, EXIT_FAILURE, "Invalid Arguments.");
    t_game *game = (t_game *)malloc(sizeof(t_game));
    if (!game)
        end_game(game, EXIT_FAILURE, "Failed to allocate memory.");
    game = init_game(game, open(argv[1], O_RDONLY));
    mlx_hook(game->win, 17, 0, close_window, (void *)game);
    // mlx_key_hook(game->win, key_hook, (void *)game);
    // mlx_loop_hook(game->mlx, update, (void *)game);
    mlx_loop(game->mlx);
}