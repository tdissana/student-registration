#include <App.hpp>
#include <iostream>

using namespace registration;

void App::showMenu()
{
    std::cout << "==========Student Registration==========" << std::endl;
    std::cout << "1. Create                               " << std::endl;
    std::cout << "2. Remove                               " << std::endl;
    std::cout << "3. Update                               " << std::endl;
    std::cout << "4. View                                 " << std::endl;
    std::cout << "5. Exit                                 " << std::endl;
    std::cout << "========================================" << std::endl;
}

Choice App::getChoice()
{
    int choice {};
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return static_cast<Choice>(choice);
}

bool App::isValidChoice(Choice choice)
{
    return (Choice::NONE < choice && choice <= Choice::EXIT);
}

void App::run()
{
    showMenu();
    Choice choice = Choice::NONE;
    do
    {
        choice = getChoice();
        switch (choice)
        {
        case CREATE:
            createStudent();
            break;
        case REMOVE:
            removeStudent();
            break;
        case UPDATE:
            updateStudent();
            break;
        case VIEW:
            viewStudent();
            break;
        case EXIT:
            exit();
            break;
        default:
            std::cout << "Invalid Choice" << std::endl;
            break;
        }
    } while (isValidChoice(choice) == false);
}

void App::createStudent()
{
    std::cout << "Creating a Student Account.............." << std::endl;
    int id;
    std::string name;
    std::cout << "Enter Id: ";
    std::cin >> id;
    std::cout << "Enter Name: ";
    std::cin >> name;
    dbManager.addStudent(id, name);
    run();
}

void App::removeStudent()
{
    std::cout << "Removing a Student Account.............." << std::endl;
    int id;
    std::cout << "Enter Id: ";
    std::cin >> id;
    dbManager.removeStudentById(id);
    run();
}

void App::updateStudent()
{
    std::cout << "Updating a Student Account.............." << std::endl;
    std::cout << "Select Update Option" << std::endl;
    std::cout << "1. Update Student Id" << std::endl;
    std::cout << "2. Update Student Name" << std::endl;
    std::cout << "Enter your update choice: ";
    int updateChoice = 0;
    std::cin >> updateChoice;

    if (updateChoice == 1)
    {
        int oldId, newId;
        std::cout << "Enter Old Id: ";
        std::cin >> oldId;
        std::cout << "Enter New Id: ";
        std::cin >> newId;
        dbManager.updateStudentId(oldId, newId);
    }
    else if (updateChoice == 2)
    {
        int id;
        std::string newName;
        std::cout << "Enter Id: ";
        std::cin >> id;
        std::cout << "Enter New Name: ";
        std::cin >> newName;
        dbManager.updateStudentName(id, newName);
    }
    else
    {
        std::cerr << "Error: Invalid Update Choice" << std::endl;
    }
    run();
}

void App::viewStudent()
{
    std::cout << "Viewing a Student Account..............." << std::endl;
    int id;
    std::cout << "Enter Id: ";
    std::cin >> id;
    dbManager.viewStudentById(id);
    run();
}

int App::exit()
{
    std::cout << "Exiting the system......................" << std::endl;
    dbManager.eraseAllData();
    std::cout << "===============Thank You!===============" << std::endl;
    return 0;
}