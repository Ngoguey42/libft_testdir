/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:29:25 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 10:07:31 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		main(void)
{
// char	lol[] = "salut lol vous allez bien ici les noobs ? \n \0";
// char	lol[] = "salut lol vous allez bien ici les noobs ? \n \0";

// t_list	**alst;
// t_list	*tmp;

// alst = (t_list**)malloc(sizeof(t_list*) * 1);

// t_list	*ft_lstnewfront(t_list **alst,
			// void const *content, size_t content_size);
// t_list	*ft_lstnewback(t_list **alst,
			// void const *content, size_t content_size);
// t_list	*ft_lstnewprev(t_list **alst, t_list *lst,
			// void const *content, size_t content_size);
// t_list	*ft_lstnewnext(t_list **alst, t_list *lst,
			// void const *content, size_t content_size);
// void	ft_lstpushfront(t_list **alst, t_list *new);
// void	ft_lstpushback(t_list **alst, t_list *new);
// void	ft_lstpushprev(t_list **alst, t_list *lst, t_list *new);
// void	ft_lstpushnext(t_list **alst, t_list *lst, t_list *new);
// t_list	*ft_lstpullfirst(t_list** alst);
// t_list	*ft_lstpulllast(t_list** alst);
// t_list	*ft_lstpullprev(t_list** alst, t_list *lst);
// t_list	*ft_lstpullcur(t_list** alst, t_list *lst);
// t_list	*ft_lstpullnext(t_list *lst);


// *alst = ft_lstnew("1ere", 5);
// (*alst)->next = ft_lstnew("2eme", 5);
// ft_lstnewback(alst, "1ere", 5);
// ft_lstnewback(alst, "2eme", 5);
// ft_lstnewback(alst, "3eme", 5);
// ft_lstnewback(alst, "4eme", 5);
// ft_lstnewback(alst, "5eme", 5);
// ft_lstnewback(alst, "6eme", 5);
// ft_lstnewback(alst, "4eme", 5);
// ft_lstnewprev(alst, ft_lstat(*alst, 3), "5eme", 5);
// ft_lstnewnext(alst, ft_lstat(*alst, 5), "6eme", 5);

// ft_lstpulllast(alst);
// printf("lol%p^lol\n", ft_lstpullfirst(alst));
;
// ft_lstpullcur(alst, *alst);
// ft_lstpushfront(alst, ft_lstpulllast(alst));


// ft_lstprnt(*alst);
// ft_memprint(lol, 17);
// (void)tmp;
// exit(0);
#if TEST_PART_N == 1

# ifdef TEST_ATOI
try_atoi();
# endif
# ifdef TEST_BZERO
try_bzero();
# endif
# ifdef TEST_ISALNUM
try_isalnum();
# endif
# ifdef TEST_ISALPHA
try_isalpha();
# endif
# ifdef TEST_ISASCII
try_isascii();
# endif
# ifdef TEST_ISDIGIT
try_isdigit();
# endif
# ifdef TEST_ISPRINT
try_isprint();
# endif
# ifdef TEST_MEMCCPY
try_memccpy();
# endif
# ifdef TEST_MEMCHR
try_memchr();
# endif
# ifdef TEST_MEMCMP
try_memcmp();
# endif
# ifdef TEST_MEMCPY
try_memcpy();
# endif
# ifdef TEST_MEMMOVE
try_memmove();
# endif
# ifdef TEST_MEMSET
try_memset();
# endif
# ifdef TEST_STRCAT
try_strcat();
# endif
# ifdef TEST_STRCHR
try_strchr();
# endif
# ifdef TEST_STRCMP
try_strcmp();
# endif
# ifdef TEST_STRCPY
try_strcpy();
# endif
# ifdef TEST_STRDUP
try_strdup();
# endif
# ifdef TEST_STRLCAT
try_strlcat();
# endif
# ifdef TEST_STRLEN
try_strlen();
# endif
# ifdef TEST_STRNCAT
try_strncat();
# endif
# ifdef TEST_STRNCMP
try_strncmp();
# endif
# ifdef TEST_STRNCPY
try_strncpy();
# endif
# ifdef TEST_STRNSTR
try_strnstr();
# endif
# ifdef TEST_STRRCHR
try_strrchr();
# endif
# ifdef TEST_STRSTR
try_strstr();
# endif
# ifdef TEST_TOLOWER
try_tolower();
# endif
# ifdef TEST_TOUPPER
try_toupper();
# endif

#endif



#if TEST_PART_N == 2

# ifdef TEST_ITOA
try_itoa();
# endif
# ifdef TEST_MEMALLOC
try_memalloc();
# endif
# ifdef TEST_MEMDEL
try_memdel();
# endif
# ifdef TEST_PUTCHAR
try_putchar();
# endif
# ifdef TEST_PUTCHAR_FD
try_putchar_fd();
# endif
# ifdef TEST_PUTENDL
try_putendl();
# endif
# ifdef TEST_PUTENDL_FD
try_putendl_fd();
# endif
# ifdef TEST_PUTNBR
try_putnbr();
# endif
# ifdef TEST_PUTNBR_FD
try_putnbr_fd();
# endif
# ifdef TEST_PUTSTR
try_putstr();
# endif
# ifdef TEST_PUTSTR_FD
try_putstr_fd();
# endif
# ifdef TEST_STRCLR
try_strclr();
# endif
# ifdef TEST_STRDEL
try_strdel();
# endif
# ifdef TEST_STREQU
try_strequ();
# endif
# ifdef TEST_STRITER
try_striter();
# endif
# ifdef TEST_STRITERI
try_striteri();
# endif
# ifdef TEST_STRJOIN
try_strjoin();
# endif
# ifdef TEST_STRMAP
try_strmap();
# endif
# ifdef TEST_STRMAPI
try_strmapi();
# endif
# ifdef TEST_STRNEQU
try_strnequ();
# endif
# ifdef TEST_STRNEW
try_strnew();
# endif
# ifdef TEST_STRSPLIT
try_strsplit();
# endif
# ifdef TEST_STRSUB
try_strsub();
# endif
# ifdef TEST_STRTRIM
try_strtrim();
# endif

#endif



#if TEST_PART_N == 3



#endif

	return(0);
}


void	ref_myassert(int relation)
{
	if (relation)
	{
		ft_putstr("\033[32m");
		ft_putstr("_TRUE");
	}
	else
	{
		ft_putstr("\033[31m");
		ft_putstr("FALSE");
	}
	ft_putstr("\033[39m");
}


#include <unistd.h>

/* void ft_putchar(char c) */
/* { */
/* 	write(1, &c, 1); */
/* } */

/* void ft_putstr(const char *s) */
/* { */
/* 	write(1, s, ft_strlen(s)); */
/* } */

/* void ft_putnbr(int n) */
/* { */
/* 	if (n < 0) */
/* 	{ */
/* 		ft_putchar('-'); */
/* 		if (n <= -10) */
/* 			ft_putnbr(-(n / 10)); */
/* 		ft_putchar(-(n % 10) + '0'); */
/* 		return ; */
/* 	} */
/* 	if (n >= 10) */
/* 		ft_putnbr(n / 10); */
/* 	ft_putchar(n % 10 + '0'); */
/* } */

void    ft_myassert(int relation)
{
    ref_myassert(relation);
}

static void putbs(char c, int *count)
{
	ft_putstr("\033[33m");
	ft_putnbr(c);
	ft_putstr("\033[39m");
	if (c < 0)
		(*count)++;
	if (c <= -10 || c >= 10)
		(*count)++;
	if (c <= -100 || c >= 100)
		(*count)++;
}

static void putspecial(char c)
{
	ft_putstr("\033[33m\\");
	if (c == '\f')
		ft_putchar('f');
	else if (c == '\n')
		ft_putchar('n');
	else if (c == '\r')
		ft_putchar('r');
	else if (c == '\033')
		ft_putchar('e');
	else if (c > '\b')
		ft_putchar(c + 107);
	else
		ft_putchar(c + 90);
	ft_putstr("\033[39m");
}

int ref_myputnchar(char *str, int num)
{
	int count;

	if (!str)
	{
		ft_putstr("\033[33m(null)\033[39m");
		return (6);
	}
	count = 0;
	while (num > 0)
	{
		if (isprint(*str))
		{
			ft_putchar(*str);
		}
		else if ((*str >= '\a' && *str <= '\r') || *str == '\033')
		{
			count++;
			putspecial(*str);
		}
		else
			putbs(*str, &count);
		str++;
		num--;
		count++;
	}
	return (count);
}
