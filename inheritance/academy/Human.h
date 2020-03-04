#pragma once
#include<iostream>
#include<string>
#include<regex>
#include<Windows.h>

class Human {
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const;
	const std::string& get_first_name()const;
	const unsigned int get_age()const;
	void set_last_name(const std::string& last_name);
	void set_first_name(const std::string& first_name);
	void set_age(unsigned int age);
	//CONSTRUCTORS
	Human(const std::string& last_name, const std::string first_name, unsigned int age);
		virtual ~Human();
	virtual void print();
};

