#include<iostream>
#include<string>
#include<regex>
#include<Windows.h>
//#define POLYMORPHYSM
//#define REGEX_NAME
#define REGEX_GROUP
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
		std::regex rgx_ru("[А-Я]{1}[а-я]{1,10}");
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
		std::cout << "|успеваемость " <<rating;
		std::cout.width(10);
		std::cout <<"% | посещаемость " << attendence << std::endl;
		
		//std::cout << "|"<< spec << "|" << group << "|успеваемость " << rating << "% | посещаемость " << attendence << "%|\n";
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
		std::cout << "Предмет:" << subject << "|Опыт работы(в годах):" << experience << "|Уровень злости:" << evil << "%|" << std::endl;
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
		std::cout << "|Тема дипломной работы: " << tesis <<"|Куратор: "<< curator<< "|Процент плагиата: " << plagiatory << "%|" << std::endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*Human human("Тупенко", "Василь", 18);
	human.print();
	Student stud("Тупенко", "Василь", 18, "Дизайн", "СТ ДВ 37");
	stud.print();
	Teacher("Наталия", "Ичанская", 58, "AdskiyMatan	", 20, 100).print();
	Graduate("Тупенко", "Василь", 23, "Дизайн", "СТ ДВ 37", 70, 80, "Всё о дизайне табуретов","Иван Иванович", 1).print();*/

#ifdef POLYMORPHISM
	/*Human* group[] =
	{
		new Student("Ковальчук", "Антон", 15, "РПО", "СТ ДВ 37",95, 100),
		new Student("Кравцов", "Артем", 16,"РПО", "СТ ПВ 35", 85, 97),
		new Student("Горбенко", "Богдан", 16, "РПО","СТ ПВ 35", 99,100),
		new Teacher("Кобылинский", "Андрей", 42, "Hardware&Windows", 5, 0),
		new Graduate("Маслак", "Михаил", 17, "РПО","СТ ПВ 35", 95, 100, "3D Shoter development","ОА",17),
		new Teacher("Котун", "Олег", 35, "С++", 5, 64),
		new Graduate("Колач","Геннадий",21,"РПО","СТ ИТВ 35",91,100,"Разработка игры для Android","Some teacher",10)
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
	/*std::regex rgx_ru("[А-Я]{1}[а-я]{1,10}");
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
}