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
        bool Enroll();
        friend std::ostream& operator<<(std::ostream& output, const Course& c);
};

#endif