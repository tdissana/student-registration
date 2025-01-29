#include <App.hpp>
#include <iostream>
#include <Utils.hpp>

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
    int choice = utilities::Utility::getValidInt("Enter your choice: ");
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
    int id = utilities::Utility::getValidInt("Enter Id: ");
    std::string name;
    std::cout << "Enter Name: ";
    std::cin >> name;
    dbManager.addStudent(id, name);
    run();
}

void App::removeStudent()
{
    std::cout << "Removing a Student Account.............." << std::endl;
    int id = utilities::Utility::getValidInt("Enter Id: ");
    dbManager.removeStudentById(id);
    run();
}

void App::updateStudent()
{
    std::cout << "Updating a Student Account.............." << std::endl;
    std::cout << "Select Update Option" << std::endl;
    std::cout << "1. Update Student Id" << std::endl;
    std::cout << "2. Update Student Name" << std::endl;
    int updateChoice = utilities::Utility::getValidInt("Enter your update choice: ");;

    if (static_cast<UpdateChoice>(updateChoice) == UpdateChoice::UPDATE_ID)
    {
        int oldId = utilities::Utility::getValidInt("Enter Old Id: ");
        int newId = utilities::Utility::getValidInt("Enter New Id: ");
        dbManager.updateStudentId(oldId, newId);
    }
    else if (static_cast<UpdateChoice>(updateChoice) == UpdateChoice::UPDATE_NAME)
    {
        int id = utilities::Utility::getValidInt("Enter Id: ");
        std::string newName;
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
    int id = utilities::Utility::getValidInt("Enter Id: ");
    dbManager.viewStudentById(id);
    run();
}

void App::exit()
{
    std::cout << "Exiting the system......................" << std::endl;
    std::cout << "===============Thank You!===============" << std::endl;
}