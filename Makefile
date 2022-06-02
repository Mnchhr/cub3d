# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkuehl <mkuehl@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/31 16:35:38 by mkuehl            #+#    #+#              #
#    Updated: 2022/05/31 16:42:51 by mkuehl           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= cub3d

HEADER		= inc/cub3d.h

# HEADER_BONUS = inc/cub3d_bonus.h

SRCS		= srcs/main.c

# SRCS_BONUS	= srcs_bonus/main_bonus.c

OBJS		= $(SRCS:%.c=%.o)

# OBJS_BONUS	= $(SRCS_BONUS:%.c=%.o)

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

MINILIBX	= -L mlx -lmlx -framework OpenGL -framework AppKit

LIBFT_LIB	= ./libft/libft.a

.PHONY: 	all clean fclean re bonus re_bonus

all: 		$(NAME)
			@ make -C ./libft

$(NAME):	$(OBJS) $(HEADER)
			make -C ./libft
			make -s -C ./mlx
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MINILIBX) -o $(NAME)

%.o:		%.c $(HEADER) $(HEADER_BONUS)
			$(CC) $(CFLAGS) -c $< -o $@

clean:		
			rm -f $(OBJS) $(OBJS_BONUS)
			make clean -C ./libft
			make clean -C ./mlx

fclean: 	clean
			rm -f $(NAME)
			make fclean -C ./libft

re:			fclean all
			make re -C ./libft
			make re -C ./mlx

# bonus:		$(OBJS_BONUS) $(HEADER_BONUS)
# 			make -C ./libft
# 			make -s -C ./mlx
# 			$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_LIB) $(MINILIBX) -o $(NAME)

# re_bonus:	fclean bonus
# 			make re -C ./libft
# 			make re -C ./mlx
