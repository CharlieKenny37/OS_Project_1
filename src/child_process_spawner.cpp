/*
 * Charlie Kenny and Ryan Donald
 * 2/7/2023
 * EECE.4811 Operating Systems
 * Project 1
 * child_process_spawner.cpp will create a specified number of child processes running a set of test programs. The number of child processes
 * 	that will be created will be given as a command line argument. The status of each child will be printed to the screen throughout the 
 * 	duration of the childrens' lifetimes.
 */

#include <sys/types.h>		// Needed for pid_t data type
#include <sys/wait.h>		// Necessary on my Mac for wait() function
#include <stdio.h>
#include <unistd.h>			// Needed for system calls
							// Header file for POSIX API
#include <stdlib.h>
#include <map>
#include <iostream>

int main(int argc, char* argv[])
{
	// Determine the number of processes to spawn
	int num_processes_to_spawn = 5;
	if(argc == 2)
		num_processes_to_spawn = atoi(argv[1]);

	std::map<pid_t, int> child_processes;
	pid_t current_pid = getpid();

	// Print the parent PID
	std::cout << "Parent pid is " << current_pid << std::endl;

	// Launch the child processes
	bool is_child = false;
	for(int loop = 0; loop < num_processes_to_spawn; loop++)
	{
		// Get the current process ID from the fork
		current_pid = fork();

		// Check if the current running process is a child process
		if(current_pid == 0)
		{
			is_child = true;
			break;
		}

		// In the parent process, print the child process that were started
		std::cout << "Started child " << loop + 1 << " with pid " << current_pid << std::endl; 

		child_processes[current_pid] = loop + 1;
	}
	
	if(current_pid == 0)
		current_pid = getpid();
	
	if (is_child)
	{
		// to get an approximate even distribution of test programs running, determine which program to run based off of a modulus
		// operation on the current pid
		switch(current_pid % 5)
		{
			// TODO, launch the respective C file tasks
			case 0:
				std::cout << "Running program test1 in process " << current_pid << std::endl;
				current_pid = fork();
				execlp("test_files/", "./test1", NULL);

				// if(current_pid==0) {
				// 	exec("test_files/test1")
				// }

				break;
			case 1: 
				std::cout << "Running program test2 in process " << current_pid << std::endl;
				//current_pid = fork();
				execlp("test_files/", "./test2", NULL);

				break;
			case 2: 
				std::cout << "Running program test3 in process " << current_pid << std::endl;
				//current_pid = fork();
				execlp("test_files/", "./test3", NULL);

				break;
			case 3: 
				std::cout << "Running program test4 in process " << current_pid << std::endl;
				//current_pid = fork();
				execlp("test_files/", "./test4", NULL);

				break;
			case 4: 
				std::cout << "Running program test5 in process " << current_pid << std::endl;
				//current_pid = fork();
				execlp("test_files/", "./test5", NULL);

				break;
		}
	}

	else
	{
		// Wait for all of the child processes to finish
		while(!child_processes.empty())
		{
			pid_t finished_pid = wait(NULL);

			// Print the status of the finishing child processes and remove them from the dictionary of active children processes
			std::cout << "Child " << child_processes[finished_pid] << " (PID " << finished_pid << ") finished" << std::endl;
			child_processes.erase(finished_pid);
		}
			
	}
}
