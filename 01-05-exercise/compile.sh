#!/bin/bash

# Install required packages
sudo apt-get update
sudo apt-get install -y libglfw3 libglfw3-dev libglu1-mesa-dev mesa-common-dev

# Compile the code
g++ -o cube cube.cpp -lGL -lGLU -lglfw

# Run the program
./cube
