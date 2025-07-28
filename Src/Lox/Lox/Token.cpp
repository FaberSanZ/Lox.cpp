/*
﻿	 Copyright (c) Faber Leonardo. All Rights Reserved. (https://github.com/FaberSanZ);
	 This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT);
*/


#include "Token.hpp"



namespace Lox
{

	std::string Token::ToString() const
	{
		std::string literal_text;

		switch (m_Type)
		{
		case (IDENTIFIER):
			literal_text = m_Lexeme;
			break;
		case (STRING):
			literal_text = std::any_cast<std::string>(m_Literal);
			break;
		case (NUMBER):
			literal_text = std::to_string(std::any_cast<double>(m_Literal));
			break;
		case (TRUE):
			literal_text = "true";
			break;
		case (FALSE):
			literal_text = "false";
			break;
		default:
			literal_text = "nil";
		}

		return TokenTypeToString(m_Type) + " " + m_Lexeme + " " + literal_text;
	}

	std::string Token::TokenTypeToString(TokenType type) const
	{
		static const std::string strings[] =
		{
		  "LEFT_PAREN", "RIGHT_PAREN", "LEFT_BRACE", "RIGHT_BRACE",
		  "COMMA", "DOT", "MINUS", "PLUS", "SEMICOLON", "SLASH", "STAR",
		  "BANG", "BANG_EQUAL",
		  "EQUAL", "EQUAL_EQUAL",
		  "GREATER", "GREATER_EQUAL",
		  "LESS", "LESS_EQUAL",
		  "IDENTIFIER", "STRING", "NUMBER",
		  "AND", "CLASS", "ELSE", "FALSE", "FUN", "FOR", "IF", "NIL", "OR",
		  "PRINT", "RETURN", "SUPER", "THIS", "TRUE", "VAR", "WHILE",
		  "END_OF_FILE"
		};

		return strings[static_cast<int>(type)];
	}


}
