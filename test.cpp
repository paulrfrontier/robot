
#include "catch/catch_amalgamated.hpp"

#include "robot.h"

/*
    Turn Tests
*/
TEST_CASE("directions clockwise")
{
    REQUIRE(clockwise("NORTH") == "EAST");
    REQUIRE(clockwise("EAST") == "SOUTH");
    REQUIRE(clockwise("SOUTH") == "WEST");
    REQUIRE(clockwise("WEST") == "NORTH");
    REQUIRE_THROWS(clockwise("INVALID"));
}

TEST_CASE("directions anticlockwise")
{
    REQUIRE(anti_clockwise("NORTH") == "WEST");
    REQUIRE(anti_clockwise("EAST") == "NORTH");
    REQUIRE(anti_clockwise("SOUTH") == "EAST");
    REQUIRE(anti_clockwise("WEST") == "SOUTH");
    REQUIRE_THROWS(anti_clockwise("INVALID"));
}

/*
    actions without place tests
*/
TEST_CASE("report without place give no result")
{
    Robot rob(5,5);
    REQUIRE(rob.report() == "not placed");
}

TEST_CASE("left without place give no report")
{
    Robot rob(5,5);
    rob.left();
    REQUIRE(rob.report() == "not placed");
}

TEST_CASE("right without place give no report")
{
    Robot rob(5,5);
    rob.right();
    REQUIRE(rob.report() == "not placed");
}

TEST_CASE("move without place give no report")
{
    Robot rob(5,5);
    rob.right();
    REQUIRE(rob.report() == "not placed");
}

/* 
  report after place
*/
TEST_CASE("Place and get valid report")
{
    Robot rob(5, 5);
    rob.place(0, 0, "NORTH");
    REQUIRE(rob.report() == "0,0,NORTH");
}

/*
  out of bounds place tests
*/
TEST_CASE("Place out of bounds negative x and get empty report")
{
    Robot rob(5, 5);
    rob.place(-1, 0, "NORTH");
    REQUIRE(rob.report() == "not placed");
}

TEST_CASE("Place out of bounds x and get empty report")
{
    Robot rob(5, 5);
    rob.place(5, 0, "NORTH");
    REQUIRE(rob.report() == "not placed");
}

TEST_CASE("Place out of bounds negative y and get empty report")
{
    Robot rob(5, 5);
    rob.place(0, -1, "NORTH");
    REQUIRE(rob.report() == "not placed");
}

TEST_CASE("Place out of bounds y and get empty report")
{
    Robot rob(5, 5);
    rob.place(0, 5, "NORTH");
    REQUIRE(rob.report() == "not placed");
}

TEST_CASE("turn left give correct coordinate")
{
    Robot rob(5, 5);
    rob.place(0, 0, "NORTH");
    rob.left();
    REQUIRE(rob.report() == "0,0,WEST");
    rob.left();
    REQUIRE(rob.report() == "0,0,SOUTH");
    rob.left();
    REQUIRE(rob.report() == "0,0,EAST");
    rob.left();
    REQUIRE(rob.report() == "0,0,NORTH");
}

TEST_CASE("turn right give correct coordinate")
{
    Robot rob(5, 5);
    rob.place(0, 0, "NORTH");
    rob.right();
    REQUIRE(rob.report() == "0,0,EAST");
    rob.right();
    REQUIRE(rob.report() == "0,0,SOUTH");
    rob.right();
    REQUIRE(rob.report() == "0,0,WEST");
    rob.right();
    REQUIRE(rob.report() == "0,0,NORTH");
    rob.right();
    REQUIRE(rob.report() == "0,0,EAST");
}

/*
    Move Tests
*/
TEST_CASE("move north to space")
{
    Robot rob(5, 5);
    rob.place(0, 0, "NORTH");
    rob.move();
    REQUIRE(rob.report() == "0,1,NORTH");
}

TEST_CASE("move north to out of bounds")
{
    Robot rob(5, 5);
    rob.place(0, 4, "NORTH");
    rob.move();
    REQUIRE(rob.report() == "0,4,NORTH");
}

TEST_CASE("move south to space")
{
    Robot rob(5, 5);
    rob.place(0, 4, "SOUTH");
    rob.move();
    REQUIRE(rob.report() == "0,3,SOUTH");
}

TEST_CASE("move south to out of bounds")
{
    Robot rob(5, 5);
    rob.place(0, 0, "SOUTH");
    rob.move();
    REQUIRE(rob.report() == "0,0,SOUTH");
}

TEST_CASE("move west to space")
{
    Robot rob(5, 5);
    rob.place(4, 0, "WEST");
    rob.move();
    REQUIRE(rob.report() == "3,0,WEST");
}

TEST_CASE("move west to out of bounds")
{
    Robot rob(5, 5);
    rob.place(0, 0, "WEST");
    rob.move();
    REQUIRE(rob.report() == "0,0,WEST");
}

TEST_CASE("move east to space")
{
    Robot rob(5, 5);
    rob.place(0, 0, "EAST");
    rob.move();
    REQUIRE(rob.report() == "1,0,EAST");
}

TEST_CASE("move east to out of bounds")
{
    Robot rob(5, 5);
    rob.place(4, 0, "EAST");
    rob.move();
    REQUIRE(rob.report() == "4,0,EAST");
}
