#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include "Student.h"
#include "Course.h"
using namespace std;
void readFromFile();
void readCourses();
void readStudents();
//void readAdmins();
vector<Course>courses;
vector<Student> students;

int main()
{
	readFromFile();
	/*for (const auto& s : students)
	{
		cout << "Name: " << s.Name << endl;
		cout << "ID: " << s.ID << endl;
		cout << "Email: " << s.Email << endl;
		cout << "Password: " << s.Password << endl;
		cout << "Maximum Hours Allowed: " << s.MaximumHoursAllowed << endl;
		cout << "Finished Courses: ";
		for (const auto& c : s.FinishedCourses)
		{
			cout << c.Name << ", ";
		}
		cout << endl;
		cout << "Courses in Progress: ";
		for (const auto& c : s.CoursesInProgress)
		{
			cout << c.Name << ", ";
		}
		cout << endl;
		cout << "Academic Year: " << s.AcademicYear << endl;
		cout << "GPA: " << s.GPA << endl << endl;
	}*/

	//map<int, Student> mymap;
	//for (int i = 0; i < students.size(); i++)
	//{
	//	mymap[students[i].ID] = students[i];
	//}
	//cout << "enter your ID\n";
	//int id;
	//cin >> id;
	//auto it = mymap.find(id);
	//if (it != mymap.end())
	//{
	//	it->second.EditData(mymap,id);
	//}
	//else
	//	cout << "Incorrect ID\n";
	//students[0].FilterCourses(courses);
	//students[0].FilterStudentCourses(students[0]);
	
	//students[0].ViewAllHisCourses(students[0]);

	//students[0].ViewAllAvailableCourses(courses);
	for (int i = 0; i < students[0].CoursesInProgress.size(); i++)
	{
		cout << students[0].CoursesInProgress[i].Name;
	}
	string name;
	getline(cin,name);
	students[0].RegisterCourse(courses, students[0], name);
	for (int i = 0; i < students[0].CoursesInProgress.size(); i++)
	{
		cout << students[0].CoursesInProgress[i].Name;
	}
	
	/*students[0].ViewCGPA(students[0]);*/
}

void readFromFile()
{
	readCourses();
	readStudents();
//	readAdmins();
}
void readStudents()
{
	ifstream input;
	input.open("Students.txt");
	string name, email, password;
	string cname, code, req, instructor, prereq, str;
	int hours, max;
	long long id;
	int max_hours_allowed, academic_year;
	float gpa;
	Student s;

	while (getline(input, name))
	{

		while (getline(input, cname))
		{
			if (cname.empty())
				break;
			Course c;
			getline(input, code);
			getline(input, req);
			input >> max;
			input.ignore();
			getline(input, prereq);
			stringstream ss(prereq);
			while (getline(ss, str, ','))
			{
				c.ListofPreRequiredCourses.push_back(str);
			}
			input >> hours;
			input.ignore();
			getline(input, instructor);
			c.Name = cname;
			c.Code = code;
			c.RequirementOrElective = req;
			c.MaximumNumberofStudents = max;
			c.Hours = hours;
			c.Instructor = instructor;
			s.CoursesInProgress.push_back(c);
		}
		input >> id;
		input.ignore();
		getline(input, email);
		getline(input, password);
		input >> max_hours_allowed;
		input.ignore();
		while (getline(input, cname))
		{
			if (cname.empty())
				break;
			Course c;
			getline(input, code);
			getline(input, req);
			input >> max;
			input.ignore();
			getline(input, prereq);
			stringstream ss(prereq);

			while (getline(ss, str, ','))
			{
				c.ListofPreRequiredCourses.push_back(str);
			}
			input >> hours;
			input.ignore();
			getline(input, instructor);
			c.Name = cname;
			c.Code = code;
			c.RequirementOrElective = req;
			c.MaximumNumberofStudents = max;
			c.Hours = hours;
			c.Instructor = instructor;
			s.FinishedCourses.push_back(c);
		}
		input >> academic_year >> gpa;
		input.ignore();
		s.Name = name;
		s.ID = id;
		s.Email = email;
		s.Password = password;
		s.MaximumHoursAllowed = max_hours_allowed;
		s.AcademicYear = academic_year;
		s.GPA = gpa;
		students.push_back(s);
	}
	input.close();
}
void readCourses()
{
	ifstream input;
	input.open("Courses.txt");
	string name, req_or_elective, instructor, code, list, line, prereq;
	int hours;
	long long max_no;

	while (getline(input, name))
	{
		Course c;
		getline(input, code);
		getline(input, req_or_elective);
		input >> max_no;
		input.ignore();
		getline(input, line);
		stringstream ss(line);
		while (getline(ss, prereq, ','))
		{
			c.ListofPreRequiredCourses.push_back(prereq);
		}
		input >> hours;
		input.ignore();
		getline(input, instructor);
		c.Name = name;
		c.Code = code;
		c.RequirementOrElective = req_or_elective;
		c.MaximumNumberofStudents = max_no;
		c.Hours = hours;
		c.Instructor = instructor;
		courses.push_back(c);
	}
	input.close();
}
