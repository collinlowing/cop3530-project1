#define CATCH_CONFIG_MAIN

#include<sstream>

#include "catch/catch.hpp"
#include "../classtime.hpp"
#include "../instructor.hpp"
#include "../course.hpp"
#include "../courselist.hpp"

TEST_CASE("ClassTime Class")
{
	std::ostringstream courseInfo;
	ClassTime ct;
	courseInfo << ct;
	REQUIRE(courseInfo.str() == "");

	courseInfo.str("");
	ClassTime ct2("0,1,2,3,4,5,6", "13:30-14:45");
	courseInfo << ct2;
	REQUIRE(courseInfo.str() == "Class is on Sunday & Monday & Tuesday & Wednesday & Thursday & Friday & Saturday from 13:30 to 14:45");

	// Test break of invalid day of week

	courseInfo.str("");
	ClassTime ct3("3,-1,4", "13:30-14:45");
	courseInfo << ct3;
	REQUIRE(courseInfo.str() == "Class is on Wednesday from 13:30 to 14:45");
}

TEST_CASE("Instructor Class")
{
	std::ostringstream instructor;

	Instructor oaklandAs;
	instructor << oaklandAs;
	REQUIRE(instructor.str() == "Crazy George");

	instructor.str("");
	Instructor adm("Hopper,Grace");
	instructor << adm;
	REQUIRE(instructor.str() == "Grace Hopper");

	REQUIRE(adm.MatchesInstructorSearch("Hopper"));
	REQUIRE(adm.MatchesInstructorSearch("Grace"));
	REQUIRE(!adm.MatchesInstructorSearch("Foo"));
}

TEST_CASE("Course Class")
{
	std::ostringstream printedCourse;

	Course cs1;
	printedCourse << cs1;
	REQUIRE(printedCourse.str() == "CS 1\n\t0 seats remaining of 0.\n\tInstructor: Foo Bar.\n\tClass is on Monday & Tuesday & Wednesday from 1:00 to 1:15");
	REQUIRE(!cs1.Enroll());

	Course cop3530("COP 3530 Turing,Alan 30 1 1,2,3 12:15-13:30");
	printedCourse.str("");
	printedCourse << cop3530;
	REQUIRE(printedCourse.str() == "COP 3530\n\t1 seat remaining of 30.\n\tInstructor: Alan Turing.\n\tClass is on Monday & Tuesday & Wednesday from 12:15 to 13:30");

	REQUIRE(cop3530.MatchesPrefixSearch("COP"));
	REQUIRE(!cop3530.MatchesPrefixSearch("CS"));

	REQUIRE(cop3530.Enroll());
	printedCourse.str("");
	printedCourse << cop3530;
	REQUIRE(printedCourse.str() == "COP 3530\n\t0 seats remaining of 30.\n\tInstructor: Alan Turing.\n\tClass is on Monday & Tuesday & Wednesday from 12:15 to 13:30");
}

TEST_CASE("Course list read and enrollment")
{
	CourseList courseList("courselist.txt");

	REQUIRE(courseList.GetAllCourses() == "ID 0: COP 3530\n\t1 seat remaining of 30.\n\tInstructor: Alan Turing.\n\tClass is on Monday & Wednesday from 12:15 to 13:30\nID 1: CS 0\n\t33 seats remaining of 100.\n\tInstructor: John Doe.\n\tClass is on Tuesday & Thursday from 9:00 to 10:15\nID 2: PHL 101\n\t12 seats remaining of 50.\n\tInstructor: Abraham Maslow.\n\tClass is on Monday & Wednesday & Friday from 11:30 to 12:20\nID 3: CS 1\n\t27 seats remaining of 100.\n\tInstructor: Jane Doe.\n\tClass is on Monday & Wednesday from 8:00 to 9:15\n");

	REQUIRE(courseList.GetMyCourses() == "You are not enrolled in any courses\n");

	bool canEnroll = courseList.Enroll(1);
	REQUIRE(canEnroll);
	REQUIRE(courseList.GetMyCourses() == "ID 1: CS 0\n\t32 seats remaining of 100.\n\tInstructor: John Doe.\n\tClass is on Tuesday & Thursday from 9:00 to 10:15\n");

	bool cannotEnroll = courseList.Enroll(1);
	REQUIRE(!cannotEnroll);
	courseList.Enroll(2);
	REQUIRE(courseList.GetMyCourses() == "ID 1: CS 0\n\t32 seats remaining of 100.\n\tInstructor: John Doe.\n\tClass is on Tuesday & Thursday from 9:00 to 10:15\nID 2: PHL 101\n\t11 seats remaining of 50.\n\tInstructor: Abraham Maslow.\n\tClass is on Monday & Wednesday & Friday from 11:30 to 12:20\n");
}

TEST_CASE("Course list searching")
{
	CourseList courseList("courselist.txt");
	REQUIRE(courseList.InstructorSearch("Foo") == "");
	REQUIRE(courseList.InstructorSearch("Doe") == "ID 1: CS 0\n\t33 seats remaining of 100.\n\tInstructor: John Doe.\n\tClass is on Tuesday & Thursday from 9:00 to 10:15\nID 3: CS 1\n\t27 seats remaining of 100.\n\tInstructor: Jane Doe.\n\tClass is on Monday & Wednesday from 8:00 to 9:15\n");

	REQUIRE(courseList.PrefixSearch("Foo") == "");
	REQUIRE(courseList.PrefixSearch("CS") == "ID 1: CS 0\n\t33 seats remaining of 100.\n\tInstructor: John Doe.\n\tClass is on Tuesday & Thursday from 9:00 to 10:15\nID 3: CS 1\n\t27 seats remaining of 100.\n\tInstructor: Jane Doe.\n\tClass is on Monday & Wednesday from 8:00 to 9:15\n");
	REQUIRE(courseList.PrefixSearch("COP") == "ID 0: COP 3530\n\t1 seat remaining of 30.\n\tInstructor: Alan Turing.\n\tClass is on Monday & Wednesday from 12:15 to 13:30\n");
}

// Compile & run:
// make clean test
