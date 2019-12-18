#include<iostream>
//#define BASICS
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
};

#define ENCAPSULATION
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
}