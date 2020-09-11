/* Stephane Kamdem Kamguia        *
 * 135736189                      *
 * skamdem-kamguia@myseneca.ca    *
 * IPC144NPP                      *
 **********************************/




#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_DAYS 10
int main(void) {
	int days; //Number of days for temperature (between 3 and 10).
	int tempHigh[MAX_DAYS]; //Array for high temperature (max size is 10).
	int tempLow[MAX_DAYS]; //Arrayfor low temperature (max size is 10).
	int n; //Integer compare to days, for temperature requests.
	int highestTemp = -100; //Highest temperature, set to lowest probable value.
	int lowestTemp = 100; //Lowest temperature, set to highest probable value.
	int highestDay, lowestDay; //Days of highest and lowest temperatures.
	int userInput = 1; //Integer input for average temperature calculation. double averageTemp, averageTotal; //Average temperature per set of days, before and after division.
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &days);
	printf("\n"); //Blank line.
	while (days > MAX_DAYS || days < 3) { //If number of days is not within 3-10, request a valid entry again.
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &days); //Record and store integer as value of days.
		printf("\n"); //Add a blank line.
	}
	for (n = 0; n < days; n++) { //As long as "n" is less thandays, request value for the "n"th member of high temperature array.
		printf("Day %d - High: ", n + 1);
		scanf("%d", &tempHigh[n]);
		printf("Day %d - Low: ", n + 1); //As long as "n" is less than days, request value for the "n"th member of low temperature array.
		scanf("%d", &tempLow[n]);
		if (tempHigh[n] > highestTemp) { //Assigning new values to highest temperature and on which day it occured, per each iteration.
			highestTemp = tempHigh[n];
			highestDay = n + 1;
		}
		if (tempLow[n] < lowestTemp) { //New values for lowest temperature for the day it occured.
			lowestTemp = tempLow[n];
			lowestDay = n + 1;
		}
	}
	printf("\nDay  Hi  Low\n"); //Print a "chart" of high and low temperature for specified number of days.
	for (n = 0; n < days; n++) {
		printf("%d    %d    %d\n", n + 1, tempHigh[n], tempLow[n]);
	}
	printf("\nThe highest temperature was %d, on day %d", highestTemp, highestDay); //Print highest and lowest temperatures for apropriate days.
	printf("\nThe lowest temperature was %d, on day %d\n", lowestTemp, lowestDay);
	printf("\n");
	while (1) {
		double averageTotal = 0;
		double averageTemp;
		printf("Enter a number between 1 and 5 to see the average temperature for the entered number of days, enter a negative number to exit: ");
		scanf("%d", &userInput); //User input for number of days to measureaverage for.
		printf("\n"); //Blank line.
		while (userInput > 5 || userInput == 0) { //If input is not between 1 and 5, request a valid entry again.
			printf("Invalid entry, please enter a number between 1 and 5, inclusive: ");
			scanf("%d", &userInput);
			printf("\n"); //Blank line.
		}
		if (userInput > 0 && userInput < 6) {//If input is valid, perform addition of all temperature within the given range of days.
			for (n = 0; n < userInput; n++) {
				averageTotal = averageTotal + (double)tempHigh[n] + (double)tempLow[n]; //Running total sum within the range of days.
			}
			averageTemp = averageTotal / (double)(2 * n); //Total sum is divided by 2n to find average temperature.
			printf("The average temperature up to day %d is: %.2f\n", userInput, averageTemp);
			printf("\n");
		}
		if (userInput < 0) { //If input is negative, exit the program.
			printf("Goodbye!\n");
			return 0;
		}
	}
	return 0;
}
	
