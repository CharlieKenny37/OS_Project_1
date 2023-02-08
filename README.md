TODO

# Data Structures Program - by Charlie Kenny 2/6/2023

The data_structures_test.cpp program reads a file containing a list of newline delineated integers and stores the integers in three different data structures: a list, a queue, and a stack. The list is then sorted from smallest to largest, and the contents of all three data structures are printed to the screen.

## Compiling the Program
To compile the program, unzip the program using an archive manager of your choosing, and then place the unzipped folder in a 
directory of your choosing. Note before running the program, the g++ compiler, cmake, and make need to be installed on the linux system. Then inside of the build folder included inside of the project folder, run the following commands:

    cmake ../src
    make

This will create the data_structures_test executable in the build directory.

## Running the Program
While still in the build directory, run the following following command:

./data_structures_test <filename>

Replace <filename> with the name of the file containing the list of integers. The file must be located in the same directory as the program.

## Output

The program will output the contents of the list, queue, and stack data structures to the screen. The example output for "file1.txt" is shown below.

./data_structures_test file1.txt

QUEUE CONTENTS:
48 10 57 30 -5 5 1 31 20 -9

STACK CONTENTS:
-9 20 31 1 5 -5 30 57 10 48

LIST CONTENTS:
-9 -5 1 5 10 20 30 31 48 57
