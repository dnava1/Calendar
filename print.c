#include"calendar.h"


void print(int MM, int YYYY) {
	
	printf("\n   Su   Mo   Tu   We   Th   Fr   Sa\n\n");
	
	
	int d = 1; 
	int m = MM; 
	int y = YYYY; 
	int weekday = (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;
	//Using the Doomsday algorithm to determine the day of the week of day 1 in a given month
	
	int howManyDays =monthDays(MM, YYYY);
	//getting the number of days in a given month
	
	int j;
	for (j = 0;j < weekday;j++) {
		printf("     ");
		//determining how many white spaces to print by seeing what day the week starts in
	}
	for (int i = 1;i <= howManyDays; i++) {
		printf("%5d", i);
		if (++j > 6) {
			j = 0;
			printf("\n\n");
		}
		//Prints the number and when it gets to the Saturday which is value 6, it prints a new line, continues printing numbers
		
	}
	printf("\n\n");


	
	
}

void handlePrint(void) {
	int MM, YYYY;
	scanf_s("%d/%d",&MM,&YYYY);
	//taking an input from the user 
	if (YYYY <= 9999 && YYYY>=1)
	{
		if (MM >= 1 && MM <= 12) {
			print(MM, YYYY);
		}
		else
			printf("The date you entered is invalid\n\n");
	}
	else
	{
		printf("The date you entered is invalid\n\n");
	}
	
	//loop that calls the print function if it receives valid input
	
}