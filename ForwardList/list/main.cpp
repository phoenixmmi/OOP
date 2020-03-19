#include<iostream>

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
	List()
	{
		head = tail = nullptr;
		std::cout << "LConstructor:\t" << this << std::endl;
	}


	// adding elements:
	void push_front(int data)
	{
		if (head == nullptr)
		{
			head = tail = new Element(data);
			return;
		}
		head =head->pPrev= new Element(data, head);
		size++;
	}

	//removind elements:

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

void main()
{
	setlocale(LC_ALL, "");

	int n;
	std::cout << "Input list size: "; std::cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
	}
	list.print();
	std::cout << "\n-----------------------------------\n";
	
	list.print_reverse();
}