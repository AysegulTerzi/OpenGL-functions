#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut -lGLEW -lGL -lglfw"

$CC blendEqSep.cpp ../fonts/mainfonts.cpp $CPPFLAGS $LDFLAGS -o blendEqSep
