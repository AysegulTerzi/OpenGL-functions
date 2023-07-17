#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew freetype2 glfw3`
LDFLAGS="$LDFLAGS -lglut"

$CC stencil.cpp ../Common/ogldev_util.cpp $CPPFLAGS $LDFLAGS -o stencil -I/usr/include/freetype2
