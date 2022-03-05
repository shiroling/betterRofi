#ifndef POPEN3_H_
#define POPEN3_H_

#include <stdio.h>
#include <unistd.h>
#include <paths.h>
#include <stdlib.h>

typedef struct {
	FILE *in, *out, *err;
} stdpipes;

void closeBooth(int pair[2]);
stdpipes popen3(const char *command);



#endif