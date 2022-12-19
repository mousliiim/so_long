NAME			=	so_long

GNL				=	includes/gnl/get_next_line.c includes/gnl/get_next_line_utils.c

LIBFT			=	includes/libft/libft.a

PRINTF			=	includes/ft_printf/libftprintf.a

SRCS			=	main.c utils.c mapcheck.c ft_pathfinding_rtbl.c pathfinding.c

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
PURPLE= \033[38;2;255;105;180m
RESET= \033[0m

OBJS			=	${SRCS:.c=.o}

OBJS_GNL		=	${GNL:.c=.o}

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes

CFLAGS			=	-Wall -Werror -Wextra -g

all				:	${NAME}

$(NAME) : $(OBJS) ${OBJS_GNL}
	@echo "${GREEN}========================${DEF_COLOR}"
	@echo "${GREEN}===== MAKE ${PURPLE}LIBFT ⌛${DEF_COLOR}${GREEN}=====${DEF_COLOR}"
	@echo "${GREEN}========================${DEF_COLOR}"
	@make -C includes/libft
	@echo "${GREEN}=============================${DEF_COLOR}"
	@echo "${GREEN}===== MAKE ${PURPLE}FT_PRINTF${DEF_COLOR} ⌛${GREEN} =====${DEF_COLOR}"
	@echo "${GREEN}=============================${DEF_COLOR}"
	@make -C includes/ft_printf
	@echo "${GREEN}==============================${DEF_COLOR}"
	@echo "${GREEN}==== ALL IS ${PURPLE}COMPILATED${DEF_COLOR} ✅${GREEN} ====${DEF_COLOR}"
	@echo "${GREEN}==============================${DEF_COLOR}"
	cc $(OBJS) ${OBJS_GNL} mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${LIBFT} ${PRINTF} -o $(NAME)

clean			:
					make clean -C includes/libft/
					make clean -C includes/ft_printf/
					rm -rf ${OBJS} ${OBJS_GNL}

fclean			:	clean
					make fclean -C includes/libft/
					make fclean -C includes/ft_printf/
					rm -rf ${LIBFT}
					rm -rf ${PRINTF}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re bonus