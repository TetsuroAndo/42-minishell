#!/bin/bash

echo -e "\n\n\n"
echo "--------PWD TESTING--------"
cc *.c -I../../inc -D TEST_PWD -o pwdtest && ./pwdtest && rm ./pwdtest



echo -e "\n\n\n"
echo "--------CD TESTING---------"

