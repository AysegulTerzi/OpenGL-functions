#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew glfw3`
LDFLAGS="$LDFLAGS -lglut"

$CC depthRangef.cpp  $CPPFLAGS $LDFLAGS -o depthRangef
