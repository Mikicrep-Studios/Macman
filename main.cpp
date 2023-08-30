#include <iostream>
#include <cstring>
#include <fstream>
#include <unistd.h>
#include <rapidjson/document.h>

int main(int argc, char* argv[]) {
	if(argc >= 2 && strcmp(argv[1], "-S") == 0) {
		// Get package name
		const char* package = argv[2];

		// Loading database
		std::ifstream file("macman.mdb");
		std::string mdb_file((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
   		file.close();
		
		// Turn into json
		rapidjson::Document mdb;
		mdb.Parse(mdb_file.c_str());

		// Prepare command for downloading file
		
		// Make non-const copies of the strings
        std::string destCopy = mdb[package]["dest"].GetString();
        std::string urlCopy = mdb[package]["url"].GetString();
		
		const char* args[6];
		args[0] = "echo";
		args[1] = "curl";
		args[2] = urlCopy.c_str();
		args[3] = "-Lo";
		args[4] = destCopy.c_str();
		args[5] = NULL;

		char* execargs[6];
        for (int i = 0; i < 5; ++i) {
            execargs[i] = const_cast<char*>(args[i]);
        }

		// Prepare command for adding perms
		/*const char* argsp[4];
		argsp[0] = "sudo";
		argsp[1] = "chmod";
		argsp[2] = "777";
		argsp[3] = destCopy.c_str();*/
	
		/*char* execargsp[4];
		for (int i = 0; i < 3; i++) {
			execargsp[i] = const_cast<char*>(argsp[i]);
		}*/
		
		pid_t child_pid;
		child_pid = fork();
		if(child_pid == 0) {
			// Execute command we just made
			execvp(args[0], execargs);
			//execvp(argsp[0], execargsp);
			// Exit if error
			exit(1);
		}
	}
	// Make variables
	//pid_t child_pid;

	// Create child process
	//child_pid = fork();
		//if(child_pid == 0) {
			//execvp(args[0], args);

			// Exit if error
			//exit(1);
		//}
}
