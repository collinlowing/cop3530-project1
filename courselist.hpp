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
        std::string * classes;
        Course course[5];
    public:
        CourseList();
        void ReadFile();
        void ParseList();
        void DoubleArray();
};

#endif