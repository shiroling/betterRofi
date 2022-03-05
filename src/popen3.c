#include "popen3.h"


void closeBooth(int pair[2]) {
	close(pair[0]);
	close(pair[1]);
}


stdpipes popen3(const char *command) {
	stdpipes result = {.out = NULL, .in = NULL, .err = NULL};

	int sout_pair[2], sin_pair[2], serr_pair[2];
	pid_t pid;

	if (pipe(sout_pair) < 0)
	{
		return result;
	}
	if (pipe(serr_pair) < 0)
	{
		closeBooth(sout_pair);
		return result;
	}
	if (pipe(sin_pair) < 0) {
		closeBooth(sout_pair);
		closeBooth(serr_pair);
		return result;
	}

	pid =  vfork(); // clone process
	if (pid < 0) {  // Case of ERROR
		closeBooth(sout_pair);
		closeBooth(serr_pair);
		closeBooth(sin_pair);
		return result;
	}

	if (pid == 0) {   //CHILD PROCESS
		dup2(sout_pair[1], STDOUT_FILENO);
		closeBooth(sout_pair);

		dup2(serr_pair[1], STDERR_FILENO);
		closeBooth(serr_pair);

		dup2(sin_pair[0], STDIN_FILENO);
		closeBooth(sin_pair);


		execl("/bin/bash", "bash ", "-c", command, NULL);
		exit(127);
	}

	//PARENT
	result.out = fdopen(sout_pair[0], "r");  // Allows us ti use fscanf, fget ..
	close(sout_pair[1]);

	result.err = fdopen(serr_pair[0], "r");  // Allows us ti use fscanf, fget ..
	close(serr_pair[1]);

	result.in = fdopen(sin_pair[1], "w");  // Allows us ti use fscanf, fget ..
	close(sin_pair[0]);

	return result;
}	


