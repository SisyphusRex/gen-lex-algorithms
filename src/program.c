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
    int running = 1;

    while (running == 1)
    {
        int userInput = PrintMenuAndGetMenuInput(menu);

        switch (userInput)
        {
        case 1:
            // Enter Permutation Menu
            int permNumber;
            permNumber = PrintPromptGetNaturalNumber("Enter Natural Number for set {1,...,n} to get lexicographic permutations.");
            break;
        case 2:
            // Enter Subset Menu
            int subsetNumber;
            subsetNumber = PrintPromptGetNaturalNumber("Enter Natural Number for set {1,...,n} to get lexicographic subsets.");
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
    }

    return 0;
}