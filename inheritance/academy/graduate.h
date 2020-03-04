#pragma once
#include"Student.h"
class Graduate :public Student
{
	std::string tesis;
	std::string curator;
	unsigned int plagiatory;
private:
	void set_tesis(const std::string& tesis);
	void set_curator(const std::string& curator);

public:
	const std::string& get_tesis()const;

	const std::string& get_curator()const;

	const unsigned int get_plagiatory()const;


	void set_plagiatory(unsigned int plagiatory);

	//constructors

	Graduate(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& spec, const std::string& group, unsigned int rating, unsigned int attendence,
		const std::string& tesis, const std::string& curator, unsigned int plagiatory
	) :Student(last_name, first_name, age, spec, group, rating, attendence)
	{
	}
	~Graduate();
	void print();
};