#include <iostream>   /*for debugging*/
#include <string>

#include "calc/format.hpp"


std::string strip_input(std::string input)
{
    std::string stripped_input = "";

    for (size_t i = 0; i < input.size(); i++)
    {
        if (input[i] != ' ')
        {
            stripped_input += input[i];
            continue;
        }
    }
    
    return stripped_input;
}

std::string format(int argc, char* argv[])
{
    /*handle flags here*/

    /*strip whitespace*/
    return strip_input(argv[1]);
}