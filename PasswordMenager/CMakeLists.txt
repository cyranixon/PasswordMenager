cmake_minimum_required(VERSION 3.24)
project(PR)

set(CMAKE_CXX_STANDARD 23)

add_executable(PR main.cpp Password.cpp Password.h PasswordManager.cpp PasswordManager.h)
