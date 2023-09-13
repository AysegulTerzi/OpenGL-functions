#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew freetype2 glfw3`
LDFLAGS="$LDFLAGS -lglut -lSOIL"

$CC colorattachment.cpp  $CPPFLAGS $LDFLAGS -o colorattachment -I/usr/include/SOIL/soil.h -I/home/rosselia/openGL-functions/sources/

