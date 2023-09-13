#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew `
LDFLAGS="$LDFLAGS -lglut"

$CC bindframe.cpp $CPPFLAGS $LDFLAGS -o bindframe
