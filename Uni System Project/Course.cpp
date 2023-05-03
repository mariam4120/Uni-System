#include "Course.h"

Course::Course()
{
	Name = Code = Instructor = " ";
	MaximumNumberofStudents = Hours = 0;
	
}
Course::Course(string name, string code, bool reqorelec, int maxofstudents, vector<string> listsofcourses, int hours, string instructor)
{
	Name = name;
	Code = code;
	RequirementOrElective = reqorelec;
	MaximumNumberofStudents = maxofstudents;
	for (int i = 0; i < listsofcourses.size(); i++)
		ListofPrRequiredCourses[i] = listsofcourses[i];
	Hours = hours;
	Instructor = instructor;
}
