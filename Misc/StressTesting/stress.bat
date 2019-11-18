@echo off

:loop
  g++ solution.cpp -o solution.exe
  g++ stupid.cpp -o stupid.exe
  g++ gen.cpp -o gen.exe

  gen.exe > in
  solution.exe < in > out
  stupid.exe < in > out-stupid
  
  fc out out-stupid
  if errorlevel 1 
    goto fail
  
  echo OK
  goto loop

:fail
  echo Found failing test!