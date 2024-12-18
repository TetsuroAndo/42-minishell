# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/15 18:05:31 by teando            #+#    #+#              #
#    Updated: 2024/12/19 01:45:00 by teando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
LFLAGS		:= -lreadline
RM			:= rm -rf
ROOT_DIR	:= .
OUT_DIR		:= $(ROOT_DIR)/obj
INCS_DIR	:= $(ROOT_DIR)/inc
LIBFT_DIR	:= $(ROOT_DIR)/lib/libft
LIBFT		:= $(LIBFT_DIR)/libft.a
IDFLAGS		:= -I$(INCS_DIR) -I$(LIBFT_DIR)

SRCS 		:= \
	$(addprefix src/, \
		$(addprefix 0_system/, \
			readline.c \
			system_absolute_path.c \
			system_allocate.c \
			system_exit.c \
			system_file_op.c \
			system_init.c \
			system_io.c \
		) \
		$(addprefix 1_tokenizer/, \
			__test_put_tokens.c \
			tokenizer.c \
			lexer_loop.c \
			lexer_utils.c \
			lexer_quote.c \
			lexer_read_word.c \
			lexer_token_manage.c \
			lexer_error.c \
			lexer_cmd_tokenize.c \
			lexer_wildcard.c \
		) \
		$(addprefix 2_parser/, \
		) \
		$(addprefix 3_executor/, \
		) \
		$(addprefix 4_redirect/, \
		) \
		$(addprefix 5_env/, \
		) \
		$(addprefix 6_signals/, \
			sig_setup.c \
		) \
		$(addprefix 7_builtin/, \
		) \
		$(addprefix 8_utils/, \
		) \
		main.c \
	)

SRCS := \
    test/test_parser.c \
    src/2_parser/parser.c \
	src/2_parser/ast_free.c \
	src/2_parser/ast_utils.c \
    src/0_system/system_init.c \
    src/0_system/system_exit.c \
    src/0_system/system_allocate.c \
    src/0_system/readline.c \
    src/1_tokenizer/lexer_cmd_tokenize.c \
    src/1_tokenizer/lexer_loop.c \
    src/1_tokenizer/lexer_read_word.c \
    src/1_tokenizer/lexer_token_manage.c \
    src/1_tokenizer/lexer_utils.c \
    src/1_tokenizer/lexer_quote.c \
    src/1_tokenizer/lexer_error.c \
    src/1_tokenizer/lexer_wildcard.c \
    src/1_tokenizer/tokenizer.c \

OBJS		:= $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS		:= $(OBJS:.o=.d)

ifeq ($(DEBUG), 1)
	CFLAGS	+= -g -fsanitize=address
else
	CFLAGS	+= -O2
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) $(LIBFT) -o $@

$(LIBFT): | $(LIBFT_DIR)/Makefile
	$(MAKE) -C $(LIBFT_DIR)

$(OUT_DIR)/%.o: $(ROOT_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -MMD -MP $(IDFLAGS) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OUT_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

$(LIBFT_DIR)/Makefile:
	git submodule update --init --recursive

sub:
	git submodule update --remote

norm:
	@norminette $(SRCS) $(INCS_DIR)

debug:
	$(MAKE) DEBUG=1

.PHONY: all clean fclean re initsub sub norm debug

-include $(DEPS)