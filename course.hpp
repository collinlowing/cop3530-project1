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
        Instructor instructor;
        int seatsAvailable;
        int maxSeats;
        ClassTime meetingTime;
    public:
        Course();
        Course(std::string courseDetails);
        bool MatchesCourseNumberSearch(int courseNumber);
        bool MatchesPrefixSearch(std::string coursePrefix);
        bool MatchesIntructorSearch(std::string searchName);
        bool Enroll();
        std::string CreateCourse(std::string);
        friend std::ostream& operator<<(std::ostream& output, const Course& c);
};

#endif