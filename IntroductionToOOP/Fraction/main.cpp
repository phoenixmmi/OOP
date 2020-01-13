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
	
	/*Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}*/

	Fraction(double  integer = 0, double numerator = 0, double denominator = 1 )
	{
		this->integer = integer;
		this->numerator = numerator;
		this->denominator = denominator;

		std::cout << "Constuctor:\t" << this << std::endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;

		std::cout << "CopyConstructor:" << this << std::endl;

	}
	~Fraction()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		std::cout << "CopyAssignment:" << this << std::endl;
		return *this;
	}

	Fraction& operator+=(const Fraction& other)
	{
		this->integer += other.integer;
		this->numerator += other.numerator;
		this->denominator += other.denominator;
		return *this;
	}
	Fraction& operator-=(const Fraction& other)
	{
		this->integer -= other.integer;
		this->numerator -= other.numerator;
		this->denominator -= other.denominator;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		this->integer *= other.integer;
		this->numerator *= other.numerator;
		this->denominator *= other.denominator;
		return *this;
	}
	Fraction& operator/=(const Fraction& other)
	{
		this->integer /= other.integer;
		this->numerator /= other.numerator;
		this->denominator /= other.denominator;
		return *this;
	}

	Fraction operator+(const Fraction& other)const
	{
		Fraction result;
		result.integer = this->integer + other.integer;
		result.numerator = this->numerator + other.numerator;
		result.denominator = this->denominator + other.denominator;
		std::cout << "operator +" << std::endl;
		return result;
	}
	Fraction operator-(const Fraction& other)const
	{
		Fraction result;
		result.integer = this->integer - other.integer;
		result.numerator = this->numerator - other.numerator;
		result.denominator = this->denominator - other.denominator;
		std::cout << "operator -" << std::endl;
		return result;
	}
	Fraction operator*(const Fraction& other)const
	{
		Fraction result;
		result.integer = this->integer * other.integer;
		result.numerator = this->numerator * other.numerator;
		result.denominator = this->denominator * other.denominator;
		std::cout << "operator *" << std::endl;
		return result;
	}
	Fraction operator/(const Fraction& other)const
	{
		Fraction result;
		result.integer = this->integer / other.integer;
		result.numerator = this->numerator / other.numerator;
		result.denominator = this->denominator / other.denominator;
		std::cout << "operator /" << std::endl;
		return result;
	}
	//metods
	void print()const
	{
		std::cout << "integer= " << integer << "\t" << "numerator = " << numerator<< "\t"<< "denominator= " << denominator << std::endl;
	}

	void to_proper()
	{
		int numerator;
		int denominator;
		int integer;
		std::cout << "Введите целую часть: "; std::cin >> integer;
			std::cout << "Введите числитель: "; std::cin >> numerator;
			std::cout << "Введите знаменитель: "; std::cin >> denominator;
		if (numerator > denominator)
		{
			integer+=numerator / denominator;
			numerator = (numerator % denominator);
		}
		else
		{
			std::cout << "Дробь и так правильная." << std::endl;
		}
		std::cout << "Целая часть: " << integer << std::endl;
		std::cout << "Числитель: " << numerator << std::endl;
		std::cout << "Знаменитель: " << denominator << std::endl;

	}

	void to_improper()
	{
		int numerator;
		int denominator;
		int integer;
		std::cout << "Введите целую часть: "; std::cin >> integer;
		std::cout << "Введите числитель: "; std::cin >> numerator;
		std::cout << "Введите знаменитель: "; std::cin >> denominator;

		if (numerator < denominator)
		{
			numerator += integer * denominator;
			integer = 0;
		}
		else {
			std::cout << "Дробь и так неправильная" << std::endl;
		}
		std::cout << "Целая часть: " << integer << std::endl;
		std::cout << "Числитель: " << numerator << std::endl;
		std::cout << "Знаменитель: " << denominator << std::endl;
	}
	void reduce()
	{
		int numerator;
		int denominator;
		int integer;
		std::cout << "Введите целую часть: "; std::cin >> integer;
		std::cout << "Введите числитель: "; std::cin >> numerator;
		std::cout << "Введите знаменитель: "; std::cin >> denominator;
		if (denominator % numerator == 0)
		{
			denominator = denominator / numerator;
			numerator=numerator
		}
		std::cout << "Целая часть: " << integer << std::endl;
		std::cout << "Числитель: " << numerator << std::endl;
		std::cout << "Знаменитель: " << denominator << std::endl;
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
		A.set_denominator(4);
	}
	catch (std::exception e)
	{
	std::cerr << e.what() << std::endl;
	}

	std::cout << "\n------------------------------------\n";
	const Fraction B;
	B.print();
	std::cout << "\n------------------------------------\n";
	//Демострация CopyConstuctor
	const Fraction C(5,3,6);
	const Fraction D=C;
	D.print();
	std::cout << "\n------------------------------------\n";
	Fraction F(3, 5, 2);
	Fraction E = C + F;
	E.print();
	std::cout << "\n------------------------------------\n";
	C.print();
	F.print();
	std::cout << "\n------------------------------------\n";
	std::cout << "Преобразование неправильной дроби в правильную: " << std::endl;
	F.to_proper();
	std::cout << "Преобразование правильной дроби в неправильную: " << std::endl;
	F.to_improper();
	std::cout << "Сокращение дроби: " << std::endl;
	F.reduce();
	

}