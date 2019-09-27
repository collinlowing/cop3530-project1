#include"classtime.hpp"
#include"courselist.hpp"
#include"course.hpp"
#include"instructor.hpp"



int main()
{
	std::string fileName;
	std::string courseList;
	char choice1;
	char choice2;
	int choice3;
	std::string name;
	std::string prefix;

	std::cout << "Input the course data file name:" << std::endl;
	std::cin >> fileName;
    CourseList list(fileName);
	std::cout << "Welcome to class registration!" << std::endl;
	std::cout << "Below is a list of all available courses." << std::endl;
    std::cout << list.GetAllCourses();

	std::cout << "=============================================================" << std::endl;

	do
	{
		std::cout << "To search for a course, press 'S'." << std::endl;
		std::cout << "To enroll, press 'E'." << std::endl;
		std::cout << "To view your current enrollments, press 'V'." << std::endl;
		std::cout << "Press 'Q' to quit." << std::endl;

		std::cin  >> choice1;

		std::cout << "=============================================================" << std::endl;

		switch(choice1)
		{
			case 's':
			case 'S':
				std::cout << "Do you want to search for an instructor name or a course prefix?" << std::endl;
				std::cout << "Type 'I' for instructor." << std::endl;
				std::cout << "Type 'P' for course prefix." << std::endl;
				std::cin  >> choice2;
				
				std::cout << "=============================================================" << std::endl;

				if(choice2 == 'I' || choice2 == 'i')
				{
					std::cout << "What is the name for search?" << std::endl;
					std::cin  >> name;

					if(list.InstructorSearch(name) == "")
					{
						std::cout << "Instructor not found." << std::endl;
						std::cout << std::endl;
					}
					else
					{
						std::cout << list.InstructorSearch(name);
						std::cout << "=============================================================" << std::endl;
					}	
				}
				else if (choice2 == 'P' || choice2 == 'p')
				{
					std::cout << "What is the prefix for search?" << std::endl;
					std::cin  >> prefix;

					if(list.PrefixSearch(prefix) == "")
					{
						std::cout << "No courses found." << std::endl;
					}
					else
					{
						std::cout << list.PrefixSearch(prefix);
						std::cout << "=============================================================" << std::endl;
					}
				}
				else
				{
					std::cout << "ERROR: Invalid option, please try again." << std::endl;
				}

				break;
			case 'e':
			case 'E':
				std::cout << "Which Course ID do you wish to enroll?" << std::endl;
				std::cin  >> choice3;

				if(!list.Enroll(choice3))
				{
					std::cout << "ERROR: You cannot enroll in that course." << std::endl;
				}
				else
				{
					std::cout << "Enrolled in class." << std::endl;
				}
				std::cout << "=============================================================" << std::endl;
				break;
			case 'v':
			case 'V':
				std::cout << list.GetMyCourses();
				std::cout << "=============================================================" << std::endl;
				break;
			case 'q':
			case 'Q':
				std::cout << "Goodbye!" << std::endl;
				break;
			default:
			std::cout << "ERROR: Invalid command, try again" << std::endl;
		}
	}
	while (choice1 != 'q' && choice1 != 'Q');

    return 0;
}