/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariusmeier <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:54:53 by mariusmeier       #+#    #+#             */
/*   Updated: 2024/03/11 12:54:57 by mariusmeier      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
    void    *mlx_ptr;
    void    *win_ptr;

    mlx_ptr = mlx_init();
    if (!mlx_ptr)
        return(ft_free_map(&mlx_ptr));
    win_ptr = mlx_new_window(mlx_ptr, 600, 400, "test!");
    if (!win_ptr)
        return(ft_free_map(&mlx_ptr));
    mlx_destroy_window(mlx_ptr, win_ptr);
    mlx_destroy_display(mlx_ptr);
    return (ft_free_map(&mlx_ptr));
}



// int	main(void)
// {
// 	int		fd;
// 	char	*map;

// 	fd = open("./maps/rectangular.ber", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	map = ft_read_map(fd);
// 	if (!map_is_ok(map))
// 		ft_putstr_fd("Error\n", 1);//return ()
// 	printf("%s", map);
// 	free(map);
// 	close(fd);
// 	return (0);
// }