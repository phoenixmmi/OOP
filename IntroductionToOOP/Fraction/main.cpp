#include <iostream>

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer() const
	{
		return this->integer;
	}
	int get_numerator()const
	{
		return this->numerator;
	}
	int get_debominator()const
	{
		return this->denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator != 0)
		{
			this->denominator = denominator;
		}
		else
		{
			//this->denominator = 1;
			throw std::exception("F^cking F^ck, nizya tak delat'!!!!");
		}

		//this->denominator = denominator ? denominator : 1;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Fraction A;
	try
	{
		A.set_integer(2);
		A.set_numerator(3);
		A.set_denominator(0);
	}
	catch (std::exception e)
	{
	std::cerr << e.what() << std::endl;
	}

}