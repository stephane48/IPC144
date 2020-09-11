// Name: stephane kamdem kamguia
// Student Number: 135736189
// Email: skamdem-kamguia@myseneca.ca
// Section: IPC144NPP
// Workshop: W3_in lab



#define _CRT_SECURE_NO_WARNINGS
#define NUMS 3 
#include <stdio.h>

int main(void) {
	int dayCount;
	int lowTemp;
	int highTemp;


	printf("---=== IPC Temperature Analyzer ===---");

	for (dayCount = 1; dayCount <= NUMS; dayCount++)
	{
		printf("\nEnter the high value for day %d: ", dayCount);
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
	}
	return 0;
}