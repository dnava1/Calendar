#include<stdio.h>
#include<string.h>
#define MAX_COMMAND_TOKEN_LENGTH 15
char getCommandWord(char command[], int maxLength);
int monthDays(int month, int year);
void handleCount(void);
int count(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear);
void handlePrint(void);
int isLeapYear(int year);
