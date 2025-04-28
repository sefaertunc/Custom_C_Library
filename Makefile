# Compiler and flags
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

# Colors
GREEN   = \033[0;32m
RED     = \033[0;31m
NC      = \033[0m

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

# Mandatory test files
TEST_SRCS = \
    test_ft_isalpha.c \
    test_ft_isdigit.c \
    test_ft_isascii.c \
    test_ft_isprint.c \
    test_ft_strlen.c \
    test_ft_memset.c \
    test_ft_bzero.c \
    test_ft_memcpy.c \
    test_ft_memmove.c \
    test_ft_strlcpy.c \
    test_ft_strlcat.c \
    test_ft_toupper.c \
    test_ft_tolower.c \
    test_ft_strchr.c \
    test_ft_strrchr.c \
    test_ft_strncmp.c \
    test_ft_memchr.c \
    test_ft_memcmp.c \
    test_ft_strnstr.c \
    test_ft_atoi.c \
    test_ft_calloc.c \
    test_ft_strdup.c \
    test_ft_substr.c \
    test_ft_strjoin.c \
    test_ft_strtrim.c \
    test_ft_split.c \
    test_ft_itoa.c \
    test_ft_strmapi.c \
    test_ft_striteri.c \
    test_ft_putchar_fd.c \
    test_ft_putstr_fd.c \
    test_ft_putendl_fd.c \
    test_ft_putnbr_fd.c

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

# Run both mandatory and bonus tests
test: bonus
	@printf "\n--- Mandatory tests ---\n"
	@for file in $(TEST_SRCS); do \
		echo "\nCompiling and testing $$file..."; \
		$(CC) $(CFLAGS) $$file libft.a -I. -o testfile; \
		if ./testfile; then \
			echo "$(RED)FAIL$(NC) $$file"; \
		else \
			echo "$(GREEN)PASS$(NC) $$file"; \
		fi; \
		rm -f testfile; \
	done

	@printf "\n--- Bonus tests ---\n"
	@for file in $(BONUS_TEST_SRCS); do \
		echo "\nCompiling and testing $$file..."; \
		$(CC) $(CFLAGS) $$file libft.a -I. -o testfile; \
		if ./testfile; then \
			echo "$(RED)FAIL$(NC) $$file"; \
		else \
			echo "$(GREEN)PASS$(NC) $$file"; \
		fi; \
		rm -f testfile; \
	done
