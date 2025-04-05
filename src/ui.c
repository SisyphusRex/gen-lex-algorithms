#include <stdio.h>
#include <ui.h>

int PrintMenuAndGetMenuInput(int numberOfMenuItems, char *menu[])
{
    int userInput = -1;
    for (int i = 0; i < numberOfMenuItems; i++)
    {
        printf("%d. %s", i, menu[i]);
    }

    while (userInput < 0)
    {
        PrintMenu(numberOfMenuItems, menu);
        PrintInputRequest();
        userInput = GetMenuInput(numberOfMenuItems);
    }
    return userInput;
}

void PrintMenu(int numberOfMenuItems, char *menu[])
{
    for (int i = 0; i < numberOfMenuItems; i++)
    {
        printf("%d. %s", i, menu[i]);
    }
}

void PrintInputRequest()
{

    printf("Enter menu selection:\n");
    printf("> \n");
}

int GetMenuInput(int numberOfMenuItems)
{
    char buff[10];
    int numCharacters = 2;
    int userInput;
    fgets(buff, numCharacters, stdin);
    userInput = ValidateIsInt(buff);
    if (userInput < 0)
    {
        return -1;
    }
    else if (ValidateInMenu(numberOfMenuItems, userInput) < 0)
    {
        return -1;
    }
    else
    {
        return userInput;
    }
}

int ValidateIsInt(char buff[])
{
    int userInput;
    if (sscanf(buff, "%d", &userInput))
    {
        return userInput;
    }
    else
    {
        ErrorNotInt();
        return -1;
    }
}

int ValidateInMenu(int numberOfMenuItems)
{
}

void ErrorNotInt()
{
    printf("Not an integer.\nYou must enter an integer.\n\n");
}