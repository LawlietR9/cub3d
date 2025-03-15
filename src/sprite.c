# include "../inc/cub3d.h"

void *xpm_alpha(t_game *game, char *file_path)
{
    int width, height, bpp, size_l, endian;
    void *img = mlx_xpm_file_to_image(game->mlx, file_path, &width, &height);
    if (!img && printf("File %s does not exist\n", file_path))
        end_game(game, EXIT_FAILURE, "mlx_xpm_file_to_image() failed.");
    int *data = (int *)mlx_get_data_addr(img, &bpp, &size_l, &endian);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (data[y * width + x] == 0x000000)
                data[y * width + x] = 0xFF000000;
        }
    }
    return (img);
}