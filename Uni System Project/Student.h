#pragma once
#include<iostream>
#include <string>
#include<vector>
#include<map>
#include "Course.h"
using namespace std;
class Student
{
public:

	string Name;
	int ID;
	string Email;
	string Password;
	int MaximumHoursAllowed;
	vector<Course>FinishedCourses;
	vector<Course>CoursesInProgress;
	int AcademicYear;
	float GPA;
	Student(string name, int id, string email, string password, int maxhours, int academicYear, float gpa, vector<Course>finishedcourses, vector<Course>coursesinprogress);
	Student(string name, int id, string email, string password, int maxhours, int academicYear, float gpa);
	Student();
	void EditData(map<int, Student> stdData, int stdID);
	void FilterCourses(vector<Course> c);
	void FilterStudentCourses(Student std);
	//Log in.
	//	View List of all available courses.
	//	View details of a specific course.
	//	Register for a course.
	//	View all his / her courses.
	//	View his / her courses grades and cumulative GPA.
};


