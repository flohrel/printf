#!/bin/sh

make -C .. re

if [ $? -eq 0 ]; then
	gcc -fsanitize=address -g3 -I../incld main.c -L.. -lftprintf
fi

./a.out
