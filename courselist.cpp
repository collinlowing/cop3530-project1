#include"courselist.hpp"


// Constructor
CourseList::CourseList(std::string fileName)
{
	this->fileName = fileName;
    numClasses = 5; 										// Note: Seg faults if numClasses == 1
    classes = new std::string[numClasses];
	classPrefix = new std::string[numClasses];
	classNumber = new int[numClasses];
	course = new Course[numClasses];
	enrolledID = new int[numClasses];
	enrolledID[0] = -1;

	courseID = new int[numClasses];
	enrolledNum = 0;
}

// Destructor
CourseList::~CourseList()
{
	delete [] classes;
	delete [] classPrefix;
	delete [] classNumber;
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

		// Checks if file opened successfully.
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

		// Checks if the getline is just blank spaces.
		if(classes[lineNum].find_first_not_of(' ') != std::string::npos)
		{
			std::istringstream localList(classes[lineNum]);

			localList >> classPrefix[lineNum];
			localList >> classNumber[lineNum];

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
	std::ostringstream instructorList;

	bool isMatch;

	for(int i = 0; i < numClasses; i++)
	{
		isMatch = course[i].MatchesIntructorSearch(searchName);
		if(isMatch)
		{
			instructorList << "ID " << courseID[i] << ": " << course[i] << std::endl;
		}
	}

	return instructorList.str();
}

std::string CourseList::PrefixSearch(std::string prefix)
{
	std::ostringstream prefixList;

	bool isMatch;

	for(int i = 0; i < numClasses; i++)
	{
		isMatch = course[i].MatchesIntructorSearch(prefix);
		if(isMatch)
		{
			prefixList << "ID " << courseID[i] << ": " << course[i] << std::endl;
		}
	}

	return prefixList.str();
}

bool CourseList::Enroll(int ID)
{
	int i = 0;
	
	// Search for index of the enrolledID if exists.
	while(i < enrolledNum)
	{
		if (enrolledID[i] == ID)
		{
			break;
		}
		else
			i++;
	}

	// Checks if the ID was already enrolled, and matches a real course description.
	if ((enrolledID[i] != ID) && course[ID].MatchesCourseNumberSearch(classNumber[ID]) && course[ID].MatchesPrefixSearch(classPrefix[ID]))
	{
		course[ID].Enroll();
		enrolledID[enrolledNum] = ID;
		enrolledNum++;
		return true;
	}
	else
		return false;
}

// Double arrays when reaches over numClasses.
void CourseList::DoubleArray()
{
    int newSize = numClasses * 2;
    std::string * tempClasses = new std::string[newSize];
	std::string * tempPrefix = new std::string[newSize];
	int * tempNum = new int[newSize];
	int * tempID = new int[newSize];
	int * tempEnrolled = new int[newSize];
	Course * tempCourse = new Course[newSize];

    for(int i = 0; i < numClasses; i++)
    {
        tempClasses[i] = classes[i];
		tempPrefix[i] = classPrefix[i];
		tempNum[i] = classNumber[i];
		tempID[i] = courseID[i];
		tempEnrolled[i] = enrolledID[i];
		tempCourse[i] = course[i];

    }
    
    delete [] classes;
	delete [] classPrefix;
	delete [] classNumber;
	delete [] courseID;
	delete [] enrolledID;
	delete [] course;

    classes = tempClasses;
	classPrefix = tempPrefix;
	classNumber = tempNum;
	courseID = tempID;
	enrolledID = tempID;
	course = tempCourse;

	delete [] tempClasses;
	delete [] tempCourse;
	delete [] tempEnrolled;
	delete [] tempID;
	delete [] tempNum;
	delete [] tempPrefix;

    numClasses = newSize;
}