#include "Course.h"

Course::Course()
{
	Name = Code = Instructor = " ";
	CurrentNumberOfStudents= MaximumNumberofStudents = Hours = 0;
	
}
Course::Course(string name, string code, bool reqorelec, int currentstudents, int maxofstudents, vector<string> listsofcourses, int hours, string instructor)
{
	Name = name;
	Code = code;
	CurrentNumberOfStudents = currentstudents;
	RequirementOrElective = reqorelec;
	MaximumNumberofStudents = maxofstudents;
	for (int i = 0; i < listsofcourses.size(); i++)
	ListofPreRequiredCourses[i] = listsofcourses[i];
	Hours = hours;
	Instructor = instructor;
}
