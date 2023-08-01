# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschmunk <jschmunk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/15 18:39:31 by jschmunk          #+#    #+#              #
#    Updated: 2023/07/15 20:31:20 by jschmunk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c case_c_s_d_i_u.c case_ptr_hex_perc.c tools00.c tools01.c\

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

COMPILE = $(CC) $(CFLAGS) -c

LIB = ar -rcs $(NAME)

# -r      Replace or add the specified files to the archive.  If the archive does not exist a new archive file is created.
#c      Whenever an archive is created, an informational message to that effect is written to standard error.
#-s      Write an object-file index into the archive, or update an existing one, even if no other change is made to the archive.

%.o : %.c
	$(COMPILE) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re