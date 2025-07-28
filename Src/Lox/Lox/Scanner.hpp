#pragma once

#include <map>
#include <string>
#include <string_view>
/*
﻿	 Copyright (c) Faber Leonardo. All Rights Reserved. (https://github.com/FaberSanZ);
	 This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT);
*/


#include <utility>      // std::move
#include <vector>
#include "Error.hpp"
#include "Token.hpp"


namespace Lox
{
	class Scanner
	{
		static const std::map<std::string, TokenType> m_Keywords;

		std::string_view m_Source;
		std::vector<Token> m_Tokens;
		int m_Start = 0;
		int m_Current = 0;
		int m_Line = 1;

	public:
		Scanner(std::string_view source)
			: m_Source { source }
		{
		}


		std::vector<Token> ScanTokens();

	private:
		void ScanToken();

		void Identifier();

		void Number();

		void String();

		bool Match(char expected);

		char Peek();

		char PeekNext();

		bool IsAlpha(char c);

		bool IsAlphaNumeric(char c);

		bool IsDigit(char c);

		bool IsAtEnd();

		char Advance();

		void AddToken(TokenType type);

		void AddToken(TokenType type, std::any literal);




	};



}

