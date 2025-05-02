#include <stdio.h>

void Reset(void)
{
    printf("\033[0m");
}

void PrintRed(char *message)
{
    printf("\033[31m");
    printf("%s", message);
    Reset();
}
