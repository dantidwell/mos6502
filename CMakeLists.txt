cmake_minimum_required(VERSION 3.9.4)


if(MSVC) 
  add_compile_options(/W4)
else() 
  add_compile_options(-Wall -Wextra -Wpedantic)
  add_compile_options(-std=c++14)
endif() 

add_executable(cpu cpu.cpp)