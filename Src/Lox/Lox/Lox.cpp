/*
﻿	 Copyright (c) Faber Leonardo. All Rights Reserved. (https://github.com/FaberSanZ);
     This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT);
*/


#include <cstring>      
#include <fstream>      
#include <iostream>    
#include <string>
#include <string_view>
#include <vector>
#include "Scanner.hpp"


using namespace Lox;



//std::string ReadFile(std::string_view path)
//{
//    std::ifstream file { path.data(), std::ios::in | std::ios::binary | std::ios::ate };
//    if (!file)
//    {
//        std::cout << "Failed to open file " << path << ": " << std::strerror(errno) << "\n";
//        std::exit(74);
//    };
//
//    std::string contents;
//    contents.resize(file.tellg());
//
//    file.seekg(0, std::ios::beg);
//    file.read(contents.data(), contents.size());
//
//    return contents;
//}

void Run(std::string_view source)
{
    Scanner scanner { source };
    std::vector<Token> tokens = scanner.ScanTokens();

    // For now, just print the tokens.
    for (const Token& token : tokens)
    {
        std::cout << token.ToString() << "\n";
    }
}

//void RunFile(std::string_view path)
//{
//    std::string contents = ReadFile(path);
//
//    Run(contents);
//
//    // Indicate an error in the exit code.
//    if (hadError)
//        std::exit(65);
//}

void RunPrompt()
{
    for (;;)
    {
        std::cout << "> ";
        std::string line;
        if (!std::getline(std::cin, line)) break;
        Run(line);
    }
}

int main()
{
    std::string contents = "!*+-/=<> <= == ";
    Run(contents);


    // TODO: Implement command line argument parsing.
    //if (argc > 2) 
    //{
    //  std::cout << "Usage: jlox [script]\n";
    //  std::exit(64);
    //} 

    //else if (argc == 2) 
    //  runFile(argv[1]);

    //else 
    //  runPrompt();



    return 0;
}
