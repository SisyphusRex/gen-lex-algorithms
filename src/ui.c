#include <stdio.h>
#include <ui.h>

void PrintMenu(int numberOfMenuItems, char *menu[])
{
    for (int i = 0; i < numberOfMenuItems; i++)
    {
        printf("%d. %s", i, menu[i]);
    }
}

int PrintMenuAndGetMenuInput(int numberOfMenuItems, char *menu[])
{
    for (int i = 0; i < numberOfMenuItems; i++)
    {
        printf("%d. %s", i, menu[i]);
    }
    PrintMenu(numberOfMenuItems, menu);
}