#pragma once
#include<iostream>
#include <string>
#include<vector>
using namespace std;
class Course
{
public:
	string Name;
	string Code;
	string RequirementOrElective;
	int MaximumNumberofStudents;
	int CurrentNumberOfStudents;
	vector<string>ListofPreRequiredCourses;
	int Hours;
	string Instructor;
	Course();
	Course(string name, string code, bool reqorelec, int currentstudents, int maxofstudents, vector<string>listsofcourses, int hours, string instructor);
};

