#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/msg.h>
#define MAX_SIZE 10
#define MAX_TEXT 512
#define DATA_SIZE 50000


void validateNumberOfArguement(const int *input);