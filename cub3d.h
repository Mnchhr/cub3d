/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:36:58 by mkuehl            #+#    #+#             */
/*   Updated: 2022/06/02 15:31:40 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include "../libft/libft.h"

# define MALLOC_ERR 1
# define ARG_ERR 2
# define FD_ERR 3
# define MLX_ERR -1
# define EXT_ERR -2

typedef struct s_cub
{
	void	*mlx;
	void	*win;
	void	*south_wall;
	void	*north_wall;
	void	*east_wall;
	void	*west_wall;
	int		ceiling_color;
	int		floor_color;
	char	**map;
	int		lines_count;
	int		columns_count;
}	t_cub;

int		ft_check_input(int argc, char **argv);
void	ft_parse_map(t_cub *cub, char *filename);
void	ft_strerror(int error);
t_cub	*ft_init_vars(void);

#endif