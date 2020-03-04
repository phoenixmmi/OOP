#pragma once
#include<iostream>
#include<string>
#include<regex>
#include<Windows.h>
#include<Human.h>
class Student :public Human
{
	std::string spec;
	std::string group;
	unsigned int rating;
	unsigned int attendence;
public:
	const std::string& get_specialty()const;
	const std::string& get_group()const;
	unsigned int get_rating()const;
	unsigned int get_attendence()const;
	void set_specialty(const std::string& spec);
	void set_group(const std::string& group);
	void set_rating(unsigned int rating);
	void set_attendence(unsigned int attendence);
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
		std::cout << "|успеваемость " << rating;
		std::cout.width(10);
		std::cout << "% | посещаемость " << attendence << std::endl;

		//std::cout << "|"<< spec << "|" << group << "|успеваемость " << rating << "% | посещаемость " << attendence << "%|\n";
	}
};