#include "classtime.hpp"



ClassTime::ClassTime (std::string days, std::string times)
{
		this->SetDaysOfTheWeek(days);
		this->SetTime(times);
}

void ClassTime::SetDaysOfTheWeek (std::string days)
{
	for (int i = 0; i < DAYS_PER_WEEK; ++i)
	{
		this->daysOfTheWeek[i] = -1;
	}

	std::istringstream is(days);
	std::string day;
	int i = 0;
	while (std::getline(is, day, ',')) // split the string at the comma (,) 
	{
      this->numDays++;
		this->daysOfTheWeek[i++] = stoi(day); // cast the string value to an integer type
	}
}
void ClassTime::SetTime (std::string times)
{
	if (times == "")
	{
		this->times[ClassTime::START_HOUR] = 0;
		this->times[ClassTime::START_MINUTE] = 0;

		this->times[ClassTime::END_HOUR] = 0;
		this->times[ClassTime::END_MINUTE] = 0;
		return;
	}

	std::istringstream is(times);
	std::string part;
	std::string minOrHour;

	std::istringstream is2;

	for (int i = 0; i < 2; ++i)
	{
		// reset the string stream and set to new substring
		is2.str("");
		is2.clear();

		std::getline(is, part, '-');
		is2.str(part);
		std::getline(is2, minOrHour, ':');

		// we fetched the hours value as a string (required by getline), so let's cast it to an integer
		this->times[2*i] = stoi(minOrHour);

		// We can use the stream directly now that it's been setup with getline, so no need to cast any more
		is2 >> this->times[2*i + 1]; // 
	}
}

bool ClassTime::MatchesSearch(int day, int beginHour, int beginMinute, int endHour, int endMinute)
{

	return false;
}

std::ostream& operator<<(std::ostream& os, const ClassTime& ct)
{
	bool hasOtherDay = false;
	if (ct.daysOfTheWeek[0] >= 0)
	{
		os << "Class is on ";

		for (int i = 0; i < ct.numDays; ++i)
		{
			if (ct.daysOfTheWeek[i] < 0)
			{
				break;
			}

			if (hasOtherDay)
			{
				os << " & ";
			}
			else
			{
				hasOtherDay = true;
			}

			switch (ct.daysOfTheWeek[i])
			{
				case 0:
					os << "Sunday";
					break;
				case 1:
					os << "Monday";
					break;
				case 2:
					os << "Tuesday";
					break;
				case 3:
					os << "Wednesday";
					break;
				case 4:
					os << "Thursday";
					break;
				case 5:
					os << "Friday";
					break;
				case 6:
					os << "Saturday";
					break;
			}
		}

		os << " from " << ct.times[ClassTime::START_HOUR] << ":";
		os << std::setw(2) << std::setfill('0') << ct.times[ClassTime::START_MINUTE];
		os << " to " << ct.times[ClassTime::END_HOUR] << ":";
		os << std::setw(2) << std::setfill('0') << ct.times[ClassTime::END_MINUTE];
	}

	return os;
}
