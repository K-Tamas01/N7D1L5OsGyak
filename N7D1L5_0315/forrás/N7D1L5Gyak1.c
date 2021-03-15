#include <stdio.h>
#include <stdlib.h>

int main()
{
    int status;
    if((status=system("lsa"))<0)
    perror("system()error");

    if(WIFEXITED(status))
    printf("Normális befejeződés, visszaadott érték= %d\n",WEXITSTATUS(status));
    exit(0);
    return 0;
}
