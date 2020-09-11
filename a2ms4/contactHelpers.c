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

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include<string.h>

// -------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause:
void pause(void)
{
	printf("(Press Enter to Continue)");
	printf("\n");
	clearKeyboard();
}

// getInt:
int getInt(void)
{
	char NL = 'x';
	int value;

	do {
		scanf("%d%c", &value, &NL);

		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}

	} while (NL != '\n');



	return value;
}

// getIntInRange:
int getIntInRange(int min, int max)
{
	int value = getInt();

	while (value < min || value > max) {
		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		value = getInt();
	}

	return value;
}

// yes:
int yes(void)
{
	int result = 0;
	char c, NL;

	do {
		scanf(" %c%c", &c, &NL);
		if (NL != '\n') {
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}
		else {
			if (c == 'Y' || c == 'y')
				result = 1;
		}
	} while (NL != '\n');

	return result;
}

// menu:
int menu(void)
{
	int option;


	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");

	option = getIntInRange(0, 6);


	return option;
}

// contactManagerSystem:
void contactManagerSystem(void)
{
	int done = 0;
	int option;
	struct Contact contacts[MAXCONTACTS] =
	{ { { "Rick",{ '\0' }, "Grimes" },
	{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
	{ "4161112222", "4162223333", "4163334444" } },
 {
	 { "Maggie", "R.", "Greene" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9051112222", "9052223333", "9053334444" } },
 {
	 { "Morgan", "A.", "Jones" },
	{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
	{ "7051112222", "7052223333", "7053334444" } },
 {
	 { "Sasha",{ '\0' }, "Williams" },
	{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
	{ "9052223333", "9052223333", "9054445555" } },
	};
	do {
		option = menu();


		switch (option) {
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			break;

		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			if (yes() == 1)
				done = 1;
                        else
                          printf("\n");
			break;
		default:
			printf("*** OUT OF RANGE *** <Enter a number between 0 and 6> ");
			break;
		}
	} while (done == 0);

	printf("\nContact Management System: terminated\n");

}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+
#include<ctype.h>
// getTenDigitPhone:
void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1;
	int stop = 0;
	int x = 0;

	while (needInput == 1) {
		//scanf("%10s", phoneNum);
		scanf("%s", phoneNum);
		clearKeyboard();
		if (strlen(phoneNum) == 10) {
			for (x = 0; x < 10; x++) {
				if (phoneNum[x] < '0' || phoneNum[x] > '9') {
					stop++;
				}
			}
			//printf("check err number in here : %d\n\n" , err);
			if (stop == 0) {
				needInput = 0;
			}
			else {
				printf("Enter a 10-digit phone number: "); //this message for when they contain letters
				stop = 0;
			}
		}
		else {
			printf("Enter a 10-digit phone number: "); // this part is for length != 10
		}
	}
	/*int i;
	scanf("%s", phoneNum);
		while (strlen(phoneNum) != 10) {
			printf("Enter a 10-digit phone number: ");
			scanf("%s", phoneNum);
			 clearKeyboard();
		}
			for (i = 0;i < 10; i++){
			 while(!isdigit(phoneNum[i])){
			 printf("Enter a 10-digit phone number: ");
			scanf("%s", phoneNum);
			clearKeyboard();
			}

			}*/
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int x;


	for (x = 0; x < size; x++)
	{
		if (strcmp(contacts[x].numbers.cell, cellNum) == 0)
		{
			return x;
		}
	}
	return -1;
}

// displayContactHeader
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
}

// displayContact:
void displayContact(const struct Contact* contact)
{
	printf(" %s ", contact->name.firstName);
	if (strlen(contact->name.middleInitial) != 0) printf("%s ", contact->name.middleInitial);
	printf("%s\n", contact->name.lastName);
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0) printf("Apt# %d, ", contact->address.apartmentNumber);
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size)
{
	int x;
	int a = 0;
	printf("\n");
	displayContactHeader();
	for (x = 0; x < size; x++)
	{
		if (strlen(contacts[x].numbers.cell) != 0)
		{
			displayContact(&contacts[x]);
			a++;
		}
	}
	displayContactFooter(a);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size)
{
	char cell[11];
	int search;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cell);
	search = findContactIndex(contacts, sizeof(contacts), cell);
	if (search == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
		printf("\n");

	}
	else {
		printf("\n");
		displayContact(&contacts[search]);
		printf("\n");
	}
}

// addContact:
void addContact(struct Contact contacts[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 0) {
			break;
		}
	}
	if (i == size)
	{
		printf("\n*** ERROR: The contact list is full! ***\n");
		printf("\n");
	}
	else {
		printf("\n");
		getContact(&contacts[i]);
		printf("--- New contact added! ---\n");
		printf("\n");
	}
}

// updateContact:
void updateContact(struct Contact contacts[], int size)
{
	char phoneNumb[11];
	int search;
	int n;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNumb);
	search = findContactIndex(contacts, sizeof(contacts), phoneNumb);
	if (search == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
		printf("\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&contacts[search]);
		printf("\n");
		printf("Do you want to update the name? (y or n): ");
		n = yes();
		if (n == 1) getName(&contacts[search].name);

		printf("Do you want to update the address? (y or n): ");
		n = yes();
		if (n == 1) getAddress(&contacts[search].address);

		printf("Do you want to update the numbers? (y or n): ");
		n = yes();
		if (n == 1) getNumbers(&contacts[search].numbers);

		printf("--- Contact Updated! ---\n");
		printf("\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
	char phoneNumb[11];
	int search;
	int z;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNumb);
	search = findContactIndex(contacts, sizeof(contacts), phoneNumb);

	if (search == -1)
	{
		printf("*** Contact NOT FOUND ***\n");
	}
	else {
		printf("\nContact found:\n");
		displayContact(&contacts[search]);
		printf("\n");
		printf("CONFIRM: Delete this contact? (y or n): ");
		z = yes();
		if (z == 1)
		{
			contacts[search].numbers.business[0] = '\0';
			contacts[search].numbers.cell[0] = '\0';
			contacts[search].numbers.home[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
		printf("\n");
	}
}

// sortContacts:
void sortContacts(struct Contact contacts[], int size) {
	int k;
	int l;
	struct Contact time;
	for (k = 0; k < size - 1; k++)
	{
		for (l = k + 1; l < size; l++)
		{
			if (strlen(contacts[k].numbers.cell) != 0 && strlen(contacts[l].numbers.cell) != 0) {
				if (strcmp(contacts[k].numbers.cell, contacts[l].numbers.cell) > 0) {
					time = contacts[k];
					contacts[k] = contacts[l];
					contacts[l] = time;
				}
			}
		}
	}
	printf("\n--- Contacts sorted! ---\n");
	printf("\n");
}
	
