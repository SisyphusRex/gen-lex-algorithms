#ifndef UI_H
#define UI_H

int PrintMenuAndGetMenuInput(char *menu[]);
int CountMenuItems(char *menu[]);
void PrintMenu(int numberOfMenuItems, char *menu[]);
void GetMenuInput(int numberOfMenuItems, char *userInput);
void PrintInputRequest(void);
int ValidateInput(char *userInput, int numberOfMenuItems);
int ValidateIsInt(char *userInput);
int ValidateIsPositiveInt(int convertedInput);
int ValidateIsInMenu(int convertedInput, int numberOfMenuItems);
void ErrorNotInt(void);
void ErrorNotPositiveInt(void);
void ErrorNotInMenu();

#endif