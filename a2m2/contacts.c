//==============================================
// Name:stephane kamdem kamguia
// Student Number: 135736189
// Email: skamdem-kamguia@myseneca.ca
// Section: NPP
// Date: oct 28, 2019 
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include"contacts.h"


// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:
#include"contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper 
//        functions where applicable (ex: yes() and getInt() )


void getName(struct Name* name) {

	printf("Please enter the contact's first name: ");
	scanf(" %31[^\n]", name->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	if (yes()) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %6[^\n]", name->middleInitial);
		clearKeyboard();
	}

	printf("Please enter the contact's last name: ");
	scanf(" %36[^\n]", name->lastName);
}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:

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


// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:

void getNumbers(struct Numbers* numbers) {

	printf("Please enter the contact's cell phone number: ");
	scanf(" %21[^\n]", numbers->cell);

	printf("Do you want to enter a home phone number? (y or n): ");
	if (yes()) {
		printf("Please enter the contact's home phone number: ");
		scanf(" %21[^\n]", numbers->home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	if (yes()) {
		printf("Please enter the contact's business phone number: ");
		scanf(" %21[^\n]", numbers->business);
	}
}

// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               |
// +-------------------------------------------------+
// getContact
void getContact(struct Contact* contacts) {
	
	getName(&contacts->name);
	getAddress(&contacts->address);
	getNumbers(&contacts->numbers);
}
