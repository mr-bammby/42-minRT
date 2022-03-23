/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbanfi <dbanfi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:53:13 by dbanfi            #+#    #+#             */
/*   Updated: 2022/03/12 01:28:59 by dbanfi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECTOR_H
# define LIBVECTOR_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define FT_FIXED_FRAC_BITS 30

typedef long long		t_fixed;

typedef struct s_norm_vector
{
	t_fixed	x;
	t_fixed	y;
	t_fixed	z;
}			t_norm_vector;

typedef t_norm_vector	t_point;

typedef struct s_vec
{
	t_norm_vector	n_vec;
	t_fixed			size;
}			t_vec;

typedef struct s_ray
{
	t_point	source;
	t_vec	direction;
}				t_ray;

typedef struct s_sphere
{
	t_point		coord;
	t_fixed		diameter;
}			t_sphere;

typedef struct s_plane
{
	t_point		coord;
	t_vec		dir_vector;
}			t_plane;

typedef struct s_cylinder
{
	t_point		coord;
	t_vec		dir_vector;
	t_fixed		diameter;
	t_fixed		height;
}			t_cylinder;

t_fixed	ltofx(long in);
t_fixed	dtofx(double in);
long	fxtol(t_fixed in);
double	fxtod(t_fixed in);

t_vec	ft_creat_vec(t_fixed x, t_fixed y, t_fixed z);
t_vec	ft_create_vec_from_points(t_point start, t_point end, t_fixed size);
t_vec	ft_add_vec(t_vec vec1, t_vec vec2);
t_vec	ft_sub_vec(t_vec vec1, t_vec vec2);
t_fixed	ft_scalar_prod(t_vec vec1, t_vec vec2);
t_vec	ft_cross_prod_vec(t_vec vec1, t_vec vec2);

int		ft_quadratic_solver(t_fixed a, t_fixed b, t_fixed c, t_fixed result[2]);

t_ray	ft_create_ray(t_point source, t_point point);
t_fixed	ft_points_dist(t_point a, t_point b);
t_point	ft_point_on_ray(t_ray ray, t_fixed distance);

t_fixed	ft_parallel_line_dist(t_point point1, t_point point2, t_vec dir_vec);
t_vec	ft_rev_vec(t_vec vec);
t_plane	ft_create_plane(t_point point, t_norm_vector n_vec);

#endif