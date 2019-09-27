#include"instructor.hpp"


// Initializes first and last name
Instructor::Instructor()
{
    firstName = "Crazy";
    lastName = "George";
}

// Parses instrucotr name
Instructor::Instructor(std::string nameData)
{
        std::istringstream is(nameData);
        
        std::getline(is, lastName, ',');
        std::getline(is, firstName, ',');
}

// Checks if searched name matches first or last name stored
bool Instructor::MatchesInstructorSearch(std::string searchName)
{
	if (firstName == searchName)
		return true;
	if (lastName == searchName)
		return true;
	else
		return false;
}

std::ostream& operator<<(std::ostream& output, const Instructor& i)
{
	output << i.firstName << " " << i.lastName;

    return output;
}