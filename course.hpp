#ifndef COURSE_HPP
#define COURSE_HPP

#include<iostream>
#include<string>
#include<sstream>

#include"instructor.hpp"
#include"classtime.hpp"

class Course
{
    private:
        std::string coursePrefix;
        int courseNumber;
        Instructor * instructor = new Instructor("Foo,Bar");
        int seatsAvailable;
        int maxSeats;
        ClassTime * meetingTime = new ClassTime("1,2,3", "1:00-1:15");
    public:
        Course();
		~Course();
        Course(std::string courseDetails);
        bool MatchesCourseNumberSearch(int courseNumber);
        bool MatchesCourseNumberSearch(std::string coursePrefix);
        bool Enroll();
        std::string CreateCourse(std::string);
        friend std::ostream& operator<<(std::ostream& output, const Course& c);
};

#endif