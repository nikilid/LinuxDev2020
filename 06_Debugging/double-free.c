#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int size = 1024;
    char* str = (char*)malloc(size);
    for (int i = 0; i < size; i++){
    	str[i] = '0';
    }
    free(str);
    free(str);
    return 0;
}