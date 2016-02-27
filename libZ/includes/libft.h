/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdezitte <mdezitte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 18:37:43 by mressier          #+#    #+#             */
/*   Updated: 2016/02/27 12:23:14 by mdezitte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "get_next_line.h"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/*
**  	------------------------------------------------------
**  	|						MEMORY	         	         |
**  	------------------------------------------------------
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_malloc(size_t size);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memdup(const void *s, size_t n);
void				ft_memdel(void **ap);
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**  	------------------------------------------------------
**  	|					      NB	         	         |
**  	------------------------------------------------------
*/

int					ft_unsigned_len(unsigned long long int nb, size_t base);
int					ft_signed_len(long long int nb, size_t base);
void				ft_swap(int *a, int *b);

/*
**  	------------------------------------------------------
**  	|						STRING	         	         |
**  	------------------------------------------------------
*/

/*
**	Modifications
*/

char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(const char *dest, const char *src, size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
void				ft_strdel(char **as);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
char				**ft_strsplit(const char *s, char c);
void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));
char				*ft_strmap(const char *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strfjoin(char **s1, const char *s2);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strnfjoin(char **s1, const char *s2, size_t n);
char				*ft_strnjoin(const char *s1, const char *s2, size_t n);
char				*ft_strcfjoin(char **s1, const char *s2, char c);

/*
**	Research, ...
*/

int					ft_strclen(const char *s, int c);
size_t				ft_strlen(const char *s);
size_t				ft_strnlen(const char *s, size_t maxlen);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);

/*
**	Wchar & Wstr
*/

int					ft_wcharlen(wchar_t value);
wchar_t				*ft_wstrdup(const wchar_t *wstr);
size_t				ft_wstr_len(wchar_t	*wstr);

/*
**  	------------------------------------------------------
**  	|					  	  IS		       	         |
**  	------------------------------------------------------
*/

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(int c);
int					ft_is_sort_descend(int *tab, size_t size);
int					ft_is_sort_ascend(int *tab, size_t size);
int					ft_is_lower(int n1, int n2);
int					ft_is_higher(int n1, int n2);

/*
**  	------------------------------------------------------
**  	|					  CONVERSION	       	         |
**  	------------------------------------------------------
*/

char				*ft_itoa(int n);
int					ft_atoi(const char *nptr);
long long int		ft_atolli(const char *nptr);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_str_toupper(const char *str);
char				*ft_str_tolower(const char *str);
char				*ft_itoa_base(int nb, size_t base);
char				*ft_uitoa_base(unsigned int nb, size_t base);
char				*ft_llitoa_base(long long int nb, size_t base);
char				*ft_ullitoa_base(unsigned long long int nb, size_t base);
char				*ft_unctoa_base(unsigned char nb, size_t base);
char				*ft_unshrtoa_base(unsigned short nb, size_t base);

/*
**  	------------------------------------------------------
**  	|						ARRAY	         	         |
**  	------------------------------------------------------
*/

void				*ft_create_2d_tab(size_t size);
void				ft_rotate_down(int *tab, size_t size);
void				ft_rotate_up(int *tab, size_t size);
void				ft_go_up(int *tab, size_t size);
void				ft_go_down(int *tab, size_t size);
int					ft_find_the_lower(int *tab, size_t size);

/*
**  	------------------------------------------------------
**  	|						DISPLAY	         	         |
**  	------------------------------------------------------
*/

void				ft_putchar(char c);
void				ft_putnchar(size_t n, int c);
void				ft_putchar_fd(char c, int fd);

void				ft_putstr(const char *s);
void				ft_putnstr(const char *s, size_t n);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl(const char *s);
void				ft_putnstr_fd(const char *s, size_t n);
void				ft_putendl_fd(const char *s, int fd);

void				ft_putnbr(int nb);
void				ft_putnbrendl(int nb);
void				ft_putnbr_fd(int n, int fd);

void				ft_putwstr(const wchar_t *ws);
void				ft_putnwstr(const wchar_t *ws, int size);
int					ft_putwchar(wchar_t wc);

void				ft_puterror(const char *str);
void				ft_putstr_color(const char *color, const char *s);

/*
**  	------------------------------------------------------
**  	|						LST		         	         |
**  	------------------------------------------------------
*/

int					ft_lst_len(t_list *lst_ptr);
int					ft_lst_total_len(t_list *ptr_lst);

t_list				*ft_lst_new(void *data, size_t size);
t_list				*ft_lst_new_empty(void);

t_list				*ft_lst_add_after(t_list *lst_ptr, t_list *lst_to_add);
t_list				*ft_lst_add_before(t_list *lst_ptr, t_list *lst_to_add);
t_list				*ft_lst_add_start(t_list *ptr_lst, t_list *lst_to_add);
void				ft_lst_add_end(t_list *lst, t_list *lst_to_add);
t_list				*ft_lst_add_index(t_list *ptr_lst,
						t_list *lst_to_add, int index);

t_list				*ft_lst_get_last(t_list	*ptr);
t_list				*ft_lst_get_first(t_list *ptr);
t_list				*ft_lst_get_index(t_list *ptr_lst, int index);

t_list				*ft_lst_del(t_list **lst_to_del, void (*del)(void **));
t_list				*ft_lst_del_one(t_list **lst_to_del, void (*del)(void **));
t_list				*ft_lst_clr_one(t_list *lst, void (*clr)(void *));
t_list				*ft_lst_clr(t_list *lst, void (*clr)(void *));
void				ft_lst_clr_all(t_list *lst, void (*clr)(void *));

/*
**  	------------------------------------------------------
**  	|						ARGUMENTS         	         |
**  	------------------------------------------------------
*/

void				*get_void_arg(va_list start, size_t nb_arg);
char				*get_str_arg(va_list start, size_t nb);
wchar_t				*get_wstr_arg(va_list start, size_t nb);
long long int		get_lli_arg(va_list start, size_t nb_arg);
long int			get_li_arg(va_list start, size_t nb);
int					get_int_arg(va_list start, size_t nb);
char				get_char_arg(va_list start, size_t nb);
wchar_t				get_wchar_arg(va_list start, size_t nb);
short				get_short_arg(va_list start, size_t nb);

#endif
