/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:06:10 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 14:09:31 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <stdlib.h>

typedef struct	s_print
{
	char		*s;
	int			pos;
	int			size;
	va_list		ap;
	int			w;
	int			p;
	int			min;
	int			plus;
	int			space;
	int			r;
	int			l;
	int			h;
	int			j;
	int			z;
	int			xo;
	int			end;
	int			wtf;
	int			sharp;
	int			zero;
}				t_print;

int				ft_printf(const char *str, ...);
int				ft_argfound(t_print **sprt);
int				putnbrf(t_print **sprt);
int				puthnbrf(t_print **sprt);
int				putunbrf(t_print **sprt);
int				putlnbrf(t_print **sprt);
int				putlunbrf(t_print **sprt);
int				putptrf(t_print **sprt);
int				putstrf(t_print **sprt);
int				putcharf(t_print **sprt);
int				putmajcharf(t_print **sprt);
int				putmajf(t_print **sprt);
int				putxoitoa(t_print **sprt);
int				putxoitoalu(t_print **sprt);
int				putxoitoallu(t_print **sprt);
int				putxoitoaumax(t_print **sprt);
int				ft_putoptions(t_print **sprt);
char			*ft_sharp(t_print **sprt, char *str);
int				ft_error(t_print **sprt);
int				ft_sort(char c);
int				ft_width(t_print **sprt);
int				ft_precision(t_print **sprt);
char			*ft_putwidth(t_print **sprt, char *str);
char			*ft_putprecision(t_print **sprt, char *str);
t_print			*ft_newstruc(const char *str);
int				ft_backtozero(t_print **sprt, int c);
int				ft_optsharp(t_print **sprt);
int				ft_optmin(t_print **sprt);
int				ft_optplus(t_print **sprt);
int				ft_optspace(t_print **sprt);
char			*ft_flag(t_print **sprt, long long int nbr, char *str);
int				ft_mod(t_print **sprt);
int				puthxoitoa(t_print **sprt);
int				puthhxoitoa(t_print **sprt);
int				putllnbrf(t_print **sprt);
int				putllunbrf(t_print **sprt);
int				putmaxnbrf(t_print **sprt);
int				putumaxnbrf(t_print **sprt);
int				ft_putwchar(wint_t nb);
int				ft_putwstr(wint_t *str);
wint_t			*ft_putspecwidth(t_print **sprt, wint_t *str);
wint_t			*ft_strwcat(wint_t *s1, wint_t *s2, int size);
wint_t			*ft_strwdup(wint_t *s1);
wint_t			*ft_strwnew(int size);
int				ft_strwlen(wint_t *s, int t);
char			*minandwidth(char *nbr, t_print **sprt);
int				ft_nonvalid(t_print **sprt);
wint_t			*ft_strwncpy(wint_t *dst, wint_t *src, size_t n);
wint_t			*ft_putspecprecision(t_print **sprt, wint_t *str);
int				speccharsize(wint_t c);
int				ft_nullprecision(t_print **sprt);
int				ft_wii(char c);
int				ft_ifw(t_print **sprt, char c, int t);
int				endofprint(t_print **sprt);
int				ft_truedirection(t_print **sprt);
void			ft_optwidth(t_print **sprt, int t, int i, char c);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putnbr(int long n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *restrict dst, const char *restrict src);
char			*ft_strncpy(char *restrict dst, const char *restrict src,\
				size_t n);
char			*ft_strcat(char *restrict s1, const char *restrict s2);
int				ft_atoi(const char *str);
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_itoa(int n);
char			*ft_uitoa(unsigned int n);
char			*ft_litoa(long int n);
char			*ft_llitoa(long long int n);
char			*ft_itoamax(intmax_t n);
char			*ft_luitoa(long unsigned int n);
char			*ft_lluitoa(long long unsigned int n);
char			*ft_itoabase(unsigned int n, unsigned int base);
char			*ft_itoabaselu(long unsigned int n, long unsigned int base);
char			*ft_itoabasellu(long long unsigned int n,\
					long long unsigned int base);
char			*ft_itoabaseumax(uintmax_t n, uintmax_t base);
char			*ft_mintomaj(char *str);
int				ft_btoi(char *nbr);
char			*ft_itoabaseshort(char n, int base);
char			*sharpandwidth(char *nbr);
void			ft_strdel(char **as);
void			ft_memdel(void **ap);
int				sizeinit(char *s, t_print **sprt);
int				endofptrf(char *str, int size, char *s);
char			*freeandret(char *tofree1, char *tofree2, char *toret);

#endif
