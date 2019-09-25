#include"classtime.hpp"
#include"courselist.hpp"
#include"course.hpp"
#include"instructor.hpp"
#include"student.hpp"

int main()
{
	std::string fileName;
	std::string courseList;

	std::cout << "Input the course data file name:" << std::endl;
	std::cin >> fileName;
    CourseList list(fileName);
    courseList = list.GetAllCourses();



    return 0;
}