// Student Number: 135736189
// Email: skamdem-kamguia@myseneca.ca
// Section: NPP
// Date: oct 28, 2019       
//==============================================
// Assignment:     1
// Milestone:      2
//==============================================

#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS
// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};


// Structure type Numbers declaration
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};