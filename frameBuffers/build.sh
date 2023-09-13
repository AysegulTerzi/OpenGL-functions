#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew `
LDFLAGS="$LDFLAGS -lglut -lGLEW -lGL"

chmod +x build.sh

$CC bindframe.cpp $CPPFLAGS $LDFLAGS -o bindframe


