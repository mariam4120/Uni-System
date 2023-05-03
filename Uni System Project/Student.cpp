#include "Student.h"
#include<iostream>
#include<string>
#include<map>
#include "Course.h"
using namespace std;
Student::Student(string name, int id, string email, string password,int currenthours , int maxhours, int academicYear, float gpa, vector<Course>finishedcourses, vector<Course>coursesinprogress)
{
	Name = name;
	ID = id;
	Email = email;
	Password = password;
	CurrentHours = currenthours;
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
					for (string course : val.ListofPreRequiredCourses)
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
						for (string course : val.ListofPreRequiredCourses)
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
						for (string course : val.ListofPreRequiredCourses)
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
					for (string course : val.ListofPreRequiredCourses)
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

void Student:: ViewAllAvailableCourses(vector<Course> c)
{
	
		
			for (int i = 0; i < c.size(); i++)
		 {
			if (c[i].CurrentNumberOfStudents < c[i].MaximumNumberofStudents )
			
		    {
		    cout << "Name: " << c[i].Name << endl;
			cout << "Code: " << c[i].Code << endl;
			cout << "Requirement or Elective: " << c[i].RequirementOrElective << endl;
			cout << "Maximum Number of Students: " << c[i].MaximumNumberofStudents << endl;
			cout << "List of Prerequisite Required Courses:" << endl;
			for (int j = 0; j < c[i].ListofPreRequiredCourses.size(); j++)
			{
				cout << j << " - " << c[i].ListofPreRequiredCourses[j];
			}
			cout << "Hours: " << c[i].Hours << endl;
			cout << "Instructor: " << c[i].Instructor << endl;
			cout << "***************************************************************************************************************\n";
			
		    }
				

		 }		

	
	
}

void Student:: RegisterCourse(vector<Course>c, Student& s, string course)
{
	
	bool isfound = false;
	for (int i = 0; i < c.size(); i++)
	{
		
		if (c[i].Name == course)
		{
			isfound = true;
			if (c[i].CurrentNumberOfStudents < c[i].MaximumNumberofStudents && s.CurrentHours+c[i].Hours < s.MaximumHoursAllowed)
			{
				for (int j = 0; j < s.FinishedCourses.size(); j++)
				{
					if (s.FinishedCourses[j].Name != course)
					{
						for (int k = 0; k < c[i].ListofPreRequiredCourses.size(); k++)
						{
							if (s.FinishedCourses[j].Name == c[i].ListofPreRequiredCourses[k] || c[i].ListofPreRequiredCourses.size() == 0)
							{
									s.CoursesInProgress.push_back(c[i]);
									s.CurrentHours++;
									c[i].CurrentNumberOfStudents++;
									cout << "You have registered successfully";
							}
							
						}
					}
					else
						cout << "You already finished this course";
				}
				
			}
			else
				cout << "This course is full or your hours have run out";

			

			break;

		}
		
		
	

	}
	if (!isfound)
		{
			cout << "Not valid";
		}
		else
		{
		cout << "found";
			
		}
	
}


void Student::ViewAllHisCourses(Student s)
{
	int choice;
	cout << "1) View Finished Courses." << endl;
	cout << "2) View In Progress Courses." << endl;
	cin >> choice;

	if (choice == 1)
	{
		for (int i = 0; i < s.FinishedCourses.size(); i++)
		{
				cout << "Name:" << " " << s.FinishedCourses[i].Name << endl;
				cout << "Code:" << " " << s.FinishedCourses[i].Code << endl;
				cout << "Requirement or Elective:" << " " << s.FinishedCourses[i].RequirementOrElective << endl;
				cout << "List of Prerequisite Required Courses:" << endl;
				for (int k = 0; k < s.FinishedCourses[i].ListofPreRequiredCourses.size(); k++)
				{
					cout << k + 1 << " - " << s.FinishedCourses[i].ListofPreRequiredCourses[k] << endl;
				}
				cout << "Hours:" << " " << s.FinishedCourses[i].Hours << endl;
				cout << "Instructor:" << " " << s.FinishedCourses[i].Instructor << endl;
			
		}

	}

	else
		
	{
		for (int i = 0; i < s.CoursesInProgress.size(); i++)
		{
		cout << "Name:" << " " << s.CoursesInProgress[i].Name << endl;
		cout << "Code:" << " " << s.CoursesInProgress[i].Code << endl;
		cout << "Requirement or Elective:" << " " << s.CoursesInProgress[i].RequirementOrElective << endl;
		cout << "List of Prerequisite Required Courses:" << endl;
		for (int k = 0; k < s.CoursesInProgress[i].ListofPreRequiredCourses.size(); k++)
		{
			cout << k + 1 << " - " << s.CoursesInProgress[i].ListofPreRequiredCourses[k] << endl;
		}
		cout << "Hours:" << " " << s.CoursesInProgress[i].Hours << endl;
		cout << "Instructor:" << " " << s.CoursesInProgress[i].Instructor << endl;

		}
		
	}


	
}

void Student:: ViewCGPA(Student s)
{
	float* grades = new float[s.FinishedCourses.size()];
	float total_grades = 0;
	float total_hours = 0;
	for (int i = 0; i < s.FinishedCourses.size(); i++)
	{
		cin >> grades[i];
	}
	for (int i = 0; i < s.FinishedCourses.size(); i++)
	{
		total_grades += grades[i]*s.FinishedCourses[i].Hours;
		total_hours += s.FinishedCourses[i].Hours;
	}
	cout<< total_grades / total_hours;

}