#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut -lGLEW -lGL"

$CC clearcolor.cpp ../fonts/mainfonts.cpp $CPPFLAGS $LDFLAGS -o clearcolor
