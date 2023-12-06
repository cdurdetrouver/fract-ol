# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 03:29:21 by gbazart           #+#    #+#              #
#    Updated: 2023/12/06 03:45:56 by gbazart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Wextra -Werror
OPTION = -c -I ./
SRCB = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
SRC = $(filter-out $(SRCB), $(wildcard *.c))
OBJ = *.o

all: $(NAME)

$(NAME):
        cc $(FLAG) $(OPTION) $(SRC)
        ar rc $(NAME) $(OBJ)

bonus:
        cc $(FLAG) $(OPTION) $(SRCB)
        ar rc $(NAME) $(OBJ)

clean:
        /bin/rm -f $(OBJ)
fclean: clean
        /bin/rm -f $(NAME)

re: fclean all
