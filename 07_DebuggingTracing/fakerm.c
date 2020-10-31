#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h> 
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>


typedef int (* intvoid)(int , char *, int );

int unlinkat(int fd, char* str, int flag) {
	intvoid oldunlink;
	if (strstr(str, "FIX") != NULL){
		return(EPERM);
	}
	oldunlink = (intvoid)dlsym(RTLD_NEXT, "unlinkat");
	return oldunlink(AT_FDCWD, str, 0);
}
