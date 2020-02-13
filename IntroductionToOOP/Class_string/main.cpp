#include<iostream>
#include"string.h"

//#define CONSTRUCTORS
//#define MOVE_OPERATORS
//#define COMPARISON
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS
	String str1(20);
	str1.print();

	String str2 = "hello";
	str2.print();

	String str3 = str2; // copy constructor
	str3.print();

	str1 = str2;// copy assignment 
	str1.print();

	str1 = str1;
	str1.print();

	std::cout << str1 << std::endl;

	//Проверка оператора ввода
//String str;
//std::cout << "input the string: " << std::endl;
//std::cin >> str;
//std::cout << str << std::endl;
#endif
#ifdef MOVE_OPERATORS
	/*
	//Проверка конкантенации.
	String str1 = "Hello";
	String str2 = " World";
	std::cout << "__________________________" << std::endl;
	String str3 = str1 + str2;
	std::cout << "__________________________" << std::endl;
	str3.print();
		*/
		/* str1 += str2;
		 std::cout << str1 << std::endl;*/
#endif
#ifdef COMPARISON
	String str1 = "Hello";
	String str2 = "World";
	std::cout << (str1 < str2) << std::endl;

	String str(5);
#endif

}