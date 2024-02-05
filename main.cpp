#include <iostream>

int main()
{
    std::string firstString;
    std::string secondString;

    std::cout << "Enter first string: ";
    getline(std::cin, firstString);

    std::cout << "Enter second string: ";
    getline(std::cin, secondString);

    std::cout << "You entered: " << firstString << " and " << secondString << std::endl;
}
