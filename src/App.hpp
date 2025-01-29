#pragma once
#include <StudentManager.hpp>
#include <Defs.hpp>

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

        StudentManager studentManager;

    public:
        void run();
    };
}