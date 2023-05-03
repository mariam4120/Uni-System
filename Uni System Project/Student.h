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
	int CurrentHours;
	vector<Course>FinishedCourses;
	vector<Course>CoursesInProgress;
	int AcademicYear;
	float GPA;
	Student(string name, int id, string email, string password, int currenthours, int maxhours, int academicYear, float gpa, vector<Course>finishedcourses, vector<Course>coursesinprogress);
	Student();
	void EditData(map<int, Student> stdData, int stdID);
	void FilterCourses(vector<Course> c);
	void FilterStudentCourses(Student std);
	//Log in.
	void ViewAllAvailableCourses(vector<Course> c);
	//	View details of a specific course.
	void RegisterCourse(vector <Course>c, Student& s, string course);
	void ViewAllHisCourses(Student s);
	void ViewCGPA(Student s);
};


