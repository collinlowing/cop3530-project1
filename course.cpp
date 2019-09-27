#include"course.hpp"



Course::Course()
{
	meetingTime = ClassTime("1,2,3", "1:00-1:15");
	instructor = Instructor("Bar,Foo");
    coursePrefix = "CS";
    courseNumber = 1;
    seatsAvailable = 0;
    maxSeats = 0;
}

Course::Course(std::string courseDetails)
{
	std::string courseNumberString;
	std::string maxSeatsString;
	std::string seatsAvailableString;
	std::string name;
	std::string days;
	std::string time;

	std::stringstream is(courseDetails);

	std::getline(is, coursePrefix, ' ');

	std::getline(is, courseNumberString, ' ');
	courseNumber = atoi(courseNumberString.c_str()); // cast to int

	std::getline(is, name, ' ');

	std::getline(is, maxSeatsString, ' ');
	maxSeats = atoi(maxSeatsString.c_str()); // cast to int

	std::getline(is, seatsAvailableString, ' ');
	seatsAvailable = atoi(seatsAvailableString.c_str()); // cast to int
	
	std::getline(is, days, ' ');
	std::getline(is, time, ' ');

	instructor = Instructor(name);
	meetingTime = ClassTime(days, time);

}

// FIXME: Figure out what to do with this.
std::string Course::CreateCourse(std::string)
{

	return "";
}

bool Course::MatchesCourseNumberSearch(int courseNumber)
{
	if (this->courseNumber == courseNumber)
	{
		return true;
	}
	else
		return false;
}

bool Course::MatchesPrefixSearch(std::string coursePrefix)
{
	if(this->coursePrefix == coursePrefix)
		return true;
	else
		return false;
}

bool Course::MatchesIntructorSearch(std::string searchName)
{
	return instructor.MatchesInstructorSearch(searchName);
}

bool Course::Enroll()
{
	if(seatsAvailable < 1)
		return false;
	else
	{
		seatsAvailable--;
		return true;
	}
    	
}

std::ostream& operator<<(std::ostream& output, const Course& c)
{
	output << c.coursePrefix << " " << c.courseNumber << "\n\t" << c.seatsAvailable;
	
	if(c.seatsAvailable == 1)
		output << " seat remaining of ";
	else
		output << " seats remaining of ";

	 output << c.maxSeats << ".\n\t" << "Instructor: " << c.instructor << ".\n\t" << c.meetingTime;

	return output;
}
