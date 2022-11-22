#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Fraction.h"
using namespace std;
// This file contains all of the definitions of the member functions in the Fraction class. They are declared in the Fraction.h header file.

// This is the default constructor for the Fraction class. It sets the fraction equal to 0.
Fraction::Fraction() : numerator(0), denominator(1)
{}
// This constructor sets the fraction equal to a whole number value.
Fraction::Fraction(int& numerator) : numerator(numerator), denominator(1)
{}
// This is a copy constructor.
Fraction::Fraction(const Fraction& secondFraction)
{
	numerator = secondFraction.numerator;
	denominator = secondFraction.denominator;
}
// This constructor takes a double for some reason and multiplies it by 100000. I'm not sure what the point of including this one is, but the prompt asked for it.
Fraction::Fraction(double& input)
{
	numerator = input * 100000;
	denominator = 1 * 100000;
}
// This constructor takes an input for numerator and denominator. If the denominator equals 0, it outputs an error message and loops until it is set to something other than 0.
Fraction::Fraction(int numerator, int denominator)
{
	Fraction::numerator = numerator;
	Fraction::denominator = denominator;
	while (denominator == 0)
	{
		cout << "Denominator cannot be equal to zero. Input different value for denominator.";
		cin >> denominator;
		denominator = denominator;
	}
}

// This section contains all of the overloaded operators for the Fraction class. They behave as appropriate for objects of the Fraction class. If an operation would
// cause a division by zero, they will prompt the user for an alternative denominator or cancel the operation.
// For certain operators, like addition, I've used the logic from my previous functions as the blueprint for the overloads.
Fraction Fraction::operator + (Fraction& secondFraction)
{
	int newFirstNum = 1, newSecondNum = 1, commonDenom = 1;
	if (secondFraction.denominator == denominator)
	{
		numerator = numerator + secondFraction.numerator;
	}
	else
	{
		newFirstNum = numerator * secondFraction.denominator;
		newSecondNum = secondFraction.numerator * denominator;
		commonDenom = secondFraction.denominator * denominator;
		numerator = newFirstNum;
		denominator = commonDenom;
		secondFraction.numerator = newSecondNum;
		secondFraction.denominator = commonDenom;

		numerator = numerator + secondFraction.numerator;
	}
	return Fraction(numerator, denominator);
}
Fraction Fraction::operator += (Fraction& secondFraction)
{
	if (secondFraction.denominator == denominator)
	{
		numerator += secondFraction.numerator;
	}
	else
	{
		int newFirstNum = numerator * secondFraction.denominator;
		int newSecondNum = secondFraction.numerator * denominator;
		int commonDenom = secondFraction.denominator * denominator;
		numerator = newFirstNum;
		denominator = commonDenom;
		secondFraction.numerator = newSecondNum;
		secondFraction.denominator = commonDenom;

		numerator += secondFraction.numerator;
	}
	return Fraction(numerator, denominator);
}
Fraction Fraction::operator - (Fraction& secondFraction) 
{
	if (secondFraction.denominator == denominator)
	{
		numerator = numerator - secondFraction.numerator;
	}
	else
	{
		int newFirstNum = numerator * secondFraction.denominator;
		int newSecondNum = secondFraction.numerator * denominator;
		int commonDenom = secondFraction.denominator * denominator;
		numerator = newFirstNum;
		denominator = commonDenom;
		secondFraction.numerator = newSecondNum;
		secondFraction.denominator = commonDenom;

		numerator = numerator - secondFraction.numerator;
	}
	return Fraction(numerator, denominator);
}

Fraction Fraction::operator -= (Fraction& secondFraction) 
{
	if (secondFraction.denominator == denominator)
	{
		numerator -= secondFraction.numerator;
	}
	else
	{
		int newFirstNum = numerator * secondFraction.denominator;
		int newSecondNum = secondFraction.numerator * denominator;
		int commonDenom = secondFraction.denominator * denominator;
		numerator = newFirstNum;
		denominator = commonDenom;
		secondFraction.numerator = newSecondNum;
		secondFraction.denominator = commonDenom;

		numerator -= secondFraction.numerator;
	}
	return Fraction(numerator, denominator);
}
Fraction Fraction::operator * (Fraction& secondFraction) 
{
	numerator = numerator * secondFraction.numerator;
	denominator = denominator * secondFraction.denominator;
	return Fraction(numerator, denominator);
}
Fraction Fraction::operator *= (Fraction& secondFraction) 
{
	numerator = numerator * secondFraction.numerator;
	denominator = denominator * secondFraction.denominator;
	return Fraction(numerator, denominator);
}
Fraction Fraction::operator / (Fraction& secondFraction) 
{
	numerator = numerator * secondFraction.denominator;
	denominator = denominator * secondFraction.numerator;
	if (denominator == 0)
	{
		cout << "Operation not possible, denominator equals 0.";
		return Fraction();
	}
	else
		return Fraction(numerator, denominator);
}
Fraction Fraction::operator /= (Fraction& secondFraction)
{
	numerator = numerator * secondFraction.denominator;
	denominator = denominator * secondFraction.numerator;
	if (denominator == 0)
	{
		cout << "Operation not possible, denominator equals 0.";
		return Fraction();
	}
	else
		return Fraction(numerator, denominator);
}
void Fraction::operator = (Fraction& secondFraction) 
{
	numerator = secondFraction.numerator;
	denominator = secondFraction.denominator;
}
Fraction Fraction::operator ++ ()
{
	numerator += denominator;
	return Fraction(numerator, denominator);
}
Fraction Fraction::operator ++ (int)
{
	numerator += denominator;
	return Fraction(numerator, denominator);
}
Fraction Fraction::operator -- ()
{
	numerator -= denominator;
	return Fraction(numerator, denominator);
}
Fraction Fraction::operator -- (int)
{
	numerator -= denominator;
	return Fraction(numerator, denominator);
}
void Fraction::operator - ()
{
	numerator = -numerator;
}
void Fraction::operator ~ ()
{
	if (numerator != 0)
	{
		int newNum = denominator;
		denominator = numerator;
		numerator = newNum;
	}
}

std::ostream & operator << (std::ostream &os, const Fraction &fraction)
{
	os << fraction.numerator << '/' << fraction.denominator;
	return os;
}
std::istream& operator >> (std::istream& is, Fraction& fraction)
{
	is >> fraction.numerator >> fraction.denominator;
	while (fraction.denominator == 0)
	{
		cout << "Denominator cannot be set to 0, input different value: ";
		cin >> fraction.denominator;
	}
  return is;
}
// These relational operators require that the fraction's numerator and denominator be converted to float values before they can be compared. If they are compared, as
// in the if statement, without being converted to floats beforehand, they will remain as whole numbers and give false feedback.
bool Fraction::operator < (Fraction secondFraction)
{
	float firstNum = numerator;
	float firstDen = denominator;
	float secondNum = secondFraction.numerator;
	float secondDen = secondFraction.denominator;
	if (firstNum/firstDen < secondNum/secondDen)
		return true;
	else
		return false;
}
bool Fraction::operator <= (Fraction secondFraction)
{
	float firstNum = numerator;
	float firstDen = denominator;
	float secondNum = secondFraction.numerator;
	float secondDen = secondFraction.denominator;
	if (firstNum / firstDen <= secondNum / secondDen)
		return true;
	else
		return false;
}
bool Fraction::operator > (Fraction secondFraction)
{
	float firstNum = numerator;
	float firstDen = denominator;
	float secondNum = secondFraction.numerator;
	float secondDen = secondFraction.denominator;
	if (firstNum / firstDen > secondNum / secondDen)
		return true;
	else
		return false;
}
bool Fraction::operator >= (Fraction secondFraction)
{
	float firstNum = numerator;
	float firstDen = denominator;
	float secondNum = secondFraction.numerator;
	float secondDen = secondFraction.denominator;
	if (firstNum / firstDen >= secondNum / secondDen)
		return true;
	else
		return false;
}
bool Fraction::operator == (Fraction secondFraction)
{
	float firstNum = numerator;
	float firstDen = denominator;
	float secondNum = secondFraction.numerator;
	float secondDen = secondFraction.denominator;
	if (firstNum / firstDen == secondNum / secondDen)
		return true;
	else
		return false;
}
bool Fraction::operator != (Fraction secondFraction)
{
	float firstNum = numerator;
	float firstDen = denominator;
	float secondNum = secondFraction.numerator;
	float secondDen = secondFraction.denominator;
	if (firstNum / firstDen != secondNum / secondDen)
		return true;
	else
		return false;
}

bool Fraction::operator ! ()
{
	if (true)
		return false;
	if (false)
		return true;
}

Fraction::operator double()
{
	double num = numerator;
	double den = denominator;
	return (num / den);
}
Fraction::operator float()
{
	float num = numerator;
	float den = denominator;
	return (num / den);
}

// This function takes user input to set the numerator and denominator of a fraction. It will only accept integer values. If the user attempts to input something
// different, such as a char, it will output an error message until it receives an integer input. If the user attempts to set the denominator to 0, it will also
// output an error message until it is set to something other than 0.

// This function is no longer necessary now the the I/O operators have been overloaded but I've left it here for posterity.
void Fraction::Input()
{
	cout << "Enter value for fraction numerator and denominator" << endl;
	cout << "Numerator: ";
	cin >> numerator;
	while (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Only integer values accepted. Enter an integer value. ";
		cin >> numerator;
	}
	cout << endl << "Denominator: ";
	cin >> denominator;
	while (!cin)
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Only integer values accepted. Enter an integer value. ";
		cin >> denominator;
	}
	while (denominator == 0)
	{
			cout << "Denominator cannot be 0. Set different value." << endl;
			cin >> denominator;
	}
}

// This function reduces fractions by using a counter variable that is initially set to the smaller of the values of one fraction's numerator and denominator.
// It then checks if it can divide by the value of the counter variable while leaving no remainder. If it can, it will do so, then decrement the counter by one and check again.
// If it can't, then it will decrement the counter by one and check again. It will do this until the counter reaches 1.
// It will also work in more or less the opposite way for negative fractions, incrementing instead of decrementing the counter.
void Fraction::Reduce()
{
	int i = 2;
	if (numerator >= denominator)
		i = denominator;
	if (numerator < denominator)
		i = numerator;
	if (i == 0)
		return;
	if (i > 0)
	{
		while (i >= 2)
		{
			;		if (numerator % i == 0 && denominator % i == 0)
			{
				numerator /= i;
				denominator /= i;
				i--;
			}
			if (numerator % i != 0 || denominator % i != 0)
				i--;
		}
	}
	if (i < 0)
	{
		while (i <= -2)
		{
			;		if (numerator % i == 0 && denominator % i == 0)
			{
				numerator /= i;
				denominator /= i;
				i++;
			}
			if (numerator % i != 0 || denominator % i != 0)
				i++;
		}
		if (numerator > 0)
			numerator = -numerator;
		if (denominator < 0)
			denominator = -denominator;
	}
	return;
}

// These functions are no longer necessary with the overloaded operators, but I've left them for posterity.
// This function performs fraction addition with both fractions in the expression as arguments.
void Fraction::Add(Fraction& firstFraction, Fraction& secondFraction)
{
	// This conditional checks whether or not the fractions have a common denominator, if they do, it will add the numerators.
	if (firstFraction.denominator == secondFraction.denominator)
	{
		firstFraction.numerator = firstFraction.numerator + secondFraction.numerator;
	}
	// If the fractions did not have a common denominator, then it will execute a few multiplications to give the fractions common denominators and adjust the
	// numerators accordingly. It will then add the numerators.
	else
	{
		int newFirstNum = firstFraction.numerator * secondFraction.denominator;
		int newSecondNum = secondFraction.numerator * firstFraction.denominator;
		int commonDenom = firstFraction.denominator * secondFraction.denominator;
		firstFraction.numerator = newFirstNum;
		firstFraction.denominator = commonDenom;
		secondFraction.numerator = newSecondNum;
		secondFraction.denominator = commonDenom;

		firstFraction.numerator = firstFraction.numerator + secondFraction.numerator;
	}
}

// This function performs fraction subtraction with both fractions in the expression as arguments.
void Fraction::Subtract(Fraction& firstFraction, Fraction& secondFraction)
{
	// This conditional checks whether or not the fractions have a common denominator, if they do, it will subtract the second numerator from the first.
	if (firstFraction.denominator == secondFraction.denominator)
	{
		firstFraction.numerator = firstFraction.numerator - secondFraction.numerator;
	}
	// If the fractions did not have a common denominator, then it will execute a few multiplications to give the fractions common denominators and adjust the
	// numerators accordingly. It will then subtract the second numerator from the first.
	else
	{
		int newFirstNum = firstFraction.numerator * secondFraction.denominator;
		int newSecondNum = secondFraction.numerator * firstFraction.denominator;
		int commonDenom = firstFraction.denominator * secondFraction.denominator;
		firstFraction.numerator = newFirstNum;
		firstFraction.denominator = commonDenom;
		secondFraction.numerator = newSecondNum;
		secondFraction.denominator = commonDenom;

		firstFraction.numerator = firstFraction.numerator - secondFraction.numerator;
	}
}

// This function performs fraction multiplication with both fractions in the expression as arguments.
void Fraction::Multiply(Fraction& firstFraction, Fraction& secondFraction)
{
	firstFraction.numerator = firstFraction.numerator * secondFraction.numerator;
	firstFraction.denominator = firstFraction.denominator * secondFraction.denominator;
}

// This function performs fraction division with both fractions in the expression as arguments.
void Fraction::Divide(Fraction& firstFraction, Fraction& secondFraction)
{
	firstFraction.numerator = firstFraction.numerator * secondFraction.denominator;
	firstFraction.denominator = firstFraction.denominator * secondFraction.numerator;
}

// This function performs fraction addition with one fraction as an argument and the other as an object.
Fraction Fraction::Add(Fraction& firstFraction)
{
	// This conditional checks whether or not the fractions have a common denominator, if they do, it will add the numerators.
	if (firstFraction.denominator == denominator)
	{
		firstFraction.numerator = firstFraction.numerator + numerator;
	}
	// If the fractions did not have a common denominator, then it will execute a few multiplications to give the fractions common denominators and adjust the
	// numerators accordingly. It will then add the numerators.
	else
	{
		int newFirstNum = firstFraction.numerator * denominator;
		int newSecondNum = numerator * firstFraction.denominator;
		int commonDenom = firstFraction.denominator * denominator;
		firstFraction.numerator = newFirstNum;
		firstFraction.denominator = commonDenom;
		numerator = newSecondNum;
		denominator = commonDenom;

		firstFraction.numerator = firstFraction.numerator + numerator;
	}
	return firstFraction;
}

// This function performs fraction subtraction with one fraction as an argument and the other as an object. it will subtract the object fraction from the argument.
Fraction Fraction::Subtract(Fraction& firstFraction)
{
	// This conditional checks whether or not the fractions have a common denominator, if they do, it will subtract the object numerator from the argument fraction.
	if (firstFraction.denominator == denominator)
	{
		firstFraction.numerator = firstFraction.numerator - numerator;
	}
	// If the fractions did not have a common denominator, then it will execute a few multiplications to give the fractions common denominators and adjust the
	// numerators accordingly. It will then subtract the object numerator from the argument fraction.
	else
	{
		int newFirstNum = firstFraction.numerator * denominator;
		int newSecondNum = numerator * firstFraction.denominator;
		int commonDenom = firstFraction.denominator * denominator;
		firstFraction.numerator = newFirstNum;
		firstFraction.denominator = commonDenom;
		numerator = newSecondNum;
		denominator = commonDenom;

		firstFraction.numerator = firstFraction.numerator - numerator;
	}
	return firstFraction;
}

// This function performs fraction multiplication with one fraction as an argument and the other as an object.
Fraction Fraction::Multiply(Fraction& firstFraction)
{
	firstFraction.numerator = firstFraction.numerator * numerator;
	firstFraction.denominator = firstFraction.denominator * denominator;
	return firstFraction;
}

// This function performs fraction division with one fraction as an argument and the other as an object.
Fraction Fraction::Divide(Fraction& firstFraction)
{
	firstFraction.numerator = firstFraction.numerator * denominator;
	firstFraction.denominator = firstFraction.denominator * numerator;
	return firstFraction;
}
