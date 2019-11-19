#!/bin/bash

# solution.cpp  solution you want to stress test
# stupid.cpp    stupid solution for the problem
# gen.cpp       generates a new random test case for the problem

# compile all programs first
g++ solution.cpp -o solution
g++ stupid.cpp -o stupid
g++ gen.cpp -o gen

for ((i = 1; ;i++)) do
  # generate a new test case in the file named "in"
  # note that we pass i as a random seed to the generator
  ./gen $i > in
  # redirect the solution output to the "out" file
  ./solution < in > out
  # redirect the stupid solution output to the "out-stupid" file
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
