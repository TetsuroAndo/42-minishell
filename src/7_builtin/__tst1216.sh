#!/bin/bash
echo "--------TESTING--------"
cc *.c -I../../inc -o test && ./test && rm ./test



echo -e "\n\n\n"
