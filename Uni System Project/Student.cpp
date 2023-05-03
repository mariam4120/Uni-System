#include "Student.h"
#include<iostream>
#include<string>
#include<map>
#include "Course.h"
using namespace std;
Student::Student(string name, int id, string email, string password, int maxhours, int academicYear, float gpa, vector<Course>finishedcourses, vector<Course>coursesinprogress)
{
	Name = name;
	ID = id;
	Email = email;
	Password = password;
	MaximumHoursAllowed = maxhours;
	AcademicYear = academicYear;
	GPA = gpa;
	for (int i = 0; i < finishedcourses.size(); i++)
	{
		FinishedCourses[i] = finishedcourses[i];
	}
	for (int i = 0; i < coursesinprogress.size(); i++)
	{
		CoursesInProgress[i] = coursesinprogress[i];
	}
}
Student::Student(string name, int id, string email, string password, int maxhours, int academicYear, float gpa)
{
	Name = name;
	ID = id;
	Email = email;
	Password = password;
	MaximumHoursAllowed = maxhours;
	AcademicYear = academicYear;
	GPA = gpa;

}

Student::Student()
{
	Name = Email = Password = " ";
	ID = MaximumHoursAllowed = AcademicYear = GPA = 0;
}
void Student::FilterStudentCourses(Student std)
{
	int choise;
	bool Exitflag = false;
	while (!Exitflag)
	{

		cout << "1)Filter Finished Courses\n";
		cout << "2)Filter Courses In Progress\n3)Exit\n";
		cin >> choise;
		switch (choise)
		{
			case 1:
			{ 
				std.FilterCourses(std.FinishedCourses); 
				break;
			}
			case 2:
			{
				std.FilterCourses(std.CoursesInProgress);
				break;
			}
			case 3:
			{
				Exitflag = true;
			   break; 
			}
			default:
			{
				cout << "enter correct number\n";
				system("cls");
				continue;
			}
		}
	}
}
void Student::EditData(map<int, Student> stdData, int stdID)
{
	string oldpassword,newpassword;
	cout << "Enter Your Old Password\n";
	cin >> oldpassword;
	if (oldpassword == stdData[stdID].Password)
	{
		cout << "Enter Your New Password\n";
		cin >> newpassword;
		stdData[stdID].Password = newpassword;
	}
	else
		cout << "Incorrect Password\n";
}
void Student::FilterCourses(vector<Course>c)
{
	int choise,hours,reqorelective;
	string name;
	bool Exitflag = false;
	while (!Exitflag)
	{
		cout << "1)Filter Courses by Hours\n2)Filter Courses by Requirement or Elective\n";
		cout << "3)Filter Courses by Instrustor Name\n4)Exit\n";
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			cout << "Filter Course by Hours\n";
			cin >> hours;
			for (Course val : c)
			{
				if (val.Hours == hours)
				{
					int i = 1;
					cout << "Name: " << val.Name << endl;
					cout << "Code: " << val.Code << endl;
					cout << "Requirement or Elective: " << val.RequirementOrElective << endl;
					cout << "Maximum Number of Students: " << val.MaximumNumberofStudents << endl;
					cout << "List of Prerequisite Required Courses:" << endl;
					for (string course : val.ListofPrRequiredCourses)
					{
						cout << i << "- " << course << endl;
						i++;
					}
					cout << "Hours: " << val.Hours << endl;
					cout << "Instructor: " << val.Instructor << endl;
					cout << "***************************************************************************************************************\n";
				}
			}
			break;
		}
		case 2:
		{
			cout << "Filter Course by Requirement or Elective\n";
			cout << "1-Show Requirment Courses\n2-Show Elective Courses\n";
			cin >> reqorelective;
			if (reqorelective == 1)
			{
				for (Course val : c)
				{
					if (val.RequirementOrElective == "Requirement" || val.RequirementOrElective == "requirement")
					{
						int i = 1;
						cout << "Name: " << val.Name << endl;
						cout << "Code: " << val.Code << endl;
						cout << "Requirement or Elective: " << val.RequirementOrElective << endl;
						cout << "Maximum Number of Students: " << val.MaximumNumberofStudents << endl;
						cout << "List of Prerequisite Required Courses:" << endl;
						for (string course : val.ListofPrRequiredCourses)
						{
							cout << i << "- " << course << endl;
							i++;
						}
						cout << "Hours: " << val.Hours << endl;
						cout << "Instructor: " << val.Instructor << endl;
						cout << "***************************************************************************************************************\n";
					}
				}
			}
			else
			{
				for (Course val : c)
				{
					if (val.RequirementOrElective == "elective" || val.RequirementOrElective == "Elective")
					{
						int i = 1;
						cout << "Name: " << val.Name << endl;
						cout << "Code: " << val.Code << endl;
						cout << "Requirement or Elective: " << val.RequirementOrElective << endl;
						cout << "Maximum Number of Students: " << val.MaximumNumberofStudents << endl;
						cout << "List of Prerequisite Required Courses:" << endl;
						for (string course : val.ListofPrRequiredCourses)
						{
							cout << i << "- " << course << endl;
							i++;
						}
						cout << "Hours: " << val.Hours << endl;
						cout << "Instructor: " << val.Instructor << endl;
						cout << "***************************************************************************************************************\n";
					}
				}
			}
			break;
		}
		case 3:
		{
			cout << "Filter Courses by Instrustor Name\n";
			cin.ignore();
			getline(cin, name);
			for (Course val : c)
				if (name == val.Instructor)
				{
					int i = 1;
					cout << "Name: " << val.Name << endl;
					cout << "Code: " << val.Code << endl;
					cout << "Requirement or Elective: " << val.RequirementOrElective << endl;
					cout << "Maximum Number of Students: " << val.MaximumNumberofStudents << endl;
					cout << "List of Prerequisite Required Courses:" << endl;
					for (string course : val.ListofPrRequiredCourses)
					{
						cout << i << "- " << course << endl;
						i++;
					}
					cout << "Hours: " << val.Hours << endl;
					cout << "Instructor: " << val.Instructor << endl;
					cout << "***************************************************************************************************************\n";
				}
			break;
		}
		case 4:
		{
			Exitflag = true;
			break; 
		}
		default:
		{
			cout << "enter correct number\n";
			system("cls");
			continue;
		}
		}
	}
}

