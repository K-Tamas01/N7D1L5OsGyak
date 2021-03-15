#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void abort(void);
void exit(int status);

int main()
{
    int status;
    int pid = fork();
    if(pid==0)
    {
        exit(7);
    }
    else if(pid<0)perror("Error:");
    if(wait(&status)!=pid)perror("wait hiba");
    if(WIFEXITED(status))
        printf("Normális befejeződés, vissza adott érték = %d\n",WEXITSTATUS(status));
    if((pid=fork())<0)perror("Hiba:");
    else if(pid==0)
        abort();
    if(wait(&status)!=pid)perror("wait hiba");
    if(WIFSIGNALED(status))
        printf("Abnormális befejeződés, a szignál sorszáma = %d\n",WTERMSIG(status));
    return 0;
}
