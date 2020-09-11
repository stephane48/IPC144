/* Stephane Kamdem Kamguia        *
 * 135736189                      *
 * skamdem-kamguia@myseneca.ca    *
 * IPC144NPP                      *
 **********************************





#include<stdio.h>
#include<math.h>
int main()
{
	double amount;
	int loonie;
	double balance;
	int x,t,m,p;
	double y,a;
	double z;


	printf("Please enter the amount to be paid: $"); //enter the amount
	scanf_s("%lf", &amount);
	loonie = (int)amount;              //casting the amount for displaying the integer value
	x = amount * 100;                 //multiply by 100 to get a big number
	y = x % 100;                   //take the remainder
	z = y / 100;             // divise by 100 to get the first balance owing


	t = z * 100;   //multiply the first balance owing by 100
	m = t % 25;      //take the renainder
	a = (double)m / 100;     //cast the previous remainder for getting the second balance owing


	p = t / 25;  //getting the quaters (we should not cast because we need the integer value)

	printf("Loonies required: %d, balance owing $%.2lf \n", loonie, z);
	printf("Quarters required: %d, balance owing $%.2lf \n", p, a);
	return 0;
}*/

#define _CRT_DEFINE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	int loonie, b, e, h, k, o;
	int quarters;
	int dimes;
	int nickels;
	int pennies;
	double amountOwing, GST, balanceOwing;
	double c, d, f, g, i, j, l, n, r, s;
       

	printf("Please enter the amount to be paid: $"); //enter the amount
	scanf("%lf", &amountOwing);
       

	GST = amountOwing * 0.13 + 0.005; //calcul of the GST
	printf("GST: %.2lf\n", GST);

	balanceOwing = GST + amountOwing;  // calcul of the first balance owing
	printf("Balance owing: $%.2lf\n", balanceOwing);

	loonie = (int)balanceOwing;  // cast for getting loonies
	b = balanceOwing * 100;  //multiply by 100 to get a big number
	c = b % 100;   //take the remainder
	d = c / 100;   //divise by 100 to get the second balance owing
	printf("Loonies required: %d, balance owing $%.2lf\n", loonie, d);

	e = d * 100; // motiply the second balance owing by 100
	f = e % 25;     //take the remainder by 25
	g = f / 100;
	quarters = e / 25; //getting the quarters
	printf("Quarters required: %d, balance owing $%.2lf\n", quarters, g);

	h = g * 100;
	i = h % 10;
	j = i / 100;
	dimes = h / 10;
	printf("Dimes required: %d, balance owing $%.2lf\n", dimes, j);

	k = j * 100;
	l = k % 5;
	n = l / 100;
	nickels = k / 5;
	printf("Nickels required: %d, balance owing $%.2lf\n", nickels, n);

	o = n * 100;
	r = o % 1;
	s = r / 100;
	pennies = o / 1;
	printf("Pennies required: %d, balance owing $%.2lf\n", pennies, s);




	return 0;
}
