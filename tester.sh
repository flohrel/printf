#!/bin/sh

make

if [[ $? -eq 0 ]]; then
	ggc -fsanitize-address -g3 -include incld/printf.h main.c -L. -lftprintf
