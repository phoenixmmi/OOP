#include<iostream>

class BTree
{
	class Element
	{
		int Data;
		Element* pLeft;
		Element* pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			std::cout << "EContructor:\t" << this << std::endl;
		}
		~Element()
		{
			std::cout << "EDestructor:\t" << this << std::endl;
		}
		friend class BTree;
	}*Root;
public:
	Element* getRoot()
	{
		return this->Root;
	}
	BTree() :Root(nullptr)
	{
		std::cout << "TConstructor" << this << std::endl;
	}
	~BTree()
	{
		clear(this->Root);
		std::cout << "TDestructor" << this << std::endl;
	}
	BTree(const std::initializer_list<int>& il) :BTree()
	{
		for (int i : il)
		{
			insert(i);
		}
	}
	BTree(const BTree& other):BTree()
	{
		copy(this->Root, other.Root);
		std::cout << "BTCopyConstructor"<<this << std::endl;
	}

	BTree& operator=(const BTree& other)
	{
		if (this == &other)return *this;
		clear();
		copy(this->Root, other.Root);
		std::cout << "BTCopyassignment" << this << std::endl;
		return *this;
	}
	/*BTree& operator=(const BTree& other)
	{
		//if (this == &other)return *this;
		if (this == nullptr)return *this;
		for (Element* i = other.Root; i != nullptr; i++)
		{
			insert(Root->Data);
		}
		return *this;
	}*/
	void insert(int Data)
	{
		insert(Data, this->Root);
	}
	void erase(int Data)
	{
		erase(Data, this->Root);
	}
	void clear()
	{
		clear(this->Root);
		this->Root = nullptr;
	}
	int minValue()const
	{
		return minValue(this->Root);
	}
	int maxValue()const
	{
		return maxValue(this->Root);
	}

	int count()const
	{
		return count(this->Root);
	}
	int sum()const
	{
		return sum(this->Root);
	}
	double avg()const
	{
		return (double)sum(this->Root) / count(this->Root);
	}
	void print()
	{
		print(this->Root);
		std::cout << std::endl;
	}
private:
	void copy(Element*& thisRoot, Element* otherRoot)
	{
		if (otherRoot == nullptr)return;
		thisRoot = new Element(otherRoot->Data);
		copy(thisRoot->pLeft, otherRoot->pLeft);
		copy(thisRoot->pRight, otherRoot->pRight);
	}
	//Adding elements:
	void insert(int Data, Element* Root)
	{
		if (this->Root == nullptr)//Если дерево пустое, то добавляем элемент прямо в корень.
		{
			this->Root = new Element(Data);
			return;
		}
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)Root->pLeft = new Element(Data);
			else insert(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
		}
	}
	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr)return;
		if (Data < Root->Data)
		{
			erase(Data, Root->pLeft);
		}
		else if (Data > Root->Data)
		{
			erase(Data, Root->pRight);
		}
		else// (Data == Root->Data)
		{
			if (Root->pLeft == Root->pRight)
			{
				delete Root;
				Root = nullptr;
			}
			else if (count(Root->pLeft) > count(Root->pRight))
			{
				Root->Data = maxValue(Root->pLeft);
				erase(maxValue(Root->pLeft), Root->pLeft);
			}
			else
			{
				Root->Data = minValue(Root->pRight);
				erase(minValue(Root->pRight), Root->pRight);
			}

		}

	}
	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}

	int minValue(Element* Root)const
	{
		//Условие
		//if (Root->pLeft == nullptr)return Root->Data;
	/*	if (Root->pLeft != nullptr)
		{
			return minValue(Root->pLeft);
		}
		else
		{
			return Root->Data;
		}*/
		//написано тернарником 
		return (Root->pLeft == nullptr) ? Root->Data : minValue(Root->pLeft);
	}
	int maxValue(Element* Root)const
	{
		/*if (Root->pRight != nullptr)
		{
			return maxValue(Root->pRight);
		}
		else
		{
			return Root->Data;
		}*/
		//написано тернарником 
		return(Root->pRight) ? maxValue(Root->pRight) : Root->Data;
	}
	void print(Element* Root)const
	{
		/*//Мой вариант
		if (Root != nullptr)
		{
			print(Root->pLeft);
			std::cout << Root->Data << "\t";
			print(Root->pRight);
		}
		std::cout << std::endl;*/
		if (Root == nullptr)return;
		print(Root->pLeft);
		std::cout << Root->Data << "\t";
		print(Root->pRight);
		//std::cout << std::endl;
	}

	int count(Element* Root)const
	{
		if (Root == nullptr)return 0;
		return count(Root->pLeft) + count(Root->pRight) + 1;

	}
	int sum(Element* Root)const
	{
		if (Root == nullptr)return 0;
		return sum(Root->pLeft) + sum(Root->pRight) + Root->Data;
	}
	int avg(Element* Roo)
	{

	}

};
//#define BASE_CHECK
//#define ERASE_CHECK
void main()
{
	setlocale(LC_ALL, "");

	//std::cout << "Hello World";
#ifdef BASE_CHECK
	int n;
	std::cout << "Input number of elements: "; std::cin >> n;
	BTree T800;
	for (int i = 0; i < n; i++)
	{
		T800.insert(rand() % 100);

	}

	T800.print();
	std::cout << "Min value in tree: " << T800.minValue() << std::endl;
	std::cout << "Max value in tree: " << T800.maxValue() << std::endl;
	std::cout << std::endl;
	std::cout << "size: " << T800.count() << std::endl;
	std::cout << "sum: " << T800.sum() << std::endl;
	std::cout << "Avg: " << T800.avg() << std::endl;
#endif
#ifdef ERASE_CHECK
	BTree T800;
	T800.insert(50);

	T800.insert(25);
	T800.insert(20);
	T800.insert(30);

	T800.insert(80);
	T800.insert(64);
	T800.insert(85);
	T800.print();
#endif
	BTree T800 = { 50,25,30,75,64,85 };
	T800.print();
	/*int value;
	std::cout << "Type value to erase: "; std::cin >> value;
	T800.erase(value);
	T800.print();*/

	BTree T1000;// = T800;
	T1000 = T800;
	T1000.print();
}