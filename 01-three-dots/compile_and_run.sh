#!/bin/bash

# Compile the program
g++ -o dots main.cpp -lGL -lGLU -lglut

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    # Run the program
    ./dots
else
    echo "Compilation failed. Please check for any errors."
fi

