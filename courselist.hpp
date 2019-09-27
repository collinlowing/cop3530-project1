#ifndef COURSELIST_HPP
#define COURSELIST_HPP

#include<iostream>
#include<fstream>
#include<string>

#include"course.hpp"


class CourseList
{
    private:
        std::string fileName;
        std::ifstream list;
        int numClasses;
		int enrolledNum;
        int * courseID;
		int * enrolledID;
        int * classNumber;
        std::string * classPrefix;
        std::string * classes;
        Course * course;
    public:
        CourseList(std::string fileName);
		~CourseList();
        std::string GetAllCourses();
		std::string GetMyCourses();
        std::string InstructorSearch(std::string searchName);
        std::string PrefixSearch(std::string prefix);
		bool Enroll(int ID);
        void DoubleArray();
};

#endif