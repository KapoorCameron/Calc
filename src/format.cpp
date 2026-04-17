#include <iostream>   /*for debugging*/
#include <string>

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

    std::cout << "striped_input in strip(): " << stripped_input << "\n";

    return stripped_input;
}

std::string format(int argc, char* argv[])
{
    /*handle flags here*/

    /*strip whitespace*/
    return strip_input(argv[1]);
}