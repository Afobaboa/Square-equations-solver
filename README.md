# Square equations solver


This program can solve any square equation in real numbers. 
You can use this like a calculator.


# Downloading (Linux)


You don't need to have special programs
on your computer for using this program.

1. Clone repository
```git clone https://github.com/Afobaboa/Square-equations-solver```

2. Go to root directory og
this project
```cd squareSolver```

3. Run squareSolver
```./squareSolver -help```


# Documentation


1. There are documentation for developers.
You can open it by browser. 
If you are in root directory of this 
project use
```cd html```
```firefox index.html```
You can use any other browser.

2. If you want to expand documentation,
use "doxygen". To make documentation change
dyrectory to root directory of this
project and write
```doxygen```
Then do first point.


# Make


You can expand this project, adding new .cpp
and .h files to /sources and /headers directories.
You can use ready Makefile.

1. To compile project write
```make```
or 
```make squareSolver```

2. To run program 
```make run```

3. To test solver.cpp write
```make test```
All tests are in /sources/solverTest.cpp

P.S. if you change ready source files, 
you can break program. Be careful!