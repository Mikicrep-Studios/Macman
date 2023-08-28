#include <iostream>
#include <unistd.h>

int main() {
	// Make variables
	char* args[512 + 1];
	char* workingdir = "./neofetch";
	char* url = "https://github.com/Mikicrep-Studios/Neofetch/releases/download/release/neofetch";
	pid_t child_pid;
	
	args[0] = "curl";
	args[1] = url;
	args[2] = "-Lo";
	args[3] = workingdir;
	args[4] = NULL;

	// Create child process
	child_pid = fork();
		if(child_pid == 0) {
			execvp(args[0], args);

			// Exit if error
			exit(1);
		}
}
