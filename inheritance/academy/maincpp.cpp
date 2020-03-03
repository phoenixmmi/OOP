#include<iostream>
#include<string>
#include<regex>
#include<Windows.h>
//#define POLYMORPHYSM
//#define REGEX_NAME
//#define REGEX_GROUP
//#define REGEX_EMAIL
//#define REGEX_PHONE
#define CONVERT_PHONE
class Human {
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	const unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		//std::regex exp = ("\\w");
		this->last_name = last_name;
		std::regex rgx_ru("[�-�]{1}[�-�]{1,10}");
		std::regex rgx_eng("[A-Z][a-z]{1,10}");
		std::cout << std::regex_match(this->last_name, rgx_eng, std::regex_constants::match_default);
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		if (age >= 15 && age <= 80)this->age = age;
	}
	//CONSTRUCTORS
	Human(const std::string& last_name, const std::string first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		std::cout << "HConstructor:\t" << this << std::endl;

	}
	virtual ~Human()
	{
		std::cout << "HDesctructor:\t" << this << std::endl;
	}
	 virtual void print()
	{
		std::cout.width(10);
		std::cout << last_name<< "\t";
		std::cout.width(10);
		std::cout << first_name << "\t";
		std::cout.width(10);
		std::cout << age << std::endl;
		//std::cout << last_name << "\t" << first_name << "|" << age<< "|";
	}
};
class Student :public Human
{
	std::string spec;
	std::string group;
	unsigned int rating;
	unsigned int attendence;
public:
	const std::string& get_specialty()const
	{
		return spec;
	}
	const std::string& get_group()const
	{
		return group;
	}
	unsigned int get_rating()const
	{
		return rating;
	}
	unsigned int get_attendence()const
	{
		return attendence;
	}
	void set_specialty(const std::string& spec)
	{
		this->spec = spec;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(unsigned int rating)
	{
		this->rating = rating <= 100 ? rating : 100;
	}
	void set_attendence(unsigned int attendence)
	{
		this->attendence = attendence <= 100 ? attendence : 100;
	}
	//constructors:
	Student(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string& group, unsigned int rating = 0, unsigned int attendence = 0
	) :Human(last_name, first_name, age)
	{
		set_specialty(spec);
		set_group(group);
		this->rating = rating;
			this->attendence = attendence;
		std::cout << "SConstructor:\t" << this << std::endl;
	}
	~Student()
	{
		std::cout << "SDesctructor:\t" << this << std::endl;
	}

	void print()
	{
		Human::print();
		std::cout.width(10);
		std::cout << "|" << spec << "\t";
		std::cout.width(10);
		std::cout << "|"  << group << "\t";
		std::cout.width(10);
		std::cout << "|������������ " <<rating;
		std::cout.width(10);
		std::cout <<"% | ������������ " << attendence << std::endl;
		
		//std::cout << "|"<< spec << "|" << group << "|������������ " << rating << "% | ������������ " << attendence << "%|\n";
	}
};
class Teacher : public Human
{
	std::string subject;
	unsigned int experience;
	unsigned int evil;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	unsigned int get_number_of_groups()const
	{
		return experience;
	}
	unsigned int get_evil()const
	{
		return evil;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}
	void set_number_of_groups(unsigned int number_of_groups)
	{
		this->experience = number_of_groups;
	}
	void set_evil(unsigned int evil)
	{
		this->evil = evil;
	}

	//Constructors
	Teacher(const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& subject, unsigned int number_of_groups, unsigned int evil
	) :Human(last_name, first_name, age)
	{
		set_subject(subject);
		set_number_of_groups(number_of_groups);
		set_evil(evil);
		std::cout << "TConstructor:\t" << this << std::endl;
	}
	~Teacher()
	{
		std::cout << "TDesctructor:\t" << this << std::endl;
	}
	void print()
	{
		Human::print();
		std::cout << "�������:" << subject << "|���� ������(� �����):" << experience << "|������� ������:" << evil << "%|" << std::endl;
	}
};
class Graduate :public Student
{
	std::string tesis;
	std::string curator;
	unsigned int plagiatory;
private:
	void set_tesis(const std::string& tesis)
	{
		this->tesis = tesis;
	}
	void set_curator(const std::string& curator)
	{
		this->curator = curator;
	}
public:
	const std::string& get_tesis()const
	{
		return tesis;
	}
	const std::string& get_curator()const
	{
		return curator;
	}
	const unsigned int get_plagiatory()const
	{
		return plagiatory;
	}
	
	void set_plagiatory(unsigned int plagiatory)
	{
		this->plagiatory = plagiatory <= 100 ? plagiatory : 100;
	}
	//constructors

	Graduate(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string& group, unsigned int rating, unsigned int attendence,
		const std::string& tesis,const std::string& curator, unsigned int plagiatory
	) :Student(last_name, first_name, age, spec, group, rating, attendence)
	{
		set_tesis(tesis);
		set_curator(curator);
		set_plagiatory(plagiatory);
		std::cout << "GConstructor:\t" << this << std::endl;
	}
	~Graduate()
	{
		std::cout << "GDestrictor:\t" << this << std::endl;
	}

	void print()
	{
		Student::print();
		std::cout << "|���� ��������� ������: " << tesis <<"|�������: "<< curator<< "|������� ��������: " << plagiatory << "%|" << std::endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*Human human("�������", "������", 18);
	human.print();
	Student stud("�������", "������", 18, "������", "�� �� 37");
	stud.print();
	Teacher("�������", "��������", 58, "AdskiyMatan	", 20, 100).print();
	Graduate("�������", "������", 23, "������", "�� �� 37", 70, 80, "�� � ������� ���������","���� ��������", 1).print();*/

#ifdef POLYMORPHISM
	/*Human* group[] =
	{
		new Student("���������", "�����", 15, "���", "�� �� 37",95, 100),
		new Student("�������", "�����", 16,"���", "�� �� 35", 85, 97),
		new Student("��������", "������", 16, "���","�� �� 35", 99,100),
		new Teacher("�����������", "������", 42, "Hardware&Windows", 5, 0),
		new Graduate("������", "������", 17, "���","�� �� 35", 95, 100, "3D Shoter development","��",17),
		new Teacher("�����", "����", 35, "�++", 5, 64),
		new Graduate("�����","��������",21,"���","�� ��� 35",91,100,"���������� ���� ��� Android","Some teacher",10)
	};
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		group[i]->print();
		std::cout << "------------------------------------------------------------------------------\n";
	}

	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}*/
#endif
#ifdef REGEX_NAME
	std::string name;
	std::cout << "Input name: "; std::cin >> name;
	std::regex rgx("[A-Z][a-z]{1,10}");
	std::cout << std::regex_match(name, rgx, std::regex_constants::match_default) << std::endl;
	/*std::regex rgx_ru("[�-�]{1}[�-�]{1,10}");
	std::regex rgx_eng("[A-Z][a-z]{1,10}");
	std::cout << std::regex_match(this->last_name, rgx_eng, std::regex_constants::match_default);*/
#endif//REGEX_NAME

#ifdef REGEX_GROUP
	std::string group;
	std::cout << "input group: "; //std::cin >> group;
	std::regex rgx("(ST|PS(_| )(SB|VS))[_ \-](PU|PV|ITU|ITV|DU|DV)[_ \-]\\d{2}[abv]?"); //([a-b]|v)?  = [abv]?
	getline(std::cin, group);
	std::regex rgx_replace(" |\-");
	group = std::regex_replace(group,rgx_replace,"_", std::regex_constants::match_default);
	std::cout << std::regex_match(group, rgx, std::regex_constants::match_default) << std::endl;
	std::cout << group << std::endl;
#endif

#ifdef REGEX_EMAIL
	std::string email="vasya@gmail.fg.sf";
	/*std::cout << "Input email: "; std::cin >> email;*/
	std::regex rgx("\\w{3,50}@[a-z]{1,20}[.][a-z]{2,3}(.[a-z]{2})?");
	std::cout << std::regex_match(email, rgx, std::regex_constants::match_default) << std::endl;

#endif

#ifdef REGEX_PHONE
	std::string phone = "+38(099)123-45-67";
	/*std::regex rgx("\\+\\d{2}\\(\\d{3}\\)\\d{3}(-\\d{2}){2}");*/
	std::regex rgx(R"(\+\d{2}\(\d{3}\)\d{3}(-\d{2}){2})");
std::cout << (R"(\\+\\d{2}\\(\\d{3}\\)\\d{3}(-\\d{2}){2})")<< std::endl;
	std::cout << std::regex_match(phone, rgx, std::regex_constants::match_default) << std::endl; 
#endif

#ifdef CONVERT_PHONE
	std::string phone = "380991234567";
	std::regex rgx("\\d{12}");
	if (std::regex_match(phone, rgx, std::regex_constants::match_default))
	{

		phone.insert(0, "+");
		phone.insert(phone.size() - 10, "(");
		phone.insert(phone.size() - 7, ")");
		phone.insert(phone.size() - 4, "-");
		phone.insert(phone.size() - 2, "-");
	}
	std::cout << phone << std::endl;
#endif
}