#ifndef __ROBOT_H_INCLUDED__
#define __ROBOT_H_INCLUDED__

#include <string>

std::string clockwise(const std::string& direction);
std::string anti_clockwise(const std::string& direction);


class Robot
{
    int width_;
    int height_;

    int x_;
    int y_;
    std::string direction_;

    public:

    Robot(int width, int height);

    void place(int x, int y, const std::string& direction);
    void left();
    void right();
    void move();
    std::string report();
};

#endif
