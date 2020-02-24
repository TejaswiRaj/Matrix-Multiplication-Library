# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

main: Matrix.o MatrixLib.o pch.o
	$(CXX) $(CXXFLAGS) -o Matrix Matrix.o MatrixLib.o pch.o

# The main.o target can be written more simply

Matrix.o: Matrix.cpp MatrixLib.h pch.h
	$(CXX) $(CXXFLAGS) -c Matrix.cpp

MatrixLib.o: MatrixLib.h pch.h

pch.o: pch.h

