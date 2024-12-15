# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/15 18:05:31 by teando            #+#    #+#              #
#    Updated: 2024/12/15 18:26:17 by teando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -rf
ROOT_DIR	:= .
OUT_DIR		:= $(ROOT_DIR)/obj
INCS_DIR	:= $(ROOT_DIR)/inc
LIBFT_DIR	:= $(ROOT_DIR)/lib/libft
LIBFT		:= $(LIBFT_DIR)/libft.a
IDFLAGS		:= -I$(INCS_DIR) -I$(LIBFT_DIR)

SRCS 		:= \
	$(addprefix srcs/, \
		$(addprefix 0_parser/, \
		) \
		$(addprefix 1_tokenizer/, \
		) \
		$(addprefix 2_executor/, \
		) \
		$(addprefix 3_redirect/, \
		) \
		$(addprefix 4_signals/, \
		) \
		$(addprefix 5_env/, \
		) \
		$(addprefix 6_builtin/, \
		) \
		$(addprefix 7_utils/, \
		) \
		main.c \
	)
OBJS		:= $(addprefix $(OUT_DIR)/, $(SRCS:.c=.o))
DEPS		:= $(OBJS:.o=.d)

ifeq ($(DEBUG), 1)
	CFLAGS	+= -g -fsanitize=address
else
	CFLAGS	+= -O2
endif

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT): | sub-init
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
	
sub-init:
	git submodule update --init --recursive

sub:
	git submodule update --remote

norm:
	@norminette $(SRCS) $(INCS_DIR)

debug:
	$(MAKE) DEBUG=1

.PHONY: all clean fclean re initsub sub norm debug

-include $(DEPS)