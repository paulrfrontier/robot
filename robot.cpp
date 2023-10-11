
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>

#include "robot.h"

/*
    Potentially use an enum to represent directions, this  will 
    * restrict possible inputs and avoid some compile time error checking.
    * speed up comparisons of directions.
     
    I did do it like this originally but changed it to string to meet the
    spec in the simplest possible manner.
*/

/**
 * Get the direction if turning clockwise.
 * @param direction a string representing a valid direction.
 * @return the direction clockwise from the parameter direction.
*/
std::string clockwise(const std::string& direction)
{
    if      (direction == "NORTH") return "EAST";
    else if (direction == "EAST")  return "SOUTH";
    else if (direction == "SOUTH") return "WEST";
    else if (direction == "WEST")  return "NORTH";

    throw std::invalid_argument("Direction value is not handled by this function");
}

/**
 * Get the direction if turning anti-clockwise.
 * @param direction a string representing a valid direction.
 * @return the direction anti-clockwise from the parameter direction.
*/
std::string anti_clockwise(const std::string& direction)
{
    if      (direction == "NORTH") return "WEST";
    else if (direction == "WEST")  return "SOUTH";
    else if (direction == "SOUTH") return "EAST";
    else if (direction == "EAST")  return "NORTH";

    throw std::invalid_argument("Direction value is not handled by this function");
}

/**
 * Check that a direction is valid
 * @param string representing a direction
 * @return true if one of the valid direction values otherwise false.
*/
bool is_valid_direction(const std::string& d)
{
    return d == "NORTH" || d == "SOUTH" || d == "EAST" || d == "WEST";
}

/**
 * Construct a Robot with a given grid size in which it can roam.
 * It may be better to represent that robot and the grid seperately.
*/
Robot::Robot(int width, int height)
  : width_(width),
    height_(height),
    x_(-1),
    y_(-1),
    direction_("NONE") 
{}

/**
 * Put the robot at a given location and facing a given direction
 * @param x the x coordinate in the grid to place the robot.
 * @param y the y coordinate in the grid to place the robot.
 * @param direction the direction the robot will face.
*/
void Robot::place(int x, int y, const std::string& direction)
{
    if((x < 0 || x >= width_) || (y < 0 || y >= height_))
    {
        std::cerr << "got out of bounds value in place command x:" << x << ", y:" << y << std::endl;
        return;
    }

    if (!is_valid_direction(direction))
    {
        std::cerr << "got invalid direction " << direction << "in place command" << std::endl;
        return;
    }

    x_ = x;
    y_ = y;
    direction_ = direction;
}

/**
 * Turn the robot left
*/
void Robot::left()
{
    if (x_ != -1) 
    {
        direction_ = anti_clockwise(direction_);
        std::cout << "robot moved left now facing " << direction_ << std::endl;
    } else 
    {
        std::cerr << "ignoring left command, as robot not placed " << std::endl;
    }
}

/**
 * Turn the robot right
*/
void Robot::right()
{
    if (x_ != -1) {
        direction_ = clockwise(direction_);
        std::cout << "robot moved right now facing " << direction_ << std::endl;
    } else 
    {
        std::cerr << "ignoring right command, as robot not placed " << std::endl;
    }
}

/**
 * Move the robot given its internal state (x, y and direction)
 * Will only move if it is not being asked to move outside of its grid.
*/
void Robot::move()
{
    if (x_ != -1) 
    {
        if (direction_ == "NORTH")
        {
            if (y_ < (height_ - 1))
            {
                std::cout << "moving north" << std::endl;
                y_ += 1;
            } else 
            {
                std::cerr << "cannot move, reached edge of grid" << std::endl;
            }
        }
        else if (direction_ == "SOUTH")
        {
            if (y_ > 0)
            {
                std::cout << "moving south" << std::endl;
                y_ -= 1;
            } else 
            {
                std::cerr << "cannot move, reached edge of grid" << std::endl;
            }
        }
        else if (direction_ == "EAST")
        {
            if (x_ < (width_ - 1))
            {
                std::cout << "moving east" << std::endl;
                x_ += 1;
            } else 
            {
                std::cerr << "cannot moved reached edge of grid" << std::endl;
            }
        }
        else if (direction_ == "WEST")
        {
            if (x_ > 0)
            {
                std::cout << "moving west" << std::endl;
                x_ -= 1;
            } else 
            {
                std::cerr << "cannot moved reached edge of grid" << std::endl;
            }
        }
    } else 
    {
        std::cerr << "ignoring move command, as robot not placed " << std::endl;
    }
}

/**
 * Return a report of the robots location
*/
std::string Robot::report()
{
    if (x_ != -1) {
        std::stringstream ss;
        ss << x_ << ',' << y_ << ',' << direction_;
        return ss.str();
    } else 
    {
        std::cerr << "ignoring report command, as robot not placed" << std::endl;
        return "not placed";
    }    
}
