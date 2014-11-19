#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 11:28:17 by ngoguey           #+#    #+#              #
#    Updated: 2014/11/17 09:43:38 by ngoguey          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = testmain

INCLUDE = ./
SRCPATH = .
OBJPATH = obj

CC = gcc
CFLAGS = 
RM = rm -rf

SRCSFILES = main.c try_ob.c try_su.c

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)

all: cpllibft $(NAME)

$(NAME):$(OBJECTS)
	$(CC) -o $@ $(CFLAGS) $(OBJECTS) -g -L ../ -lft

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) -g -I ../ -I ./ -c $<

cpllibft:
	make -C ../

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

relft:
	make -C ../ re