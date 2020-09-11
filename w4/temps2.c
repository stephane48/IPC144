/* Stephane Kamdem Kamguia        *
 * 135736189                      *
 * skamdem-kamguia@myseneca.ca    *
 * IPC144NPP                      *
 **********************************/



#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX_DAYS 10

	int main() {

	int n;
	int day;
	int highTemp[MAX_DAYS];
	int lowTemp[MAX_DAYS];

	printf("---=== IPC Temperature Calculator V2.0 ===---\n");
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &n);
	printf("\n");
	while (n < 3 || n > 10) {
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &n);
	};
	printf("\n");
	 for (day = 1; day <= n; day++) {
		printf("Day %d - High: ", day);
		scanf("%d", &highTemp[day]);
		printf("Day %d - Low: ", day);
		scanf("%d", &lowTemp[day]);
		
	}
	printf("\n");
	printf("Day  Hi  Low\n");
	   for (day = 1; day <= n; day++) {
		printf("%d    %d    %d\n", day, highTemp[day], lowTemp[day]);
	}



	return 0;
}


