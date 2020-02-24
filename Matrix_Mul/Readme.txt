Matrix.sln contains all libraries and header files and works with MS Visual Studio.
MatrixLib.cpp is the matrix library file.
Make file is included
make
->g++ -Wall -g -o Matrix Matrix.o MatrixLib.o pch.o

 g++ -c Matrix.cpp
 g++ -c MatrixLib.cpp
 g++ -c pch.cpp
 Matrix Matrix.o MatrixLib.o pch.p

 ./Matrix should give the output.

