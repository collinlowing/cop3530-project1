#include"instructor.hpp"



Instructor::Instructor()
{
    firstName = "Crazy";
    lastName = "George";
	
}

Instructor::Instructor(std::string nameData)
{
        std::istringstream is(nameData);
        
        std::getline(is, lastName, ',');
        std::getline(is, firstName, ',');
}

bool Instructor::MatchesInstructorSearch(std::string searchName)
{
	if (firstName == searchName)
		return true;
	else if (lastName == searchName)
		return true;
	else
		return false;
}

std::ostream& operator<<(std::ostream& output, const Instructor& i)
{
	output << i.firstName << " " << i.lastName;

    return output;
}