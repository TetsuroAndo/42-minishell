cc -Wall -Wextra -Werror -o lexer_test ../src/2_tokenizer/tokenizer.c lexer_test.c -I../inc
./lexer_test
rm lexer_test