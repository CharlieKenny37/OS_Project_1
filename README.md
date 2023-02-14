# Data Structures Project 1 - by Charlie Kenny, Ryan Donald 2/13/2023

The child_process_spawner.cpp program creates five child processes, and each of these child processes then execute one of five test programs given to us. These programs are found in src/test_files/ and are named "test1.c", "test2.c", "test3.c", "test4.c", "test5.c".

## Compiling the Program
To compile the program, unzip the program using an archive manager of your choosing, and then place the unzipped folder in a 
directory of your choosing. Note before running the program, the g++ compiler, cmake, and make need to be installed on the linux system. Then inside of the build folder included inside of the project folder, run the following commands, in the following directories:

    In the src/ directory:
    make
    
    In the src/test_files/ directory:
    make

This will create the child_process_spawner executable in the src/ directory, as well as executables for each of the test programs in the src/test_files/ directory.

## Running the Program
While still in the src/ directory, run the following following command:

./project1 <number of processes>

Replace <number of processes> with the desired number of child processes to be created in the program.

## Output

The program will output the contents of the list, queue, and stack data structures to the screen. The example output for "file1.txt" is shown below.

./project1 3

Parent pid is 49031
Started child 1 with pid 49032
Running program test3 in process 49032
Started child 2 with pid 49033
Running program test4 in process 49033
Started child 3 with pid 49034
Running program test5 in process 49034
Running program test3 in process 49032
T3: PID 49032 is even
Running program test4 in process 49033
T4: PID 49033 has 5 digits
Child 1 (PID 49032) finished
Running program test5 in process 49034
T5: QS L[0-9]
T5: QS L[0-3]
T5: QS L[0-2]
T5: QS L[5-9]
T5: QS L[5-7]
Child 2 (PID 49033) finished
T5: QS L[5-6]
T5: Final list = 1 2 3 4 5 6 7 8 9 10 
Child 3 (PID 49034) finished
