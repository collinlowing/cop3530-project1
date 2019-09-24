#include"courselist.hpp"

CourseList::CourseList()
{
    numClasses = 5;
    classes = new std::string[numClasses];
}

void CourseList::ReadFile()
{
    do
    {
        std::cout << "Input the course data file name:" << std::endl;
        std::cin  >> fileName;
        list.open(fileName);
        if(!list.is_open())
        {
            std::cout << "ERROR: file could not be opened \n";
            std::cout << "Please try again." << std::endl;
        }
    } 
    while (!list.is_open());
    
    int i = 0;
    while(!list.eof())
    {
        if(numClasses == i + 1)
        {
            DoubleArray();
        }
        std::getline(list, classes[i]);

        
    }

    list.close();
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