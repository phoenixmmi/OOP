#include<iostream>

class String;
String operator+(const String& left, const String& rignt);

class String {
	int size;
	char* str;
public:
	int get_size()const
	{
		return this->size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		std::cout << "DefaultConstructor:\t" << this << std::endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		std::cout << "Constructor:\t" << this << std::endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		std::cout << "CopyConstructor:\t" << this << std::endl;
	}
	String(String&& other)
	{
	
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		std::cout << " Move Construnctor:\t" << this << std::endl;
	}
	~String()
	{
		delete[] this->str;
		std::cout << "Destructor:\t" << this << std::endl;
	}
	String& operator=(const String other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		std::cout << "CopyAssignment:" << this << std::endl;
		return *this;
	}
	
		
	 String& operator+=(const String& other)
	{
		 return *this = *this + other;
	}

	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	//methods
	void print()
	{
		std::cout << size << "\t" << str << std::endl;
	}
};
String operator+(const String& left, const String& right)
{
	String cat = left.get_size() + right.get_size() - 1;
	for (int i = 0; i < left.get_size(); i++)
	{
		cat[i] = left[i];

	}
	for (int i = 0; i < right.get_size(); i++)
	{
		cat[i + left.get_size() - 1] = right[i];
	}

	return cat;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	/*if (!obj.get_numerator())
	{
		std::cout << obj.get_integer() << std::endl;
	}
	else if (!obj.get_integer())
	{
		std::cout << obj.get_numerator() << "/" << obj.get_denominator() << std::endl;
	}
	else
	{
		std::cout << obj.get_integer() << " [" << obj.get_numerator() << "/" << obj.get_denominator() << "]" << std::endl;
	}*/

	return os << obj.get_str();

}
void main()
{
	setlocale(LC_ALL, "");
	//String str1(20);
	//str1.print();

	//String str2 = "Hello";
	//str2.print();

	//String str3 = str2; // copy constructor
	//str3.print();
	//
	//str1 = str2;// copy assignment 
	//str1.print();

	//str1 = str1;
	//str1.print();

	//std::cout << str1 << std::endl;
	String str1 = "Hello";
	String str2 = " World";
	std::cout << "__________________________" << std::endl;
	String str3 = str1 + str2;
	std::cout << "__________________________" << std::endl;
	str3.print();
		
	/* str1 += str2;
	 std::cout << str1 << std::endl;*/
}