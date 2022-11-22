#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Fraction.h"
using namespace std;

// This program contains a loop that will continue until the user decides to quit. It performs the arithmetic functions of addition, subtraction, multiplication,
// and division on two fractions at a time. Now that I've overloaded all of the operators requested in MP3, it can also perform a variety of other functions, like
// incrementing, decremeting, inverting fractions. It will also automatically reduce any fraction before it returns the answer to a given operation.
// Written by Logan Skura, 10/10/2022
int main()
{
	// These variables are used throughout the main. They are declared here so they don't need to be declared in each operation.
	char operation = 'X';
	Fraction firstFraction;
	Fraction secondFraction;
	cout << "Welcome to the fraction calculator." << endl << endl;

	// This loop will perform calculations until the user decides to quit.
	while (true)
	{
		cout << "Which operation would you like to perform? Enter + for addition, - for subtraction, * for multiplication, / for division, or Q/q to quit. Enter M to see more operators. " << endl;
		cin >> operation;
		// This conditional tests to see if the user wants to quit or has entered a wrong input. If they have entered a correct input for one of the operations,
		// it will ask them to input values for the fractions they'd like to calculate with.
		if (operation == '+' || operation == '-' || operation == '*' || operation == '/')
		{
			cout << "Enter your first fraction." << endl;
			cin >> firstFraction;
			cout << "Your first fraction is: " << firstFraction << endl;
			cout << "Enter your second fraction." << endl;
			cin >> secondFraction;
			cout << "Your second fraction is: " << secondFraction << endl;
		}
		if (operation == 'M')
		{
			cout << "Which operation would you like to perform? Enter I to increment, D to decrement, N to make negative, V to invert, or Q/q to quit" << endl;
			cin >> operation;
		}
		if (operation == 'I' || operation == 'D' || operation == 'N' || operation == 'V')
		{
			cout << "Enter your fraction." << endl;
			cin >> firstFraction;
			cout << "Your fraction is " << firstFraction << endl;
		}

		// This switch performs one of the arithmetic functions, quits the program, or outputs an error message based on the user input.
		switch (operation)
		{
		case '+':
			{
				firstFraction + secondFraction;
				firstFraction.Reduce();
				cout << "The answer is: " << firstFraction << endl << endl;
				break;
			}
		case '-':
			{
				firstFraction - secondFraction;
				firstFraction.Reduce();
				cout << "The answer is: " << firstFraction << endl << endl;
				break;
			}
		case '*':
			{
				firstFraction * secondFraction;
				firstFraction.Reduce();
				cout << "The answer is: " << firstFraction << endl << endl;
				break;
			}
		case '/':
			{
				firstFraction / secondFraction;
				firstFraction.Reduce();
				cout << "The answer is: " << firstFraction << endl << endl;
				break;
			}
		case 'I':
			{
				firstFraction++;
				firstFraction.Reduce();
				cout << "The answer is: " << firstFraction << endl << endl;
				break;
			}
		case 'D':
			{
				firstFraction--;
				firstFraction.Reduce();
				cout << "The answer is: " << firstFraction << endl << endl;
				break;
			}
		case 'N':
			{
				-firstFraction;
				firstFraction.Reduce();
				cout << "The answer is: " << firstFraction << endl << endl;
				break;
			}
		case 'V':
			{
				~firstFraction;
				firstFraction.Reduce();
				cout << "The answer is: " << firstFraction << endl << endl;
				break;
			}
			// These 2 cases, 'Q' and 'q', quit the program.
		case 'Q':
			return 1;
		case 'q':
			return 1;
			// If anything but the defined cases are entered, the program will prompt the user to enter a correct input and then restart the loop.
		default:
			cout << operation << " is not a valid choice. Please choose +, -, *, /, M, I, D, N, V, or Q/q to quit." << endl;
			break;
		}
	}
	return 1;
}