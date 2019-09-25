#include"courselist.hpp"

CourseList::CourseList(std::string fileName)
{
	this->fileName = fileName;
    numClasses = 5;
    classes = new std::string[numClasses];
	course = new Course[numClasses];
	enrolledID = new int[numClasses];
}

CourseList::~CourseList()
{
	delete [] classes;
	delete [] course;
	delete [] enrolledID;
}

std::string CourseList::GetAllCourses()
{
	int lineNum = 0;
	std::string courseList;
	
	do
	{
		list.open(fileName);
		if (!list.is_open())
		{
			std::cout << "ERROR: file could not be opened"	<< std::endl;
			std::cout << "Please try again."				<< std::endl;
			std::cout << "Input the course data file name:"	<< std::endl
															<< std::endl;
			
			std::cin  >> fileName;
		}
	} 
	while (!list.is_open());

	while (!list.eof())
	{
		if (numClasses >= lineNum)
			DoubleArray();

		std::getline(list, classes[lineNum]);

		courseList += classes[lineNum];
		courseList += "\n";

		lineNum++;
	}
	std::cout << courseList;
	return courseList;
}

std::string CourseList::GetMyCourses()
{
	
	return "";
}

bool CourseList::Enroll(int ID)
{
	//for(int i = 0; i < numClasses; i++)
	//if(ID == enrolledID[])
	//course[]
	return false;
}

void CourseList::ParseList()
{
    for(int i = 0; i < numClasses; i++)
    {

    }
}

void CourseList::DoubleArray()
{
    int newSize = numClasses * 2;
    std::string * temp = new std::string[newSize];

    for(int i = 0; i < numClasses; i++)
    {
        temp[i] = classes[i];
    }
    
    delete [] classes;
    classes = temp;
    numClasses = newSize;
}