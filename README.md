# Student Management System

A console-based Student Management System developed in C++ using Object-Oriented Programming (OOP) principles.

This application allows users to manage students, courses, enrollments, and grades through an interactive menu-driven interface. The project was developed as part of the SD105 Development Principles course and focuses on applying core programming concepts such as classes, encapsulation, vectors, functions, data validation, and CRUD operations.

---

## Features

### Student Management
- Add Students
- View Students
- Edit Student Information
- Delete Students

### Course Management
- Add Courses
- View Courses
- Edit Course Information
- Delete Courses
- View Students Enrolled in a Course
- Remove Students from Courses

### Grade Management
- Add Grades
- View Grades
- Edit Grades
- Delete Grades

### Enrollment Management
- Enroll Students into Courses
- Track Student-Course Relationships

### Reporting
- Generate Student Academic Reports
- Calculate Weighted Grades
- Automatically Assign Letter Grades

---

## Technologies Used

- C++
- Object-Oriented Programming (OOP)
- STL Vector
- Console Application Development
- Data Validation
- CRUD Operations

---

## Object-Oriented Design

The system is built around three main classes:

### Student
Stores:
- Roll Number
- Student Name

### Course
Stores:
- Course Code
- Course Title

### Grade
Stores:
- Student Information
- Course Information
- Internal Marks
- Final Marks
- Weighted Total
- Letter Grade

---

## Grade Calculation

Weighted total is calculated as:

```cpp
(internalMark * 0.3) + (finalMark * 0.7)