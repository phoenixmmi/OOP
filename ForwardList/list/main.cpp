#include<iostream>
#include<string>
//#define ADDING_ELEMENTS_PUSH_FRONT
//#define ADDING_ELEMENTS_PUSH_BACK
//#define REMOVING_ELEMENTS_POP_FRONT
//#define REMOVING_ELEMENTS_POP_BACK
//#define OPERATOR_PLUS_CHECK
template<typename T>
class List
{
	class Element
	{
		T data;
		Element* pNext;
		Element* pPrev;
	public:

		Element(T data, Element* pNext = nullptr, Element* pPrev = nullptr) :data(data), pNext(pNext), pPrev(pPrev)
		{
			std::cout << "EConstructor\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor\t" << this << std::endl;
		}
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
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp)
		{
			this->Temp = Temp;

			//std::cout << "ItConstructor:\t" << this << std::endl;
		}
		~Iterator()
		{
			//std::cout << "ItDesctructor:\t" << this << std::endl;
		}
		Iterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}

		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;//CopyConstructor
			return old;
		}

		const T& operator*()const
		{
			return Temp->data;
		}
		T& operator*()
		{
			return Temp->data;
		}

		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
		//////////////////////
	};


	Iterator begin()
	{
		return this->head;
	}
	Iterator end()
	{
		return nullptr;
	}
	const Iterator begin()const
	{
		return this->head;
	}
	const Iterator end()const
	{
		return nullptr;
	}
	List()
	{
		head = tail = nullptr;
		size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	List(int size) :List()
	{
		while (size--)push_front(0);
		std::cout << "ConstructorSIZE" << std::endl;
	}
	~List()
	{
		//while (tail)pop_back();
		while (head || tail)
		{
			pop_front();
			pop_back();
		}
		std::cout << "LDesctructor:\t" << this << std::endl;
	}
	List(const std::initializer_list<T>& il) :List()
	{
		std::cout << typeid(il.begin()).name() << std::endl;
		/*for (int const* it = il.begin(); it != il.end(); it++)
		{
				push_back(*it);
		}*/
		for (T i : il)
		{
			push_back(i);
		}
	}



	List(const List<T>& other) :List()
	{
		//for (Element* Temp = other.head; /*Temp != nullptr*/Temp; Temp = Temp->pNext)
		//{
		//	push_back(Temp->data);
		//}
		for (Iterator it = other.head; it != nullptr; it++)
			push_back(*it);
		std::cout << "LCopyConstructor:\t" << this << std::endl;
	}
	List(List&& other)
	{
		this->head = other.head;
		this->tail = other.tail;
		this->size = other.size;
		other.head = nullptr;
		other.tail = nullptr;
		std::cout << "LMoveConstructor:\t" << this << std::endl;
	}
	//operators
	List<T>& operator=(const List<T>& other)
	{
		if (this == &other)return *this;
		while (head)pop_front();
		for (Element* Temp = other.head; Temp; Temp = Temp->pNext)push_back(Temp->data);
		std::cout << "LCopyAssignment:\t" << this << std::endl;
		return *this;
	}
	
	List<T>& operator=(List<T>&& other)
	{
		while (head)pop_front();
		this->head = other.head;
		this->tail = other.tail;
		this->size = other.size;
		other.head = nullptr;
		other.tail = nullptr;
		std::cout << "LMoveAssignment:\t" << this << std::endl;
		return *this;
	}

	
	// adding elements:
	void push_front(T data)
	{
		if (head == nullptr)
		{
			head = tail = new Element(data);
			size++;
			return;
		}
		head = head->pPrev = new Element(data, head);
		size++;
	}

	void push_back(T data)
	{
		/*if (tail == nullptr)
		{
			push_front(data);
			size++;
			return;
		}
		Element* New = new Element(data);
		tail->pNext = New;
		tail->pNext->pPrev = tail;
		tail = New;
		size++;*/
		if (tail == nullptr)
		{
			head = tail = new Element(data);
			size++;
			return;
		}
		tail = tail->pNext = new Element(data, tail->pNext, tail);
		size++;
	}

	void insert(int index, T data)
	{
		if (index > size)
		{
			throw std::exception("Error: out of range");
		}

		Element* Temp;
		if (index < size / 2)
		{
			Temp = head;
			for (T i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = tail;
			for (T i = 0; i < size - 1 - index; i++)Temp = Temp->pPrev;
		}
		/*Element* New = new Element(data);
		New->pNext = Temp;
		New->pPrev = Temp->pPrev;
		Temp->pPrev->pNext = New;
		Temp->pPrev = New;*/

		Temp->pPrev = Temp->pPrev->pNext = new Element(data, Temp, Temp->pPrev);
		size++;


	}
	//removind elements:
	void pop_front()
	{

		/*Element* buffer = head;
		head = head->pNext;
		head->pPrev = nullptr;
		delete buffer;
		size--;*/
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
			if (size)size--;
			return;
		}
		head = head->pNext;
		delete head->pPrev;
		head->pPrev = nullptr;
		size--;
	}
	void pop_back()
	{
		/*Element* buffer = tail;
		tail = tail->pPrev;
		tail->pNext = nullptr;
		delete buffer;
		size--;*/
		if (head == tail)
		{
			delete tail;
			head = tail = nullptr;
			if (size)size--;
			return;
		}
		tail = tail->pPrev;
		delete tail->pNext;
		tail->pNext = nullptr;
		size--;
	}


	void erase(int index)
	{
		if (index >= size)throw std::exception("Error: Out of range.");
		if (index == 0)
		{
			pop_front();
			return;
		}
		if (index == size - 1)
		{
			pop_back();
			return;
		}

		Element* Temp;
		if (index < size / 2)
		{
			Temp = head;
			for (T i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = tail;
			for (T i = 0; i < size - 1 - index; i++)Temp = Temp->pPrev;
		}
		Temp->pPrev->pNext = Temp->pNext;
		Temp->pNext->pPrev = Temp->pPrev;
		delete Temp;
		size--;
	}

	//methods:

	void print()const
	{
		for (Element* Temp = head; Temp != nullptr; Temp = Temp->pNext)
		{
			std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
		}
		std::cout << "List size:\t" << size << std::endl;
	}

	void print_reverse()const
	{
		for (Element* Temp = tail; Temp != nullptr; Temp = Temp->pPrev)
		{
			std::cout << Temp->pPrev << "\t" << Temp << "\t" << Temp->data << "\t" << Temp->pNext << std::endl;
		}
		std::cout << "List size:\t" << size << std::endl;
	}

};
template<typename T>
List<T> operator+(const List<T>& left,const List<T>& right)
{
	List<T> buffer = left;//copyConstructor
	/*for (List<T>::Iterator it = right.begin();it != right.end();it++)
	{
		buffer.push_back(*it);
	}*/
	for (T i: right)buffer.push_back(i);
	std::cout << "Global operator +\n";
	return buffer;
}

//#define BASE_CHECK
//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "");

	int n;
	//std::cout << "Input list size: "; std::cin >> n;
	//List list;
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
#ifdef OPERATOR_PLUS_CHECK
	int arr[] = { 3,5,8,13,21 };
	for (int i : arr)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;

	List list = { 3,5,8,13,21 };
	for (List::Iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	List list2 = { 34,55,89 };
	for (List::Iterator it = list2.begin(); it != list2.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;
	std::cout << "\n----------------------------\n";
	//List list = { 3,5,8,13,21 };
	/*for (int i : list + list2)
	{
			std::cout << i << "\t";	
	}
	std::cout << std::endl;*/
	std::cout << "\n----------------------------\n";
	List list3;
	list3 = list + list2;
	list3.print();
	std::cout << "\n----------------------------------\n";
#endif
	//Проверка конкатенации с int
	/*List<int> list1 = { 3,5,8,13,21 };
	for (List<int>::Iterator it = list1.begin(); it != list1.end(); it++)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

	List<int> list2 = { 34,55,89 };
	for (int i:list2)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<int> list3 = list1 + list2;
	list3.print();
	for (int i : list3)
		std::cout << i << "\t";
	std::cout << std::endl;*/

	//Проверка конкантенации с double
	/*List<double> list1 = { 3.1,5.1,8.1,13.1,21.1 };
	for (double i : list1)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<double> list2 = { 34.1,55.1,89.1 };
	for (double i : list2)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<double> list3 = list1 + list2;
	list3.print();
	for (double i : list2)
		std::cout << i << "\t";
	std::cout << std::endl;*/

	//Проверка конкантенации со string
	/*List<std::string> list1 = { "Hi, ","bro!" };
	for (std::string i : list1)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<std::string> list2 = { "How","are","you?" };
	for (std::string i : list2)
		std::cout << i << "\t";
	std::cout << std::endl;

	List<std::string> list3 = list1 + list2;
	list3.print();
	for (std::string i : list3)
		std::cout << i << "\t";
	std::cout << std::endl;*/


	
	/*List<double> list2 = { 2.7,3.14,5.5 };
	for (double i : list2)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;

	List<std::string> list3 = {"Hello", "World!", "How", "are", "you?"};
	for (std::string i : list3)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;*/
}