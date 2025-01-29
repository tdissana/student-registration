#pragma once

#include <Student.hpp>
#include <unordered_map>
#include <mysql/mysql.h>

namespace registration
{
    class DBManager
    {
    private:
        MYSQL* connection;

    public:
        DBManager(const std::string& host, const std::string& user, const std::string& password, const std::string& database);
        ~DBManager();
        
        void addStudent(int id, const std::string& name);
        void removeStudentById(int id);
        void updateStudentId(int oldId, int newId);
        void updateStudentName(int id, const std::string& newName);
        void viewStudentById(int id);
    };
}