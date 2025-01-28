#pragma once

#include <string>

namespace registration 
{
    class Student
    {
        private:
            int studentId;
            std::string studentName;

        public:
            Student(int id, std::string name);

            int getId();
            std::string getName();

            void setId(int id);
            void setName(std::string name);
    };
}