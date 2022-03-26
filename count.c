#include"calendar.h"
int count(int fromMonth, int fromDay, int fromYear, int toMonth, int toDay, int toYear) {
	
	int negativeCounter = 0;

	if (toYear < fromYear || toYear == fromYear && toMonth < fromMonth) {
		int storageToYear = toYear;
		int storageToMonth = toMonth;
		int storageToDay = toDay;
		int storageFromYear = fromYear;
		int storageFromMonth = fromMonth;
		int storageFromDay = fromDay;

		toYear = storageFromYear;
		toMonth = storageFromMonth;
		toDay = storageFromDay;
		fromYear = storageToYear;
		fromMonth = storageToMonth;
		fromDay = storageToDay;

		negativeCounter = 1;
		//This loop swaps the dates if the from date is larger than the to date, sets counter to show it is in reverse order
	}

	int yearDifference = toYear - fromYear;
	int monthDifference = toMonth - fromMonth;
	int dayDifference = toDay - fromDay ;
	//Math variables

	int totalMonth = (yearDifference * 12) + monthDifference; 
	//Gets the amount of months between two days

	int numberOfDays = 0;
	//counter for number of days between two dates

	for (int i = 0; i < totalMonth;i++) {
		
		numberOfDays += monthDays(fromMonth, fromYear);
		//Adds the number of days in every month to counter
		
		if (fromMonth == 12) {
			fromMonth = 0;
			
			fromYear += 1;
			//If the month reaches 12, start at month 1 again, move to the next year
		}
		fromMonth += 1;
		
	}

	numberOfDays += dayDifference ;
	//adds the extra difference of days to the counter

	if (negativeCounter == 1) {
		numberOfDays *= -1;
	}
	//accounts for date written backwards
	return numberOfDays;
	
}



void handleCount(void) {
	int dd, DD, mm,MM, yyyy, YYYY;
	
	scanf_s("%d/%d/%d %d/%d/%d", &MM, &DD, &YYYY, &mm, &dd, &yyyy);
	if ((YYYY <= 9999 && YYYY >= 1) &&(yyyy <= 9999 && yyyy >= 1))
	{
		if ((MM >= 1 && MM <= 12) && (mm >= 1 && mm <= 12))
		{
			if ((DD >= 1 && DD <= 31) && (dd >= 1 && dd <= 31))
			{
				int finalCount = count(MM, DD, YYYY, mm, dd, yyyy);
				//calls function and stores int in finalCount
				printf("\n%d days between those two dates without including end date\n\n", finalCount);
			}
			else {
				printf("The date you entered is invalid\n\n");
			}
		}
		else {
			printf("The date you entered is invalid\n\n");
		}
	}
	else {
		printf("The date you enetered is invalid\n\n");
	}
	//loops that verifies if input is an actual acceptable date
}

int monthDays(int month, int year) {
	switch (month) {
	case 1: 
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
	case 2:
		if (isLeapYear(year))
			return 29;
		else
			return 28;
	}
	return -1;
	//returns the proper amount of days depending on the month
}

int isLeapYear(int year) //97 leap years in every 400 years... 365 days + 97/400
{
	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);//2000, 2020, 1600, 2024, 2016,... are leap years...
	//1900, 1800, 1700, 2100, 2002, 2019,... are not leap years...
}