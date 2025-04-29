#ifndef UI_H
#define UI_H

int PrintMenuAndGetMenuInput(char *menu[]);
static int CountMenuItems(char *menu[]);
static void PrintMenu(int numberOfMenuItems, char *menu[]);
static char *GetMenuInput(int numberOfMenuItems);
static void PrintInputRequest(void);
static int ValidateInput(char *userInput, int numberOfMenuItems);
static int ValidateIsInt(char *userInput);
static int ValidateIsPositiveInt(int convertedInput);
static int ValidateIsInMenu(int convertedInput, int numberOfMenuItems);
static void ErrorNotInt(void);
static void ErrorNotPositiveInt(void);
static void ErrorNotInMenu();

#endif