#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 2// Define Number of Employees "SIZE" to be 2


struct Employee  // Declare Struct Employee
{
	int EmployeeID;
	int Age;
	double Salary;
};


/* main program */
int main(void)
{
	int option = 0;
	int i = 0;
	int count = 0;

	struct Employee emp[SIZE] = { {0} };// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero


	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option)
		{
		case 0:

			printf("Exiting Employee Data Program. Good Bye!!!\n");// Exit the program

			break;

		case 1: // Display Employee Data
				// @IN-LAB

			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			for (i = 0;i < SIZE;i++) {
				printf("%6d%9d%11.2lf\n", emp[i].EmployeeID, emp[i].Age, emp[i].Salary);
			}
			printf("\n");
			// Use "%6d%9d%11.2lf" formatting in a   
			// printf statement to display
			// employee id, age and salary of 
			// all  employees using a loop construct 

			// The loop construct will be run for SIZE times 
			// and will only display Employee data 
			// where the EmployeeID is > 0

			break;

		case 2:	// Adding Employee
				// @IN-LAB

			printf("Adding Employee\n");
			printf("===============\n");

			// Check for limits on the array and add employee 
			// data accordingly. 
			if (count < SIZE) {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[count].EmployeeID);

				printf("Enter Employee Age: ");
				scanf("%d", &emp[count].Age);

				printf("Enter Employee Salary: ");
				scanf("%lf", &emp[count].Salary);
				count++;
				
			}
			else
				printf("ERROR!!! Maximum Number of Employees Reached\n");
			    printf("\n");

			break;

		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}
