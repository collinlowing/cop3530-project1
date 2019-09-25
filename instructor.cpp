#include"instructor.hpp"



Instructor::Instructor()
{
    firstName = "Crazy";
    lastName = "George";
}

Instructor::Instructor(std::string nameData)
{
        std::istringstream is(nameData);
        /* FIXME: split first and last name.
        std::getline(is, lastName, ",");
        std::getline(is, firstName, ",");
        */ 

       
}

std::ostream& operator<<(std::ostream& output, const Instructor& i)
{


    return output;
}