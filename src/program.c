#include <stdio.h>
#include <program.h>

void run(int argCount, char *passedArgs[])
{
    printf("You entered:\n");
    for (int i = 0; i < argCount; i++)
    {

        printf("%s\n", passedArgs[i]);
    }
}