#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew freetype2 glfw3`
LDFLAGS="$LDFLAGS -lglut -lfreetype"

$CC bindframe.cpp $CPPFLAGS $LDFLAGS -o bindframe
