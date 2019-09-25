#include"course.hpp"

Course::Course()
{
    coursePrefix = "";
    courseNumber = 0;
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

	instructor = new Instructor(name);
	meetingTime = new ClassTime(days, time);

}

bool Course::MatchesCourseNumberSearch(int courseNumber)
{

    return false;
}

bool Course::Enroll()
{

    return false;
}
