#include <Student.hpp>

using namespace registration;

Student::Student(int id, std::string name) : studentId(id), studentName(name) {};

int Student::getId()
{
    return studentId;
}
std::string Student::getName()
{
    return studentName;
}

void Student::setId(int id)
{
    this->studentId = id;
}

void Student::setName(std::string name)
{
    this->studentName = name;
}
