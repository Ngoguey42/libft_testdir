/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:21:13 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/19 13:30:13 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>
# include <ctype.h>
# include "libft.h"

/* void ft_putchar(char c); */
/* void ft_putstr(const char *s); */
void    ft_myassert(int relation);
int ref_myputnchar(char *str, int num);
void	ref_myassert(int relation);

#define ABS(ARG) (ARG < 0 ? -ARG : ARG)

typedef unsigned int t_ui32;

# define TEST_PART_N 1 //change part
# if TEST_PART_N == 1 // Partie Obligatoire

// ft_atoi.c
// ft_bzero.c
// ft_isalnum.c
// ft_isalpha.c
// ft_isascii.c
// ft_isdigit.c
// ft_isprint.c
// ft_memccpy.c
// ft_memchr.c
// ft_memcmp.c
// ft_memcpy.c
// ft_memmove.c
// ft_memset.c
// ft_strcat.c
// ft_strchr.c
// ft_strcmp.c
// ft_strcpy.c
// ft_strdup.c
// ft_strlcat.c
// ft_strlen.c
// ft_strncat.c
// ft_strncmp.c
// ft_strncpy.c
// ft_strnstr.c
// ft_strrchr.c
// ft_strstr.c
// ft_tolower.c
// ft_toupper.c



 # define TEST_ATOI
 # define TEST_BZERO
 # define TEST_ISALNUM
 # define TEST_ISALPHA
 # define TEST_ISASCII
 # define TEST_ISDIGIT
 # define TEST_ISPRINT
 # define TEST_MEMCCPY
 # define TEST_MEMCHR
 # define TEST_MEMCMP
 # define TEST_MEMCPY
 # define TEST_MEMMOVE
 # define TEST_MEMSET
/*  # define TEST_STRCAT */
/*  # define TEST_STRCHR */
/*  # define TEST_STRCMP */
/*  # define TEST_STRCPY */
/*  # define TEST_STRDUP */
/*  # define TEST_STRLCAT */
/*  # define TEST_STRLEN */
/*  # define TEST_STRNCAT */
/*  # define TEST_STRNCMP */
/*  # define TEST_STRNCPY */
/*  # define TEST_STRNSTR */
/*  # define TEST_STRRCHR */
/*  # define TEST_STRSTR */
/*  # define TEST_TOLOWER */
/*  # define TEST_TOUPPER */

void try_atoi(void);
void try_bzero(void);
void try_isalnum(void);
void try_isalpha(void);
void try_isascii(void);
void try_isdigit(void);
void try_isprint(void);
void try_memccpy(void);
void try_memchr(void);
void try_memcmp(void);
void try_memcpy(void);
void try_memmove(void);
void try_memset(void);
void try_strcat(void);
void try_strchr(void);
void try_strcmp(void);
void try_strcpy(void);
void try_strdup(void);
void try_strlcat(void);
void try_strlen(void);
void try_strncat(void);
void try_strncmp(void);
void try_strncpy(void);
void try_strnstr(void);
void try_strrchr(void);
void try_strstr(void);
void try_tolower(void);
void try_toupper(void);

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void	*ft_memchr(const void *ptr, int value, size_t num);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num);
void	*ft_memcpy(void *destination, const void *source, size_t num);
void	*ft_memmove(void *destination, const void *source, size_t num);
void	*ft_memset(void *ptr, int value, size_t num);
char	*ft_strcat(char *destination, const char *source);
char	*ft_strchr(const char *str, int character);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strcpy(char *destination, const char *source);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strncat(char *destination, const char *source, size_t num);
int		ft_strncmp(const char *str1, const char *str2, size_t num);
char	*ft_strncpy(char *destination, const char *source, size_t num);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *str, int c);
char	*ft_strstr(const char *str1, const char *str2);
int		ft_tolower(int c);
int		ft_toupper(int c);

# endif

# if TEST_PART_N == 2 // Partie Supplementaire

// ft_itoa.c
// ft_memalloc.c
// ft_memdel.c
// ft_putchar.c
// ft_putchar_fd.c
// ft_putendl.c
// ft_putendl_fd.c
// ft_putnbr.c
// ft_putnbr_fd.c
// ft_putstr.c
// ft_putstr_fd.c
// ft_strclr.c
// ft_strdel.c
// ft_strequ.c
// ft_striter.c
// ft_striteri.c
// ft_strjoin.c
// ft_strmap.c
// ft_strmapi.c
// ft_strnequ.c
// ft_strnew.c
// ft_strsplit.c
// ft_strsub.c
// ft_strtrim.c

# define TEST_ITOA
# define TEST_MEMALLOC
# define TEST_MEMDEL
# define TEST_PUTCHAR
# define TEST_PUTCHAR_FD
# define TEST_PUTENDL
# define TEST_PUTENDL_FD
# define TEST_PUTNBR
# define TEST_PUTNBR_FD
# define TEST_PUTSTR
# define TEST_PUTSTR_FD
# define TEST_STRCLR
# define TEST_STRDEL
# define TEST_STREQU
# define TEST_STRJOIN
# define TEST_STRNEQU
# define TEST_STRNEW
# define TEST_STRSPLIT
# define TEST_STRSUB
# define TEST_STRTRIM

/* # define TEST_STRITER */
/* # define TEST_STRITERI */
/* # define TEST_STRMAP */
/* # define TEST_STRMAPI */


void try_itoa(void);
void try_memalloc(void);
void try_memdel(void);
void try_putchar(void);
void try_putchar_fd(void);
void try_putendl(void);
void try_putendl_fd(void);
void try_putnbr(void);
void try_putnbr_fd(void);
void try_putstr(void);
void try_putstr_fd(void);
void try_strclr(void);
void try_strdel(void);
void try_strequ(void);
void try_striter(void);
void try_striteri(void);
void try_strjoin(void);
void try_strmap(void);
void try_strmapi(void);
void try_strnequ(void);
void try_strnew(void);
void try_strsplit(void);
void try_strsub(void);
void try_strtrim(void);


char	*ft_itoa(int n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(const char *s);
void	ft_putendl_fd(const char *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	ft_strclr(char *s);
void	ft_strdel(char **as);
int		ft_strequ(const char *s1, const char *s2);
void	ft_striter(char *s, void(*f)(char*));
void	ft_striteri(char *s, void(*f)(t_ui32, char*));
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strmap(const char *s, char(*f)(char));
char	*ft_strmapi(const char *s, char(*f)(t_ui32, char));
int		ft_strnequ(const char *s1, const char *s2,size_t n);
char	*ft_strnew(size_t size);
char	**ft_strsplit(const char *s, char c);
char	*ft_strsub(const char *s, t_ui32 start, size_t len);
char	*ft_strtrim(const char *s);


# endif

# if TEST_PART_N == 3 // Partie Bonus

// ft_lstpush.c
// ft_lstdel.c
// ft_lstdelone.c
// ft_lstiter.c
// ft_lstmap.c
// ft_lstnew.c

# define TEST_lstpush
# define TEST_LSTDEL
# define TEST_LSTDELONE
# define TEST_LSTITER
# define TEST_LSTMAP
# define TEST_LSTNEW

// typedef struct 	s_list
// {
// void*			data;
// struct s_list	next;
// }				t_list;

void	ft_lstadd(t_list **alst, t_list *new);
void	ft_lstdel(t_list **alst, void(*del)(void *,size_t));
void	ft_lstdelone(t_list **alst, void(*del)(void*, size_t));
void	ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list	*ft_lstnew(void const *content, size_t content_size);

# endif




#endif
