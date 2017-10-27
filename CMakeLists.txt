cmake_minimum_required(VERSION 3.2.2)

#compile for c++14
set(CMAKE_CXX_STANDARD 14)

if(MSVC) 
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
  add_compile_options(/W4)
else() 
  add_compile_options(-Wall -Wextra -Wpedantic)
endif() 

add_executable(masm AssemblerMain.cpp SourceText.cpp Lexer.cpp)
