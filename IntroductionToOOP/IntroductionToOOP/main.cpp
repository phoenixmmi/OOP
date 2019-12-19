#include<iostream>
//#define BASICS
//#define ENCAPSULATION
//#define CONSTRUCTORS
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		if (abs(x) <= 100)
		{
			this->x = x;
		}
		else
		{
			this->x = 0;
		}
		//if отфильтровывает неккоректные значения 

	}
	void set_y(double y)
	{
		this->y = y;
	}

	/*
	Point()
	{
		x = y = 0;
		std::cout << "DefaultConstructor:\t" << this << std::endl;

	}*/
	Point(double  x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		std::cout << "Constuctor:\t" << this << std::endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyConstructor:" << this << std::endl;
	}
	~Point()
	{
		std::cout << "Destructor:\t" << this << std::endl;
	}
	//operators
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyAssignment:" << this << std::endl;
	}
	// Methods
	void print()const
	{
		std::cout << "x= " << x << "\t" << "y = " << y << std::endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
#ifdef BASICS
	int a;//Обьявление переменной а, типа int.
	Point A;//Обьявление переменной А, типа Point
			//Создание(Обьявление)  обьекта А типа Point
	A.x = 5;
	A.y = 2;
	std::cout << A.x << "\t" << A.y << std::endl;

	Point* pA = &A;
	std::cout << pA->x << "\t" << pA->y << std::endl;
	std::cout << (*pA).x << "\t" << (*pA).y << std::endl;
#endif

#ifdef ENCAPSULATION
	Point A;
	A.set_x(5);
	A.set_y(3);
	std::cout << A.get_x() << "\t" << A.get_y() << std::endl;
#endif
#ifdef CONSTRUCTORS
	const Point B;//Обьявление константного обьекта
	//std::cout << B.get_x() << std::endl;
	B.print();

	Point C = 5;
	C.print();

	Point D(6);
	D.print();

	Point E(5, 2);
	E.print();

	Point F = E;
	F.print();

	Point G;
	G = E;
#endif

	Point A(5, 2);
	A.print();
	int a = 2;
	int b = 3;
	a = b;
	Point B; //default contructor
	B = A;//copy assignment
	B.print();

}