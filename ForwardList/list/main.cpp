#include<iostream>
//#define ADDING_ELEMENTS_PUSH_FRONT
//#define ADDING_ELEMENTS_PUSH_BACK
//#define REMOVING_ELEMENTS_POP_FRONT
//#define REMOVING_ELEMENTS_POP_BACK
class List
{
	class Element
	{
		int data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int data, Element* pNext = nullptr, Element* pPrev = nullptr) :data(data), pNext(pNext), pPrev(pPrev)
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

		const int& operator*()const
		{
			return Temp->data;
		}
		int& operator*()
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

	List()
	{
		head = tail = nullptr;
		size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
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
	List(const std::initializer_list<int>& il) :List()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}

	List(const List& other) :List()
	{
		//for (Element* Temp = other.head; /*Temp != nullptr*/Temp; Temp = Temp->pNext)
		//{
		//	push_back(Temp->data);
		//}
		for (Iterator it = other.head; it != nullptr; it++)push_back(*it);
		std::cout << "LCopyConstructor:\t" << this << std::endl;
	}
	//operators
	List& operator=(const List& other)
	{
		if (this == &other)return *this;
		{

		}
		while (head)pop_front();
		for (Element* Temp = other.head; Temp; Temp = Temp -> pNext)push_back(Temp->data);
		std::cout << "LCopyAssignment:\t" << this << std::endl;
		return *this;
	}
	// adding elements:
	void push_front(int data)
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

	void push_back(int data)
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
		tail = tail->pNext = new Element(data,tail->pNext,tail);
		size++;
	}
	
	void insert(int index, int data)
	{
		if (index > size)
		{
			throw std::exception("Error: out of range");
		}

		Element* Temp;
		if (index < size / 2)
		{
			Temp = head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = tail;
			for (int i = 0; i < size - 1 - index; i++)Temp = Temp->pPrev;
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
			if(size)size--;
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
			if(size)size--;
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
		if (index == size-1)
		{
			pop_back();
			return;
		}
		
		Element* Temp;
		if (index < size / 2)
		{
			Temp = head;
			for (int i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = tail;
			for (int i = 0; i < size - 1 - index; i++)Temp = Temp->pPrev;
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

//#define BASE_CHECK
//#define CONSTCUTORS_CHECK
void main()
{
	setlocale(LC_ALL, "");

	int n;
	std::cout << "Input list size: "; std::cin >> n;
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
	//list2 = list;
	list2.print();
	list2.print_reverse();
#endif

	int arr[] = { 3,5,8,13,21 };
	for (int i : arr)
	{
		std::cout << i << "\t";
	}
	std::cout << std::endl;

	/*List list = { 3,5,8,13,21 };
	for (int i : list)
	{
		std::cout << i << std::endl;
	}*/
}