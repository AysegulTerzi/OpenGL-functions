#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew freetype2 glfw3`
LDFLAGS="$LDFLAGS -lglut"

$CC bufferObjectQueries.cpp ../sources/util.cpp $CPPFLAGS $LDFLAGS -o bufferObjectQueries