#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew `
LDFLAGS="$LDFLAGS -lglut -lGLEW -lGL"

$CC clear.cpp ../fonts/mainfonts.cpp $CPPFLAGS $LDFLAGS -o clear
