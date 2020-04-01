
#pragma once
#include<iostream>
//#include<string>
#include<Windows.h>
class List
{
	class Element
	{
		int data;
		Element* pNext;
		Element* pPrev;
	public:

		Element(int data, Element* pNext = nullptr, Element* pPrev = nullptr);

		~Element();
		friend class List;
	};
	Element* head;// Содержит указатель на начало списка.
	Element* tail;// Указывает на конец списка.
	unsigned int size;//Количество элементов списка.
public:
	const Element* get_head()const
	{
		return head;
	}
	Element* get_head()
	{
		return head;
	}
	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp);
		~ReverseIterator();
		ReverseIterator& operator--();
		const int& operator*()const;
		int& operator*();
		bool operator==(const ReverseIterator& other)const;
		bool operator!=(const ReverseIterator& other)const;
	};
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp);
		~Iterator();
		Iterator& operator++();
		Iterator operator++(int);
		const int& operator*()const;
		int& operator*();

		bool operator==(const Iterator& other)const;
		bool operator!=(const Iterator& other)const;
		//////////////////////
	};
	const Iterator begin()const;
	const Iterator end()const;
	Iterator begin();
	Iterator end();
	const ReverseIterator rbegin()const;
	const ReverseIterator rend()const;
	ReverseIterator rbegin();
	ReverseIterator rend();

	List();
	List(int size);
	~List();
	List(const std::initializer_list<int>& il);
	List(const List& other);
	List(List&& other);

	//operators
	List& operator=(const List& other);
	List& operator=(List&& other);

	// adding elements:
	void push_front(int data);
	void push_back(int data);
	void insert(int index, int data);

	//removing elements:
	void pop_front();
	void pop_back();
	void erase(int index);

	//methods:
	void print()const;
	void print_reverse()const;
};