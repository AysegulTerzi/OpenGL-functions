#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew freetype2 glfw3`
LDFLAGS="$LDFLAGS -lglut"

$CC blendFuncSep.cpp ../fonts/mainfonts.cpp $CPPFLAGS $LDFLAGS -o blendFuncSep
