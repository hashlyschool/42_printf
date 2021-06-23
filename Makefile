NAME		= libftprintf.a
LIBFT		= ./libft/libft.a
FLAGS		= -Wall -Wextra -Werror
INC			= -I ./includes/
CC			= clang
RM			= rm -rf
AR			= ar -rcs

SRCS_PATH	= ./sources/
OBJS_PATH	= ./objs/

SRCS_NAME = ft_printf.c ft_pars_spec.c ft_pars_spec2.c \
			ft_treat_flags.c ft_write_arg.c ft_write_c.c \
			ft_write_s.c ft_write_p.c ft_write_d_i.c

SRCS		= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS_NAME:.c=.o))

B_SRCS_NAME	=

BONUS_SRCS	= $(addprefix $(SRCS_PATH), $(B_SRCS_NAME))
BONUS_OBJS	= $(addprefix $(OBJS_PATH), $(B_SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS_PATH) $(OBJS)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) -c $(FLAGS) $(INC)  $< -o $@

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS_PATH)

fclean:		clean
	$(RM) $(NAME) $(LIBFT)

bonus:	$(OBJS_PATH) $(OBJS) $(BONUS_OBJS)
	$(MAKE) bonus -C ./libft
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS) $(LIBFT)
	ranlib $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus
