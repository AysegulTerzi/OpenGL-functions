#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew freetype2 glfw3`
LDFLAGS="$LDFLAGS -lglut -lfreetype"

$CC 3dcube.cpp  $CPPFLAGS $LDFLAGS -o 3dcube
