.PHONY: all clean

CPPFLAGS=-Wall -Wextra -pedantic
SHARED_DEPS=robot.o
MAIN_DEPS=$(SHARED_DEPS) main.cpp
TEST_DEPS=$(SHARED_DEPS) test.cpp test.cpp catch/catch_amalgamated.cpp

main: $(MAIN_DEPS)
test: $(TEST_DEPS)
all: main test

robot.o: robot.cpp robot.h
	$(CXX) $(CPPFLAGS) -c $< robot.cpp

clean:
	rm -f main test robot.o
