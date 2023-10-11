from enum import Enum

class Direction(Enum):
  NORTH = 1
  EAST = 2
  SOUTH = 3
  WEST = 4
  @classmethod
  def anticlockwise(cls, direction):
    return cls.WEST if direction == cls.NORTH else Direction(direction.value - 1)
  @classmethod
  def clockwise(cls, direction):
    return cls.NORTH if direction == cls.WEST else Direction(direction.value + 1)


class Robot:
  def __init__(self, height, width):
    self.height = height
    self.width = width
    self.x = -1
    self.y = -1
    self.direction = None


  def place(self, x, y, direction):
    if x < 0 or x >= self.width:
      raise ValueError('out of bounds')
    if y < 0 or x >= self.height:
      raise ValueError('out of bounds')
    
    self.x = x
    self.y = y
    self.direction = direction
    print(f'robot placed ok {self}')


  def left(self):
    if self.x == -1:
      raise ValueError('can\'t turn robot unless its been placed')
    self.direction = Direction.anticlockwise(self.direction)
    print(f'robot turned left {self}')


  def right(self):
    if self.x == -1:
      raise ValueError('can\'t turn robot unless its been placed')
    self.direction = Direction.clockwise(self.direction)
    print(f'robot turned right {self}')


  def move(self):
    if self.x == -1:
      raise ValueError('can\'t move robot unless its been placed')
    
    if self.direction == Direction.NORTH:
      if self.y >= (self.height - 1):
        raise ValueError('cannot move')
      print('move north')
      self.y += 1
    elif self.direction == Direction.EAST:
      if self.x >= (self.width - 1):
        raise ValueError('cannot move')
      print('move east')
      self.x += 1
    elif self.direction == Direction.SOUTH:
      if self.y <= 0:
        raise ValueError('cannot move')
      print('move south')
      self.y -= 1
    elif self.direction == Direction.WEST:
      if self.x <= 0:
        raise ValueError('cannot move')
      print('move west')
      self.x -= 1
    else:
      raise ValueError('the robot had an invalid direction')
    print(f'robot moved {self}')


  def report(self):
    if self.x == -1:
      raise ValueError('can\'t report unless robot has been placed')
    return f'{self.x}, {self.y}, {self.direction}'


  def __str__(self):
    return f'x:{self.x}, y:{self.y}, direction:{self.direction}'


if __name__ == '__main__':
  robot = Robot(5, 5)
  while True:
    line = input(':')

    if line:
      try:
        cmd, *params = line.split(' ')
        if cmd == 'q':
          break
        elif cmd == 'place':
          x, y, direction = params
          robot.place(int(x), int(y), Direction[direction])
        elif cmd == 'left':
          robot.left()
        elif cmd == 'right':
          robot.right()
        elif cmd == 'move':
          robot.move()
        elif cmd == 'report':
          print(robot.report())
        else:
          print(f'invalid command {cmd}')
      except Exception as e:
        print('error:', e)
