#### Libft testing/debugging files for 42 peer-correcting.
--------  -----------------------

Clone 'libft_testdir' directory inside the project folder:

####files:
* libft/libft_testdir/README.md
* libft/libft_testdir/Makefile
* libft/libft_testdir/test.h
* libft/libft_testdir/main.c
* libft/libft_testdir/try_ob.c
* libft/libft_testdir/try_su.c

####requires:
* libft/Makefile
* libft/libft.h

--------  -----------------------

####How To:
In _test.h_, line 33 set TEST_PART_N to 1 or 2.
```c
# define TEST_PART_N 1 //change part
```
In _test.h_, comment/uncomment defines lines 67-96 and lines 186-205.
```c
# define TEST_ITOA
//# define TEST_MEMALLOC
```
The _Makefile_ calls your __Makefile__ and links both your __*.h__ and __libft.a__ files to the _testmain_ binary.
```sh
make re ; ./testmain
```

--------  -----------------------

Tests everything but:

* ft_strmap.c
* ft_strmapi.c
* ft_striter.c
* ft_striteri.c
* ft_lstpush.c
* ft_lstdel.c
* ft_lstdelone.c
* ft_lstiter.c
* ft_lstmap.c
* ft_lstnew.c

--------  -----------------------

Ngoguey@42
