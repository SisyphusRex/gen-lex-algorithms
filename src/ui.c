#include <stdio.h>
#include <ui.h>

// This is the only function available outside of this file.  All other functions are helper functions.
int PrintMenuAndGetMenuInput(char *menu[])
{
    int numberOfMenuItems = sizeof(menu) / sizeof(menu[0]);
    char *userInput;
    int isValid = -1;
    int convertedInput;

    while (isValid < 0)
    {
        PrintMenu(numberOfMenuItems, menu);
        PrintInputRequest();
        userInput = GetMenuInput(numberOfMenuItems);
        isValid = ValidateInput(userInput, numberOfMenuItems);
    }
    sscanf(userInput, "%d", &convertedInput);
    return convertedInput;
}

static void PrintMenu(int numberOfMenuItems, char *menu[])
{
    for (int i = 0; i < numberOfMenuItems; i++)
    {
        printf("%d. %s", i + 1, menu[i]);
    }
    printf("\n");
}

static void PrintInputRequest(void)
{

    printf("Enter menu selection:\n");
    printf("> ");
}

static char *GetMenuInput(int numberOfMenuItems)
{
    // Here we use fgets() to prevent buffer overflow
    char buff[10];
    int numCharacters = 2;
    char *userInput = NULL;
    fgets(buff, numCharacters, stdin);
    sscanf(buff, "%s", userInput);
    return userInput;
}

static int ValidateInput(char *userInput, int numberOfMenuItems)
{
    int convertedInput;
    if (ValidateIsInt(userInput) < 0)
    {
        return -1;
    }
    sscanf(userInput, "%d", &convertedInput);
    if (ValidateIsPositiveInt(convertedInput) < 0)
    {
        return -1;
    }
    if (ValidateIsInMenu(convertedInput, numberOfMenuItems) < 0)
    {
        return -1;
    }
    return 1;
}

static int ValidateIsInt(char *userInput)
{

    int convertedToInt;
    if (sscanf(userInput, "%d", &convertedToInt) == 1)
    {
        return 1;
    }
    else
    {
        ErrorNotInt();
        return -1;
    }
}

static int ValidateIsPositiveInt(int convertedInput)
{
    if (convertedInput > 0)
    {
        return 1;
    }
    else
    {
        ErrorNotPositiveInt();
        return -1;
    }
}

static int ValidateIsInMenu(int convertedInput, int numberOfMenuItems)
{
    if (convertedInput <= numberOfMenuItems)
    {
        return 1;
    }
    else
    {
        ErrorNotInMenu();
        return -1;
    }
}

static void ErrorNotInt(void)
{
    printf("Not an integer.\nYou must enter an integer.\n\n");
}

static void ErrorNotPositiveInt(void)
{
    printf("Not a positive integer.\nYou must enter a positive integer.\n\n");
}

static void ErrorNotInMenu()
{
    printf("Your selection is not in the menu.\n\n");
}