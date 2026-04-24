#include <iostream>
#include <string>

#include "calc/lexer.hpp"


/* """Take in a string reresenting user input and tokenize --> return a vector of tokens""" */

void Lexer::go_next_char()
{
    _pos += 1;

}

void Lexer::update_current_char()
{
    _current_char = _expression[_pos];
}

bool Lexer::end_of_expression()
{
    return _pos >= _expression.size();
}

inline bool is_number(char c)
{
    return (c >= '0' && c <= '9') || c == '.';
}

inline bool is_alpha(char c)
{
    return (c >= 65 && c <= 90) || (c >= 97 && c <= 122);
}

std::vector<Token> Lexer::lex()
{
    std::vector<Token> tokens_from_input = {};

    if (_expression.size() < 1)
    {
        std::cerr << "error: empty expression\n";
        
    }

    // NUMBER, IDENT, PLUS, MINUS, STAR, SLASH, CARET, LPAREN, RPAREN, LBRACKET, RBRACKET, COMMA, END_OF_INPUT
    while (!end_of_expression())
    {
        if (_current_char == ' ')
        {
            go_next_char();
            update_current_char();
            continue;
        }

        if (is_number(_current_char))
        {
            Token new_token = Token(TokenKind::NUMBER, std::string(1, _current_char), _pos);
            tokens_from_input.push_back(new_token);
            go_next_char();
            update_current_char();
            continue;
        }

        if (is_alpha(_current_char))
        {
            Token new_token = Token(TokenKind::IDENT, std::string(1, _current_char), _pos);
            tokens_from_input.push_back(new_token);
            go_next_char();
            update_current_char();
            continue;
        }

        if (_current_char == '+')
        {
            Token new_token = Token(TokenKind::PLUS, std::string(1, _current_char), _pos);
            tokens_from_input.push_back(new_token);
            go_next_char();
            update_current_char();
            continue;
        }

        if (_current_char == '-')
        {
            Token new_token = Token(TokenKind::MINUS, std::string(1, _current_char), _pos);
            tokens_from_input.push_back(new_token);
            go_next_char();
            update_current_char();
            continue;
        }

        if (_current_char == '*')
        {
            Token new_token = Token(TokenKind::STAR, std::string(1, _current_char), _pos);
            tokens_from_input.push_back(new_token);
            go_next_char();
            update_current_char();
            continue;
        }

        if (_current_char == '/')
        {
            Token new_token = Token(TokenKind::SLASH, std::string(1, _current_char), _pos);
            tokens_from_input.push_back(new_token);
            go_next_char();
            update_current_char();
            continue;
        }

        if (_current_char == '^')
        {
            Token new_token = Token(TokenKind::CARET, std::string(1, _current_char), _pos);
            tokens_from_input.push_back(new_token);
            go_next_char();
            update_current_char();
            continue;
        }

        if (_current_char == '(')
        {
            Token new_token = Token(TokenKind::LPAREN, std::string(1, _current_char), _pos);
            tokens_from_input.push_back(new_token);
            go_next_char();
            update_current_char();
            continue;
        }

        if (_current_char == ')')
        {
            Token new_token = Token(TokenKind::RPAREN, std::string(1, _current_char), _pos);
            tokens_from_input.push_back(new_token);
            go_next_char();
            update_current_char();
            continue;
        }

        if (_current_char == '[')
        {
            Token new_token = Token(TokenKind::LBRACKET, std::string(1, _current_char), _pos);
            tokens_from_input.push_back(new_token);
            go_next_char();
            update_current_char();
            continue;
        }

        if (_current_char == ']')
        {
            Token new_token = Token(TokenKind::RBRACKET, std::string(1, _current_char), _pos);
            tokens_from_input.push_back(new_token);
            go_next_char();
            update_current_char();
            continue;
        }

        if (_current_char == ',')
        {
            Token new_token = Token(TokenKind::COMMA, std::string(1, _current_char), _pos);
            tokens_from_input.push_back(new_token);
            go_next_char();
            update_current_char();
            continue;
        }

        tokens_from_input.push_back(Token(TokenKind::END_OF_LINE, "", _pos));
        return tokens_from_input;

        std::cerr << "error: unexpected character \"" << _current_char << "\" at position " << _pos << "\n";
        exit(1);
    }

    return tokens_from_input;
}