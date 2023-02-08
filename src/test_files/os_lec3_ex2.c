//
//  os_lec3_ex2.c
//  
//  EECE.4810/5730
//  Dr. Michael Geiger
//  1/29/17
//	In-class example program for second lecture
//

#include <sys/types.h>		// Needed for pid_t data type
#include <sys/wait.h>		// Necessary on my Mac for wait() function
#include <stdio.h>
#include <unistd.h>			// Needed for system calls
							// Header file for POSIX API

int nums[5] = {0,1,2,3,4};

int main() {
	int i;
	pid_t pid;
	
	pid = fork();
	
	if (pid == 0) {
		for (i = 0; i < 5; i++) {
			nums[i] *= -i;
			printf("CHILD: %d\n", nums[i]);
		}
	}
	else if (pid > 0) {
		wait(NULL);
		for (i = 0; i < 5; i++)
			printf("PARENT: %d\n", nums[i]);
	}
}
