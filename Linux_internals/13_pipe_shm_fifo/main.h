#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<ctype.h>
#include<fcntl.h>
#include<sys/mman.h>
#include <sys/stat.h>

#define FIFO_NAME "/tmp/p1"
#define MAX_STRING_LEN 80
#define SMSIZE 100
