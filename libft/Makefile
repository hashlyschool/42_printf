NAME		= libft.a
CC			= clang
FLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
AR			= ar rc
INC			= -I ./includes/

SRCS_PATH	= ./sources/
OBJS_PATH	= ./objs/

SRCS_NAME	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c \
			ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
			ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
			ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isdigit.c \
			ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
			ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c
SRCS		= $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS		= $(addprefix $(OBJS_PATH), $(SRCS_NAME:.c=.o))

B_SRCS_NAME	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			ft_lstadd_back.c  ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			ft_lstmap.c
BONUS_SRCS	= $(addprefix $(SRCS_PATH), $(B_SRCS_NAME))
BONUS_OBJS	= $(addprefix $(OBJS_PATH), $(B_SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_PATH) $(OBJS)
	$(AR) $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) -c $(FLAGS) $(INC) $< -o $@

$(OBJS_PATH):
	mkdir -p $(OBJS_PATH)

clean:
	$(RM) $(OBJS_PATH)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

bonus:	$(OBJS_PATH) $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
	ranlib $(NAME)

.PHONY: all clean fclean re bonus
