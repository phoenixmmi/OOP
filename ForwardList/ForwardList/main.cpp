#include<iostream>

class Element {
	int Data;// Значение элемента 
	Element* pNext;//path(Адресс сделующего элемента)
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		std::cout << "EConstructor:\t" << this << std::endl;
	}
	~Element()
	{
		std::cout << "EDestructor:\t" << this << std::endl;
	}
	friend class ForwardList;
};
class ForwardList
{
	Element* Head;
public:
	ForwardList()
	{
		Head = nullptr;//Если список пуст, то его голова указывает на ноль 
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
		Element* New = new Element(Data);
		Temp->pNext = New;
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
		fl.push_back(rand()%200);
	}
	fl.push_back(1024);
	fl.print();
}