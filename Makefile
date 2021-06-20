NAME = libftprintf.a

FLAGS = #-Wall -Wextra -Werror

INC = -I ./includes/

SRCS_NAME = ft_printf.c ft_pars_spec.c ft_pars_spec2.c \
			ft_treat_flags.c ft_write_arg.c ft_wtite_c.c

SRCS_PATH = sources/
OBJ_PATH  = obj/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)
