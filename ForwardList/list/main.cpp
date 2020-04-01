#include<iostream>
#include"header.h"
//#define ADDING_ELEMENTS_PUSH_FRONT
//#define ADDING_ELEMENTS_PUSH_BACK
//#define REMOVING_ELEMENTS_POP_FRONT
//#define REMOVING_ELEMENTS_POP_BACK
//#define BASE_CHECK
//#define CONSTRUCTORS_CHECK

void main()
{
	setlocale(LC_ALL, "");
	int n;
	//std::cout << "Input list size: "; std::cin >> n;
#ifdef ADDING_ELEMENTS_PUSH_FRONT
	std::cout << "\n-----------------PUSH FRONT--------\n";
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
	std::cout << "\n-----------------------------------\n";
	list.print_reverse();
#endif
#ifdef ADDING_ELEMENTS_PUSH_BACK
	std::cout << "\n------------------PUSH BACK--------\n";
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}

	list.print();
	std::cout << "\n-----------------------------------\n";
	list.print_reverse();
#endif

#ifdef REMOVING_ELEMENTS_POP_FRONT
	std::cout << "\n----------------POP FRONT----------\n";
	list.pop_front();
	list.print();
	std::cout << "\n-----------------------------------\n";
	list.print_reverse();

#endif
#ifdef REMOVING_ELEMENTS_POP_BACK
	std::cout << "\n-----------------------------------\n";
	list.pop_back();
	list.print();
	list.print_reverse();
	std::cout << "\n-----------------------------------\n";
#endif
#ifdef BASE_CHECK
	int index;
	int data;
	try
	{
		std::cout << "Input index: "; std::cin >> index;
		//std::cout << "Input value: "; std::cin >> data;
		//list.insert(index,data);
		list.erase(index);
		list.print();
		list.print_reverse();
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
}
#endif
#ifdef CONSTRUCTORS_CHECK
	List list = { 3,5,8,13,21 };
	list = list;
	list.print();
	list.print_reverse();

	List list2 = list;
	list2 = list;
	list2.print();
	list2.print_reverse();
#endif
	/*
	//использование цикла без индексации

	int arr[] = { 3,5,8,13,21 };
	for (int i : arr)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;
	*/
	/*
	//¬ывод элементов на экран с помощью итератора,который мы создали
	List list = { 3,5,8,13,21 };
	for (List::Iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	List list2 = { 34,55,89 };
	for (List::Iterator it = list2.begin(); it != list2.end(); it++)
	{
		std::cout << *it << "\t";
	}
	*/
	/*
	//std::cout << std::endl;
	//std::cout << "\n----------------------------\n";
	//использование цикла без индексации и конкатенци€
	//List list = { 3,5,8,13,21 };
	for (int i : list + list2)
	{
			std::cout << i << "\t";
	}
	std::cout << std::endl;*/
	//std::cout << "\n----------------------------\n";
	/*
	// онкантеци€ строк
	List list3;
	list3 = list + list2;
	list3.print();
	*/
	std::cout << "\n----------------------------------\n";

	List list2 = { 34,55,89 };
	for (List::ReverseIterator Rit = list2.rbegin(); Rit != list2.rend(); --Rit)
	{
		std::cout << *Rit << "\t";
		std::cout << std::endl;
	}

}

