#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut"

$CC colormask.cpp ../sources/util.cpp $CPPFLAGS $LDFLAGS -o colormask
