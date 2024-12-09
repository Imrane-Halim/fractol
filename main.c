#include <mlx.h>
#include <stdio.h>

#define WIDTH 	1920
#define HEIGHT	1080

typedef struct img_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_lenght;
	int		endian;
}	img_data;

void	put_pixel(img_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int get_color(int og)
{
	int r, g, b;
	int res = 0;
	r = (og >> 16) & 0xff;
	g = (og >> 8) & 0xff;
	b = (og >> 0) & 0xff;

	if (r == 255 && g != 255)
		g++;
	

	res = (r << 16) | (g << 8) | b;
	return res;
}
int	main(void)
{
	void		*mlx, *mlx_win;
	int			color = 0;
	img_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "tamazirt");
	
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_lenght, &img.endian);
	for (int i = 0; i < HEIGHT; i ++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			put_pixel(&img, j, i, get_color(color));
		}
	}
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
