#include<iostream>

#define DELIMITER "\n--------------------------------\n"
#define  FIRST_LESSON
class Element {
	int Data;// Значение элемента 
	Element* pNext;//path(Адресс сделующего элемента)
	static int count;
public:
	const int getData()const
	{
		return Data;
	}
	const Element* getpNext()const
	{
		return pNext;
	}
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		std::cout << "EConstructor:\t" << this << std::endl;
	}
	~Element()
	{
		
		count--;
		std::cout << "EDestructor:\t" << this << std::endl;
	}
	

	friend class ForwardList;
	friend class Iterator;
};

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp)
	{
		this->Temp = Temp;
		std::cout << "ITConstuctor" << this << std::endl;
	}
	/*Iterator(const Element* Temp)
	{
		this->Temp = (Element*)Temp;
	}*/
	~Iterator()
	{
		std::cout << "ITdesctuctor" << this << std::endl;
	}

	Iterator& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}

	Iterator& operator++(int) 
	{
		/*Iterator old = *this;
		Temp = Temp->pNext;
		return old;*/
		Temp = Temp->pNext;
		return *this;
	}
	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}

	int operator*()
	{
		return Temp->Data;
	}
};

int Element::count = 0;

class ForwardList
{
	Element* Head;
	unsigned int Size;
public:
	const Element* get_head()const
	{
		return Head;
	}
	Element* get_head()
	{
		return Head;
	}
	unsigned int get_size()const
	{
		return Size;
	}
	ForwardList()
	{
		Head = nullptr;//Если список пуст, то его голова указывает на ноль 
		Size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	
	ForwardList(int size):ForwardList()
	{
		while (size--)push_front(0);
		std::cout << "ConstructorSIZE" << std::endl;
	}
	ForwardList(const std::initializer_list<int>& il) :ForwardList()
	{
		for (const int* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	ForwardList(const ForwardList& other) :ForwardList()
	{
		//for (Element* Temp = other.Head; Temp; Temp = Temp->pNext)push_back(Temp->Data);
		for (Iterator Temp = other.Head; Temp!=nullptr; Temp++)
			push_back(*Temp);
		std::cout << "FLCopyConstructor:\t" << this << std::endl;
	}
	
	ForwardList(ForwardList&& other)
	{
		this->Head = other.Head;
		this->Size = other.Size;
		other.Head = nullptr;
		std::cout << "FLMoveConstructor:\t" << this << std::endl;
	}
	~ForwardList()
	{
		while (Head)pop_front();
		std::cout << "LDestructor:\t" << this << std::endl;
	}
	// OPERATORS:
	ForwardList& operator=(const ForwardList& other)
	{
		while (Head)pop_front();
		for (Element* Temp = other.Head; Temp != nullptr; Temp = Temp->pNext)push_back(Temp->Data);
		std::cout << "FLCopyAssignment:\t" << this << std::endl;
		return *this;
	}
	ForwardList& operator=(ForwardList&& other)
	{
		this->Head = other.Head;
		this->Size = other.Size;
		other.Head = nullptr;
		std::cout << "FLMoveAssignment:\t" << this << std::endl;
		return *this;
	}
	
	int& operator[](int index)
	{
		Element* Temp = Head;
		for (int i = 0; i < index; i++)Temp=Temp->pNext;
		return Temp->Data;
	}

	// Adding elements:
	void push_front(int Data)
	{
		/*Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		Size++;*/
		Head = new Element(Data, Head);
		Size++;
	}

	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}

		Temp->pNext = new Element(Data);
		Size++;
	}
	//methods
	void print()
	{
		Element* Temp = Head; // итератор- это указатель при помощи которого можно получить доступ к элемантам структуры данных 
		while (Temp != nullptr)
		{
			std::cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << std::endl;
			Temp = Temp->pNext;//Переход на следующий элемент
		}
		std::cout << "List size: " << Size << " Elements.\n";
	}
	void insert(int Index, int Data)
	{
		if (Index > Size)
		{
			std::cout << "Error: out of range" << std::endl;
			return;
		}
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		/*Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		Temp->pNext = new Element(Data, Temp->pNext);
		Size++;
	}

	//removing elements:

	void pop_front()
	{
		Element* buffer = Head; //Запоманием адресс удаляемого элемента
		Head = Head->pNext;//	Исключаем элемент из списка 
		delete buffer;
		Size--;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		Size--;
	}
	void erase(int index)
	{
		if (index >= this->Size)
		{
			throw std::exception("Error: Out of range");
		}
		if (index == 0)
		{
			pop_front();
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
		Element* buffer = Temp->pNext;//save address of destructing element.
		Temp->pNext = Temp->pNext->pNext;//exclude  destructing element from list.
		delete buffer;//remove element from memory.
		Size--;
	}
};


ForwardList operator+(const ForwardList& left,const ForwardList& right)
{
	ForwardList buffer = left;
	for (const Element* Temp = right.get_head(); Temp != nullptr; Temp = Temp->getpNext())
		buffer.push_back(Temp->getData());
	return buffer;
}
//#define BASE_FUNCTIONS_CHECK
//#defien CONSTRUCTORS_CHECK_1
void main()
{
	setlocale(LC_ALL, "");
	int n;
	std::cout << "Input list-size: "; std::cin >> n;

#ifdef BASE_FUNCTIONS_CHECK
	ForwardList fl;
	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 200);
	}
	//fl.push_back(1024);
	fl.print();
	/*std::cout << DELIMITER;
	fl.pop_front();
	fl.print();
	std::cout << DELIMITER;
	fl.pop_back();
	fl.print();
	std::cout << DELIMITER; */
	int index;
	int value;
	std::cout << DELIMITER;
	std::cout << "Input index: "; std::cin >> index;
	std::cout << "Input value: "; std::cin >> value;
	fl.insert(index, value);
	fl.print();
	//std::cout << DELIMITER;
	//ForwardList fl2;
	//fl2.push_back(3);
	//fl2.push_back(5);
	//fl2.push_back(8);
	//fl2.push_back(13);
	//fl2.push_back(21);
	//fl2.print();

	// Erase
	//try {
	//	std::cout << "Input index: "; std::cin >> index;
	//	fl.erase(index);
	//	fl.print();
	//}
	//catch (const std :: exception& e)
	//{
	//	std::cerr << e.what() << std::endl;
	//	/*
	//	cin- Console Input;
	//	cout << Console Output;
	//	cerr- Console Error;
	//	*/
	//}
#endif

#ifdef CONSTRUCTORS_CHECK_1
	ForwardList fl(n);
	fl.push_back(3);
	fl.push_back(5);
	fl.push_back(8);
	fl.push_back(13);

	fl.print();
	for (int i = 0; i < fl.get_size(); i++)
	{
		fl[i] = rand() % 100;
	}
	for (int i = 0; i < fl.get_size(); i++)
	{
		std::cout << fl[i] << "\t";
	}
	std::cout << std::endl;
#endif
	
	ForwardList list = { 3,5,8,13,21 };
	for (int i = 0; i < list.get_size(); i++)
	{
		std::cout << list[i] << "\t";
	}
	list.print();
	std::cout << std::endl;

	ForwardList list2 = { 34,55,89 };
	//list2 = list;
	list2.print();
	ForwardList list3=list + list2;
	//list3 = list + list2;
	list3.print();


	for (Iterator it = list3.get_head(); it != nullptr; it++)
	{
		std::cout << *it <<  "\t";
	}
	std::cout << std::endl;
}
