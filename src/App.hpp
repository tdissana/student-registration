#pragma once
#include <DBManager.hpp>
#include <Defs.hpp>
#include <string>

namespace registration
{
    class App
    {
    private:
        void showMenu();
        Choice getChoice();
        bool isValidChoice(Choice choice);
        void createStudent();
        void removeStudent();
        void updateStudent();
        void viewStudent();
        void exit();
        
        DBManager dbManager = DBManager("localhost", "root", "abcdefghi", "student_db");

    public:
        void run();
    };
}