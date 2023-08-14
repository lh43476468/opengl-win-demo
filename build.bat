@echo off
cd build && ^
cmake -G "Visual Studio 17 2022" -A x64 .. && ^
cmake --build . -j 34 --config Debug