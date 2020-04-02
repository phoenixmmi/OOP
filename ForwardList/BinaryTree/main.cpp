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
	void insert(int Data)
	{
		insert(Data, this->Root);
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
	
	void print()
	{
		print(this->Root);
		std::cout << std::endl;
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
		else
		{
			if (Root->pRight == nullptr)Root->pRight = new Element(Data);
			else insert(Data, Root->pRight);
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
		return(Root->pRight)? maxValue(Root->pRight) : Root->Data;
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
	

};

void main()
{
	setlocale(LC_ALL, "");

	//std::cout << "Hello World";
	int n;
	std::cout << "Input number of elements: "; std::cin >> n;
	BTree T800;
	for (int i = 0; i < n; i++)
	{
		T800.insert(rand() % 100, T800.getRoot());
		
	}

	T800.print();
	std::cout << "Min value in tree: "<<  T800.minValue() << std::endl;
	std::cout << "Max value in tree: " << T800.maxValue() << std::endl;
}