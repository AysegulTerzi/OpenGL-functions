#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut -lGLEW -lGL"

$CC blendColor.cpp ../fonts/mainfonts.cpp  $CPPFLAGS $LDFLAGS -o blendColor
