# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feberman <feberman@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 14:30:52 by feberman          #+#    #+#              #
#    Updated: 2024/01/05 10:03:33 by feberman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=	philo
CC=		cc
CFLAGS=	-Wall -Werror -Wextra -pthread
IFLAG=	-Iincludes
SHELL= 	/bin/bash

OBJD=	obj/
SRCD=	src/

SRC_explicit= 	philo.c structs.c errors.c input.c utils.c
SRCs=	$(addprefix $(SRCD), $(SRC_explicit))
OBJs=	$(addprefix $(OBJD), $(SRC_explicit:.c=.o))

all: $(NAME)

$(NAME): $(SRCs)
	@echo -ne "\015\tBuilding object-files:\t"
	@$(MAKE) -s $(OBJs)
	@echo ""
	@echo -ne "\tBuilding executable\t"
	@$(CC) $(CFLAGS) $(IFLAG) $(OBJs) -o $(NAME)
	@echo -e "\033[32m\xE2\x9C\x94\033[0m"
	@echo -e "\t\033[1;5;93m$(NAME) is ready!!!\033[0m"

$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(OBJD)
	@echo -ne "\033[32m\xE2\x9C\x94\033[0m"
	@$(CC) $(CFLAGS) $(IFLAG) -c $< -o $@

clean:
	@echo -ne "\tRemove object-files:\t"
	@rm -rf $(OBJD)
	@echo -e "\033[32m\xE2\x9C\x94\033[0m"

fclean: clean
	@echo -ne "\tRemove executable:\t"
	@rm -f $(NAME)
	@echo -e "\033[32m\xE2\x9C\x94\033[0m"


re: fclean all

.PHONY: all clean fclean re
