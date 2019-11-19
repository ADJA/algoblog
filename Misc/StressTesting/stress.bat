@echo off

g++ solution.cpp -o solution.exe
g++ stupid.cpp -o stupid.exe
g++ gen.cpp -o gen.exe

set i=0

:loop
  gen.exe %i% > in
  solution.exe < in > out
  stupid.exe < in > out-stupid

  fc out out-stupid
  if errorlevel 1 goto fail

  echo OK
  set /a i=%i%+1
  goto loop

:fail
  echo Found failing test!
