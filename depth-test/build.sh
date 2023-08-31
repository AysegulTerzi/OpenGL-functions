#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut"

$CC depth.cpp ../fonts/mainfonts.cpp $CPPFLAGS $LDFLAGS -o depth
