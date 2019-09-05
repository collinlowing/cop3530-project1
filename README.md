# COP 3530 - Data Structures and Algorithms I 
# Project 1 

## Objective: 
This project is meant to help you review concepts of programming in C++ while also getting used to the environment for this course.
In this project, you are asked to create a simplified version of a course lookup engine, similar to UWF's Banner.
You will need to be able to perform basic file input, create classes, and manipulate basic data structures in C++.
You will also need to modify a Makefile to compile your program.
Information about creating Makefiles is in your Zybook.

## Problem Description: 
Your program will be given files in the following format (See [course.txt](course.txt) for an example):
```
course_prefix course_number instructor max_seats seats_available days time
```
 

Each line of the file composes a hypothetical course that is being offered.
The data elements are as follows:
1. course_prefix (string)
	1. This is the three letter code that shows what type of class it is. CS classes at UWF start with COP, for example.
1. course_number (integer)
	1. The number for the course. DSA I has a course number of 3530.
A file can contain any number of questions and answers.
1. instructor (string)
	1. Given in the format last,first without spaces. For example `Hopper,Grace`.
1. max_seats (integer)
	1. The maximum class size.
1. seats_available (integer)
	1. The number of seats remaining.
1. days (string of comma-separated integers)
	1. The numbered days of the week, from 0-6 where the 0th day of the week is Sunday.
1. time
	1. Begin and end times (24 hour clock) separated by a hyphen. E.g. 13:00-14:15.

## Testing
Included in this repository is a bare bones unit test file ([test/test.cpp](test/test.cpp)).
This file can be run by typing `make test` or `make clean test` (if you want to remove previously compiled files before running) at the command line.

Before you start writing your code, think about what parts you'll need.
Then break out how each part should work.
Before you write any implementation code, first write a test which will verify when the coding is done correctly for that section of the project.
For example, you know that 2+2=4, so if you needed a `sum` function that adds two numbers, you could write a test that calls that function with 2 as both arguments.
Then your test would need to verify that the result is 4.
In this trivial example, you'd also want to check negative numbers and any other potentially _strange_ paths through your code.
Now, write the code. Once you've got the code working and the test (or tests) pass, commit your work to save a stable snapshot of your code.

Try to work on the tests one-at-a-time from top to bottom writing the classes and methods to enable them to pass.
After you get a single test to pass, save your code to that point via `git add .`, `git commit -m "DESCRIPTION OF CODE ADDED"`, `git push origin master`.
Committing and pushing code early and often will save you time in the end.
Your unit test file will be run as part of the grading process, so be sure to run them yourself.

If you have planned out the parts of your program well and tested them, then the program user interface will be a very trivial `main` function that uses the same types of calls as your test file to do the heavy lifting.
Your main class can, and should, use some of the declarations and method calls in exactly the same way as the unit tests.

## Creating the Tool
You are required to implement the classes described below ([Code Organization](#code-organization)), and a main.cpp.
Each class should be divided into a .cpp and .hpp file.
You will also be well-served to store the list of courses, along with the user's enrollments, in yet another class.
Upon the start of the program, your terminal should display a menu that a user can interact with to search for classes and enroll.
A general idea of what that would look like can be found below under [Sample run](#sample-run).
 
## Your Program Shall
* Prompt the user for the input file name.
	* Repeat as necessary if the file cannot be read.
* After the classes in your project have read and parsed the information, the program should be ready to interact.
* Users should be able to view their current registration (or just a "You are not enrolled in any courses" message if they haven't added any).
* Users must be able to search for a course by its attributes.
* A minimum of two search options should be implemented, such as course_number and time.
* The options to display registration, enroll in a course, perform a search, or exit the application should all be clear to the user.

## Sample run
```
Input the name of the file with the course data: njdgbhkdg
Input the name of the file with the course data: bigcourselist.txt
Hello. Welcome to fake Banner!
Below is a list of all available courses.
ID 0: COP 3530
	1 seat remaining of 30.
	Instructor: Alan Turing.
	Class is on Monday & Wednesday from 12:15 to 13:30
ID 1: CS 0
	33 seats remaining of 100.
	Instructor: John Doe.
	Class is on Tuesday & Thursday from 9:00 to 10:15
...
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	To search for a course, press 'S'.
	To Enroll, press 'E'.
	To view your current enrollments, press 'V'.
	Any other key press will exit this application:V
You are not enrolled in any courses
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	To search for a course, press 'S'.
	To Enroll, press 'E'.
	To view your current enrollments, press 'V'.
	Any other key press will exit this application:S
	Enter 'P' to search by course prefix, or 'N' to search by instructor name'
	'N' is the default: P
		Enter the course prefix to search for: COP
ID 0: COP 3530
	1 seat remaining of 30.
	Instructor: Alan Turing.
	Class is on Monday & Wednesday from 12:15 to 13:30
ID 7: COP 2334
	0 seats remaining of 35.
	Instructor: Richard Landry.
	Class is on Monday & Wednesday from 13:00 to 14:15
...
ID 36: COP 5522
	5 seats remaining of 15.
	Instructor: Ashok Srinivasan.
	Class is on Monday & Wednesday from 16:00 to 17:15
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	To search for a course, press 'S'.
	To Enroll, press 'E'.
	To view your current enrollments, press 'V'.
	Any other key press will exit this application:E
	Enter the ID of the course you want to enroll in: 36
Enrolled in 36
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	To search for a course, press 'S'.
	To Enroll, press 'E'.
	To view your current enrollments, press 'V'.
	Any other key press will exit this application:V
ID 36: COP 5522
	4 seats remaining of 15.
	Instructor: Ashok Srinivasan.
	Class is on Monday & Wednesday from 16:00 to 17:15
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	To search for a course, press 'S'.
	To Enroll, press 'E'.
	To view your current enrollments, press 'V'.
	Any other key press will exit this application:q
```

You can click the image below to watch a sample execution of the program on Youtube.
[![Sample execution of program](https://img.youtube.com/vi/XdW18W8GbrA/0.jpg)](https://www.youtube.com/watch?v=XdW18W8GbrA)


## Code Organization
You will need to make sure that your code meets the following specifications.
Note that there is some room for interpretation, but a general code outline is given below.
 
### The Main File
If you have written well tested code for the rest of the project, your main file should be quite small.
It must contain a `main` function that is used as the entry point into the user interface.


### `Course`
![UML of Course class](http://www.plantuml.com/plantuml/png/POx1IZGn48JlUOe-BJFyloyGXcLbzE114VG5CjbUDv2ab-wEB8ZlRe-EuugtIbUbwjk91jPMieivYC18ZGNTcxk2-2aV6G_fx45qxxqef_goUW-jJCWUKbMxfMfsYqfskLkr6O91vVerf1ocZD_n4ivFix6-4TNAdrEno3Z3pDAvVmjJr__8h_aRLEkKNsnpw3veFAAC5uosnF48tH_k7ZnCHDc-tLQcdA7hbyim73XXtM-tG2VaeCJ3q57JKrCFP7iO2cp-Hm-HgkW21vl-mdNlRcSThUGF)

This class is responsible for storing the information needed to store details for a given course.
This class should have the following methods:
* `Course()`
	* Set some simple defaults such as 0 seats remaining, 0 max, etc.
* `Course(std::string)`
	* Should parse out the string (which is a line from the input file) and store the attributes of the course.
* `CreateCourse (std::string)`
	* Returns an std::string that is the question body.
* `MatchesCourseNumberSearch (int)`
	* You need two functions of this general type in order to deal with course search.
	* If the course matches the search criteria, it should return true, otherwise false.
* `Enroll ()`
	* Returns true and decrements the number of remaining seats, if any seats are remaining.
	* Returns false, otherwise.
* Overloaded `<<` operator
	* Used by other parts of the program to output the course in a well-formatted manner.

### `Instructor`
![UML of Instructor class](http://www.plantuml.com/plantuml/png/ROyngiCm341tdK9JYFc_5p0cPEZIfNSGZbCCiHqaUIgzUpKwq55wJm-qYX9hBmV4WqJmKKMvHsqCRxZXdbdqIILv5DsyDvZhou39F_RmDmHcTnshwNTIkfmu267ddEgsBDZEn6Hg27FhUdRrs4nBL73wpnvZizgGnCaD1dnWjOxzyWK0)

This is a simple class that is used for storing the instructor's first and last name.
In practice, it would be used to hold more details and would have limits such as max credit load, etc.
* `Instructor()`
	* Choose a good silly default name.
* `Instructor(std::string)`
	* Split string apart to get the first and last name and store for later display.
* Overloaded `<<` operator
	* Used by other parts of the program to output the instructor name in a well-formatted manner.

### `ClassTime`
![UML of ClassTime class](http://www.plantuml.com/plantuml/png/LOunQyCm48Lt_OgRGapTGAU2C27GfKleq4A7qa6HBucehJDtfw6K_lVQeaBESl2-zuxt3gAEDOs3yOCJWQVbleKHpO-vXzvzoylv7V7BGeZwyR3RFNxEF3yzK-AC2pY6c1GBmjZNH9PhtzpLgcrpevPIAzhR-N28bnPqnckov8zE_HNb5Htxw_9ZGzGMJdW9CVTM-T-RGLbLHFKQ2oUYmNJTcSFixFT04x9JugxRKj8fgGKIPNGZR5hmQZr5qJeTDiqgONxD0MEVnk4F)

You are welcome to add another class that stores times as minute and hour data chunks, but in the interest of keeping the project more tractable, I'm lumping it all in here.
* `ClassTime()`
* `ClassTime(std::string, std::string)`
	* Accepts a comma-separated string for days of the week and a hyphen separated start and end time. Each time is an hour and minute value separated by a colon.
* `MatchesSearch(int, int, int, int, int)`
	* That is about as ugly as a parameter list can get. Accepts the day of the week and time limits that a user is searching for.
		* This is only necessary if you choose to implement search by day/time as one of your minimum of two attributes to search by.
	* Returns true of the class meets the search criteria and false otherwise.

## Breakdown of Grades:
You will find a rubric for the project in Canvas. 
Grade yourself against the rubric in advance of the deadline to identify things you might have overlooked.
The grade you receive from me or the TA should never be a surprise to you.

## Submission Instructions: 
Make sure that your build succeeds when you push it to Github.
Make sure that your project follows all requirements under code organization.
