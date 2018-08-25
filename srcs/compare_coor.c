/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_coor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vduong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 10:57:34 by vduong            #+#    #+#             */
/*   Updated: 2018/08/22 15:59:49 by vduong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

#define ABS(X)	(X > 0 ? X : -X)
#define PCONTENT piece.content[i][j]

int		round_sqrt(int n)
{
	int i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i * i == n ? i : (i - 1));

}

int		distance(int c1, int c2, int C1, int C2)
{
	//return (round_sqrt((c1 - C1) * (c1 - C1) + (c2 - C2) * (c2 - C2)));
	return (ABS(c1 - C1) + ABS(c2 - C2));
}

int		enemy_distance(t_map map, t_piece piece, int **en_c, int *c)
{
	int	n;
	int i;
	int j;
	int	dist;
	int tmp;

	n = 1;
	dist = -1;
	while (n < en_c[0][0] + 1)
	{
				i = 0;
		while (i < piece.height)
		{
			j = 0;
			while (j < piece.width)
			{
				if (PCONTENT == '*' && map.content[c[0] + i][c[1] + j] == '.')
				{
					tmp = distance(en_c[n][0], en_c[n][1], c[0] + i, c[1] + j);
					//printf("en_coor = %d, %d\n", en_c[n][0], en_c[n][1]);
					//printf("my_coor = %d, %d\n", c[0] + i, c[1] + j);
					//printf("test_coor = %d, %d\n", c[0], c[1]);
					//printf("tmp = %d\n", tmp);
					dist = tmp < dist || dist == -1 ? tmp : dist;
					//printf("dist = %d\n", dist);
				}
				j++;
			}
			i++;
		}
		n++;
	}
	//printf("test_coor = %d, %d\n", c[0], c[1]);
	//printf("dist = %d\n\n", dist);
	return (dist);
}

int		compare_coor(t_map map, t_piece piece, int **en_c, int *c1, int *c2)
{
	return (enemy_distance(map, piece, en_c, c1) > enemy_distance(map, piece, en_c, c2));
}
