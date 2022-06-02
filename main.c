/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:36:19 by mkuehl            #+#    #+#             */
/*   Updated: 2022/06/02 15:45:18 by mkuehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	*cub;

	ft_check_input(argc, argv);
	cub = ft_init_vars();
	ft_parse_map(cub, argv[1]);
	return (0);
}

int	ft_check_input(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		ft_strerror(MALLOC_ERR);
	if (ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub\0"))
		ft_strerror(EXT_ERR);
	fd = open(argv[1], 'r');
	if (fd < 0)
		ft_strerror(FD_ERR);
	close(fd);
	return (0);
}

t_cub	*ft_init_vars(void)
{
	t_cub *temp;

	temp = (t_cub *)malloc(sizeof(t_cub));
	if (!temp)
		ft_strerror(MALLOC_ERR);
	temp->lines_count = 0;
	temp->columns_count = 0;
	return (temp);
}

void	ft_parse_map(t_cub *cub, char *filename)
{
	int	fd;
	int	i;

	fd = open(filename, O_RDONLY);
	while (get_next_line(fd))
		cub->lines_count++;
	printf("%d - lines count\n", cub->lines_count);
	cub->map = (char **)malloc(sizeof(char *) * cub->lines_count + 1);
	i = -1;
	cub->map[++i] = get_next_line(fd);
	while (cub->map[i])
		cub->map[++i] = get_next_line(fd);
	close(fd);
	cub->map[cub->lines_count] = NULL;
	i = 0;
	while (cub->map[i++])
		printf("%s", cub->map[i]);
}

void	ft_strerror(int error)
{
	if (error == MALLOC_ERR)
		printf("Error: Malloc error\n");
	else if (error == ARG_ERR)
		printf("Error: Invalid number of arguments\n");
	else if (error == EXT_ERR)
		printf("Error: Input file's extension must be '.cub'\n");
	else if (error == FD_ERR)
		printf("Error: Couldn't open/read input file or permission is denied\n");
	else if (error == MLX_ERR)
		printf("Error: Mlx library error\n");
	exit(1);
}