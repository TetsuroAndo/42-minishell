#!/bin/bash
echo "--------TESTING--------"
cc *.c ../0_system/*.c -L.-l../../lib/libft/libft.a -I../../inc -I../../lib/libft -o test && ./test && rm ./test
cc builtin_env.c ../0_system/*.c -L.-l../../lib/libft/libft.a -I../../inc -I../../lib/libft -o test && ./test && rm ./test


echo -e "\n\n\n"
