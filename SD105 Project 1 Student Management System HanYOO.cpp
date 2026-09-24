
#include <iostream>
#include <vector>
#include <string>

using namespace std; // use the standard namespace

	/////////////////////////////////////////////////////////////////////////////////////
	// define classes for student, course, and grade
	// each class will have appropriate attributes and methods
	// Student class
    class student {
    private: // private attributes
        int rollNumber; // roll number for students
        string name; // name of the student

    public: // public methods
        student(int r, const string& n) : rollNumber(r), name(n) {} // student constructor with roll number and name
        int getRollNumber() const { return rollNumber; } // getter for roll number
        string getName() const { return name; } // getter for name
        void setName(const string& n) { name = n; } // setter for name
    };
	// Course class
    class course {
	private: // private attributes
        int courseCode; // course code
        string title; // course title

	public: // public methods
		course(int c, const string& t) : courseCode(c), title(t) {} // course constructor with course code and title
		int getCourseCode() const { return courseCode; } // getter for course code
		string getTitle() const { return title; } // getter for title
		void setTitle(const string& t) { title = t; } // setter for title
    };
	// Grade class
	class Grade {
	private: // private attributes
		int rollNumber; // roll number of the student
		string name; // name of the student
		int courseCode; // course code
		int internalMark; // internal mark
		int finalMark; // final mark
		string title; // course title

	public: // public methods
		Grade(int r, string n, string t, int c, int im, int fm) : rollNumber(r), name(n), title(t), courseCode(c), internalMark(im), finalMark(fm) {} // grade constructor with roll number, name, course code, internal mark, and final mark

		int getRollNumber() const { return rollNumber; } // getter for roll number
		string getName() const { return name; }// getter for name
		string getTitle() const { return title; } // getter for course title
		int getCourseCode() const { return courseCode; } // getter for course code

		void setInternalMark(int im) {
			if (im >= 0 && im <= 100) // set internal mark between 0 and 100
				internalMark = im; // set the private variable 'internalMark' to the value of 'im'
		}
		void setFinalMark(int fm) {
			if (fm >= 0 && fm <= 100) // set final mark between 0 and 100
				finalMark = fm; // set the private variable 'finalMark' to the value of 'fm'
		}
	
		int getinternalMark() const { return internalMark; } // getter for internal mark
		int getfinalMark() const { return finalMark; } // getter for final mark

		double getWeightedTotal() const {
			return (internalMark * 0.3) + (finalMark * 0.7); // calculate weighted total
		}
		// determine letter grade based on weighted total
		string getLetterGrade() const {
			double total = getWeightedTotal();
			if (total >= 90 && total <= 100) return "A+";
			else if (total >= 80 && total <= 89 ) return "A";
			else if (total >= 70 && total <= 79) return "B+";
			else if (total >= 60 && total <= 69) return "B";
			else if (total >= 50 && total <= 59) return "C";
			else return "D";
		}
	};
	
	// shared data structures
	vector<student> students;
	vector<course> courses;
	vector<Grade> grades;

	// Helper functions to find student,course and grade by their identifiers
	// find student by name
    student* findStudentByname(std::vector<student>& students, const std::string& name) {
        for (auto &s : students)
            if (s.getName() == name)
                return &s;
        return nullptr; // return nullptr if not found, nullpointer is a pointer that does not point to any object or function
    }
	// find student by roll number
	student* findStudent(int rollNumber) {
		for (auto& s : students) {
			if (s.getRollNumber() == rollNumber)
				return &s;
		}
		return nullptr; // return nullptr if not found
	}
	// find course by course code
	course* findCourse(int code) {
		for (auto& c : courses) {
			if (c.getCourseCode() == code)
				return &c;
		}
		return nullptr; // return nullptr if not found
	}
	// find grade by roll number and course code
	Grade* findGrade(int rollNumber, int courseCode) { // findGrade function to find a grade by roll number and course code
		for (auto &g : grades)
			if (g.getRollNumber() == rollNumber && g.getCourseCode() == courseCode) // if roll number and course code match
				return &g;
		return nullptr; // return nullptr if not found
	}
    
	// operations for managing students, courses, and grades
	void addStudent() { // operation to add a student
		int rollNumber; // variable to store roll number
		string name; // variable to store student name
        cout << "Enter Roll Number: ";
        cin >> rollNumber;
        cin.ignore(); // to ignore the newline character left in the buffer

		if (findStudent(rollNumber)) { // check if student with the same roll number already exists
			cout << "Student with this roll number already exists." << endl;
            return;
        }

		cout << "Enter Student Name: ";
        getline(cin, name);

		students.push_back(student(rollNumber, name)); // add new student to the students vector
		cout << "Student added successfully." << endl;
    }
	// operation to view all students
    void viewStudents() {
		cout << "List of Students:" << endl;
        for (const auto& s : students) {
            cout << s.getRollNumber()
                << "\t"
                << s.getName()
                << "\n";
        }
    }
	// operation to edit a student's name
	void editStudent() {
		int rollNumber; // variable to store roll number
		cout << "Enter Roll Number of the student to edit: ";
		cin >> rollNumber;
		student* s = findStudent(rollNumber); // find the student by roll number
		if (!s) {
			cout << "Student not found." << endl;
			return;
		}
		string newName; // variable to store new name
		cout << "Enter new name: ";
		cin.ignore();
		getline(cin, newName);
		s->setName(newName);
		cout << "Student updated successfully." << endl;
	}
	// operation to delete a student
    void deleteStudent() {
		int rollNumber; // variable to store roll number
		cout << "Enter Roll Number of the student to delete: ";
		cin >> rollNumber;

		for (size_t i = 0; i < students.size(); ++i) { // iterate through the students vector
			if (students[i].getRollNumber() == rollNumber) { // if roll number matches
				students.erase(students.begin() + i); // erase the student from the vector
				cout << "Student deleted successfully." << endl;
				return;
            }
        }
		cout << "Student not found." << endl;
    }
	// operation to add a course
    void addCourse() {
		int courseCode; // variable to store course code
		string title; // variable to store course title

		cout << "Enter Course Code: ";

		while (!(cin >> courseCode)) {
			cout << "Invalid course code. Numbers only: ";

			cin.clear();
			cin.ignore(10000, '\n');
		}

		cin.ignore();

		if (findCourse(courseCode)) { // check if course with the same code already exists
			cout << "Course with this code already exists." << endl;
			return;
    }
		cout << "Enter Course title: ";
		getline(cin, title);

		courses.push_back(course(courseCode, title)); // add new course to the courses vector
		cout << "Course added successfully." << endl;
	}
	// operation to view all courses
	void viewCourses() {
		cout << "List of Courses:" << endl;
		for (const auto& c : courses) { // iterate through the courses vector
			cout << c.getCourseCode() 
				<< "\t"
				<< c.getTitle()
				<< "\n";
		}
	}
	// operation to edit a course's title
    void editCourse() {
		int courseCode; // variable to store course code
		cout << "Enter Course Code of the course to edit: ";
		cin >> courseCode;
        cin.ignore(); 

		course* c = findCourse(courseCode); // find the course by course code
		if (!c) {
			cout << "Course not found." << endl;
			return;
    }

		string newTitle; // variable to store new title
		cout << "Enter new title: ";
		getline(cin, newTitle);
		c->setTitle(newTitle);
		cout << "Course updated successfully." << endl;
	}
	// operation to delete a course
	void deleteCourse() {
		int courseCode; // variable to store course code
		cout << "Enter Course Code of the course to delete: ";
		cin >> courseCode;

		for (size_t i = 0; i < courses.size(); ++i) { // iterate through the courses vector
			if (courses[i].getCourseCode() == courseCode) { // if course code matches
				courses.erase(courses.begin() + i); // erase the course from the vector
				cout << "Course deleted successfully." << endl;
				return;
			}
		}
		cout << "Course not found." << endl;
	}
	// operation to view students enrolled in a specific course by course code
	void viewStudentsInCourse() {
		int code; // variable to store course code
		cout << "Enter Course Code: ";
		cin >> code;
		course* course = findCourse(code); // find the course by course code
		if (!course) { // if course not found
			cout << "Course not found." << endl;
			return;
		}
		cout << "Students enrolled in course"
			<< course->getTitle() // get the title of the course
			<< " (" << course->getCourseCode() << "):" << endl; // get the course code
		cout << "rollNumber\tName" << endl;
		bool any = false; // flag to check if any students are enrolled
		for (const auto& g : grades) { // iterate through the grades vector
			if (g.getCourseCode() == code) { // if course code matches
				student* s = findStudent(g.getRollNumber()); // find the student by roll number
				if (s) { // if student found
					cout << s->getRollNumber()
						<< "\t\t"
						<< s->getName()
						<< "\n";

					any = true; // set flag to true if any students are found
				}
			}			 
		}

		if (!any) { // if no students are enrolled
			cout << "No students enrolled in this course." << endl;
		}
	}
	// operation to delete a student from a specific course by roll number and course code
	void deleteStudentInCourse() { 
		int rollNumber, courseCode; // variables to store roll number and course code
		cout << "Enter Roll Number of the student: ";
		cin >> rollNumber;
		cout << "Enter Course Code: ";
		cin >> courseCode;
		for (size_t i = 0; i < grades.size(); ++i) { // iterate through the grades vector
			if (grades[i].getRollNumber() == rollNumber && grades[i].getCourseCode() == courseCode) { // if roll number and course code match
				grades.erase(grades.begin() + i); // erase the grade from the vector
				cout << "Student removed from course successfully." << endl;
				return;
			}
		}
		cout << "Student not found in this course." << endl;
	}
	// operation to add a grade for a student in a specific course
	void addGrade() {
		int rollNumber, courseCode, internalMark, finalMark; // variables to store roll number, course code, internal mark, and final mark
		string name, title; // variables to store student name and course title
		
		cout << "Enter Roll Number: ";
		cin >> rollNumber;

		student* s = findStudent(rollNumber);// find the student by roll number
		
		cout << "Enter Course Code: ";
		cin >> courseCode;

		course* c = findCourse(courseCode);

		if (!s || !c) { // check if student and course exist
			cout << "Student or Course not found." << endl;
			return;
		}
		if (findGrade(rollNumber, courseCode)) { // check if grade already exists for this student in this course
			cout << "Grade for this student in this course already exists." << endl;
            return;
		}

		cout << "Enter Internal Mark (0-100): ";
		cin >> internalMark;
		cout << "Enter Final Mark (0-100): ";
		cin >> finalMark;
		grades.push_back(Grade(rollNumber, s->getName(), c->getTitle(), courseCode, internalMark, finalMark)); // add new grade to the grades vector
		cout << "Grade added successfully." << endl;
	}
	// operation to view all grades
	void viewGrades() {
		cout << "List of Grades:" << endl;
		for (const auto& g : grades) {
			cout << g.getRollNumber()
				<< "\t"
				<< g.getName()
				<< "\t"
				<< g.getCourseCode()
				<< "\t"
				<< g.getTitle()
				<< "\t"
				<< g.getinternalMark()
				<< "\t"
				<< g.getfinalMark()
				<< "\t"
				<< g.getWeightedTotal()
				<< "\t"
				<< g.getLetterGrade()
				<< "\n";
		}
	}
	// operation to edit a grade for a student in a specific course
	void editGrade() {
		int rollNumber, courseCode; // variables to store roll number and course code
		cout << "Enter Roll Number of the student: ";
		cin >> rollNumber;
		cout << "Enter Course Code: ";
		cin >> courseCode;
		Grade* g = findGrade(rollNumber, courseCode); // find the grade by roll number and course code
		if (!g) {
			cout << "Grade not found." << endl;
			return;
		}
		int internalMark, finalMark; // variables to store new internal mark and final mark
		cout << "Enter new Internal Mark (0-100): ";
		cin >> internalMark;
		cout << "Enter new Final Mark (0-100): ";
		cin >> finalMark;
		g->setInternalMark(internalMark);
		g->setFinalMark(finalMark);
		cout << "Grade updated successfully." << endl;
	}
	// operation to delete a grade for a student in a specific course
	void deleteGrade() {
		int rollNumber, courseCode; // variables to store roll number and course code
		cout << "Enter Roll Number of the student: ";
		cin >> rollNumber;
		cout << "Enter Course Code: ";
		cin >> courseCode;

		for (size_t i = 0; i < grades.size(); ++i) { // iterate through the grades vector
			if (grades[i].getRollNumber() == rollNumber && grades[i].getCourseCode() == courseCode) { // if roll number and course code match
				grades.erase(grades.begin() + i); // erase the grade from the vector
				cout << "Grade deleted successfully." << endl;
				return;
		}
	}
		cout << "Grade not found." << endl;
	}
	// operation to enrol a student in a course
	void addStudentToCourse() {
		int rollNumber, courseCode; // variables to store roll number and course code
		cout << "Enter Roll Number of the student: ";
		cin >> rollNumber;
		cout << "Enter Course Code: ";
		cin >> courseCode;
		if (!findStudent(rollNumber) || !findCourse(courseCode)) { // check if student and course exist
			cout << "Student or Course not found." << endl;
			return;
		}
		if (findGrade(rollNumber, courseCode)) { // check if student is already enrolled in this course
			cout << "Student already enrolled in this course." << endl;
			return;
		}

		student* s = findStudent(rollNumber);
		course* c = findCourse(courseCode);
		
		grades.push_back(Grade(rollNumber, s->getName(), c->getTitle(), courseCode, 0, 0)); // Initialize with 0 marks
		cout << "Student enrolled in course successfully." << endl;
	}
	// operation to generate a report for a specific student by roll number
	void generateReport() {
		int rollNumber; // variable to store roll number
		cout << "Enter Roll Number of the student: ";
		cin >> rollNumber;
		student* s = findStudent(rollNumber); // find the student by roll number
		if (!s) {
			cout << "Student not found." << endl;
			return;
		}
		cout << "Report for " << s->getName() << " (Roll Number: " << s->getRollNumber() << "):" << endl;
		cout << "Course Code\tInternal Mark\tFinal Mark\tWeighted Total\tLetter Grade" << endl;
		for (const auto& g : grades) { // iterate through the grades vector
			if (g.getRollNumber() == rollNumber) { // if roll number matches
				cout << g.getCourseCode()
					<< "\t\t"
					<< g.getinternalMark()
					<< "\t\t"
					<< g.getfinalMark()
					<< "\t\t"
					<< g.getWeightedTotal()
					<< "\t\t"
					<< g.getLetterGrade()
					<< "\n";
			}
		}
	}
	// main function to run the student management system
	int main() {

		int choice;
		do {
			cout << "Student Management System" << endl;
			cout << "1. Manage Students" << endl;
			cout << "2. Manage Courses" << endl;
			cout << "3. Manage Grades" << endl;
			cout << "4. Enrol Student in courses" << endl;
			cout << "5. Generate Report" << endl;
			cout << "6. Exit" << endl;
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice) { // main menu switch case
			case 1: { // submenu for managing students
				int subChoice; // variable to store submenu choice
				cout << "Manage Students" << endl;
				cout << "1. Add Student" << endl;
				cout << "2. View Students" << endl;
				cout << "3. Edit Student" << endl;
				cout << "4. Delete Student" << endl;
				cout << "5. Back to Main Menu" << endl;
				cout << "Enter your choice: ";
				cin >> subChoice;
				switch (subChoice) { // submenu switch case
				case 1: addStudent(); break;
				case 2: viewStudents(); break;
				case 3: editStudent(); break;
				case 4: deleteStudent(); break;
				}
				break;
			}
			case 2: { // submenu for managing courses
				int subChoice; // variable to store submenu choice
				cout << "Manage Courses" << endl;
				cout << "1. Add Course" << endl;
				cout << "2. View Courses" << endl;
				cout << "3. Edit Course" << endl;
				cout << "4. Delete Course" << endl;
				cout << "5. View Enrolled Students" << endl;
				cout << "6. Delete Student from Course" << endl;
				cout << "7. Back to Main Menu" << endl;
				cout << "Enter your choice: ";
				cin >> subChoice;
				switch (subChoice) { // submenu switch case
				case 1: addCourse(); break;
				case 2: viewCourses(); break;
				case 3: editCourse(); break;
				case 4: deleteCourse(); break;
				case 5: viewStudentsInCourse(); break;
				case 6: deleteStudentInCourse(); break;
				}
				break;
			}
			case 3: { // submenu for managing grades
				int subChoice; // variable to store submenu choice
				cout << "Manage Grades" << endl;
				cout << "1. Add Grade" << endl;
				cout << "2. View Grades" << endl;
				cout << "3. Edit Grade" << endl;
				cout << "4. Delete Grade" << endl;
				cout << "5. Back to Main Menu" << endl;
				cout << "Enter your choice: ";
				cin >> subChoice;
				switch (subChoice) { // submenu switch case
				case 1: addGrade(); break;
				case 2: viewGrades(); break;
				case 3: editGrade(); break;
				case 4: deleteGrade(); break;
				}
				break;
			}
			case 4: 
				addStudentToCourse();
				break;
			case 5:
				generateReport();
				break; 
			}
		} while (choice != 6);
		cout << "Exiting the program." << endl;
		return 0;
	}
