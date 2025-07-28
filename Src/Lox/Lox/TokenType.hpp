/*
?	 Copyright (c) Faber Leonardo. All Rights Reserved. (https://github.com/FaberSanZ);
	 This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT);
*/

#pragma once

#include <string>

namespace Lox
{

	enum TokenType
	{
		// Single-character tokens.
		LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
		COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

		// One or two character tokens.
		BANG, BANG_EQUAL,
		EQUAL, EQUAL_EQUAL,
		GREATER, GREATER_EQUAL,
		LESS, LESS_EQUAL,

		// Literals.
		IDENTIFIER, STRING, NUMBER,

		// Keywords.
		AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR,
		PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

		END_OF_FILE
	};




}
