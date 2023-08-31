#!/bin/bash

CC=g++
CPPFLAGS="-I../Include"
LDFLAGS="$LDFLAGS -lglut  -lGL"

$CC blending.cpp ../fonts/mainfonts.cpp $CPPFLAGS $LDFLAGS -o blending
