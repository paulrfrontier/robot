# Test Plan

The tests will be broken down into the following categories.

- utility function tests.
- test that calling other robot functions before place do not result in a valid report string.
- test that immediately after placing the robot it reports a correct location.
- test that out of bounds place fails for both negative coordinates and those larger than the grid.
- test that turning left and right gives gives correct direction for all directions.
- test moving when the destination is in bounds works for all directions.
- test moving when the destination is out of bounds does nothing for all directions.
