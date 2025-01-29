#pragma once

#include <iostream>
#include <limits>

namespace utilities
{
    class Utility
    {
    public:
        static int getValidInt(const std::string &prompt)
        {
            int value;
            while (true)
            {
                std::cout << prompt;
                std::cin >> value;

                if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input! Please enter a valid number." << std::endl;
                }
                else
                {
                    return value;
                }
            }
        }
    };
}
