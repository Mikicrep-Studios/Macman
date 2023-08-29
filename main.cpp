#include <iostream>
#include <cstring>
#include <unistd.h>

int main(int argc, char* argv[]) {
	if(strcmp(argv[1], "-S") == 0) {
		// TODO: Fancy mirror stuff
		if(strcmp(argv[2], "neofetch") == 0) {
			std::cout << "mirror tmp api working";
		}
	}
	// Make variables
	//char* args[512 + 1];
	//char* workingdir = "./neofetch";
	//char* url = "https://github.com/Mikicrep-Studios/Neofetch/releases/download/release/neofetch";
	//pid_t child_pid;
	
	//args[0] = "curl";
	//args[1] = url;
	//args[2] = "-Lo";
	//args[3] = workingdir;
	//args[4] = NULL;

	// Create child process
	//child_pid = fork();
		//if(child_pid == 0) {
			//execvp(args[0], args);

			// Exit if error
			//exit(1);
		//}
}
