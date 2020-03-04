#include"classes.h"


const std::string& Human::get_last_name()const
{
	return last_name;
}
const std::string& Human::get_first_name()const
{
	return first_name;
}
const unsigned int Human::get_age()const
{
	return age;
}
void Human::set_last_name(const std::string& last_name)
{
	//std::regex exp = ("\\w");
	this->last_name = last_name;
	std::regex rgx_ru("[А-Я]{1}[а-я]{1,10}");
	std::regex rgx_eng("[A-Z][a-z]{1,10}");
	std::cout << std::regex_match(this->last_name, rgx_eng, std::regex_constants::match_default);
}
void Human::set_first_name(const std::string& first_name)
{
	this->first_name = first_name;
}
void Human::set_age(unsigned int age)
{
	if (age >= 15 && age <= 80)this->age = age;
}

Human::Human(const std::string& last_name, const std::string first_name, unsigned int age)
{
	set_last_name(last_name);
	set_first_name(first_name);
	set_age(age);
	std::cout << "HConstructor:\t" << this << std::endl;
}
Human::~Human()
{
	std::cout << "HDesctructor:\t" << this << std::endl;
}
void Human::print()
{
	std::cout.width(10);
	std::cout << last_name << "\t";
	std::cout.width(10);
	std::cout << first_name << "\t";
	std::cout.width(10);
	std::cout << age << std::endl;
	//std::cout << last_name << "\t" << first_name << "|" << age<< "|";
}

const std::string& Student::get_specialty()const
{
	return spec;
}
const std::string& Student::get_group()const
{
	return group;
}
unsigned int Student::get_rating()const
{
	return rating;
}
unsigned int Student::get_attendence()const
{
	return attendence;
}
void Student::set_specialty(const std::string& spec)
{
	this->spec = spec;
}
void Student::set_group(const std::string& group)
{
	this->group = group;
}
void Student::set_rating(unsigned int rating)
{
	this->rating = rating <= 100 ? rating : 100;
}
void Student::set_attendence(unsigned int attendence)
{
	this->attendence = attendence <= 100 ? attendence : 100;
}
Student::Student(
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
Student::~Student()
{
	std::cout << "SDesctructor:\t" << this << std::endl;
}

void Student::print()
{
	Human::print();
	std::cout.width(10);
	std::cout << "|" << spec << "\t";
	std::cout.width(10);
	std::cout << "|" << group << "\t";
	std::cout.width(10);
	std::cout << "|успеваемость " << rating;
	std::cout.width(10);
	std::cout << "% | посещаемость " << attendence << std::endl;

	//std::cout << "|"<< spec << "|" << group << "|успеваемость " << rating << "% | посещаемость " << attendence << "%|\n";
}

const std::string& Teacher::get_subject()const
{
	return subject;
}
unsigned int Teacher::get_number_of_groups()const
{
	return experience;
}
unsigned int Teacher::get_evil()const
{
	return evil;
}
void Teacher::set_subject(const std::string& subject)
{
	this->subject = subject;
}

void Teacher::set_number_of_groups(unsigned int number_of_groups)
{
	this->experience = number_of_groups;
}

void Teacher::set_evil(unsigned int evil)
{
	this->evil = evil;
}

Teacher::Teacher(const std::string& last_name, const std::string& first_name, unsigned int age,
	const std::string& subject, unsigned int number_of_groups, unsigned int evil
) :Human(last_name, first_name, age)
{
	set_subject(subject);
	set_number_of_groups(number_of_groups);
	set_evil(evil);
	std::cout << "TConstructor:\t" << this << std::endl;
}
Teacher::~Teacher()
{
	std::cout << "TDesctructor:\t" << this << std::endl;
}
void Teacher::print()
{
	Human::print();
	std::cout << "Предмет:" << subject << "|Опыт работы(в годах):" << experience << "|Уровень злости:" << evil << "%|" << std::endl;
}

void Graduate::set_tesis(const std::string& tesis)
{
	this->tesis = tesis;
}
void Graduate::set_curator(const std::string& curator)
{
	this->curator = curator;
}

const std::string& Graduate::get_tesis()const
{
	return tesis;
}
const std::string& Graduate::get_curator()const
{
	return curator;
}
const unsigned int Graduate::get_plagiatory()const
{
	return plagiatory;
}
void Graduate::set_plagiatory(unsigned int plagiatory)
{
	this->plagiatory = plagiatory <= 100 ? plagiatory : 100;
}

Graduate::Graduate(
	const std::string& last_name, const std::string& first_name, unsigned int age,
	const std::string& spec, const std::string& group, unsigned int rating, unsigned int attendence,
	const std::string& tesis, const std::string& curator, unsigned int plagiatory
) :Student(last_name, first_name, age, spec, group, rating, attendence)
{
	set_tesis(tesis);
	set_curator(curator);
	set_plagiatory(plagiatory);
	std::cout << "GConstructor:\t" << this << std::endl;
}

Graduate::~Graduate()
{
	std::cout << "GDestrictor:\t" << this << std::endl;
}

void Graduate::print()
{
	Student::print();
	std::cout << "|Тема дипломной работы: " << tesis << "|Куратор: " << curator << "|Процент плагиата: " << plagiatory << "%|" << std::endl;
}