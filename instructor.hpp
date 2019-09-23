#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include<iostream>
#include<string>
#include<sstream>

class Instructor
{
    private:
        std::string firstName;
        std::string lastName;
    public:
        Instructor();
        Instructor(std::string nameData);
        friend std::ostream& operator<<(std::ostream& output, const Instructor& i);
};

#endif