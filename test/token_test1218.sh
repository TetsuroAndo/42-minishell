cc token_test.c ../src/0_system/*.c ../src/1_tokenizer/*.c ../src/5_env/*.c ../src/7_builtin/*.c -I../inc -I../lib/libft ../lib/libft/libft.a -lreadline -o TEST
./TEST
# ./TEST "exit"
# ./TEST "echo hello world"