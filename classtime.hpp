#ifndef CLASSTIME_HPP
#define CLASSTIME_HPP

#include<string>
#include<sstream>
#include<iostream>
#include<iomanip>

const int DAYS_PER_WEEK = 7;

class ClassTime
{

	public:
		ClassTime (std::string days = "", std::string times = "");
		ClassTime(std::string days, std::string time);
		bool MatchesSearch(int day, int beginHour, int beginMinute, int endHour, int endMinute);
		friend std::ostream& operator<<(std::ostream& os, const ClassTime& ct);
	private:
		int numDays = 0; 
		int daysOfTheWeek[DAYS_PER_WEEK];
		int times[4];
		void SetDaysOfTheWeek (std::string days);
		void SetTime (std::string times);
		enum timeParts { START_HOUR, START_MINUTE, END_HOUR, END_MINUTE };


};

#endif
