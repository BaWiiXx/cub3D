/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdany <bdany@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:51:00 by egomez            #+#    #+#             */
/*   Updated: 2024/10/24 11:29:32 by bdany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

uint32_t	get_color_rgba(int r, int g, int b, int a)
{
	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	if (b > 255)
		b = 255;
	return (r << 24 | g << 16 | b << 8 | a);
}

void	draw_ceiling_floor(t_game *game, int draw_start,
						int draw_end, uint32_t color)
{
	int	y;

	y = draw_start;
	while (y < draw_end)
	{
		mlx_put_pixel(game->map.img, game->x, y, color);
		y++;
	}
}

void	start_game(t_game *game)
{
	if (mlx_image_to_window(game->map.mlx, game->map.img, 0, 0) < 0)
		return ;
	raycasting(game);
}

// void	draw_textures(t_game *game)
// {
// 	uint32_t	coord;
// 	int			num;
// 	uint8_t		*pix;
// 	size_t		max_size;

// 	game->texture.tex_y = (int)game->texture.tex_pos & (T_H - 1);
// 	coord = (T_W * game->texture.tex_y + (T_W - game->texture.tex_x)) * 4;
// 	game->texture.tex_pos += game->texture.step;
// 	if (game->ray.side == 0)
// 	{
// 		if (game->player.x - game->ray.map_x < 0)
// 			num = 3;
// 		else
// 			num = 2;
// 	}
// 	else
// 	{
// 		if (game->player.y - game->ray.map_y < 0)
// 			num = 0;
// 		else
// 			num = 1;
// 	}
// 	max_size = game->texture.texture[num]->width \
// 	* game->texture.texture[num]->height * 4;
// 	pix = game->texture.texture[num]->pixels;
// 	if (coord < max_size)
// 		game->texture.color = get_color_rgba(pix[coord], pix[coord + 1],
// 				pix[coord + 2], pix[coord + 3]);
// 	mlx_put_pixel(game->map.img, game->x, game->y, game->texture.color);
// }

static int	select_texture(t_game *game)
{
	if (game->ray.side == 0)
	{
		if (game->player.x - game->ray.map_x < 0)
			return (3);
		else
			return (2);
	}
	else
	{
		if (game->player.y - game->ray.map_y < 0)
			return (0);
		else
			return (1);
	}
}

void	draw_textures(t_game *game)
{
	uint32_t	coord;
	int			num;
	uint8_t		*pix;
	size_t		max_size;

	game->texture.tex_y = (int)game->texture.tex_pos & (T_H - 1);
	coord = (T_W * game->texture.tex_y + (T_W - game->texture.tex_x)) * 4;
	game->texture.tex_pos += game->texture.step;
	num = select_texture(game);
	max_size = game->texture.texture[num]->width \
	* game->texture.texture[num]->height * 4;
	pix = game->texture.texture[num]->pixels;
	if (coord < max_size)
		game->texture.color = get_color_rgba(pix[coord], pix[coord + 1],
				pix[coord + 2], pix[coord + 3]);
	mlx_put_pixel(game->map.img, game->x, game->y, game->texture.color);
}
