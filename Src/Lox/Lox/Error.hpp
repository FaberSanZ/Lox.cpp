/*
?	 Copyright (c) Faber Leonardo. All Rights Reserved. (https://github.com/FaberSanZ);
	 This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT);
*/

#pragma once

#include <iostream>
#include <string_view>


namespace Lox
{
	class Error
	{
		public:
		Error() = delete;
		Error(const Error&) = delete;
		Error& operator=(const Error&) = delete;

		static void error(int line, std::string_view message)
		{
			std::cerr << "[line " << line << "] Error: " << message << "\n";
		}
	};

}




