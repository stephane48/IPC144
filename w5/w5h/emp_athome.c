// Name: stephane kamdem kamguia
// Student Number: 135736189
// Email: skamdem-kamguia@myseneca.ca
// Section: IPC144NPP
// Workshop: W5_Home


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define SIZE 4// Define Number of Employees "SIZE" to be 2


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
	int j = 0;
	int l = 0;
	int count = 0;
	int usernumber = 0;

	struct Employee emp[SIZE] = { {0} };// Declare a struct Employee array "emp" with SIZE elements 
	// and initialize all elements to zero


	printf("---=== EMPLOYEE DATA ===---\n\n");

	do
	{
		// Print the option list
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
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
				if (emp[i].EmployeeID > 0) {
					printf("%6d%9d%11.2lf\n", emp[i].EmployeeID, emp[i].Age, emp[i].Salary);
				}

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

		case 3:

			printf("Update Employee Salary\n");
			printf("======================\n");
			int stop = 0;
			do {
				usernumber = 0;
				j = 0;

				printf("Enter Employee ID: ");
				scanf("%d", &usernumber);
				for (j = 0;j < SIZE;j++) {
					if (usernumber == emp[j].EmployeeID) {
						printf("The current salary is %.2lf\n", emp[j].Salary);
						printf("Enter Employee New Salary: ");
						scanf("%lf", &emp[j].Salary);
						stop = 1;
						printf("\n");
					}
				}

				if (stop != 1) {
					printf("*** ERROR: Employee ID not found! ***\n");
				}




			} while (stop == 0);

			break;



		case 4:

			printf("Remove Employee\n");
			printf("===============\n");
			stop = 0;
			do {

				printf("Enter Employee ID: ");
				scanf("%d", &usernumber);
				for (l = 0;l < SIZE;l++) {
					if (usernumber == emp[l].EmployeeID) {
						printf("Employee %d will be removed\n", usernumber);
						emp[l].EmployeeID = 0;
						count = l;
						stop = 1;
						printf("\n");
					}
				}

				if (stop != 1) {
					printf("*** ERROR: Employee ID not found! ***\n");
				}




			} while (stop == 0);

			break;
		default:
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);

	return 0;
}
