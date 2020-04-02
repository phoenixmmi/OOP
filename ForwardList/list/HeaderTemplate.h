#pragma once
#include<iostream>
#include<string>
#include<Windows.h>
template<typename T>
class List
{
	class Element
	{
		T data;
		Element* pNext;
		Element* pPrev;
	public:

		Element(T data, Element* pNext = nullptr, Element* pPrev = nullptr);
		~Element();
		friend class List;
	};
	Element* head;// Содержит указатель на начало списка.
	Element* tail;// Указывает на конец списка.
	unsigned int size;//Количество элементов списка.
public:
	const Element* get_head()const;
	Element* get_head();
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp);
		~Iterator();
		Iterator& operator++();
		Iterator operator++(int);

		const T& operator*()const;
		T& operator*();
		bool operator==(const Iterator& other)const;
		bool operator!=(const Iterator& other)const;
		//////////////////////
	};


	Iterator begin();
	Iterator end();
	const Iterator begin()const;
	const Iterator end()const;
	List();
	List(int size);
	~List();
	List(const std::initializer_list<T>& il);

	List(const List<T>& other);
	List(List&& other);
	//operators
	List<T>& operator=(const List<T>& other);

	List<T>& operator=(List<T>&& other);


	// adding elements:
	void push_front(T data);

	void push_back(T data);


	void insert(int index, T data);
	//removind elements:
	void pop_front();
	void pop_back();


	void erase(int index);

	//methods:

	void print()const;
	void print_reverse()const;

};
template<typename T>
List<T> operator+(const List<T>& left, const List<T>& right);