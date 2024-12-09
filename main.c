#include <mlx.h>
#include <stdio.h>
int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Tamazirt");
	//mlx_loop(mlx);
}
