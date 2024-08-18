cmake_minimum_required(VERSION 3.28)
project(max_kcut)

set(CMAKE_CXX_STANDARD 17)

add_executable(max_kcut src/main.cpp
        src/Graph.cpp
        src/Graph.h
        src/GeneticAlgorithm.cpp
        src/GeneticAlgorithm.h
        src/GAIndividual.cpp
        src/GAIndividual.h
        src/BruteForce.cpp
        src/BruteForce.h
        src/Greedy.cpp
        src/Greedy.h)
