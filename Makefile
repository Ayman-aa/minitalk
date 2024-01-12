# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaamam <aaamam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 19:21:38 by aaamam            #+#    #+#              #
#    Updated: 2024/01/11 18:17:59 by aaamam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMEC = client
NAMES = server
BONUS_NAMEC = client_bonus
BONUS_NAMES = server_bonus
PRINTF = libftprintf.a
SRCC_FILES = client.c
SRCS_FILES = server.c
BONUSC_FILES = client_bonus.c 
BONUSS_FILES = server_bonus.c
SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
BONUSC = $(addprefix $(SRC_DIR), $(BONUSC_FILES))
BONUSS = $(addprefix $(SRC_DIR), $(BONUSS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
OBJBC = ${BONUSC:.c=.o}
OBJBS = ${BONUSS:.c=.o}
CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

# ANSI escape codes for colors
GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

all: $(NAMEC) $(NAMES)       

$(NAMEC): $(OBJC)
	@make -C ft_printf
	@$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) ft_printf/$(PRINTF) -o $(NAMEC)
	@echo "$(GREEN)$(NAMEC) compiled successfully$(NC)"

$(NAMES): $(OBJS)
	@make -C ft_printf
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) ft_printf/$(PRINTF) -o $(NAMES)
	@echo "$(GREEN)$(NAMES) compiled successfully$(NC)"

bonus : $(BONUS_NAMEC) $(BONUS_NAMES)

$(BONUS_NAMEC) : $(OBJBC)
	@make -C ft_printf
	@$(CC) $(CFLAGS) $(OBJBC) $(INCLUDE) ft_printf/$(PRINTF) -o $(BONUS_NAMEC)
	@echo "$(GREEN)$(BONUS_NAMEC) compiled successfully$(NC)"

$(BONUS_NAMES) : $(OBJBS)
	@make -C ft_printf
	@$(CC) $(CFLAGS) $(OBJBS) $(INCLUDE) ft_printf/$(PRINTF) -o $(BONUS_NAMES)
	@echo "$(GREEN)$(BONUS_NAMES) compiled successfully$(NC)"

clean:
	@make clean -C ft_printf
	@${RM} ${OBJC}
	@${RM} ${OBJS}
	@echo "$(GREEN)Object files cleaned$(NC)"

fclean: clean
	@make fclean -C ft_printf
	@${RM} $(NAMEC)
	@${RM} $(NAMES)
	@${RM} $(BONUS_NAMEC)
	@${RM} $(BONUS_NAMES)
	@${RM} $(PRINTF)
	@echo "$(GREEN)$(NAMEC), $(NAMES), and $(PRINTF) deleted$(NC)"

re: fclean all

.PHONY: all clean fclean re
