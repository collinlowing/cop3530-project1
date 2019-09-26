#include"courselist.hpp"



CourseList::CourseList(std::string fileName)
{
	this->fileName = fileName;
    numClasses = 5; 										// Note: Seg faults if numClasses == 1
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
	std::ostringstream courseList;
	
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

		if(classes[lineNum].find_first_not_of(' ') != std::string::npos)
		{
			course[lineNum] = Course(classes[lineNum]);

			courseList << "ID " << lineNum << ": " << course[lineNum] << std::endl;
		}
			lineNum++;
	}

	return courseList.str();
}

std::string CourseList::GetMyCourses()
{
	return "";
}

std::string CourseList::InstructorSearch(std::string searchName)
{
	for(int i = 0; i < numClasses; i++)
	{
		
	}

	return "";
}

std::string CourseList::PrefixSearch(std::string prefix)
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