
# Frontier Technical Challenge

This project uses make to build the tests and program. Tested on linux only.

## Tests
Use the following command to build and run the tests.

```make test && ./test```

This program uses Catch as a simple unit testing framework. 
It is the single file version of Catch, which is included in this repo. The single file version can be found in the Catch2 [github repo](https://github.com/catchorg/Catch2), in the [extras](https://github.com/catchorg/Catch2/tree/devel/extras) directory.
I did not include Catch as a submodule, to keep it simple.

## To build and run main

```make && ./main```

Make any required changes in the main function in main.cpp, recompile and run to see the robot in action.

## To clean

```make clean```
