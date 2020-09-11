// Student Number: 135736189
// Email: skamdem-kamguia@myseneca.ca
// Section: NPP
// Date: oct 28, 2019       
//==============================================
// Assignment:     1
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


// #include your contacts header file on the next line:
#include "contacts.h"

int main (void)
{

	// Declare variables here:
		struct Name nam = { {0} };
		struct Address addres;
		struct Numbers num;

		char y;


    // Display the title
		printf("Contact Management System\n");
		printf("-------------------------\n");


	// Contact Name Input:
		printf("Please enter the contact's first name: ");
		scanf("%30[^\n]", nam.firstName);

		printf("Do you want to enter a middle initial(s)? (y or n): ");
		scanf(" %c", &y);
		if (y == 'y' || y == 'Y') {
			printf("Please enter the contact's middle initial(s): ");
			scanf(" %6[^\n]", nam.middleInitial);
		}
		printf("Please enter the contact's last name: ");
		scanf(" %35[^\n]", nam.lastName);
    // Contact Address Input:
		printf("Please enter the contact's street number: ");
		scanf("%d", &addres.streetNumber);
		printf("Please enter the contact's street name: ");
		scanf(" %40[^\n]", addres.street);
		printf("Do you want to enter an apartment number? (y or n): ");
		scanf(" %c", &y);
		if (y == 'y' || y == 'Y') {
			printf("Please enter the contact's apartment number: ");
			scanf(" %d", &addres.apartmentNumber);
		}
		printf("Please enter the contact's postal code: ");
		scanf(" %7[^\n]", addres.postalCode);
		printf("Please enter the contact's city: ");
		scanf(" %40[^\n]", addres.city);


    // Contact Numbers Input:
		printf("Do you want to enter a cell phone number? (y or n): ");
		scanf(" %c", &y);
		if (y == 'y' || y == 'Y') {
			printf("Please enter the contact's cell phone number: ");
			scanf(" %20[^\n]", num.cell);
		}
		printf("Do you want to enter a home phone number? (y or n): ");
		scanf(" %c", &y);
		if (y == 'y' || y== 'Y') {
			printf("Please enter the contact's home phone number: ");
			scanf(" %20[^\n]", num.home);
		}
		printf("Do you want to enter a business phone number? (y or n): ");
		scanf(" %c", &y);
		if (y == 'y' || y == 'Y') {
			printf("Please enter the contact's business phone number: ");
			scanf(" %20[^\n]", num.business);
		}


    // Display Contact Summary Details
		printf("\nContact Details\n");
		printf("---------------\n");
		printf("Name Details:\n");
		printf("First name: %s\n", nam.firstName);
		printf("Middle initial(s): %s\n", nam.middleInitial);
		printf("Last name: %s\n\n", nam.lastName);
		printf("Address Details:\n");
		printf("Street number: %d\n", addres.streetNumber);
		printf("Street name: %s\n", addres.street);
		printf("Apartment: %d\n", addres.apartmentNumber);
		printf("Postal code: %s\n", addres.postalCode);
		printf("City: %s\n\n", addres.city);
		printf("Phone Numbers:\n");
		printf("Cell phone number: %s\n", num.cell);
		printf("Home phone number: %s\n", num.home);
		printf("Business phone number: %s\n\n", num.business);
		

    // Display Completion Message
		printf("Structure test for Name, Address, and Numbers Done!\n");


    return 0;
}

/*  SAMPLE OUTPUT:
    
    Contact Management System
    -------------------------
    Please enter the contact's first name: Tom
    Do you want to enter a middle initial(s)? (y or n): y
    Please enter the contact's middle initial(s): L. A.
    Please enter the contact's last name: Wong Song
    Please enter the contact's street number: 20
    Please enter the contact's street name: Keele Street
    Do you want to enter an apartment number? (y or n): y
    Please enter the contact's apartment number: 40
    Please enter the contact's postal code: A8A 4J4
    Please enter the contact's city: North York
    Do you want to enter a cell phone number? (y or n): Y
    Please enter the contact's cell phone number: 9051116666
    Do you want to enter a home phone number? (y or n): Y
    Please enter the contact's home phone number: 7052227777
    Do you want to enter a business phone number? (y or n): Y
    Please enter the contact's business phone number: 4163338888

    Contact Details
    ---------------
    Name Details:
    First name: Tom
    Middle initial(s): L. A.
    Last name: Wong Song

    Address Details:
    Street number: 20
    Street name: Keele Street
    Apartment: 40
    Postal code: A8A 4J4
    City: North York

    Phone Numbers:
    Cell phone number: 9051116666
    Home phone number: 7052227777
    Business phone number: 4163338888

    Structure test for Name, Address, and Numbers Done!
*/