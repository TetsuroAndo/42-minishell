#!/bin/bash
echo "--------TESTING--------"
cc *.c ../9_system/*.c ../5_env/*.c -L.-llibft.a -I../../inc -o test && ./test && rm ./test



echo -e "\n\n\n"
