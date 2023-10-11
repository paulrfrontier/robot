
from robot import Robot, Direction

if __name__ == '__main__':
  rob = Robot(5, 5)
  rob.place(0, 0, Direction.NORTH)
  rob.move()
  print(rob.report()); # => Output: 0, 1, NORTH
  rob.place(0, 0, Direction.NORTH)
  rob.left()
  print(rob.report() ) # => Output: 0, 0, WEST
  rob.place(1, 2, Direction.EAST)
  rob.move()
  rob.move()
  rob.left()
  rob.move()
  print(rob.report()) # => Output: 3, 3, NORTH
