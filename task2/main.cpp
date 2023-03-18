#include <iostream>

#include "hashtag.h"

int main()
{
    std::cout << "Input your line: ";
    std::string input;
    std::getline(std::cin, input);
    std::cout << hashtag(input);
}