/*
﻿	 Copyright (c) Faber Leonardo. All Rights Reserved. (https://github.com/FaberSanZ);
	 This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT);
*/

#pragma once

#include <any>
#include <string>
#include <utility>      // std::move
#include "TokenType.hpp"



namespace Lox
{
	class Token
	{
	public:

		Token(TokenType type, std::string lexeme, std::any literal, int line) :
			m_Type { type }, 
			m_Lexeme { std::move(m_Lexeme) }, 
			m_Literal { std::move(m_Literal) }, 
			m_Line { line }
		{
		}

		const TokenType m_Type;
		const std::string m_Lexeme;
		const std::any m_Literal;
		const int m_Line;

	public:
		std::string ToString() const;


		std::string TokenTypeToString(TokenType type) const;

	};

}

