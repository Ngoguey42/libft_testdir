/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_su.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:29:04 by ngoguey           #+#    #+#             */
/*   Updated: 2014/11/08 16:05:32 by ngoguey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
int		g_temoin;

void	ref_myassert(int relation);

#ifdef TEST_ITOA


char	*ref_itoa(int n)
{
	int		len;
	int		integer;
	char	*str;

	str = NULL;
	len = (n < 0) ? 2 : 1;
	integer = n;
	while (integer > 9 || integer < -9)
	{
		len++;
		integer = ABS(integer / 10);
	}
	if ((str = (char *)malloc((len + 1) * sizeof(*str))))
	{
		str[len--] = '\0';
		integer = n;
		while (len + 1)
		{
			str[len--] = '0' + ABS(integer % 10);
			integer = ABS(integer / 10);
		}
		if (n < 0)
			str[0] = '-';
	}
	return (str);
}

void	one_itoa(int i)
{
	char	*refret, *cusret;

	refret = ref_itoa(i);
	cusret = ft_itoa(i);

	printf("\033[34mREF\033[39m-->%d<----ret:%s----\n", i, refret);
	printf("\033[35mCUS\033[39m-->%d<----ret:%s----", i, cusret);
	fflush(stdout);
	ref_myassert(!strcmp(refret, cusret));
	printf("\n\n");
	
	free(refret);
	free(cusret);
}

void try_itoa(void)
{
	ft_putstr("5: testing (itoa):\n");
	one_itoa(0);
	one_itoa(1);
	one_itoa(-1);
	one_itoa(9);
	one_itoa(-9);
	one_itoa(10);
	one_itoa(-10);
	one_itoa(100);
	one_itoa(-100);
	one_itoa(-2147483645);
	one_itoa(-2147483646);
	one_itoa(-2147483647);
	one_itoa(-2147483648LL);
	one_itoa(2147483645);
	one_itoa(2147483646);
	one_itoa(2147483647);
    ft_putstr("\n------------------------------\n");
}



#endif

#ifdef TEST_MEMALLOC
void	one_memalloc(int size)
{
	char	*ret;
	int		i;

	printf("Calling for size(%3d):", size); fflush(stdout);
	ret = ft_memalloc(size);
	printf("Done     ");
	
	printf("Reading:"); fflush(stdout);
	for (i = 0; i < (size); i++)
	{
		if (ret[i] != '\0')
		{
			printf("Fail: str[%d] = %hhd", i, ret[i]);
			fflush(stdout);
			ref_myassert(0);
			return ;
		}
	}
	printf("Done     ");
	
	printf("Writing:"); fflush(stdout);
	for (i = 0; i < (size); i++)
	{
		ret[i] = 1;
		if (ret[i] != 1)
		{
			printf("Failed to write: str[%d] = %hhd", i, ret[i]);
			fflush(stdout);
			ref_myassert(0);
			return ;
		}
	}
	printf("Done     ");
	
	printf("Freeing:"); fflush(stdout);
	free(ret);
	printf("Done     "); fflush(stdout);
	ref_myassert(1);
	printf("\n");
}

void try_memalloc(void)
{
    ft_putstr("1: testing (ft_memalloc):\n");
	one_memalloc(0);
	one_memalloc(1);
	one_memalloc(2);
	one_memalloc(100);
    ft_putstr("\n------------------------------\n");
}
#endif

#ifdef TEST_MEMDEL
void try_memdel(void)
{
    ft_putstr("1: testing (ft_memdel):\n");
	void	*ptr_ptr = (void*)malloc(sizeof(char) * 100);
	ft_memdel(&ptr_ptr);
	ref_myassert(1);
    ft_putstr("\n------------------------------\n");
}
#endif


#ifdef TEST_PUTCHAR
void try_putchar(void)
{
	ft_putstr("5: testing (ft_putchar):\n");
	
	printf("\033[34mREF\033[39m   space>%c<   letter>%c<   \\0>%c<==\n", ' ', 'S', '\0');
	printf("\033[35mCUS\033[39m   space>"); fflush(stdout);
	ft_putchar(' ');
	printf("<   letter>"); fflush(stdout);
	ft_putchar('S');
	printf("<   \\0>"); fflush(stdout);
	ft_putchar('\0');
	printf("<\n");
	
    ft_putstr("\n------------------------------\n");
}
#endif
#ifdef TEST_PUTCHAR_FD
void try_putchar_fd(void)
{
	ft_putstr("5: testing (ft_putchar_fd):\n");
	
	dprintf(1, "\033[34mREF\033[39m==>%c<====>%c<====>%c<==\n", ' ', 'S', '\0');
	dprintf(1, "\033[35mCUS\033[39m==>"); fflush(stdout);
	ft_putchar_fd(' ', 1);
	dprintf(1, "<====>"); fflush(stdout);
	ft_putchar_fd('S', 1);
	dprintf(1, "<====>"); fflush(stdout);
	ft_putchar_fd('\0', 1);
	dprintf(1, "<==\n");
	
	dprintf(2, "\033[34mREF\033[39m==>%c<====>%c<====>%c<==\n", ' ', 'E', '\0');
	dprintf(2, "\033[35mCUS\033[39m==>"); fflush(stderr);
	ft_putchar_fd(' ', 2);
	dprintf(2, "<====>"); fflush(stderr);
	ft_putchar_fd('E', 2);
	dprintf(2, "<====>"); fflush(stderr);
	ft_putchar_fd('\0', 2);
	dprintf(2, "<==\n");

	
    ft_putstr("\n------------------------------\n");
}
#endif
#ifdef TEST_PUTENDL
void try_putendl(void)
{
	ft_putstr("5: testing (ft_putendl):\n");
	
	
	printf("********************************************\n");
	printf("\033[34mREF\033[39m==================\n%s\n=====================\n", "");
	printf("\033[35mCUS\033[39m==================\n"); fflush(stdout);
	ft_putendl("");
	printf("=====================\n********************************************\n");
	
	printf("\033[34mREF\033[39m==================\n%s\n=====================\n", "S");
	printf("\033[35mCUS\033[39m==================\n"); fflush(stdout);
	ft_putendl("S");
	printf("=====================\n********************************************\n");
	
	printf("\033[34mREF\033[39m==================\n%s\n=====================\n", "LOLOLOL 42+42=84");
	printf("\033[35mCUS\033[39m==================\n"); fflush(stdout);
	ft_putendl("LOLOLOL 42+42=84");
	printf("=====================\n");
	printf("********************************************\n");
	
	
    ft_putstr("\n------------------------------\n");
}
#endif
#ifdef TEST_PUTENDL_FD
void try_putendl_fd(void)
{
	ft_putstr("5: testing (ft_putendl_fd):\n");
	
	
	dprintf(1, "********************************************\n");
	dprintf(1, "\033[34mREF\033[39m==================\n%s\n=====================\n", "");
	dprintf(1, "\033[35mCUS\033[39m==================\n"); fflush(stdout);
	ft_putendl_fd("", 1);
	dprintf(1, "=====================\n********************************************\n");
	
	dprintf(1, "\033[34mREF\033[39m==================\n%s\n=====================\n", "S");
	dprintf(1, "\033[35mCUS\033[39m==================\n"); fflush(stdout);
	ft_putendl_fd("S", 1);
	dprintf(1, "=====================\n********************************************\n");
	
	dprintf(1, "\033[34mREF\033[39m==================\n%s\n=====================\n", "LOLOLOL 42+42=84");
	dprintf(1, "\033[35mCUS\033[39m==================\n"); fflush(stdout);
	ft_putendl_fd("LOLOLOL 42+42=84", 1);
	dprintf(1, "=====================\n");
	dprintf(1, "********************************************\n");
	
	fflush(stdout);
	dprintf(2, "********************************************\n");
	dprintf(2, "\033[34mREF\033[39m==================\n%s\n=====================\n", "");
	dprintf(2, "\033[35mCUS\033[39m==================\n"); fflush(stderr);
	ft_putendl_fd("", 2);
	dprintf(2, "=====================\n********************************************\n");
	
	dprintf(2, "\033[34mREF\033[39m==================\n%s\n=====================\n", "E");
	dprintf(2, "\033[35mCUS\033[39m==================\n"); fflush(stderr);
	ft_putendl_fd("E", 2);
	dprintf(2, "=====================\n********************************************\n");
	
	dprintf(2, "\033[34mREF\033[39m==================\n%s\n=====================\n", "FD2 error 42+42=84");
	dprintf(2, "\033[35mCUS\033[39m==================\n"); fflush(stderr);
	ft_putendl_fd("FD2 error 42+42=84", 2);
	dprintf(2, "=====================\n");
	dprintf(2, "********************************************\n");
	
	fflush(stderr);
    ft_putstr("\n------------------------------\n");
}
#endif
#ifdef TEST_PUTNBR
void try_putnbr(void)
{
	ft_putstr("5: testing (ft_putnbr):\n");
	
	printf("\033[34mREF\033[39m==>%d<====>%d<====>%d<====>%d<====>%d<====>%d<====>%d<==\n", 0, 1, -1, 100, -100, 2147483647, (int)-2147483648LL);
	printf("\033[35mCUS\033[39m==>"); fflush(stdout);
	ft_putnbr(0);
	printf("<====>"); fflush(stdout);
	ft_putnbr(1);
	printf("<====>"); fflush(stdout);
	ft_putnbr(-1);
	printf("<====>"); fflush(stdout);
	ft_putnbr(100);
	printf("<====>"); fflush(stdout);
	ft_putnbr(-100);
	printf("<====>"); fflush(stdout);
	ft_putnbr(2147483647);
	printf("<====>"); fflush(stdout);
	ft_putnbr((int)-2147483648LL);
	printf("<==\n");
	
    ft_putstr("\n------------------------------\n");
}
#endif
#ifdef TEST_PUTNBR_FD
void try_putnbr_fd(void)
{
	ft_putstr("5: testing (ft_putnbr_fd):\n");
	
	dprintf(1, "\033[34mREF\033[39m==>%d<====>%d<====>%d<====>%d<====>%d<====>%d<====>%d<==\n", 0, 1, -1, 100, -100, 2147483647, (int)-2147483648LL);
	dprintf(1, "\033[35mCUS\033[39m==>"); fflush(stdout);
	ft_putnbr_fd(0, 1);
	dprintf(1, "<====>"); fflush(stdout);
	ft_putnbr_fd(1, 1);
	dprintf(1, "<====>"); fflush(stdout);
	ft_putnbr_fd(-1, 1);
	dprintf(1, "<====>"); fflush(stdout);
	ft_putnbr_fd(100, 1);
	dprintf(1, "<====>"); fflush(stdout);
	ft_putnbr_fd(-100, 1);
	dprintf(1, "<====>"); fflush(stdout);
	ft_putnbr_fd(2147483647, 1);
	dprintf(1, "<====>"); fflush(stdout);
	ft_putnbr_fd((int)-2147483648LL, 1);
	dprintf(1, "<==\n");
	
	
	dprintf(2, "\033[34mREF\033[39m==>%d<====>%d<====>%d<====>%d<====>%d<====>%d<====>%d<==\n", 0, 1, -1, 100, -100, 2147483647, (int)-2147483648LL);
	dprintf(2, "\033[35mCUS\033[39m==>"); fflush(stderr);
	ft_putnbr_fd(0, 2);
	dprintf(2, "<====>"); fflush(stderr);
	ft_putnbr_fd(1, 2);
	dprintf(2, "<====>"); fflush(stderr);
	ft_putnbr_fd(-1, 2);
	dprintf(2, "<====>"); fflush(stderr);
	ft_putnbr_fd(100, 2);
	dprintf(2, "<====>"); fflush(stderr);
	ft_putnbr_fd(-100, 2);
	dprintf(2, "<====>"); fflush(stderr);
	ft_putnbr_fd(2147483647, 2);
	dprintf(2, "<====>"); fflush(stderr);
	ft_putnbr_fd((int)-2147483648LL, 2);
	dprintf(2, "<==\n");

	fflush(stderr);
    ft_putstr("\n------------------------------\n");
}
#endif
#ifdef TEST_PUTSTR
void try_putstr(void)
{
	ft_putstr("5: testing (ft_putstr):\n");
	printf("\033[34mREF\033[39m==>%s<====>%s<====>%s<==\n", "", "s", "salutsalutsalutsalutsalutsalutsalutsalutsalutsalutsalutsalutsalut");
	printf("\033[35mCUS\033[39m==>"); fflush(stdout);
	ft_putstr("");
	printf("<====>"); fflush(stdout);
	ft_putstr("s");
	printf("<====>"); fflush(stdout);
	ft_putstr("salutsalutsalutsalutsalutsalutsalutsalutsalutsalutsalutsalutsalut");
	printf("<==\n");
    ft_putstr("\n------------------------------\n");
}
#endif
#ifdef TEST_PUTSTR_FD
void try_putstr_fd(void)
{
	ft_putstr("5: testing (ft_putstr_fd):\n");
	dprintf(1, "\033[34mREF\033[39m==>%s<====>%s<====>%s<==\n", "", "s", "salutsalutsalutsalutsalutsalutsalutsalutsalutsalutsalutsalutsalut");
	dprintf(1, "\033[35mCUS\033[39m==>"); fflush(stdout);
	ft_putstr_fd("", 1);
	dprintf(1, "<====>"); fflush(stdout);
	ft_putstr_fd("s", 1);
	dprintf(1, "<====>"); fflush(stdout);
	ft_putstr_fd("salutsalutsalutsalutsalutsalutsalutsalutsalutsalutsalutsalutsalut", 1);
	dprintf(1, "<==\n");
	
	dprintf(2, "\033[34mREF\033[39m==>%s<====>%s<====>%s<==\n", "", "s", "errorerrorerrorerrorerrorerrorerror");
	dprintf(2, "\033[35mCUS\033[39m==>"); fflush(stdout);
	ft_putstr_fd("", 2);
	dprintf(2, "<====>"); fflush(stdout);
	ft_putstr_fd("s", 2);
	dprintf(2, "<====>"); fflush(stdout);
	ft_putstr_fd("errorerrorerrorerrorerrorerrorerror", 2);
	dprintf(2, "<==\n");
	
    ft_putstr("\n------------------------------\n");
}
#endif


#ifdef TEST_STRCLR
void one_strclr(char **sr)
{
	char	*s;
	int		i;
	int		size;

	i = 10;
	if (*sr)
	{
		size = strlen(*sr);
		s = (char*)malloc(sizeof(char) * (size + 1));
		strcpy(s, *sr);
		
		printf("Calling for str(%-*s):", i, s);
		ft_strclr(s);
		printf("Done     ");
		
		printf("Reading:"); fflush(stdout);
		for (i = 0; i < (size + 1); i++)
		{
			if (s[i] != '\0')
			{
				printf("Fail: str[%d] = %hhd", i, s[i]);
				fflush(stdout);
				ref_myassert(0);
				return ;
			}
		}
		printf("Done     ");
		
		printf("Freeing:"); fflush(stdout);
		free(s);
		printf("Done     ");
		
	}
	else
	{
		printf("Calling for str(%-*s):", i, "NULL");
		ft_strclr(*sr);
		printf("Done     ");
	}
	fflush(stdout);
	ref_myassert(1);
	printf("\n");
}


void try_strclr(void)
{
    ft_putstr("1: testing (ft_strclr):\n");
	char*	str = (char*)malloc(11);
	memset((void*)str, 0, 11);
	
	str = strcpy(str, ""); one_strclr(&str);
	str = strcpy(str, "s"); one_strclr(&str);
	str = strcpy(str, "salut"); one_strclr(&str);
/* 	str = NULL; one_strclr(&str); */
	
	
	
	
	free(str);
    ft_putstr("\n------------------------------\n");
}
#endif

#ifdef TEST_STRDEL
void try_strdel(void)
{
    ft_putstr("1: testing (ft_strdel):\n");
	char	*ptr_ptr = (char*)malloc(sizeof(char) * 100);
	ft_strdel(&ptr_ptr);
	ref_myassert(1);
    ft_putstr("\n------------------------------\n");
}
#endif

#ifdef TEST_STREQU
int		ref_strequ(char *s1, char *s2)
{
	int	ret = strcmp(s1, s2);

	return (ret ? 0 : 1);
}


void	one_strequ(char *s1, char *s2)
{
	int	refret, cusret;

	if (s1 && s2)
	{
		refret = ref_strequ(s1, s2);
		cusret = ft_strequ(s1, s2);
		printf("\033[34mREF\033[39m s1(%6s) s2(%6s) ret(%d)", s1, s2, refret);
		printf("\n");
		printf("\033[35mCUS\033[39m s1(%6s) s2(%6s) ret(%d)", s1, s2, cusret);
		fflush(stdout);
		if (refret == cusret)
			ref_myassert(1);
		else
			ref_myassert(0);
	}
	else
	{
		cusret = ft_strequ(s1, s2);
		printf("\033[35mCUS\033[39m s1(%6s) s2(%6s) ret(%d)", s1, s2, cusret);
		fflush(stdout);
		if (cusret == 1 && s1 == NULL && s2 == NULL)
			ref_myassert(1);
		else if (cusret == 0)
			ref_myassert(1);
		else
			ref_myassert(0);
	}
	printf("\n");
	printf("\n");
}

void	try_strequ(void)
{
    ft_putstr("1: testing (ft_strequ):\n");
	one_strequ("", "");
	one_strequ("abcE", "abcE");
	one_strequ("abcd", "");
	one_strequ("", "abcd");
	one_strequ("abcE", "abcd");
/* 	one_strequ(NULL, "abcE"); */
/* 	one_strequ("abcE", NULL); */
/* 	one_strequ(NULL, NULL); */
    ft_putstr("\n------------------------------\n");
}
#endif

#ifdef TEST_STRITER
void	call_striter(char *cptr)
{
	*cptr += 1;
}

void	one_striter(char *s)
{
	printf("\033[34mREF\033[39m source(%s) modified(%.*s)\n", s, strlen(s), "bcdefghijklmnopqrstuv");
	printf("\033[35mCUS\033[39m source(%s) ", s);
	ft_striter(s, &call_striter);
	printf("modified(%s)\n", s);
}

void try_striter(void)
{
	ft_putstr("1: testing (ft_striter):\n");
	char t1[] = "a";
	char t2[] = "ab";
	char t3[] = "abcdefgh";
	one_striter("");
	one_striter(t1);
	one_striter(t2);
	one_striter(t3);
	ft_putstr("\n------------------------------\n");
}
#endif
#ifdef TEST_STRITERI

void try_striteri(void)
{
    ft_putstr("1: testing (ft_striteri):\n");
	ft_putstr("OSEF\n------------------------------\n");
}
#endif

#ifdef TEST_STRJOIN
void    one_strjoin(char *s1, char *s2)
{
    char *ret;
	int i;
	int l1 = !s1 ? 3 : strlen(s1);
	int l2 = !s2 ? 3 : strlen(s2);
	
	if (s1 && s2)
	{
		printf("S1=>"); fflush(stdout);
		ref_myputnchar(s1, l1+1);
		printf("%*s", 10 - l1, "<=");
		
		printf("  S2=>"); fflush(stdout);
		ref_myputnchar(s2, l2+1);
		printf("%*s", 10 - l2, "<=");
		
		printf("Calling:"); fflush(stdout);
		ret = ft_strjoin(s1, s2);
		printf("Done     ");
		
		printf("Reading:"); fflush(stdout);
		for (i = 0; i < (l1 + l2 + 1); i++)
		{
			if (i < l1)
			{
				ref_myputnchar(ret + i, 1);
				if (ret[i] != s1[i])
				{
					ref_myassert(0);
					return ;
				}
			}
			else
			{
				ref_myputnchar(ret + i, 1);
				if (ret[i] != s2[i - l1])
				{
					ref_myassert(0);
					return ;
				}
			}
		}
		printf("%*s", 21 - l1 - l2, "Done     ");
		
		printf("Freeing:"); fflush(stdout);
		free(ret);
		printf("Done     ");
		
		fflush(stdout);
		ref_myassert(1);
		printf("\n");
	}
	else
	{
		printf("S1=>"); fflush(stdout);
		if (s1)
			ref_myputnchar(s1, l1+1);
		else
			printf("NULL");
		printf("%*s", 10 - l1, "<=");
		
		printf("  S2=>"); fflush(stdout);
		if (s2)
			ref_myputnchar(s2, l2+1);
		else
			printf("NULL");
		printf("%*s", 10 - l2, "<=");
		
		printf("Calling:"); fflush(stdout);
		ret = ft_strjoin(s1, s2);
		printf("Done     ");
		
		fflush(stdout);
		if (!ret)
			ref_myassert(1);
		else
			ref_myassert(0);
		printf("\n");
	}
}

void try_strjoin(void)
{
    ft_putstr("1: testing (ft_strjoin):\n");
    one_strjoin("", "");
    one_strjoin("", "A");
    one_strjoin("1", "");
    one_strjoin("1", "A");
    one_strjoin("", "ABCD");
    one_strjoin("12345678", "");
    one_strjoin("12345678", "ABCD");
/*     one_strjoin(NULL, "ABCD"); */
/*     one_strjoin("12345678", NULL); */
/*     one_strjoin(NULL, NULL); */
    ft_putstr("\n------------------------------\n");
}
#endif

#ifdef TEST_STRMAP
void try_strmap(void) {}
#endif
#ifdef TEST_STRMAPI
void try_strmapi(void) {}
#endif
#ifdef TEST_STRNEQU
int		ref_strnequ(char *s1, char *s2, size_t n)
{
	int	ret = strncmp(s1, s2, n);

	return (ret ? 0 : 1);
}


void	one_strnequ(char *s1, char *s2, size_t n)
{
	int	refret, cusret;

	if (s1 && s2)
	{
		refret = ref_strnequ(s1, s2, n);
		cusret = ft_strnequ(s1, s2, n);
		printf("\033[34mREF\033[39m s1(%6s) s2(%6s) size[%d]\tret(%d)", s1, s2, n, refret);
		printf("\n");
		printf("\033[35mCUS\033[39m s1(%6s) s2(%6s) size[%d]\tret(%d)", s1, s2, n, cusret);
		fflush(stdout);
		if (refret == cusret)
			ref_myassert(1);
		else
			ref_myassert(0);
	}
	else
	{
		cusret = ft_strnequ(s1, s2, n);
		printf("\033[35mCUS\033[39m s1(%6s) s2(%6s) size[%d]\tret(%d)", s1, s2, n, cusret);
		fflush(stdout);
		if (cusret == 1 && ((s1 == NULL && s2 == NULL) || (n == 0)))
			ref_myassert(1);
		else if (cusret == 0)
			ref_myassert(1);
		else
			ref_myassert(0);
	}
	printf("\n");
	// printf("\n");
}

void try_strnequ(void)
{
    ft_putstr(": testing (ft_strnequ):\n");
	one_strnequ("", "", 0);
	one_strnequ("abcE", "abcE", 0);
	one_strnequ("abcd", "", 0);
	one_strnequ("", "abcd", 0);
	one_strnequ("abcE", "abcd", 0);
/* 	one_strnequ(NULL, "abcE", 0); */
/* 	one_strnequ("abcE", NULL, 0); */
/* 	one_strnequ(NULL, NULL, 0); */
	printf("\n");
	one_strnequ("", "", 1);
	one_strnequ("abcE", "abcE", 1);
	one_strnequ("abcd", "", 1);
	one_strnequ("", "abcd", 1);
	one_strnequ("abcE", "abcd", 1);
/* 	one_strnequ(NULL, "abcE", 1); */
/* 	one_strnequ("abcE", NULL, 1); */
/* 	one_strnequ(NULL, NULL, 1); */
	printf("\n");
	one_strnequ("", "", 3);
	one_strnequ("abcE", "abcE", 3);
	one_strnequ("abcd", "", 3);
	one_strnequ("", "abcd", 3);
	one_strnequ("abcE", "abcd", 3);
/* 	one_strnequ(NULL, "abcE", 3); */
/* 	one_strnequ("abcE", NULL, 3); */
/* 	one_strnequ(NULL, NULL, 3); */
	printf("\n");
	one_strnequ("", "", 4);
	one_strnequ("abcE", "abcE", 4);
	one_strnequ("abcd", "", 4);
	one_strnequ("", "abcd", 4);
	one_strnequ("abcE", "abcd", 4);
/* 	one_strnequ(NULL, "abcE", 4); */
/* 	one_strnequ("abcE", NULL, 4); */
/* 	one_strnequ(NULL, NULL, 4); */
	printf("\n");
	one_strnequ("", "", 5);
	one_strnequ("abcE", "abcE", 5);
	one_strnequ("abcd", "", 5);
	one_strnequ("", "abcd", 5);
	one_strnequ("abcE", "abcd", 5);
/* 	one_strnequ(NULL, "abcE", 5); */
/* 	one_strnequ("abcE", NULL, 5); */
/* 	one_strnequ(NULL, NULL, 5); */
    ft_putstr("\n------------------------------\n");
}
#endif

#ifdef TEST_STRNEW
void	one_strnew(int size)
{
	char	*ret;
	int		i;

	printf("Calling for size(%3d):", size); fflush(stdout);
	ret = ft_strnew(size);
	printf("Done     ");
	
	printf("Reading:"); fflush(stdout);
	for (i = 0; i < (size + 1); i++)
	{
		if (ret[i] != '\0')
		{
			printf("Fail: str[%d] = %hhd", i, ret[i]);
			fflush(stdout);
			ref_myassert(0);
			return ;
		}
	}
	printf("Done     ");
	
	printf("Writing:"); fflush(stdout);
	for (i = 0; i < (size + 1); i++)
	{
		ret[i] = 1;
		if (ret[i] != 1)
		{
			printf("Failed to write: str[%d] = %hhd", i, ret[i]);
			fflush(stdout);
			ref_myassert(0);
			return ;
		}
	}
	printf("Done     ");
	
	printf("Freeing:"); fflush(stdout);
	free(ret);
	ft_myassert(1);
	printf("Done     "); fflush(stdout);
	printf("\n");
}

void try_strnew(void)
{
    ft_putstr("1: testing (ft_strnew):\n");
	one_strnew(0);
	one_strnew(1);
	one_strnew(2);
	one_strnew(100);
    ft_putstr("\n------------------------------\n");
}
#endif

#ifdef TEST_STRSPLIT

#define STRSPLIT_KSEVER 0

#if STRSPLIT_KSEVER == 1


static int ft_wdcount(const char *s, char sep)
{
	int num;
	int i;

	num = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		if (s[i] && s[i] != sep)
		{
			num++;
			while (s[i] && s[i] != sep)
				i++;
		}
	}
	return (num);
}

static int ft_wdlen(const char *s, char sep)
{
	int len;

	len = 0;
	while (s[len] != sep && s[len])
		len++;
	return (len);
}

static char* ft_wdncpy(const char *src, char c)
{
	char* item;
	int len;

	len = ft_wdlen(src, c);
	item = (char *)malloc(sizeof(char) * (len + 1));
	if (!item)
		return (NULL);
	ft_strncpy(item, src, len);
	item[len] = '\0';
	return (item);
}


/* copyright ksever@student.42.fr */
char            **ref_strsplit(char const *s, char c)
{
	char** res;
	int n[2];

	n[0] = 0;
	n[1] = 0;
	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_wdcount(s, c) + 1));
	if (!res)
		return (NULL);
	while (n[0] < ft_wdcount(s, c))
	{
		while (s[n[1]] == c)
			n[1] = n[1] + 1;
		if ((n[1] == 0 && s[n[1]] != c) || (s[n[1] - 1] == c && s[n[1]] != c))
		{
			res[n[0]] = ft_wdncpy(&s[n[1]], c);
			n[1] += ft_wdlen(&s[n[1]], c);
		}
		n[1] = n[1] + 1;
		n[0] = n[0] + 1;
	}
	res[ft_wdcount(s, c)] = '\0';
	return (res);

}

#else
/* copyright gfernand@student.42.fr */

static int calcword(const char *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if ((s[i] != c && i == 0) || (s[i - 1] == c && s[i] != c))
			word++;
		i++;
	}
	return (word);
}

static char** malloctab(char const *s, int c)
{
	int numword;

	if (s)
	{
		numword = calcword(s, c);
		return ((char **)ft_memalloc(sizeof(char *) * (numword + 1)));
	}
	return (NULL);
}

static int calcmalloc(char const *s, int i, int c)
{
	int n;

	n = i;
	while (s[n] && s[n] != c)
		n++;
	return (n);
}

char **ref_strsplit(char const *s, char c)
{
	char** tab;
	int i;
	int n;
	int j;

	if (s == NULL || (tab = malloctab(s, c)) == NULL)
		return (NULL);
	i = -1;
	n = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			if (tab[n] == NULL)
			{
				j = 0;
				if ((tab[n] = ft_strnew(calcmalloc(s, i, c) + 2)) == NULL)
					return (NULL);
			}
			tab[n][j++] = s[i];
		}
		else if (tab[n] != NULL)
			n++;
	}
	return (tab);
}

#endif

void	one_strsplit(char *s, char c)
{
	char **refret, **cusret;
	int i;

    printf("\033[34mREF\033[39m");
    printf(" s[%s] c[%d]'%c' ", s, c, c);
	refret = ref_strsplit(s, c);
	for (i = 0; refret[i] && refret[i][0] != '\0' ; i++)
	{
		fflush(stdout);
		printf("%d(%s) ", i, refret[i]);
		fflush(stdout);
	}
	if (!refret[i])
		printf("%i(%s) ", i, refret[i]);
	else
		printf("%i(\\0) ", i);
	printf("\n");
    printf("\033[35mCUS\033[39m");	
    printf(" s[%s] c[%d]'%c' ", s, c, c);
    cusret = ft_strsplit(s, c);
    for (i = 0; cusret[i] && cusret[i][0] != '\0' ; i++)
    {
        fflush(stdout);
        printf("%d(%s) ", i, cusret[i]);
        fflush(stdout);
    }
	if (!cusret[i])
		printf("%i(%s) ", i, cusret[i]);
	else
		printf("%i(\\0) ", i);
	fflush(stdout);
    for (i = 0; refret[i] && cusret[i] && refret[i][0] != '\0' && cusret[i][0] != '\0' ; i++)
    {
		ref_myassert(!strcmp(refret[i], cusret[i]));
    }
	if (!refret[i] && !cusret[i])
		ref_myassert(1);
	else if (refret[i] && !refret[i][0] && !cusret[i])
		ref_myassert(1);
	else if (cusret[i] && !cusret[i][0] && !refret[i])
		ref_myassert(1);
	else if (refret[i] && !refret[i][0] && cusret[i] && !cusret[i][0])
		ref_myassert(1);
	else
		ref_myassert(0);
	printf("\n");
}

void try_strsplit(void)
{
    ft_putstr(": testing (ft_strsplit):\n");
	one_strsplit("s", ' ');
	one_strsplit("s ", ' ');
	one_strsplit(" s", ' ');
	one_strsplit(" s ", ' ');
	one_strsplit("", ' ');
	one_strsplit(" ", ' ');
	one_strsplit("           ", ' ');
	one_strsplit("salut", ' ');
	one_strsplit("salut ", ' ');
	one_strsplit(" salut", ' ');
	one_strsplit(" salut ", ' ');
	one_strsplit("salut lol", ' ');
	one_strsplit("salut lol ", ' ');
	one_strsplit(" salut lol", ' ');
	one_strsplit(" salut lol ", ' ');
	one_strsplit("s lol h   hgh ss fgh", ' ');
	one_strsplit("s lol dff asa   s faf    ", ' ');
	one_strsplit("   s loff   ads sdasd", ' ');
	one_strsplit("    s lod ad   af as sda   ", ' ');
	one_strsplit("s asd asa", 0);
	one_strsplit("sa asddas ", 0);
	one_strsplit(" sasdasd", 0);
	one_strsplit(" sasdads ads ", 0);
    ft_putstr("\n------------------------------\n");
}
#endif

#ifdef TEST_STRSUB
char	*ref_strsub(const char *s, t_ui32 start, size_t len)
{
	char	*scpy;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (len + start > size)
		len = size - start;
	scpy = ft_strnew(len + 1);
	if (scpy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		scpy[i] = s[start + i];
		i++;
	}
	scpy[i] = 0;
	return (scpy);
}

void	one_strsub(char *s, t_ui32 start, size_t len)
{
	char	*refret, *cusret;
	int		i;

	refret = ref_strsub(s, start, len);
	cusret = ft_strsub(s, start, len);

	printf("\033[34mREF\033[39m str[");
	fflush(stdout);
	i = ref_myputnchar(s, (!s ? 0 : strlen(s)) + 1);
	printf("]%*s start(%2u) len(%2u)\tret[", 17 - i, " ", start, len);
	fflush(stdout);
	i = ref_myputnchar(refret, (!refret ? 0 : strlen(refret)) + 1);
	printf("%-*s", 17 - i, "]");
	printf("\n");
	
	printf("\033[35mCUS\033[39m str[");
	fflush(stdout);
	i = ref_myputnchar(s, (!s ? 0 : strlen(s)) + 1);
	printf("]%*s start(%2u) len(%2u)\tret[", 17 - i, " ", start, len);
	fflush(stdout);
	i = ref_myputnchar(cusret, (!cusret ? 0 : strlen(cusret)) + 1);
	printf("%-*s", 17 - i, "]");
	
	fflush(stdout);
	if ((!refret && !cusret) || (refret && cusret && !strcmp(refret, cusret)))
		ft_myassert(1);
	else
		ft_myassert(0);
	ft_putstr("  freeing:");
	free(cusret);
	ft_myassert(1);
	
	free(refret);
	printf("\n");
	printf("\n");
	
	// free(refret);
	
	
	(void)cusret;
}

void try_strsub(void)
{
    ft_putstr(": testing (ft_strsub):\n");
/* 	one_strsub(NULL, 0, 0); */
	one_strsub("ABC_123_789_xyz", 0, 0);
	one_strsub("ABC_123_789_xyz", 0, 1);
	one_strsub("ABC_123_789_xyz", 0, 14);
	one_strsub("ABC_123_789_xyz", 0, 15);
	one_strsub("ABC_123_789_xyz", 0, 16);
	one_strsub("ABC_123_789_xyz", 8, 0);
	one_strsub("ABC_123_789_xyz", 8, 1);
	one_strsub("ABC_123_789_xyz", 8, 2);
    ft_putstr("\n------------------------------\n");
}
#endif

#ifdef TEST_STRTRIM
char	*ref_strtrim(const char *s)
{
	char	*newstr;
	int		len;
	int		start;

	if (!s)
		return (NULL);
	start = 0;
	while (*s == '\n' || *s == ' ' || *s == '\t')
		s++;
	len = ft_strlen(s);
	newstr = ft_strnew(len - start);
	if (newstr == NULL)
		return (NULL);
	newstr = ft_strcpy(newstr, s);
	while (len-- >= 0)
	{
		if (s[len] == '\n' || s[len] == ' ' || s[len] == '\t')
			newstr[len] = 0;
		else
			break ;
	}
	return (newstr);
}

void	one_strtrim(char* str)
{
	char	*refret, *cusret;
	int		i;

	refret = ref_strtrim(str);
	cusret = ft_strtrim(str);

	printf("\033[34mREF\033[39m str[");
	fflush(stdout);
	i = ref_myputnchar(str, (!str ? 0 : strlen(str)) + 1);
	printf("]%*s\tret[", 16 - i, " ");
	fflush(stdout);
	i = ref_myputnchar(refret, (!refret ? 0 : strlen(refret)) + 1);
	printf("%-*s", 7 - i, "]");
	printf("\n");
	
	printf("\033[35mCUS\033[39m str[");
	fflush(stdout);
	i = ref_myputnchar(str, (!str ? 0 : strlen(str)) + 1);
	printf("]%*s\tret[", 16 - i, " ");
	fflush(stdout);
	i = ref_myputnchar(cusret, (!cusret ? 0 : strlen(cusret)) + 1);
	printf("%-*s", 7 - i, "]");
	fflush(stdout);
	if ((!refret && !cusret) || (refret && cusret && !strcmp(refret, cusret)))
		ft_myassert(1);
	else
		ft_myassert(0);
	ft_putstr("  adresses:");
	if (str == cusret && cusret)
		ft_myassert(0);
	else
		ft_myassert(1);
	ft_putstr("  freeing:");
	free(cusret);
	ft_myassert(1);
	printf("\n");
	printf("\n");
	
	free(refret);
	
	
	(void)cusret;
	// printf("\033[35mCUS\033[39m s1(%6s) s2(%6s) size[%d]\tret(%d)", s1, s2, n, cusret);
}

void try_strtrim(void)
{
    ft_putstr(": testing (ft_strtrim):\n");
/* 	one_strtrim(NULL); */
	one_strtrim("");
	one_strtrim(" ");
	one_strtrim("\t \n");
	one_strtrim("s");
	one_strtrim("\t \n\t \n");
	one_strtrim("salut");
	one_strtrim("\t \nsalut");
	one_strtrim("salut\t \n");
	one_strtrim("\t \nsalut\t \n");
	one_strtrim("  \t    \t\nBon\t \njour\t\n  \n     ");
    ft_putstr("\n------------------------------\n");
}
#endif

