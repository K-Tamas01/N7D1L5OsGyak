#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int pid = fork();
    if(pid==0)
    {
        execlp("main.txt","test");
    }
    else if(pid<0)perror("Hiba:");
    return 0;
}
