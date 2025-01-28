#pragma once
#include <DBManager.hpp>
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
            int exit();

            DBManager dbManager {};

        public:
            void run();
    };
}