#include <stdio.h>
#include "program.h"
#include "ui.h"

void run(int argCount, char *passedArgs[])
{
    if (argCount > 0)
    {
        printf("You entered:\n");
        for (int i = 0; i < argCount; i++)
        {

            printf("%s\n", passedArgs[i]);
        }
    }
    else
    {
        printf("You entered no arguments.\n");
    }

    const char *menu[] = {"Go Forward.", "Go Back.", NULL};
    /*
    for (int i = 0; i < 2; i++)
    {
        printf("%s\n", menu[i]);
    }
    */

    int userInput = PrintMenuAndGetMenuInput(menu);
    printf("%d", userInput);
}