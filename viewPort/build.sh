#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew freetype2 glfw3`
LDFLAGS="$LDFLAGS -lglut"

$CC viewPort.cpp ../sources/util.cpp $CPPFLAGS $LDFLAGS -o viewport
