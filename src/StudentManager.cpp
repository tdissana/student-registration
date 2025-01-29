#include <StudentManager.hpp>
#include <utility>
#include <iostream>

using namespace registration;

void StudentManager::addStudent(int id, std::string name)
{
    auto studentItr = studentDatabase.find(id);
    if (studentItr != studentDatabase.end())
    {
        std::cerr << "Error: Student Id: " << id << " already exists" << std::endl;
    }
    else
    {
        studentDatabase.insert(std::make_pair(id, new Student(id, name)));
        std::cout << "Student Account Created Successfully" << std::endl;
    }
}

void StudentManager::removeStudentById(int id)
{
    auto studentItr = studentDatabase.find(id);
    if (studentItr != studentDatabase.end())
    {
        Student *student = studentItr->second;
        delete student;
        student = nullptr;
        studentDatabase.erase(studentItr);
        std::cout << "Student Account Deleted Successfully" << std::endl;
    }
    else
    {
        std::cerr << "Error: Student Id: " << id << " doesn't exist" << std::endl;
    }
}

void StudentManager::updateStudentId(int oldId, int newId)
{
    auto newStudentItr = studentDatabase.find(newId);
    if (newStudentItr != studentDatabase.end())
    {
        std::cerr << "Error: Student Id: " << newId << " already exists" << std::endl;
    }
    else
    {
        auto studentItr = studentDatabase.find(oldId);
        if (studentItr != studentDatabase.end())
        {
            Student *student = studentItr->second;
            if (student != nullptr)
            {
                student->setId(newId);
                studentDatabase.insert(std::make_pair(newId, student));
                studentDatabase.erase(studentItr);
                std::cout << "Student Account Updated Successfully" << std::endl;
            }
            else
            {
                std::cerr << "Error: Student Id: " << oldId << " data corrupted" << std::endl;
            }
        }
        else
        {
            std::cerr << "Error: Student Id: " << oldId << " doesn't exist" << std::endl;
        }
    }
}

void StudentManager::updateStudentName(int id, std::string newName)
{
    auto studentItr = studentDatabase.find(id);
    if (studentItr != studentDatabase.end())
    {
        Student *student = studentItr->second;
        if (student != nullptr)
        {
            student->setName(newName);
            std::cout << "Student Account Updated Successfully" << std::endl;
        }
        else
        {
            std::cerr << "Error: Student Id: " << id << " data corrupted" << std::endl;
        }
    }
    else
    {
        std::cerr << "Error: Student Id: " << id << " doesn't exist" << std::endl;
    }
}

void StudentManager::viewStudentById(int id)
{
    auto studentItr = studentDatabase.find(id);
    if (studentItr != studentDatabase.end())
    {
        Student *student = studentItr->second;
        if (student != nullptr)
        {
            std::cout << "Student Id: " << student->getId() << ", Student Name: " << student->getName() << std::endl;
        }
        else
        {
            std::cerr << "Error: Student Id: " << id << " data corrupted" << std::endl;
        }
    }
    else
    {
        std::cerr << "Error: Student Id: " << id << " doesn't exist" << std::endl;
    }
}

void StudentManager::eraseAllData()
{
    for (auto studentItr = studentDatabase.begin(); studentItr != studentDatabase.end(); studentItr++)
    {
        Student *student = studentItr->second;
        delete student;
        student = nullptr;
    }
    studentDatabase.clear();
}