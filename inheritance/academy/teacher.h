#pragma once
#include"Human.h"
class Teacher : public Human
{
	std::string subject;
	unsigned int experience;
	unsigned int evil;
public:
	const std::string& get_subject()const;
	unsigned int get_number_of_groups()const;

	unsigned int get_evil()const;

	void set_subject(const std::string& subject);

	void set_number_of_groups(unsigned int number_of_groups);

	void set_evil(unsigned int evil);


	//Constructors
	Teacher(const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& subject, unsigned int number_of_groups, unsigned int evil
	) :Human(last_name, first_name, age)
	{
	}
	~Teacher();
	void print();

};