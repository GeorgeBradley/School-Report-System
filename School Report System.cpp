// School Enrollment System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <Memory>

class Class;
//Class hierarchy
class Person
{
public:
    int iPersonID;
    std::string sName;

    Person()
    {

    }
    Person(int iInitPersonID, std::string sInitName)
        :iPersonID(iInitPersonID), sName(sInitName)
    {
    }
    ~Person() {
    }
};

class Student : public Person
{
public:
    std::vector<Class>vecClasses; //Student can have many classes

    Student(int iInitPersonID, std::string sInitName) 
        :Person(iInitPersonID, sInitName) {
    }
    ~Student() {
    }
};

class Teacher : public Person
{
public:
    std::string sDepartment;
    std::string sSubject;
    std::vector<Class>vecClasses; //Teacher can teach many classes

    Teacher(int iInitID, std::string sInitName):Person(iInitID, sInitName)
    {

    }
    ~Teacher()
    {

    }
};

class Class
{
public:
    int iClasssID;
    std::shared_ptr<Teacher>objTeacher; //Class has one teacher
    std::vector<std::shared_ptr<Student>>vecStudents;//Class has many students

    Class() {
    }
    ~Class() {
    }
};


void Add_New_Student(Class &objClass)
{
    std::shared_ptr<Student>spStudent = std::make_shared<Student>(3, "Student");
    objClass.vecStudents.push_back(spStudent);
}

void Add_New_Teacher(Class& objClass) 
{
    
    objClass.objTeacher = std::make_shared<Teacher>(3, "Teacher");
}

void Display_Class(Class &objClass)
{
    std::cout << objClass.objTeacher->sName << std::endl;

    for (auto& objStudent : objClass.vecStudents)
    {
        std::cout << objStudent->sName << std::endl;
    }
    std::cout << std::endl;
}
void Display_All_Classes(std::vector<Class>&classVec) {

    for (Class& objClass : classVec)
    {
        Display_Class(objClass);
    }

}
void Add_Class(Class& objClass)
{
    Add_New_Teacher(objClass);
    Add_New_Student(objClass);
    Add_New_Student(objClass);
    Add_New_Student(objClass);
    Add_New_Student(objClass);
}
int main()
{
    std::vector<Class>classVec;

    Class objClass1;
    Add_Class(objClass1);
    classVec.push_back(objClass1);

    Class objClass2;
    Add_Class(objClass2);
    classVec.push_back(objClass2);

    Class objClass3;
    Add_Class(objClass3);
    classVec.push_back(objClass3);

    Display_All_Classes(classVec);
   
    /*std::vector<std::shared_ptr<Class>>classes;
    classes.push_back(objClass);*/
}

