/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:17:24 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/25 13:47:16 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include "mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_parse
{
	int				*line;
	int				*prox;
	int				*proy;
	int				cn;
	int				fac;
	struct s_parse	*next;
}					t_parse;

typedef struct		s_seg
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				dx;
	int				dy;
	int				dp;
	int				de;
	int				dne;
	int				cas;
}					t_seg;

typedef struct		s_env
{
	int				winx;
	int				winy;
	void			*mlx;
	void			*win;
	t_seg			*seg;
	t_parse			*map;
	unsigned int	color;
	int				fac;
	int				bx;
	int				by;
	int				y;
	float			om;
	float			al;
	int				ctr[4];
}					t_env;

t_env				*ft_struct_init(int winx, int winy, char *winname);
void				ft_outfdf(int nb, t_env *env);
t_env				*ft_clearenv(t_env *env);
int					ft_key_hook(int keycode, t_env *env);
int					ft_mouse_hook(int button, int mx, int my, t_env *env);
int					ft_drawseg(t_env *env);
t_env				*ft_firstseg(t_env *env);
t_env				*ft_secondseg(t_env *env);
t_env				*ft_firstdrawing(t_env *env);
t_env				*ft_seconddrawing(t_env *env);
int					ft_open_file(char *s);
int					ft_check_line(char *str, int nc, t_env *env);
int					*ft_add_tab(char *str, int nc, int *tab);
t_env				*ft_parsing(t_env *env, char *s);
t_parse				*ft_lstnew(int i, t_env *env);
void				ft_lstadd(t_parse **begin, t_parse *new);
void				ft_lstprint(t_parse *lst, int nc);
t_parse				*ft_clearmap(t_env *env);
t_env				*ft_proj_ortho(t_env *env);
t_parse				*ft_operations(t_env *env, t_parse *tmp, int y);
void				ft_single_proj(t_env *env, t_parse *tmp1, int nc);
void				ft_proj_print(t_env *env, \
						t_parse *tmp1, t_parse *tmp2, int nc);
t_seg				*ft_seg_init(int x0, int y0, int x1, int y1);
t_parse				*ft_lstrealloc(t_env *env, t_parse *tmp);
t_env				*ft_keycode(int key, t_env *env);
t_env				*ft_rotate(int key, t_env *env);
t_env				*ft_color(int k, t_env *env);
t_env				*ft_centring(t_env *env);
t_parse				*ft_op_ctr(t_env *env, t_parse *tmp, int y);
t_env				*ft_cmp_ctr(t_env *env, int x, int y);
t_env				*ft_fin_ctr(t_env *env);

#endif
