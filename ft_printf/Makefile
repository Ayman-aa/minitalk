SRCS = ft_printf.c ft_get_len.c \
		ft_printing.c ft_utils.c
		
OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

RESET	= \033[0m
BOLD	= \033[1m
RED		= \033[91m
GREEN	= \033[92m

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}
	@echo "$(BOLD)$(GREEN)$(NAME)$(RESET)$(BOLD) compiled successfully!$(RESET)"

all: ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
