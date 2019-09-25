#include"course.hpp"



Course::Course()
{
    coursePrefix = "CS";
    courseNumber = 1;
    seatsAvailable = 0;
    maxSeats = 0;
}

Course::~Course()
{
	delete instructor;
	delete meetingTime;
}

Course::Course(std::string courseDetails)
{
	std::string name;
	std::string days;
	std::string time;

	std::stringstream ssin(courseDetails);

	while (ssin.good())
	{
		ssin >> coursePrefix;
		ssin >> courseNumber;
		ssin >> maxSeats;
		ssin >> seatsAvailable;

		ssin >> name;
		ssin >> days;
		ssin >> time;
	}

	delete instructor;
	delete meetingTime;

	instructor = new Instructor(name);
	meetingTime = new ClassTime(days, time);

}

// FIXME: Figure out what to do with this.
std::string Course::CreateCourse(std::string)
{

	return "";
}

bool Course::MatchesCourseNumberSearch(int courseNumber)
{
	if(this->courseNumber == courseNumber)

    return false;
}

bool Course::MatchesCourseNumberSearch(std::string coursePrefix)
{
	if(this->coursePrefix == coursePrefix)
		return true;
	else
		return false;
}

bool Course::Enroll()
{
	if(seatsAvailable < 1)
		return false;
	else
	{
		--seatsAvailable;
		return true;
	}
    	
}

std::ostream& operator<<(std::ostream& output, const Course& c)
{
	std::ostringstream printCourse;
	printCourse << c.instructor;

	output << c.coursePrefix << " " << c.courseNumber << "\n\t" << c.seatsAvailable << "seats remaining of " << c.maxSeats << ".\n\t" << "Instructor: " << printCourse.str() << ".\n\t";

	printCourse << c.meetingTime;
	output << printCourse.str();

	return output;
}
