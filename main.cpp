
#include <iostream>

#include "robot.h"
int main() 
{
    Robot rob(5, 5);
    rob.place(0, 0, "NORTH");
    rob.move();
    std::cout << rob.report() << '\n'; // => Output: 0, 1, NORTH
    rob.place(0, 0, "NORTH");
    rob.left();
    std::cout << rob.report() << '\n'; // => Output: 0, 0, WEST
    rob.place(1, 2, "EAST");
    rob.move();
    rob.move();
    rob.left();
    rob.move();
    std::cout << rob.report() << '\n'; // => Output: 3, 3, NORTH
}