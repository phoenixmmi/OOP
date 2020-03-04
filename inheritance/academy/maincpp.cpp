
//#define POLYMORPHYSM
//#define REGEX_NAME
//#define REGEX_GROUP
//#define REGEX_EMAIL
//#define REGEX_PHONE
#define CONVERT_PHONE
#include"classes.h"

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