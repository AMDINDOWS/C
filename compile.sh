#!/bin/sh

CC=gcc
$CC -shared -fPIC ./table.c -o libtable.so
$CC ARR30-C.c -o ARR30 -L. -ltable -Wl,-rpath,./
