# project 
cpp codes including test case and test coverage.
using gtest/gmock and lcov  
**MarsPlan**    
5 5--edge's coordinate(x/y) meant from 0,0 to 5,5  
1 2 N---first Mars explorer' begin x/y and direction NORTH  
LMLMLMLMM---L(turn left), R(turn right), M(move forward)  

*Requirement1*  
1. Implement wrapping from one edge of the grid to another. (planets are spheres after all)  
2. Implement obstacle detection before each move to a new square. 
If a given sequence of commands encounters an obstacle, 
the rover moves up to the last possible point and reports the obstacle.


*Test Input:*   
5 5  
1 2 N  
LMLMLMLMM  
3 3 E  
MMRMMRMRRM  
  
*Expected Output:*    
1 3 N  
5 1 E  
  
  

build  
------------  
make clean  
make all  

tst/build  
------------  
make clean  
make all  
mkae report
