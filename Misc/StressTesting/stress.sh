#!/bin/bash

# solution.cpp  is a solution you want to stress test
# stupid.cpp    is a stupid but correct solution
# gen.cpp       generates a new random test for the problem

# compile all programs first
g++ solution.cpp -o solution
g++ stupid.cpp -o stupid
g++ gen.cpp -o gen

while true
do
  # generate a new test case in the file named "in"
  ./gen > in
  # output the solution output to the "out" file
  ./solution < in > out
  # output the stupid solution output to the "out-stupid" file
  ./stupid < in > out-stupid

  # compare both outputs.
  # if outputs are different, echo the 
  # corresponding message and break the loop.
  # failing test will be in the "in" file.
  if ! cmp -s out out-stupid
  then
    echo 'Found failing test!'
    break
  fi

  # if outputs are the same, we echo "OK".
  # this is optional, but helps to see the progress of stress testing.
  echo 'OK'
done
