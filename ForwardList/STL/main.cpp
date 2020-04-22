#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<forward_list>
//#define ARRAY
//#define VECTOR
//#define DEQUE
#define FORWARD_LIST

const int SIZE = 5;
#ifdef ARRAY
void print(const std::array<int, SIZE>& arr)
{
	for (std::array<int, SIZE>::const_iterator it = arr.begin(); it != arr.end(); it++)
	{
		std::cout << *it << "\t";
	}
}
#endif

void main()
{
#ifdef ARRAY

	std::array<int, SIZE> arr{ 3,5,8 };
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;

	for (std::array<int, SIZE>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	for (std::array<int, SIZE>::reverse_iterator rit = arr.rbegin(); rit != arr.rend(); rit++)
	{
		std::cout << *rit << "\t";
	}
	std::cout << std::endl;
	print(arr);
#endif

#ifdef VECTOR
	//вектор-это контейнер,который хранит данные в виде динамического массива
	std::vector<int> vec{ 0,1,1,2,3,5,8,13,21,34 };

	vec.push_back(55);

	try
	{
		for (int i = 0; i < vec.size(); i++)
		{
			//std::cout << vec[i] << "\t";
			std::cout << vec.at(i) << "\t";
		}
	}
	catch (const std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "vector size: " << vec.size() << std::endl;
	vec.shrink_to_fit();
	std::cout << "vector capacity: " << vec.capacity() << std::endl;
	std::cout << "vector max size: " << vec.max_size() << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	int value;
	int index;
	std::cout << "Type value: "; std::cin >> value;
	std::cout << "Type index: "; std::cin >> index;

	//	std::vector<int>::iterator position;
	//position = vec.begin() + index;
	//position = vec.insert(position, value);

	vec.insert(vec.begin() + index, 3, value);
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << "vector size: " << vec.size() << std::endl;
	std::cout << "vector capacity: " << vec.capacity() << std::endl;
	std::cout << "vector max size: " << vec.max_size() << std::endl;
	std::cout << std::endl;
#endif

#ifdef DEQUE
	std::deque<int> de{ 3,5,8,13 };
	de.push_front(0);
	de.push_front(1);
	de.push_front(1);
	de.push_front(2);

	for (int i : de)
	{
		std::cout << i << "\t";
	}
#endif

#ifdef FORWARD_LIST
	std::forward_list<int> list = { 3,5,8,13,21 };
	/*
	for (int i = 0 ; i < 5; i++)
	{
		//Так нельзя!//std::cout << list[i] << "\t";
	}*/
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	int index;
	int value;
	std::cout << "Type index: "; std::cin >> index;
	std::cout << "Type value: "; std::cin >> value;

	std::forward_list<int>::iterator position = list.begin();
		for (int i = 0; i < index - 1; i++)
		{
			position++;
		}
	list.insert_after(position, value);
	//list.insert_after(index,value);
	for (std::forward_list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it << "\t";
	}
#endif
}