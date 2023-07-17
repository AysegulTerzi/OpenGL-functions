#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut"

$CC scissor.cpp ../Common/ogldev_util.cpp $CPPFLAGS $LDFLAGS -o scissor
