#include <stdio.h>
#include <program.h>

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

    char *menu[] = {"Go forward.", "Go Back"};
    int userInput = PrintMenuAndGetMenuInput(menu);
    printf("%d", userInput);
}