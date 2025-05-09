#include <stdio.h>
#include "program.h"
#include "ui.h"

int run(int argCount, char *passedArgs[])
{
    /*
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
    */

    const char *menu[] = {"Permutations.", "Subsets.", "Exit.", NULL};

    int userInput = PrintMenuAndGetMenuInput(menu);

    switch (userInput)
    {
    case 1:
        // Enter Permutation Menu
        int userNaturalNumber;
        userNaturalNumber = PrintPromptGetNaturalNumber("Enter Natural Number for set {1,...,n} to get lexicographic permutations.");
        break;
    case 2:
        // Enter Subset Menu

        break;
    case 3:
        // Exit program
        Goodbye();
        return 0;
    default:
        // No match.
        ErrorSwitchCase();
        return 1;
    }

    return 0;
}