#!/bin/bash
make && gcc main.c $1 -o main && ./main && make clean