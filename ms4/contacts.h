// Student Number: 135736189
// Email: skamdem-kamguia@myseneca.ca
// Section: NPP
// Date: oct 28, 2019       
//==============================================
// Assignment:     1
// Milestone:      4
//==============================================

// Structure type Name declaration (Milestone 1)
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration 
// Place your code here... (from Milestone 1)
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};



// Structure type Numbers declaration
// Place your code here... (from Milestone 1)
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};



// Structure type Contact declaration
// Place your code here... (from Milestone 3)
struct Contacts {
	struct Name name;
	struct Address address;
	struct Numbers numbers;

};



//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name* name);

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address* address);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers* numbers);
