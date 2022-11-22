#pragma once

// This header file contains all of the declarations for the Fraction class. They are defined in the Fraction.cpp file
class Fraction
{
	int numerator;
	int denominator;
public:
	Fraction();
	Fraction(int& numerator);
	Fraction(const Fraction& secondFraction);
	Fraction(double&);
	Fraction(int numerator, int denominator);

	Fraction operator + (Fraction&) ;
	Fraction operator += (Fraction&) ;
	Fraction operator - (Fraction&) ;
	Fraction operator -= (Fraction&) ;
	Fraction operator * (Fraction&) ;
	Fraction operator *= (Fraction&) ;
	Fraction operator / (Fraction&) ;
	Fraction operator /= (Fraction&) ;
	void operator = (Fraction&) ;

	Fraction operator ++ ();
	Fraction operator ++ (int);
	Fraction operator -- ();
	Fraction operator -- (int);
	void operator - ();
	void operator ~ ();

	bool operator < (Fraction) ;
	bool operator <= (Fraction) ;
	bool operator > (Fraction) ;
	bool operator >= (Fraction) ;
	bool operator == (Fraction) ;
	bool operator != (Fraction) ;
	bool operator ! () ;

	operator double ();
	operator float ();
	
	friend std::ostream & operator << (std::ostream &os, const Fraction &fraction);
	friend std::istream & operator >> (std::istream &is, Fraction &fraction);
	
	void Input();
	void Print();
	void Reduce();

	Fraction Add(Fraction&);
	Fraction Subtract(Fraction&);
	Fraction Multiply(Fraction&);
	Fraction Divide(Fraction&);

	void Add(Fraction&, Fraction&);
	void Subtract(Fraction&, Fraction&);
	void Multiply(Fraction&, Fraction&);
	void Divide(Fraction&, Fraction&);
};


