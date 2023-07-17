#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS=`pkg-config --libs glew`
LDFLAGS="$LDFLAGS -lglut -lGLEW -lGL"

$CC blending.cpp ../Common/ogldev_util.cpp $CPPFLAGS $LDFLAGS -o blending
