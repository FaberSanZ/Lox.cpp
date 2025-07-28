/*
﻿	 Copyright (c) Faber Leonardo. All Rights Reserved. (https://github.com/FaberSanZ);
	 This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT);
*/


#include "Scanner.hpp"


namespace Lox
{
	std::vector<Token> Scanner::ScanTokens()
	{
		while (!IsAtEnd())
		{
			// We are at the beginning of the next lexeme.
			m_Start = m_Current;
			ScanToken();
		}

		m_Tokens.emplace_back(END_OF_FILE, "", nullptr, m_Line);
		return m_Tokens;
	}

	void Scanner::ScanToken()
	{
		char c = Advance();
		switch (c)
		{
		case '(': AddToken(LEFT_PAREN); break;
		case ')': AddToken(RIGHT_PAREN); break;
		case '{': AddToken(LEFT_BRACE); break;
		case '}': AddToken(RIGHT_BRACE); break;
		case ',': AddToken(COMMA); break;
		case '.': AddToken(DOT); break;
		case '-': AddToken(MINUS); break;
		case '+': AddToken(PLUS); break;
		case ';': AddToken(SEMICOLON); break;
		case '*': AddToken(STAR); break;
		case '!':
			AddToken(Match('=') ? BANG_EQUAL : BANG);
			break;
		case '=':
			AddToken(Match('=') ? EQUAL_EQUAL : EQUAL);
			break;
		case '<':
			AddToken(Match('=') ? LESS_EQUAL : LESS);
			break;
		case '>':
			AddToken(Match('=') ? GREATER_EQUAL : GREATER);
			break;

		case '/':
			if (Match('/'))
			{
				// A comment goes until the end of the line.
				while (Peek() != '\n' && !IsAtEnd()) Advance();
			}
			else
			{
				AddToken(SLASH);
			}
			break;

		case ' ':
		case '\r':
		case '\t':
			// Ignore whitespace.
			break;

		case '\n':
			++m_Line;
			break;

		case '"': String(); break;

		default:
			// error(line, "Unexpected character");

			if (IsDigit(c))
			{
				Number();
			}
			else if (IsAlpha(c))
			{
				Identifier();
			}
			else
			{
				//error(line, "Unexpected character.");
			}
			break;
		};
	}

	void Scanner::Identifier()
	{
		while (IsAlphaNumeric(Peek())) Advance();

		// addToken(IDENTIFIER);

		std::string text = std::string { m_Source.substr(m_Start, m_Current - m_Start) };

		TokenType type;
		auto match = m_Keywords.find(text);
		if (match == m_Keywords.end())
		{
			type = IDENTIFIER;
		}
		else
		{
			type = match->second;
		}

		AddToken(type);
	}

	void Scanner::Number()
	{
		while (IsDigit(Peek())) Advance();

		// Look for a fractional part.
		if (Peek() == '.' && IsDigit(PeekNext()))
		{
			// Consume the "."
			Advance();

			while (IsDigit(Peek()))
				Advance();
		}

		AddToken(NUMBER, std::stod(std::string { m_Source.substr(m_Start, m_Current - m_Start) }));
	}

	void Scanner::String()
	{
		while (Peek() != '"' && !IsAtEnd())
		{
			if (Peek() == '\n') ++m_Line;
			Advance();
		}

		if (IsAtEnd())
		{
			//error(line, "Unterminated string.");
			return;
		}

		// The closing ".
		Advance();

		// Trim the surrounding quotes.
		std::string value { m_Source.substr(m_Start + 1, m_Current - 2 - m_Start) };
		AddToken(STRING, value);
	}

	bool Scanner::Match(char expected)
	{
		if (IsAtEnd()) return false;
		if (m_Source[m_Current] != expected) return false;

		++m_Current;
		return true;
	}

	char Scanner::Peek()
	{
		if (IsAtEnd()) return '\0';
		return m_Source[m_Current];
	}

	char Scanner::PeekNext()
	{
		if (m_Current + 1 >= m_Source.length()) return '\0';
		return m_Source[m_Current + 1];
	}

	bool Scanner::IsAlpha(char c)
	{
		return (c >= 'a' && c <= 'z') ||
			(c >= 'A' && c <= 'Z') ||
			c == '_';
	}

	bool Scanner::IsAlphaNumeric(char c)
	{
		return IsAlpha(c) || IsDigit(c);
	}

	bool Scanner::IsDigit(char c)
	{
		return c >= '0' && c <= '9';
	}

	bool Scanner::IsAtEnd()
	{
		return m_Current >= m_Source.length();
	}

	char Scanner::Advance()
	{
		return m_Source[m_Current++];
	}

	void Scanner::AddToken(TokenType type)
	{
		AddToken(type, nullptr);
	}

	void Scanner::AddToken(TokenType type, std::any literal)
	{
		std::string text { m_Source.substr(m_Start, m_Current - m_Start) };
		m_Tokens.emplace_back(type, std::move(text), std::move(literal), m_Line);
	}



	const std::map<std::string, TokenType> Scanner::m_Keywords =
	{
		{"and",    TokenType::AND},
		{"class",  TokenType::CLASS},
		{"else",   TokenType::ELSE},
		{"false",  TokenType::FALSE},
		{"for",    TokenType::FOR},
		{"fun",    TokenType::FUN},
		{"if",     TokenType::IF},
		{"nil",    TokenType::NIL},
		{"or",     TokenType::OR},
		{"print",  TokenType::PRINT},
		{"return", TokenType::RETURN},
		{"super",  TokenType::SUPER},
		{"this",   TokenType::THIS},
		{"true",   TokenType::TRUE},
		{"var",    TokenType::VAR},
		{"while",  TokenType::WHILE}
	};
};
