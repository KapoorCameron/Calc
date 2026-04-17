#include <iostream>


#include "calc/cli.hpp" 


int main(int argc, char* argv[])
{
    if (run(argc, argv) == 1)
    {
        std::cerr; /*error out properly*/
        return 1;
    }

    return 0;
}