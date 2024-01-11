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
PRINTF = libftprintf.a
SRCC_FILES = client.c
SRCS_FILES = server.c
SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
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
	@make -C printf
	@$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) printf/$(PRINTF) -o $(NAMEC)
	@echo "$(GREEN)$(NAMEC) compiled successfully$(NC)"

$(NAMES): $(OBJS)
	@make -C printf
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) printf/$(PRINTF) -o $(NAMES)
	@echo "$(GREEN)$(NAMES) compiled successfully$(NC)"

clean:
	@make clean -C printf
	@${RM} ${OBJC}
	@${RM} ${OBJS}
	@echo "$(GREEN)Object files cleaned$(NC)"

fclean: clean
	@make fclean -C printf
	@${RM} $(NAMEC)
	@${RM} $(NAMES)
	@${RM} $(PRINTF)
	@echo "$(GREEN)$(NAMEC), $(NAMES), and $(PRINTF) deleted$(NC)"

re: fclean all

.PHONY: all clean fclean re
