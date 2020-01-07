#include<iostream>
//#define BASICS
//#define ENCAPSULATION
//#define CONSTRUCTORS
//#define ASSIGNMENT_CHECK
//#define DISTANCE_CHECK
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
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		std::cout << "CopyAssignment:" << this << std::endl;
		return *this;
	}

	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}
	Point& operator-=(const Point& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		return *this;
	}
	Point& operator*=(const Point& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		return *this;
	}
	Point& operator/=(const Point& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		return *this;
	}

	Point operator+(const Point& other)const 
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		std::cout << "operator +" << std::endl;
		return result;
	}
	Point operator-(const Point& other)const
	{
		Point result;
		result.x = this->x - other.x;
		result.y = this->y - other.y;
		std::cout << "operator -" << std::endl;
		return result;
	}
	Point operator*(const Point& other)const
	{
		Point result;
		result.x = this->x * other.x;
		result.y = this->y * other.y;
		std::cout << "operator *" << std::endl;
		return result;
	}
	Point operator/(const Point& other)const
	{
		Point result;
		result.x = this->x / other.x;
		result.y = this->y / other.y;
		std::cout << "operator /" << std::endl;
		return result;
	}

	// Methods
	void print()const
	{
		std::cout << "x= " << x << "\t" << "y = " << y << std::endl;
	}

	/*double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt((x_distance*x_distance)+(y_distance*y_distance));
		return distance;
	}*/
	double distance(const Point& other)const
	{
		return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = B.get_x() - A.get_x();
	double y_distance = B.get_y() - A.get_y();
	double distance = sqrt((x_distance*x_distance) + (y_distance*y_distance));
	return distance;
}

//Point operator+(const Point& left, const Point& right)
//{
//	/*Point result;
//	result.set_x(left.get_x()+right.get_x());
//	result.set_y(left.get_y()+right.get_y());*/
//	std::cout << "Global operator + " << std::endl;
//	//return result;
//	return Point(left.get_x() + right.get_x(), left.get_y() + right.get_y());
//}
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

#ifdef ASSIGNMENT_CHECK
	/*Point A(5, 2);
	A.print();
	int a = 2;
	int b = 3;
	a = b;
	Point B; //default contructor
	B = A;//copy assignment
	B.print();*/
#endif
	/*double x1, x2, y1, y2;
	std::cout << "Введите координаты: " << std::endl;
	std::cout << "x1 = "; std::cin >> x1;
	std::cout << "x2 = "; std::cin >> x2;
	std::cout << "y1= "; std::cin >> y1;
	std::cout << "y2 = "; std::cin >> y2;
	std::cout << "distance=" << distance(x1, y1, x2, y2) << std::endl;*/

	/* Вызов функции
	Point A(2,5);
	Point B(3,7);

	std::cout << distance(A, B)<< std::endl;*/
#ifdef  DISTANCE_CHECK
	Point A(5, 2);
	Point B(8, 3);
	std::cout << A.distance(B) << std::endl;
	std::cout << distance(A, B) << std::endl;
	A.print();
	B.print();

#endif
	/*Point A, B, C;
	A = B = C = Point(5, 3);*/

	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(3, 2);
	Point B(8, 3);
	std::cout << "\n------------------------------------\n";
	Point C = A + B;
	//C = A + B;
	C.print();
	std::cout << "\n------------------------------------\n";
	C = A - B;
	//C = A - B;
	C.print();
	std::cout << "\n------------------------------------\n";
	C = A * B;
	//C = A * B;
	C.print();
	std::cout << "\n------------------------------------\n";
	C = A / B;
	//C = A / B;
	C.print();
	std::cout << "\n------------------------------------\n";
	//A+B+C+A;
	//A.operator+(B).operator+(C).operator+(A).print();
	std::cout << "\n------------------------------------\n";
	A.print();
	B.print();
}