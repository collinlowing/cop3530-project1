#include"courselist.hpp"



CourseList::CourseList(std::string fileName)
{
	this->fileName = fileName;
    numClasses = 5; 										// Note: Seg faults if numClasses == 1
    classes = new std::string[numClasses];
	course = new Course[numClasses];
	enrolledID = new int[numClasses];
	enrolledID[0] = -1;

	courseID = new int[numClasses];
	enrolledNum = 0;
}

CourseList::~CourseList()
{
	delete [] classes;
	delete [] course;
	delete [] enrolledID;
	delete [] courseID;
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

			courseID[lineNum] = lineNum;

			courseList << "ID " << lineNum << ": " << course[lineNum] << std::endl;
		}
			lineNum++;
	}

	return courseList.str();
}

std::string CourseList::GetMyCourses()
{
	std::ostringstream myCourses;

	if (enrolledID[0] == -1)
		myCourses << "You are not enrolled in any courses\n";

	for (int i = 0; i < enrolledNum; i++)
	{
		for (int j = 0; j < numClasses; j++)
		{
			 if (courseID[j] == enrolledID[i])
				{
					myCourses << "ID " << courseID[j] << ": " << course[j] << std::endl;
				}
		}
	}
	
	return myCourses.str();
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
	int i = 0;
	int j = 0;
	
	// Search for courseID match index.
	while(j < numClasses)
	{
		if (courseID[j] == ID)
		{
			break;
		}
		else
			j++;
	}
	/*
	while (i < numClasses)
	{
		// Search for course number index that matches.
		if (course[i].MatchesCourseNumberSearch(courseID[j]))
		{
			break;
		}
		else
			i++;
	}
	*/

	if ((enrolledID[i] != ID) && course[i].Enroll())
	{
		enrolledID[enrolledNum] = ID;
		enrolledNum++;
		return true;
	}
	else
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