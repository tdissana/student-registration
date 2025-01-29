#include <DBManager.hpp>
#include <utility>
#include <iostream>

using namespace registration;

DBManager::DBManager(const std::string& host, const std::string& user, const std::string& password, const std::string& database) 
{
    connection = mysql_init(nullptr);
    if (!connection) {
        std::cerr << "Error: MySQL initialization failed!" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!mysql_real_connect(connection, host.c_str(), user.c_str(), password.c_str(), database.c_str(), 0, nullptr, 0)) {
        std::cerr << "Error: Connection failed: " << mysql_error(connection) << std::endl;
        exit(EXIT_FAILURE);
    }
}

DBManager::~DBManager() {
    if (connection) {
        mysql_close(connection);
    }
}

void DBManager::addStudent(int id, const std::string& name)
{
    std::string query = "INSERT INTO students (id, name) VALUES (" + std::to_string(id) + ", '" + name + "')";
    if (mysql_query(connection, query.c_str())) 
    {
        std::cerr << "Error: Insert Failed: " << mysql_error(connection) << std::endl;
        return;
    }

    std::cout << "Student Created Successfully!" << std::endl;
}

void DBManager::removeStudentById(int id) 
{
    std::string query = "DELETE FROM students WHERE id = " + std::to_string(id);
    if (mysql_query(connection, query.c_str())) {
        std::cerr << "Error: Remove Failed: " << mysql_error(connection) << std::endl;
        return;
    }
    std::cout << "Student Removed successfully!" << std::endl;
}

void DBManager::updateStudentId(int oldId, int newId) {
    // Check if newId already exists
    std::string checkQuery = "SELECT id FROM students WHERE id = " + std::to_string(newId);
    if (mysql_query(connection, checkQuery.c_str())) {
        std::cerr << "Error checking new ID: " << mysql_error(connection) << std::endl;
        return;
    }

    MYSQL_RES* result = mysql_store_result(connection);
    if (result && mysql_num_rows(result) > 0) {
        std::cerr << "Error: Student ID " << newId << " already exists" << std::endl;
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    // Check if oldId exists
    std::string checkOldIdQuery = "SELECT id FROM students WHERE id = " + std::to_string(oldId);
    if (mysql_query(connection, checkOldIdQuery.c_str())) {
        std::cerr << "Error checking old ID: " << mysql_error(connection) << std::endl;
        return;
    }

    result = mysql_store_result(connection);
    if (!result || mysql_num_rows(result) == 0) {
        std::cerr << "Error: Student ID " << oldId << " doesn't exist" << std::endl;
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    // Update student ID
    std::string updateQuery = "UPDATE students SET id = " + std::to_string(newId) + " WHERE id = " + std::to_string(oldId);
    if (mysql_query(connection, updateQuery.c_str())) {
        std::cerr << "Error updating student ID: " << mysql_error(connection) << std::endl;
        return;
    }

    std::cout << "Student ID updated successfully from " << oldId << " to " << newId << std::endl;
}


void DBManager::updateStudentName(int id, const std::string& newName) {
    // Check if the student ID exists
    std::string checkQuery = "SELECT id FROM students WHERE id = " + std::to_string(id);
    if (mysql_query(connection, checkQuery.c_str())) {
        std::cerr << "Error checking student ID: " << mysql_error(connection) << std::endl;
        return;
    }

    MYSQL_RES* result = mysql_store_result(connection);
    if (!result || mysql_num_rows(result) == 0) {
        std::cerr << "Error: Student ID " << id << " doesn't exist" << std::endl;
        mysql_free_result(result);
        return;
    }
    mysql_free_result(result);

    std::string updateQuery = "UPDATE students SET name = '" + newName + "' WHERE id = " + std::to_string(id);
    if (mysql_query(connection, updateQuery.c_str())) {
        std::cerr << "Error updating student name: " << mysql_error(connection) << std::endl;
        return;
    }

    std::cout << "Student name updated successfully for ID: " << id << std::endl;
}

void DBManager::viewStudentById(int id) {
    
    std::string query = "SELECT id, name FROM students WHERE id = " + std::to_string(id);
    if (mysql_query(connection, query.c_str())) {
        std::cerr << "Error retrieving student details: " << mysql_error(connection) << std::endl;
        return;
    }

    MYSQL_RES* result = mysql_store_result(connection);
    if (!result || mysql_num_rows(result) == 0) {
        std::cerr << "Error: Student ID " << id << " doesn't exist" << std::endl;
        mysql_free_result(result);
        return;
    }

    MYSQL_ROW row = mysql_fetch_row(result);
    std::cout << "Student ID: " << row[0] << ", Student Name: " << row[1] << std::endl;

    mysql_free_result(result);
}