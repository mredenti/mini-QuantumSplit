############
# Preamble
############

cmake_minimum_required(VERSION 3.21.4)

project(mini-QuantumSplit 
        LANGUAGES CXX)   
 
### Options
        
###############
# Dependencies
###############

include(dependencies.cmake)

###
###
add_subdirectory(src)