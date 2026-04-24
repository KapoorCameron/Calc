#include <iostream>


#include "calc/token.hpp"


std::ostream& operator<<(std::ostream& os, const Token& token)
{
    os << "kind: ";

    if (token._kind == TokenKind::NUMBER )
    {
        os << "NUMBER\n";
    }

    if (token._kind == TokenKind::IDENT)
    {
        os << "IDENT\n";
    }

    if (token._kind == TokenKind::PLUS)
    {
        os << "PLUS\n";
    }

    if (token._kind == TokenKind::MINUS)
    {
        os << "MINUS\n";
    }

    if (token._kind == TokenKind::STAR)
    {
        os << "STAR\n"; 
    }

    if (token._kind == TokenKind::SLASH)
    {
        os << "SLASH\n";
    }

    if (token._kind == TokenKind::CARET)
    {
        os << "CARET\n";
    }

    if (token._kind == TokenKind::LPAREN)
    {
        os << "LPAREN\n";
    }

    if (token._kind == TokenKind::RPAREN)
    {
        os << "RPAREN\n";
    }

    if (token._kind == TokenKind::RBRACKET)
    {
        os << "RBRACKET\n";
    }

    if (token._kind == TokenKind::LBRACKET)
    {
        os << "LBRACKET\n";
    }

    if (token._kind == TokenKind::COMMA)
    {
        os << "COMMA\n";
    }

    if (token._kind == TokenKind::END_OF_LINE)
    {
        os << "END_OF_LINE\n";
    }

    os << "text: " << token._text << "\n" << "position: " << token._pos;

    return os;
}


