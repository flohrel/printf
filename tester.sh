#!/bin/sh

make

if [ $? -eq 0 ]; then
	gcc -Wall -Werror -Wextra -fsanitize=address -g3 -include incld/printf.h main.c -L. -lftprintf
fi
