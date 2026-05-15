cmake_minimum_required(VERSION 3.10)
project(lab5)

set(TASK1_SRC 
    task1/main.cpp 
    task1/BigInt.cpp
)
add_executable(Task1 ${TASK1_SRC})

set(TASK2_SRC 
    task2/main.cpp
    task2/logic.cpp
)   
add_executable(Task2 ${TASK2_SRC}) 

set(TASK3_SRC 
    task3/main.cpp
    task3/logic.cpp
)
add_executable(Task3 ${TASK3_SRC})