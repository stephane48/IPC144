//==============================================
// Name: stephane kamdem kamguia
// Student Number: 135736189
// Email:  skamdem-kamguia@myseneca.ca
// Section:  NPP
// Date: Nov 19,2019   
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include"contacts.h"
#include"contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

// getName:
void getName(struct Name* name) {
	int stop = 0;

	printf("Please enter the contact's first name: ");
	scanf(" %31[^\n]", name->firstName);
	clearKeyboard();

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	stop = yes();
	if (stop == 0) {
		name->middleInitial[0] = '\0';
	}
	else {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %7[^\n]", name->middleInitial);

	}

	printf("Please enter the contact's last name: ");
	scanf(" %36[^\n]", name->lastName);
	clearKeyboard();
}
// getAddress:
void getAddress(struct Address* address) {

	printf("Please enter the contact's street number: ");
	address->streetNumber = getInt();
	while (address->streetNumber < 0) {
		printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
		address->streetNumber = getInt();
	}

	printf("Please enter the contact's street name: ");
	scanf(" %41[^\n]", address->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	if (yes()) {
		printf("Please enter the contact's apartment number: ");
		address->apartmentNumber = getInt();
		while (address->apartmentNumber < 0) {
			printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
			address->apartmentNumber = getInt();
		}
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %7[^\n]", address->postalCode);
	clearKeyboard();
	printf("Please enter the contact's city: ");
	scanf(" %41[^\n]", address->city);
	clearKeyboard();
}
// getNumbers:
void getNumbers(struct Numbers* numbers) {
	int stop = 0;

	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	stop = yes();

	if (stop == 0) {
		numbers->home[0] = '\0';
	}
	else {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(numbers->home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	stop = yes();

	if (stop == 0) {
		numbers->business[0] = '\0';
	}
	else {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(numbers->business);
	}
}
// getContact:
void getContact(struct Contact* contact) {
	

	getName(&contact->name);
	getAddress(&contact->address);
	getNumbers(&contact->numbers);

	
}
