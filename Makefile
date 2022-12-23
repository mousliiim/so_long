NAME			=	so_long

NAME_BONUS		= 	so_long_bonus

LIBFT			=	includes/libft/libft.a

PRINTF			=	includes/ft_printf/libftprintf.a

SRCS			=	main.c miscft/utils.c miscft/mapcheck.c miscft/ft_pathfinding_rtbl.c \
					miscft/pathfinding.c miscft/move.c miscft/gamemlxutils.c

SRCS_BONUS			=	bonus/main_bonus.c bonus/miscft/utils_bonus.c bonus/miscft/mapcheck_bonus.c \
					bonus/miscft/ft_pathfinding_rtbl_bonus.c \
					bonus/miscft/pathfinding_bonus.c bonus/miscft/move_bonus.c bonus/miscft/gamemlxutils_bonus.c

# Colors
DEF_COLOR = \033[0;39m
GREEN = \033[0;92m
PURPLE= \033[38;2;255;105;180m

OBJS			=	${SRCS:.c=.o}

OBJS_BONUS		=	${SRCS_BONUS:.c=.o}

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes

CFLAGS			=	-Wall -Werror -Wextra -g

all				:	${NAME}

$(NAME) : $(OBJS)
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}=== MAKE ${PURPLE}MANDATORY ⌛${DEF_COLOR}${GREEN}===${DEF_COLOR}"
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}\n"
	@sleep 1
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===== MAKE ${PURPLE}LIBFT ⌛${DEF_COLOR}${GREEN}=====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}\n"
	@make -C includes/libft
	@echo "\t\t\t${GREEN}=============================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===== MAKE ${PURPLE}FT_PRINTF${DEF_COLOR} ⌛${GREEN} =====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}=============================${DEF_COLOR}\n"
	@make -C includes/ft_printf
	@echo "\t\t\t${GREEN}==============================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}==== ALL IS ${PURPLE}COMPILATED${DEF_COLOR} ✅${GREEN} ====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}==============================${DEF_COLOR}"
	cc $(OBJS) mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${LIBFT} ${PRINTF} -o $(NAME)

bonus			: ${OBJS_BONUS}
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===== MAKE ${PURPLE}BONUS ⌛${DEF_COLOR}${GREEN}=====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}\n"
	@sleep 1
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===== MAKE ${PURPLE}LIBFT ⌛${DEF_COLOR}${GREEN}=====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}========================${DEF_COLOR}\n"
	@make -C includes/libft
	@echo "\t\t\t${GREEN}=============================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}===== MAKE ${PURPLE}FT_PRINTF${DEF_COLOR} ⌛${GREEN} =====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}=============================${DEF_COLOR}\n"
	@make -C includes/ft_printf
	@echo "\t\t\t${GREEN}==============================${DEF_COLOR}"
	@echo "\t\t\t${GREEN}==== ALL IS ${PURPLE}COMPILATED${DEF_COLOR} ✅${GREEN} ====${DEF_COLOR}"
	@echo "\t\t\t${GREEN}==============================${DEF_COLOR}"
	cc ${OBJS_BONUS} mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${LIBFT} ${PRINTF} -o $(NAME_BONUS)

clean			:
					make clean -C includes/libft/
					make clean -C includes/ft_printf/
					rm -rf ${OBJS}
					rm -rf ${OBJS_BONUS}

fclean			:	clean
					make fclean -C includes/libft/
					make fclean -C includes/ft_printf/
					rm -rf ${LIBFT}
					rm -rf ${PRINTF}
					rm -rf ${NAME} ${NAME_BONUS}

re				:	fclean all

.PHONY			:	all clean fclean re bonus