#! bin/bash

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -I. ../get_next_line.c ../get_next_line_utils.c ft_get_next_line_test.c -o get_next_line

