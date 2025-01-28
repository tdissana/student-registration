#pragma once

#include <Student.hpp>
#include <unordered_map>

namespace registration
{
    class DBManager
    {
        private:
            std::unordered_map<int, Student*> studentDatabase {};

        public:
            void addStudent(int id, std::string name);
            void removeStudentById(int id);
            void updateStudentId(int oldId, int newId);
            void updateStudentName(int id, std::string newName);
            void viewStudentById(int id);
            void eraseAllData();
    };
}