#!/bin/bash

echo -e "\n\n\n"
echo "--------PWD TESTING--------"
cc *.c -I../../inc -D TEST_PWD -o pwdtest && ./pwdtest && rm ./pwdtest



echo -e "\n\n\n"
echo "--------CD TESTING---------"
cc *.c -I../../inc -D TEST_CD -o cdtest && ./cdtest && rm ./cdtest
