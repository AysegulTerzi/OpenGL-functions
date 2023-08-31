#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew glfw3`
LDFLAGS="$LDFLAGS -lglut"

$CC bufferObjects.cpp ../fonts/mainfonts.cpp $CPPFLAGS $LDFLAGS -o bufferObjects

