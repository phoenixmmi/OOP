#include"HeaderTemplate.h"
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
		List::Iterator(Element* Temp)
		{
			this->Temp = Temp;

			//std::cout << "ItConstructor:\t" << this << std::endl;
		}
		List::~Iterator()
		{
			//std::cout << "ItDesctructor:\t" << this << std::endl;
		}
		List::Iterator& List::operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}

		List::Iterator List::operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;//CopyConstructor
			return old;
		}

		const T& List::operator*()const
		{
			return Temp->data;
		}
		T& List::operator*()
		{
			return Temp->data;
		}

		bool List::operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool List::operator!=(const Iterator& other)const
		{
			return this->Temp != other.Temp;
		}
		//////////////////////
	};


	List::Iterator::Iterator List::Iterator::begin()
	{
		return this->head;
	}
	List::Iterator::Iterator List::Iterator::end()
	{
		return nullptr;
	}
	const List::Iterator::Iterator List::Iterator::begin()const
	{
		return this->head;
	}
	const List::Iterator::Iterator List::Iterator::end()const
	{
		return nullptr;
	}
	List::List()
	{
		head = tail = nullptr;
		size = 0;
		std::cout << "LConstructor:\t" << this << std::endl;
	}
	List::List(int size) :List()
	{
		while (size--)push_front(0);
		std::cout << "ConstructorSIZE" << std::endl;
	}
	List::~List()
	{
		//while (tail)pop_back();
		while (head || tail)
		{
			pop_front();
			pop_back();
		}
		std::cout << "LDesctructor:\t" << this << std::endl;
	}
	List::List(const std::initializer_list<T>& il) :List()
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



	List::List(const List<T>& other) :List()
	{
		//for (Element* Temp = other.head; /*Temp != nullptr*/Temp; Temp = Temp->pNext)
		//{
		//	push_back(Temp->data);
		//}
		for (Iterator it = other.head; it != nullptr; it++)
			push_back(*it);
		std::cout << "LCopyConstructor:\t" << this << std::endl;
	}
	List::List(List&& other)
	{
		this->head = other.head;
		this->tail = other.tail;
		this->size = other.size;
		other.head = nullptr;
		other.tail = nullptr;
		std::cout << "LMoveConstructor:\t" << this << std::endl;
	}
	//operators
	List::List<T>& list::operator=(const List<T>& other)
	{
		if (this == &other)return *this;
		while (head)pop_front();
		for (Element* Temp = other.head; Temp; Temp = Temp->pNext)push_back(Temp->data);
		std::cout << "LCopyAssignment:\t" << this << std::endl;
		return *this;
	}

	List::List<T>& List::operator=(List<T>&& other)
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
	void List::push_front(List::T data)
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

	void List::push_back(List::T data)
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

	void List::insert(int index, List::T data)
	{
		if (index > size)
		{
			throw std::exception("Error: out of range");
		}

		Element* Temp;
		if (index < size / 2)
		{
			Temp = head;
			for (List::T i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = tail;
			for (List::T i = 0; i < size - 1 - index; i++)Temp = Temp->pPrev;
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
	void List::pop_front()
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
	void List::pop_back()
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


	void List::erase(int index)
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
			for (List::T i = 0; i < index; i++)Temp = Temp->pNext;
		}
		else
		{
			Temp = tail;
			for (List::T i = 0; i < size - 1 - index; i++)Temp = Temp->pPrev;
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
List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> buffer = left;//copyConstructor
	/*for (List<T>::Iterator it = right.begin();it != right.end();it++)
	{
		buffer.push_back(*it);
	}*/
	for (List::T i : right)buffer.push_back(i);
	std::cout << "Global operator +\n";
	return buffer;
}