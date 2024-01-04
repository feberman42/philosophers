# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 14:30:52 by feberman          #+#    #+#              #
#    Updated: 2024/01/04 11:12:14 by feberman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	philo
CFLAGS=	-Wall -Werror -Wextra -pthread

OBJD=	objects/

SRCs= 	philo.c
OBJs=	$(addprefix $(OBJD), $(SRCs:.c=.o))

all: $(NAME)

$(NAME): $(OBJs)
	@echo -n "Building executable..."
	@cc $(CFLAGS) $(OBJs) -o $(NAME)
	@echo "DONE"

$(OBJD)%.o: %.c
	@echo -n "Building object-files..."
	@mkdir -p $(OBJD)
	@cc $(CFLAGS) -c $< -o $@
	@echo "DONE"

clean:
	@echo -n "Remove object-files..."
	@rm -rf $(OBJD)
	@echo "DONE"

fclean: clean
	@echo -n "Remove executable..."
	@rm -f $(NAME)
	@echo "DONE"

re: fclean all

.PHONY: all clean fclean re
