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
        std::string * classPrefix;
        int * classNumber;
        std::string * classes;
		unsigned int * courseID;
		int * enrolledID;
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