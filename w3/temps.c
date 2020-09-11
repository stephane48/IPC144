// Name: stephane kamdem kamguia
// Student Number: 135736189
// Email: skamdem-kamguia@myseneca.ca
// Section: IPC144NPP
// Workshop: W3_Home




#define _CRT_SECURE_NO_WARNINGS
#define NUMS 4 
#include <stdio.h>

int main(void) {
	int dayCount, highDay, lowDay;
	int highest = -41; //Highest is set below any possible value.
	int lowest = 41;
	int lowTemp;
	int highTemp;
	double average;
	double averageHigh;
	double averageLow;
	double totHigh = 0;
	double totLow = 0;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (dayCount = 1; dayCount <= NUMS; dayCount++)
	{
		printf("Enter the high value for day %d: ", dayCount);
		scanf("%d", &highTemp);
		printf("\nEnter the low value for day %d: ", dayCount);
		scanf("%d", &lowTemp);

		while (highTemp < lowTemp || highTemp >= 41 || lowTemp <= -41)
		{
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\nEnter the high value for day %d: ", dayCount);
			scanf("%d", &highTemp);
			printf("\nEnter the low value for day %d: ", dayCount);
			scanf("%d", &lowTemp);
                       
                       
		}
		if (highTemp > highest && highTemp < 41) { //If the days temperature exceeds highest and valid, the new highest value is assigned, the current day count applied.
			highest = highTemp;    
			highDay = dayCount;  // highDay is the date that has the highest temperature

		}if (lowTemp < lowest && lowTemp > -41) { //If the days temperature is below lowestand valid, the new lowest value is assigned, the current day count applied.
			lowest = lowTemp;
			lowDay = dayCount;   // lowDay is the day that has the lowest temperature

		} // those if will determine the highest and the lowest temperature the excat day

		totHigh += highTemp;
		totLow += lowTemp;
                printf("\n");
	}

	average = (totHigh + totLow) / (NUMS * 2);
	averageHigh = totHigh / (NUMS * 1);
	averageLow = totLow / (NUMS * 1);
         
	printf("The average (mean) LOW temperature was: %.2lf\n", averageLow);
	printf("The average (mean) HIGH temperature was: %.2lf\n", averageHigh);
	printf("The average (mean) temperature was: %.2lf\n", average);
	printf("The highest temperature was %d, on day %d\n", highest, highDay);//Statement on the highest temperature and which day it occured.
	printf("The lowest temperature was %d, on day %d\n", lowest, lowDay);//Statement on the lowest temperature and which day it occured.

	return 0;
}
