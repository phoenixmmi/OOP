#include"Human.h"
#include"studentt.h"
#include"teacher.h"
#include"graduate.h"
#include<string>
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
		std::regex rgx_ru("[À-ß]{1}[à-ÿ]{1,10}");
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
		std::cout << last_name << "\t";
		std::cout.width(10);
		std::cout << first_name << "\t";
		std::cout.width(10);
		std::cout << age << std::endl;
		//std::cout << last_name << "\t" << first_name << "|" << age<< "|";
	}


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
		std::cout << "|" << group << "\t";
		std::cout.width(10);
		std::cout << "|óñïåâàåìîñòü " << rating;
		std::cout.width(10);
		std::cout << "% | ïîñåùàåìîñòü " << attendence << std::endl;

		//std::cout << "|"<< spec << "|" << group << "|óñïåâàåìîñòü " << rating << "% | ïîñåùàåìîñòü " << attendence << "%|\n";
	}


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
		std::cout << "Ïðåäìåò:" << subject << "|Îïûò ðàáîòû(â ãîäàõ):" << experience << "|Óðîâåíü çëîñòè:" << evil << "%|" << std::endl;
	}
};

	void set_tesis(const std::string& tesis)
	{
		this->tesis = tesis;
	}
	void set_curator(const std::string& curator)
	{
		this->curator = curator;
	}

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
		const std::string& tesis, const std::string& curator, unsigned int plagiatory
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
		std::cout << "|Òåìà äèïëîìíîé ðàáîòû: " << tesis << "|Êóðàòîð: " << curator << "|Ïðîöåíò ïëàãèàòà: " << plagiatory << "%|" << std::endl;
	}
