#include <iostream>
#include <unordered_set>
#include <vector>

#include "calc/cli.hpp"
#include "calc/format.hpp"
#include "calc/token.hpp"
#include "calc/lexer.hpp"


void print_help()
{
    std::cout << "Usage: calc <flag> <expression> <parameters>\n";
    std::cout << "Examples:\n";
    std::cout << "     calc \"2 + 5\"\n";
    std::cout << "     calc \"2+5\"\n";
    std::cout << "     calc \"4 * 7\"\n";
    std::cout << "     calc \"6 + 27/7\"\n";
    std::cout << "     calc \"12 + 4^3\"\n";
    std::cout << "     calc \"6log(2x) / 7\"\n";
    std::cout << "     calc \"sin(12pi)\" rad\n";
    std::cout << "     calc \"sec^2(45)\"\n";
    std::cout << "     calc \"d/dx[7x^2 + 2x - 9]\"\n";
    std::cout << "     cals \"S[3x^7 + x^5 - 2x^3 + x - 1]\" (-3, 3)\n";

    const std::unordered_set<std::string> flags = 
    {
        "-f",
        
        "--help"
    };
}

int run(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "error: no expression provided\n";
        return 1;
    }

    std::string arg_one = argv[1];

    if (argc == 2 && arg_one.empty())
    {
        std::cerr << "error: empty expression\n";
        return 1;
    }

    if (arg_one == "--help")
    {
        print_help();
        return 0;
    }

    if (arg_one == "-f")
    {
        /*user wants an expression factored*/
    }

    /*we call format(argc, argv) and are returned a string (from user input)*/
    std::string stripped_input = format(argc, argv);

    std::cout << "striped_input from format(argc, argv): " << stripped_input << "\n";

    Lexer lexer = Lexer(stripped_input);

    std::vector<Token> token_stream = lexer.lex();

    for (const Token& t : token_stream)
    {
        std::cout << t << "\n";
    }

    return 0;
}