#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew glfw3`
LDFLAGS="$LDFLAGS -lglut"

$CC bufferObjects.cpp ../sources/util.cpp $CPPFLAGS $LDFLAGS -o bufferObjects

