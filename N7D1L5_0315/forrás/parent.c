#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include "child.c"

int main()
{
    int pid = fork();
    if(pid == 0)
    {
        kiiras();
    }
    else if(pid<0)perror("fork error");
    return 0;
}
