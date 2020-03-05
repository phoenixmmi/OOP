#include<iostream>

#define DELIMITER "\n--------------------------------\n"

class Element {
	int Data;// Значение элемента 
	Element* pNext;//path(Адресс сделующего элемента)
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		std::cout << "EConstructor:\t" << this << std::endl;
	}
	~Element()
	{
		std::cout << "EDestructor:\t" << this << std::endl;
		count--;
	}
	friend class ForwardList;
};

int Element::count = 0;

class ForwardList
{
	Element* Head;
	unsigned int Size;
public:
	ForwardList()
	{
		Head = nullptr;//Если список пуст, то его голова указывает на ноль 
		Size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	~ForwardList()
	{
		std::cout << "LDestructor:\t" << this << std::endl;
	}


	// Adding elements:
	void push_front(int Data)
	{
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
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
		Element* New = new Element(Data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;
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

};

void main()
{
	setlocale(LC_ALL, "");
	int n;
	std::cout << "Input list-size: "; std::cin >> n;

	//Element e(5); 
	ForwardList fl;

	for (int i = 0; i < n; i++)
	{
		fl.push_back(rand() % 200);
	}
	//fl.push_back(1024);
	fl.print();
	std::cout << DELIMITER;
	/*fl.pop_front();
	fl.print();
	std::cout << DELIMITER;
	fl.pop_back();
	fl.print();*/
	std::cout << DELIMITER;
	int index;
	int value;
	std::cout << "Input index: "; std::cin >> index;
	std::cout << "Input value: "; std::cin >> value;
	fl.insert(index, value);
	fl.print();
	std::cout << DELIMITER;
	ForwardList fl2;
	fl2.push_back(3);
	fl2.push_back(5);
	fl2.push_back(8);
	fl2.push_back(13);
	fl2.push_back(21);
	fl2.print();
}