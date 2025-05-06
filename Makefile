# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# Library name
NAME    = libft.a

# Mandatory source files
SRC     = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
          ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
          ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
          ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
          ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
          ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# Bonus source files
BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
            ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Object files
OBJ       = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Bonus test files
BONUS_TEST_SRCS = \
    test_ft_lstnew.c \
    test_ft_lstadd_front.c \
    test_ft_lstsize.c \
    test_ft_lstlast.c \
    test_ft_lstadd_back.c \
    test_ft_lstdelone.c \
    test_ft_lstclear.c \
    test_ft_lstiter.c \
    test_ft_lstmap.c

# Default rule: build mandatory library
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Build library including bonus functions
bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(OBJ) $(BONUS_OBJ)

# Compile .c into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove all object files
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# Remove object files and library
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all